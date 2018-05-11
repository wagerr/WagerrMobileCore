/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_breadwallet_core_BRCorePaymentProtocolACK */

#ifndef _Included_com_breadwallet_core_BRCorePaymentProtocolACK
#define _Included_com_breadwallet_core_BRCorePaymentProtocolACK
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    getCustomerMemo
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_getCustomerMemo
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    getMerchantData
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_getMerchantData
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    getTransactions
 * Signature: ()[Lcom/digiwagewallet/core/BRCoreTransaction;
 */
JNIEXPORT jobjectArray JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_getTransactions
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    getRefundTo
 * Signature: ()[Lcom/digiwagewallet/core/BRCoreTransactionOutput;
 */
JNIEXPORT jobjectArray JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_getRefundTo
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    getMerchantMemo
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_getMerchantMemo
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    createPaymentProtocolACK
 * Signature: ([B)J
 */
JNIEXPORT jlong JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_createPaymentProtocolACK
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    serialize
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_serialize
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    disposeNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_disposeNative
  (JNIEnv *, jobject);

/*
 * Class:     com_breadwallet_core_BRCorePaymentProtocolACK
 * Method:    initializeNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_breadwallet_core_BRCorePaymentProtocolACK_initializeNative
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
