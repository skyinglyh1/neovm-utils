// Objective-C API for talking to github.com/o3labs/neo-utils/neoutils Go package.
//   gobind -lang=objc github.com/o3labs/neo-utils/neoutils
//
// File is generated by gobind. Do not edit.

#ifndef __Neoutils_H__
#define __Neoutils_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

NS_ASSUME_NONNULL_BEGIN

@class NeoutilsBlockCountResponse;
@class NeoutilsFetchSeedRequest;
@class NeoutilsMultiSig;
@class NeoutilsNEP2;
@class NeoutilsNEP5;
@class NeoutilsNativeAsset;
@class NeoutilsNeonJSTransaction;
@class NeoutilsNodeList;
@class NeoutilsONTAccount;
@class NeoutilsOntologyBalances;
@class NeoutilsRawTransaction;
@class NeoutilsSeedNodeResponse;
@class NeoutilsSharedSecret;
@class NeoutilsSimplifiedNEP9;
@class NeoutilsSmartCodeEvent;
@class NeoutilsSmartContract;
@class NeoutilsSmartContractInfo;
@class NeoutilsWallet;
@protocol NeoutilsMultiSigInterface;
@class NeoutilsMultiSigInterface;
@protocol NeoutilsNEP5Interface;
@class NeoutilsNEP5Interface;
@protocol NeoutilsNativeAssetInterface;
@class NeoutilsNativeAssetInterface;
@protocol NeoutilsSmartContractInterface;
@class NeoutilsSmartContractInterface;

@protocol NeoutilsMultiSigInterface <NSObject>
- (NSData* _Nullable)createMultiSigRedeemScript:(NSError* _Nullable*)error;
@end

@protocol NeoutilsNEP5Interface <NSObject>
// skipped method NEP5Interface.MintTokensRawTransaction with unsupported parameter or return types

// skipped method NEP5Interface.TransferNEP5RawTransaction with unsupported parameter or return types

@end

@protocol NeoutilsNativeAssetInterface <NSObject>
// skipped method NativeAssetInterface.GenerateRawTx with unsupported parameter or return types

// skipped method NativeAssetInterface.SendNativeAssetRawTransaction with unsupported parameter or return types

@end

@protocol NeoutilsSmartContractInterface <NSObject>
// skipped method SmartContractInterface.GenerateInvokeFunctionRawTransaction with unsupported parameter or return types

// skipped method SmartContractInterface.GenerateInvokeFunctionRawTransactionWithAmountToSend with unsupported parameter or return types

@end

@interface NeoutilsBlockCountResponse : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull jsonrpc;
@property (nonatomic) long id_;
@property (nonatomic) long result;
@property (nonatomic) int64_t responseTime;
@end

@interface NeoutilsFetchSeedRequest : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NeoutilsBlockCountResponse* _Nullable response;
@property (nonatomic) NSString* _Nonnull url;
@end

@interface NeoutilsMultiSig : NSObject <goSeqRefInterface, NeoutilsMultiSigInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) long numberOfRequiredSignatures;
// skipped field MultiSig.PublicKeys with unsupported type: [][]byte

- (NSData* _Nullable)createMultiSigRedeemScript:(NSError* _Nullable*)error;
@end

@interface NeoutilsNEP2 : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull encryptedKey;
@property (nonatomic) NSString* _Nonnull address;
@end

@interface NeoutilsNEP5 : NSObject <goSeqRefInterface, NeoutilsNEP5Interface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
// skipped field NEP5.ScriptHash with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.ScriptHash

// skipped field NEP5.NetworkFeeAmount with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.NetworkFeeAmount

// skipped method NEP5.MintTokensRawTransaction with unsupported parameter or return types

// skipped method NEP5.TransferNEP5RawTransaction with unsupported parameter or return types

@end

@interface NeoutilsNativeAsset : NSObject <goSeqRefInterface, NeoutilsNativeAssetInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
// skipped field NativeAsset.NetworkFeeAmount with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.NetworkFeeAmount

// skipped method NativeAsset.GenerateRawTx with unsupported parameter or return types

// skipped method NativeAsset.SendNativeAssetRawTransaction with unsupported parameter or return types

@end

@interface NeoutilsNeonJSTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull sha256;
@property (nonatomic) NSString* _Nonnull hash;
// skipped field NeonJSTransaction.Inputs with unsupported type: []struct{PrevIndex int "json:\"prevIndex\""; PrevHash string "json:\"prevHash\""}

// skipped field NeonJSTransaction.Outputs with unsupported type: []struct{AssetID string "json:\"assetId\""; ScriptHash string "json:\"scriptHash\""; Value interface{} "json:\"value\""}

