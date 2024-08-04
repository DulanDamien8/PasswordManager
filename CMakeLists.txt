cmake_minimum_required(VERSION 3.28)
project(PasswordManager C)

set(CMAKE_C_STANDARD 11)

#Add OpenSSL
#ind_package(OpenSSL REQUIRED)
#include_directories(${OPENSSL_INCLUDE_DIR})


add_executable(PassPhraseSystem PassPhraseSystem.c)
add_executable(nameValidation nameValidation.c)
add_executable(PasswordValidation PasswordValidation.c)
add_executable(main main.c)

add_executable(TestCode TestCode.c)
add_executable(testSystem testSystem.c)

# Link OpenSSL libraries
#target_link_libraries(TestCode ${OPENSSL_LIBRARIES})
#target_link_libraries(testSystem ${OPENSSL_LIBRARIES})

