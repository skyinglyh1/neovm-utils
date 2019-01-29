//
//  neovm.swift
//  Pods-neovmUtils_Tests
//
//  Created by Wyatt Mufson on 1/28/19.
//

import Foundation
import Neoutils

public enum OntologyParameterType: String {
    case Address
    case String
    case Fixed8
    case Integer
    case Array
    case Unknown
}

public struct OntologyParameter {
    public var type : OntologyParameterType = .Unknown
    public var value : Any = ""
}

public func createOntParam(type:OntologyParameterType, value:Any) -> OntologyParameter {
    return OntologyParameter(type: type, value: value)
}

private func convertParamArray(params: [OntologyParameter]) -> [[String:Any]] {
    var args : [[String:Any]] = []
    for i in 0..<params.count {
        let item = params[i]
        let type = item.type.rawValue
        let value = item.value
        let arg : [String:Any] = ["T": type, "V": value]
        args.append(arg)
    }
    return args
}

private func buildOntologyInvocationTransactionHelper(contractHash: String, method: String, args: [[String:Any]], gasPrice: Int, gasLimit: Int, wif: String) -> String? {
    do {
        let data =  try JSONSerialization.data(withJSONObject: args, options: .prettyPrinted)
        let params = String(data: data, encoding: String.Encoding.utf8)
        let err = NSErrorPointer(nilLiteral: ())
        let res = NeoutilsBuildOntologyInvocationTransaction(contractHash, method, params, gasPrice, gasLimit, wif, err)
        return res
    } catch {
        return nil
    }
}

private func ontologyInvokeHelper(endpoint: String, contractHash: String, method: String, args: [[String:Any]], gasPrice: Int, gasLimit: Int, wif: String) -> String? {
    do {
        let data =  try JSONSerialization.data(withJSONObject: args, options: .prettyPrinted)
        let args = String(data: data, encoding: String.Encoding.utf8)
        let err = NSErrorPointer(nilLiteral: ())
        let res = NeoutilsOntologyInvoke(endpoint, contractHash, method, args, gasPrice, gasLimit, wif, err)
        return res
    } catch {
        return nil
    }
}

public func buildOntologyInvocationTransaction(contractHash: String, method: String, args: [OntologyParameter], gasPrice: Int, gasLimit: Int, wif: String) -> String? {
    let params = convertParamArray(params: args)
    return buildOntologyInvocationTransactionHelper(contractHash: contractHash, method: method, args: params, gasPrice: gasPrice, gasLimit: gasLimit, wif: wif)
}

public func ontologyInvoke(endpoint: String = "http://polaris2.ont.io:20336", contractHash: String, method: String, args: [OntologyParameter], gasPrice: Int, gasLimit: Int, wif: String) -> String? {
    let params = convertParamArray(params: args)
    return ontologyInvokeHelper(endpoint: endpoint, contractHash: contractHash, method: method, args: params, gasPrice: gasPrice, gasLimit: gasLimit, wif: wif)
}

public func newWallet() -> NeoutilsWallet? {
    let err = NSErrorPointer(nilLiteral: ())
    return NeoutilsNewWallet(err)
}

public func generateFromWIF(wif: String) -> NeoutilsWallet? {
    let err = NSErrorPointer(nilLiteral: ())
    return NeoutilsGenerateFromWIF(wif, err)
}

public func generateFromPrivateKey(privateKey: String) -> NeoutilsWallet? {
    let err = NSErrorPointer(nilLiteral: ())
    return NeoutilsGenerateFromPrivateKey(privateKey, err)
}

public func generateFromPrivateKey(privateKey: Data) -> NeoutilsWallet? {
    let err = NSErrorPointer(nilLiteral: ())
    return NeoutilsGenerateFromPrivateKey(privateKey.bytesToHex, err)
}

public extension Data {
    var bytesToHex: String? {
        return NeoutilsBytesToHex(self)
    }
}

fileprivate extension String {
    var hexToBytes: Data? {
        return NeoutilsHexTobytes(self)
    }
}

public extension NeoutilsWallet {
    var privateKeyString: String? {
        return self.privateKey()?.bytesToHex
    }
    
    var publicKeyString: String? {
        return self.publicKey()?.bytesToHex
    }
}

public func signMessage(message: String, wallet: NeoutilsWallet) -> String? {
    let error = NSErrorPointer(nilLiteral: ())
    let data = message.data(using: .utf8)
    if let privateKey = wallet.privateKeyString {
        if let sign_data = NeoutilsSign(data, privateKey, error) {
            return sign_data.bytesToHex
        } else {
            print("Failed to sign message: \(error!)")
        }
    }
    return nil
}

public func encrypt(message: String, key: Data) -> String? {
    return NeoutilsEncrypt(key, message)
}

public func encrypt(message: String, key: String) -> String? {
    return NeoutilsEncrypt(key.hexToBytes, message)
}

public func decrypt(encrypted: String, key: Data) -> String? {
    return NeoutilsDecrypt(key, encrypted)
}

public func decrypt(encrypted: String, key: String) -> String? {
    return NeoutilsDecrypt(key.hexToBytes, encrypted)
}

public func computeSharedSecret(wallet: NeoutilsWallet, publicKey: Data) -> Data? {
    return wallet.computeSharedSecret(publicKey)
}

public func computeSharedSecret(wallet: NeoutilsWallet, publicKey: String) -> Data? {
    return wallet.computeSharedSecret(publicKey.hexToBytes)
}

public extension String {
    public var isValidAddress: Bool {
        return NeoutilsValidateNEOAddress(self)
    }
}