@property (nonatomic) NSString* _Nonnull script;
@property (nonatomic) long version;
@property (nonatomic) long type;
// skipped field NeonJSTransaction.Attributes with unsupported type: []struct{Usage int "json:\"usage\""; Data string "json:\"data\""}

// skipped field NeonJSTransaction.Scripts with unsupported type: []interface{}

@property (nonatomic) long gas;
@end

@interface NeoutilsNodeList : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
// skipped field NodeList.URL with unsupported type: []string

@end

@interface NeoutilsONTAccount : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull wif;
@property (nonatomic) NSData* _Nullable privateKey;
@property (nonatomic) NSData* _Nullable publicKey;
@end

@interface NeoutilsOntologyBalances : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull ont;
@property (nonatomic) NSString* _Nonnull ong;
@end

@interface NeoutilsRawTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull txid;
@property (nonatomic) NSData* _Nullable data;
@end

@interface NeoutilsSeedNodeResponse : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull url;
@property (nonatomic) long blockCount;
@property (nonatomic) int64_t responseTime;
@end

/**
 * Shared Secret with 2 parts.
 */
@interface NeoutilsSharedSecret : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSData* _Nullable first;
@property (nonatomic) NSData* _Nullable second;
@end

@interface NeoutilsSimplifiedNEP9 : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull to;
@property (nonatomic) NSString* _Nonnull asset;
@property (nonatomic) double amount;
@end

@interface NeoutilsSmartCodeEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull txHash;
@property (nonatomic) long state;
@property (nonatomic) long gasConsumed;
@end

@interface NeoutilsSmartContract : NSObject <goSeqRefInterface, NeoutilsSmartContractInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
// skipped field SmartContract.ScriptHash with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.ScriptHash

// skipped field SmartContract.NetworkFeeAmount with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.NetworkFeeAmount

// skipped method SmartContract.GenerateInvokeFunctionRawTransaction with unsupported parameter or return types

// skipped method SmartContract.GenerateInvokeFunctionRawTransactionWithAmountToSend with unsupported parameter or return types

@end

@interface NeoutilsSmartContractInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull avmhex;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull version;
@property (nonatomic) NSString* _Nonnull author;
@property (nonatomic) NSString* _Nonnull email;
@property (nonatomic) NSString* _Nonnull description;
// skipped field SmartContractInfo.Properties with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.Properties

// skipped field SmartContractInfo.InputTypes with unsupported type: []github.com/o3labs/neo-utils/neoutils/smartcontract.ParameterType

// skipped field SmartContractInfo.ReturnType with unsupported type: github.com/o3labs/neo-utils/neoutils/smartcontract.ParameterType

- (NSString* _Nonnull)getScriptHash;
- (NSData* _Nullable)serialize;
@end

@interface NeoutilsWallet : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (nonnull instancetype)initWithRef:(id)ref;
/**
 * Create a new wallet.
 */
- (instancetype)init;
@property (nonatomic) NSData* _Nullable publicKey;
@property (nonatomic) NSData* _Nullable privateKey;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull wif;
@property (nonatomic) NSData* _Nullable hashedSignature;
/**
 * Compute shared secret using ECDH
 */
- (NSData* _Nullable)computeSharedSecret:(NSData* _Nullable)publicKey;
@end

FOUNDATION_EXPORT NSString* const NeoutilsVERSION;

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsBuildOntologyInvocationTransaction(NSString* _Nullable contract, NSString* _Nullable method, NSString* _Nullable args, long gasPrice, long gasLimit, NSString* _Nullable wif, NSString* _Nullable payer, NSError* _Nullable* error);

/**
 * Simple bytes to Hex
 */
FOUNDATION_EXPORT NSString* _Nonnull NeoutilsBytesToHex(NSData* _Nullable b);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsClaimONG(NSString* _Nullable endpoint, long gasPrice, long gasLimit, NSString* _Nullable wif, NSError* _Nullable* error);

// skipped function ConvertByteArrayToBigInt with unsupported parameter or return types


/**
 * Decrypt AES encrypted string in base64 format to decrypted string
 */
FOUNDATION_EXPORT NSString* _Nonnull NeoutilsDecrypt(NSData* _Nullable key, NSString* _Nullable encryptedText);

// skipped function DeploySmartContractScript with unsupported parameter or return types


/**
 * Encrypt string to base64 format using AES
 */
FOUNDATION_EXPORT NSString* _Nonnull NeoutilsEncrypt(NSData* _Nullable key, NSString* _Nullable text);

