//
//  Wallet.swift
//  neovmUtils_Tests
//
//  Created by Wyatt Mufson on 2/15/19.
//  Copyright © 2019 Ryu Blockchain Technologies. All rights reserved.
//

import Foundation
import Neoutils
import CommonCrypto

public class Wallet {
    public var address : String!
    public var wif : String!
    public var privateKey : Data!
    public var publicKey : Data!
    public var privateKeyString : String!
    public var publicKeyString : String!
    private var neoWallet : NeoutilsWallet!
    public var neoPrivateKey : Data {
        return neoWallet.privateKey()
    }
    
    convenience init(address: String, wif: String, privateKey: Data, publicKey: Data, neoWallet: NeoutilsWallet) {
        self.init()
        self.address = address
        self.wif = wif
        self.privateKey = privateKey
        self.publicKey = publicKey
        self.privateKeyString = privateKey.bytesToHex
        self.publicKeyString = publicKey.bytesToHex
        self.neoWallet = neoWallet
    }
    
    public func signMessage(message: String) -> String? {
        let error = NSErrorPointer(nilLiteral: ())
        guard let data = message.data(using: .utf8) else {
            return nil
        }
        let sig = NeoutilsSign(data, neoWallet.privateKey()?.bytesToHex, error).bytesToHex
        if error != nil {
            return nil
        }
        return sig
    }
    
    public func verifySignature(signature: String, message: String) -> Bool {
        guard let data = message.data(using: .utf8) else {
            return false
        }
        guard let hash = sha256(data) else {
            return false
        }
        return NeoutilsVerify(publicKey, signature.hexToBytes, hash)
    }
    
    public func computeSharedSecret(publicKey: Data) -> Data? {
        return neoWallet.computeSharedSecret(publicKey)
    }
    
    public func computeSharedSecret(publicKey: String) -> Data? {
        return neoWallet.computeSharedSecret(publicKey.hexToBytes)
    }
    
    public func privateEncrypt(message: String) -> String {
        return NeoutilsEncrypt(neoWallet.privateKey(), message)
    }
    
    public func privateDecrypt(encrypted: String) -> String {
        return NeoutilsDecrypt(neoWallet.privateKey(), encrypted)
    }
    
    public func sharedEncrypt(message: String, publicKey: Data) -> String {
        let secretKey = computeSharedSecret(publicKey: publicKey)
        return NeoutilsEncrypt(secretKey, message)
    }
    
    public func sharedDecrypt(encrypted: String, publicKey: Data) -> String {
        let secretKey = computeSharedSecret(publicKey: publicKey)
        return NeoutilsDecrypt(secretKey, encrypted)
    }
}

// MARK: - PUBLIC FUNCTIONS

public func newWallet() -> Wallet? {
    guard let ontAccount = NeoutilsONTCreateAccount() else {
        return nil
    }
    let wallet = walletFromOntAccount(ontAccount: ontAccount)
    return wallet
}

public func walletFromWIF(wif: String) -> Wallet? {
    guard let ontAccount = NeoutilsONTAccountFromWIF(wif) else {
        return nil
    }
    let wallet = walletFromOntAccount(ontAccount: ontAccount)
    return wallet
}

public func walletFromPrivateKey(privateKey: Data) -> Wallet? {
    let count = privateKey.count
    if count == 32 {
        return walletFromNEOPrivateKey(privateKey: privateKey)
    } else if count == 67 {
        return walletFromONTPrivateKey(privateKey: privateKey)
    } else {
        return nil
    }
}

public func walletFromPrivateKey(privateKey: String) -> Wallet? {
    guard let p = privateKey.hexToBytes else {
        return nil
    }
    return walletFromPrivateKey(privateKey: p)
}

public func newEncryptedKey(wif: String, password: String) -> String? {
    let error = NSErrorPointer(nilLiteral: ())
    let nep2 = NeoutilsNEP2Encrypt(wif, password, error)
    return nep2?.encryptedKey()
}

public func wifFromEncryptedKey(encrypted: String, password: String) -> String? {
    let error = NSErrorPointer(nilLiteral: ())
    let wif = NeoutilsNEP2Decrypt(encrypted, password, error)
    return wif
}

public func addressFromWif(wif: String) -> String? {
    guard let wallet = walletFromWIF(wif: wif) else {
        return nil
    }
    return wallet.address
}

public func walletFromMnemonicPhrase(mnemonic: String) -> Wallet? {
    let m = mnemonicFromPhrase(phrase: mnemonic)
    let kp = createHDKeyPair(mnemonic: m)
    let w = walletFromPrivateKey(privateKey: kp.privateKey)
    return w
}

// MARK: - PRIVATE FUNCTIONS

private func sha256(_ data: Data) -> Data? {
    guard let res = NSMutableData(length: Int(CC_SHA256_DIGEST_LENGTH)) else { return nil }
    CC_SHA256((data as NSData).bytes, CC_LONG(data.count), res.mutableBytes.assumingMemoryBound(to: UInt8.self))
    return res as Data
}

private func walletFromOntAccount(ontAccount: NeoutilsONTAccount) -> Wallet? {
    guard let a = ontAccount.address() else {
        return nil
    }
    guard let wif = ontAccount.wif() else {
        return nil
    }
    guard let prK = ontAccount.privateKey() else {
        return nil
    }
    guard let pbK = ontAccount.publicKey() else {
        return nil
    }
    let err = NSErrorPointer(nilLiteral: ())
    guard let neoWallet = NeoutilsGenerateFromWIF(wif, err) else {
        return nil
    }
    let w = Wallet(address: a, wif: wif, privateKey: prK, publicKey: pbK, neoWallet: neoWallet)
    return w
}

private func walletFromNEOPrivateKey(privateKey: String) -> Wallet? {
    let err = NSErrorPointer(nilLiteral: ())
    guard let neoWallet = NeoutilsGenerateFromPrivateKey(privateKey, err) else {
        return nil
    }
    guard let ontAccount = NeoutilsONTAccountFromWIF(neoWallet.wif()) else {
        return nil
    }
    guard let a = ontAccount.address() else {
        return nil
    }
    guard let wif = ontAccount.wif() else {
        return nil
    }
    guard let prK = ontAccount.privateKey() else {
        return nil
    }
    guard let pbK = ontAccount.publicKey() else {
        return nil
    }
    let w = Wallet(address: a, wif: wif, privateKey: prK, publicKey: pbK, neoWallet: neoWallet)
    return w
}

private func walletFromNEOPrivateKey(privateKey: Data) -> Wallet? {
    guard let p = privateKey.bytesToHex else {
        return nil
    }
    return walletFromNEOPrivateKey(privateKey: p)
}

private func walletFromONTPrivateKey(privateKey: Data) -> Wallet? {
    guard let ontAccount = NeoutilsONTAccountFromPrivateKey(privateKey) else {
        return nil
    }
    let wallet = walletFromOntAccount(ontAccount: ontAccount)
    return wallet
}