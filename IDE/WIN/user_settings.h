#ifndef _WIN_USER_SETTINGS_H_
#define _WIN_USER_SETTINGS_H_

/* Verify this is Windows */
#ifndef _WIN32
#error This user_settings.h header is only designed for Windows
#endif

/* Configurations */
#if defined(HAVE_FIPS)
    /* FIPS */
    #define OPENSSL_EXTRA
    #define HAVE_THREAD_LS
    #define WOLFSSL_KEY_GEN
    #define HAVE_AESGCM
    #define HAVE_HASHDRBG
    #define WOLFSSL_SHA384
    #define WOLFSSL_SHA512
    #define NO_PSK
    #define NO_RC4
    #define NO_DSA
    #define NO_MD4

    #define GCM_NONCE_MID_SZ 12
#else
    /* Enables blinding mode, to prevent timing attacks */
    #define WC_RSA_BLINDING
    #define NO_MULTIBYTE_PRINT

    #if defined(WOLFSSL_LIB)
        /* The lib */
        #define OPENSSL_EXTRA
        #define WOLFSSL_RIPEMD
        //#define NO_PSK
        #define HAVE_EXTENDED_MASTER
        #define WOLFSSL_SNIFFER
        #define HAVE_SECURE_RENEGOTIATION

        #define HAVE_AESGCM
        #define HAVE_AESCCM
        #define WC_NO_HARDEN
        #define WOLFSSL_AES_128
        #define WOLFSSL_SHA384
        #define WOLFSSL_SHA512

        #define HAVE_SUPPORTED_CURVES
        #define HAVE_TLS_EXTENSIONS

        #define HAVE_ECC
        #define ECC_SHAMIR
        #define ECC_TIMING_RESISTANT

        #define SESSION_CERTS
        #define KEEP_PEER_CERT
        #define  WOLFSSL_STATIC_PSK

        #define WOLFSSL_ALWAYS_VERIFY_CB
        #define WOLFSSL_SEP
        #define WOLFSSL_CERT_EXT
        #define WOLFSSL_CERT_GEN
        #define OPENSSL_ALL

        // custom ciphers
        #define BUILD_TLS_RSA_WITH_AES_256_CBC_SHA256 // for PG&E F5
        #define BUILD_TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 // for L+G GSIS
        #define BUILD_TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384 // for L+G GSIS
        #define BUILD_TLS_ECDHE_ECDSA_WITH_AES_128_CCM_8 // SEP2 main cipher

// 

        /* Optional Performance Speedups */
        #if 0
            /* AESNI on x64 */
            #ifdef _WIN64
                #define HAVE_INTEL_RDSEED
                #define WOLFSSL_AESNI
            #endif

            /* Single Precision Support for RSA/DH 1024/2048/3072 and
             * ECC P-256/P-384 */
            #define WOLFSSL_SP
            #define WOLFSSL_HAVE_SP_ECC
            #define WOLFSSL_HAVE_SP_DH
            #define WOLFSSL_HAVE_SP_RSA

            #ifdef _WIN64
                /* Old versions of MASM compiler do not recognize newer
                 * instructions. */
                #if 0
                    #define NO_AVX2_SUPPORT
                    #define NO_MOVBE_SUPPORT
                #endif
                #define WOLFSSL_SP_ASM
                #define WOLFSSL_SP_X86_64_ASM
            #endif
        #endif

    #else

    #endif
#endif /* HAVE_FIPS */

#endif /* _WIN_USER_SETTINGS_H_ */