/**
 * Generate a wallet from a private key
 */
FOUNDATION_EXPORT NeoutilsWallet* _Nullable NeoutilsGenerateFromPrivateKey(NSString* _Nullable privateKey, NSError* _Nullable* error);

/**
 * Generate a wallet from a WIF
 */
FOUNDATION_EXPORT NeoutilsWallet* _Nullable NeoutilsGenerateFromWIF(NSString* _Nullable wif, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsGenerateNEP6FromEncryptedKey(NSString* _Nullable walletName, NSString* _Nullable addressLabel, NSString* _Nullable address, NSString* _Nullable encryptedKey);

/**
 * Generate Shamir shared secret to SharedSecret struct.
 */
FOUNDATION_EXPORT NeoutilsSharedSecret* _Nullable NeoutilsGenerateShamirSharedSecret(NSString* _Nullable secret, NSError* _Nullable* error);

FOUNDATION_EXPORT NSData* _Nullable NeoutilsGetVarUInt(int64_t value);

FOUNDATION_EXPORT NSData* _Nullable NeoutilsHash160(NSData* _Nullable data);

FOUNDATION_EXPORT NSData* _Nullable NeoutilsHash256(NSData* _Nullable b);

/**
 * Simple hex string to bytes
 */
FOUNDATION_EXPORT NSData* _Nullable NeoutilsHexTobytes(NSString* _Nullable hexstring);

FOUNDATION_EXPORT NeoutilsRawTransaction* _Nullable NeoutilsMintTokensRawTransactionMobile(NSString* _Nullable network, NSString* _Nullable scriptHash, NSString* _Nullable wif, NSString* _Nullable sendingAssetID, double amount, NSString* _Nullable remark, double networkFeeAmountInGAS, NSError* _Nullable* error);

// skipped function NEOAddressToScriptHashWithEndian with unsupported parameter or return types


FOUNDATION_EXPORT NSString* _Nonnull NeoutilsNEOAddresstoScriptHashBigEndian(NSString* _Nullable neoAddress);

FOUNDATION_EXPORT NSString* _Nullable NeoutilsNEP2Decrypt(NSString* _Nullable key, NSString* _Nullable passphrase, NSError* _Nullable* error);

FOUNDATION_EXPORT NeoutilsNEP2* _Nullable NeoutilsNEP2Encrypt(NSString* _Nullable wif, NSString* _Nullable passphrase, NSError* _Nullable* error);

// skipped function NeonJSTXSerializer with unsupported parameter or return types


/**
 * Create a new wallet.
 */
FOUNDATION_EXPORT NeoutilsWallet* _Nullable NeoutilsNewWallet(NSError* _Nullable* error);

FOUNDATION_EXPORT NeoutilsONTAccount* _Nullable NeoutilsONTAccountFromPrivateKey(NSData* _Nullable privateKeyBytes);

FOUNDATION_EXPORT NeoutilsONTAccount* _Nullable NeoutilsONTAccountFromWIF(NSString* _Nullable wif);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsONTAddressFromPublicKey(NSData* _Nullable publicKey);

FOUNDATION_EXPORT NeoutilsONTAccount* _Nullable NeoutilsONTCreateAccount(void);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyBuildGetDDO(NSString* _Nullable ontid, NSError* _Nullable* error);

FOUNDATION_EXPORT NeoutilsOntologyBalances* _Nullable NeoutilsOntologyGetBalance(NSString* _Nullable endpoint, NSString* _Nullable address, NSError* _Nullable* error);

FOUNDATION_EXPORT BOOL NeoutilsOntologyGetBlockCount(NSString* _Nullable endpoint, long* ret0_, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyGetBlockWithHash(NSString* _Nullable endpoint, NSString* _Nullable blockHash, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyGetBlockWithHeight(NSString* _Nullable endpoint, long blockHeight, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyGetRawTransaction(NSString* _Nullable endpoint, NSString* _Nullable txID, NSError* _Nullable* error);

FOUNDATION_EXPORT NeoutilsSmartCodeEvent* _Nullable NeoutilsOntologyGetSmartCodeEvent(NSString* _Nullable endpoint, NSString* _Nullable txHash, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyGetStorage(NSString* _Nullable endpoint, NSString* _Nullable scriptHash, NSString* _Nullable key, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyGetUnboundONG(NSString* _Nullable endpoint, NSString* _Nullable address, NSError* _Nullable* error);

/**
 * OntologyInvoke : Invoke a neovm contract in Ontology
 */
FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyInvoke(NSString* _Nullable endpoint, NSString* _Nullable contract, NSString* _Nullable method, NSString* _Nullable args, long gasPrice, long gasLimit, NSString* _Nullable wif, NSString* _Nullable payer, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyMakeRegister(long gasPrice, long gasLimit, NSString* _Nullable ontidWif, NSString* _Nullable payerWif, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologySendPreExecRawTransaction(NSString* _Nullable endpoint, NSString* _Nullable raw, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologySendRawTransaction(NSString* _Nullable endpoint, NSString* _Nullable raw, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsOntologyTransfer(NSString* _Nullable endpoint, long gasPrice, long gasLimit, NSString* _Nullable wif, NSString* _Nullable asset, NSString* _Nullable to, double amount, NSError* _Nullable* error);

FOUNDATION_EXPORT NeoutilsSimplifiedNEP9* _Nullable NeoutilsParseNEP9URI(NSString* _Nullable uri, NSError* _Nullable* error);

FOUNDATION_EXPORT NSString* _Nonnull NeoutilsPublicKeyToNEOAddress(NSData* _Nullable publicKeyBytes);

/**
 * Recover the secret from shared secrets.
 */
FOUNDATION_EXPORT NSString* _Nonnull NeoutilsRecoverFromSharedSecret(NSData* _Nullable first, NSData* _Nullable second, NSError* _Nullable* error);

FOUNDATION_EXPORT NSData* _Nullable NeoutilsReverseBytes(NSData* _Nullable b);

/**
 * Convert script hash to NEO address
This method takes Big Endian Script hash
 */
FOUNDATION_EXPORT NSString* _Nonnull NeoutilsScriptHashToNEOAddress(NSString* _Nullable scriptHash);

FOUNDATION_EXPORT NeoutilsSeedNodeResponse* _Nullable NeoutilsSelectBestSeedNode(NSString* _Nullable commaSeparatedURLs);

FOUNDATION_EXPORT NSData* _Nullable NeoutilsSerializeTX(NSString* _Nullable jsonString);

/**
 * Sign data using ECDSA with a private key
 */
FOUNDATION_EXPORT NSData* _Nullable NeoutilsSign(NSData* _Nullable data, NSString* _Nullable key, NSError* _Nullable* error);

// skipped function UseNEP5WithNetworkFee with unsupported parameter or return types


// skipped function UseNativeAsset with unsupported parameter or return types


FOUNDATION_EXPORT id<NeoutilsSmartContractInterface> _Nullable NeoutilsUseSmartContract(NSString* _Nullable scriptHashHex);

// skipped function UseSmartContractWithNetworkFee with unsupported parameter or return types


FOUNDATION_EXPORT NSString* _Nonnull NeoutilsVMCodeToNEOAddress(NSData* _Nullable vmCode);

/**
 * Validate NEO address
 */
FOUNDATION_EXPORT BOOL NeoutilsValidateNEOAddress(NSString* _Nullable address);

/**
 * Verify signed hash using public key
 */
FOUNDATION_EXPORT BOOL NeoutilsVerify(NSData* _Nullable publicKey, NSData* _Nullable signature, NSData* _Nullable hash);

// skipped function WriteVarUint with unsupported parameter or return types


@class NeoutilsMultiSigInterface;

@class NeoutilsNEP5Interface;

@class NeoutilsNativeAssetInterface;

@class NeoutilsSmartContractInterface;

@interface NeoutilsMultiSigInterface : NSObject <goSeqRefInterface, NeoutilsMultiSigInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (NSData* _Nullable)createMultiSigRedeemScript:(NSError* _Nullable*)error;
@end

@interface NeoutilsNEP5Interface : NSObject <goSeqRefInterface, NeoutilsNEP5Interface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
// skipped method NEP5Interface.MintTokensRawTransaction with unsupported parameter or return types

// skipped method NEP5Interface.TransferNEP5RawTransaction with unsupported parameter or return types

@end

@interface NeoutilsNativeAssetInterface : NSObject <goSeqRefInterface, NeoutilsNativeAssetInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
// skipped method NativeAssetInterface.GenerateRawTx with unsupported parameter or return types

// skipped method NativeAssetInterface.SendNativeAssetRawTransaction with unsupported parameter or return types

@end

@interface NeoutilsSmartContractInterface : NSObject <goSeqRefInterface, NeoutilsSmartContractInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
// skipped method SmartContractInterface.GenerateInvokeFunctionRawTransaction with unsupported parameter or return types

// skipped method SmartContractInterface.GenerateInvokeFunctionRawTransactionWithAmountToSend with unsupported parameter or return types

@end

NS_ASSUME_NONNULL_END

#endif
