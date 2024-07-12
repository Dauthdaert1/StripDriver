# Install script for directory: A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/StripExample")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "A:/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/block_cipher.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/build_info.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-2.x.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_legacy_crypto.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_legacy_from_psa.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_psa_from_legacy.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_psa_superset_legacy.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_ssl.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_x509.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_psa.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/constant_time.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/lms.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/mbedtls_config.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs7.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/private_access.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/psa_util.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha3.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/build_info.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_auto_enabled.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_config_key_pair_types.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_config_synonyms.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_composites.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_key_derivation.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_primitives.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_compat.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_config.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_common.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_key_derivation.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_extra.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_legacy.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_platform.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_se_driver.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_sizes.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_struct.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_types.h"
    "A:/esp/v5.2.2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_values.h"
    )
endif()

