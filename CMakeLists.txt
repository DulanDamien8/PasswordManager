cmake_minimum_required(VERSION 3.28)
project(PasswordManager C)

set(CMAKE_C_STANDARD 11)


add_executable(PassPhraseSystem PassPhraseSystem.c)
add_executable(nameValidation nameValidation.c)
add_executable(PasswordValidation PasswordValidation.c)
add_executable(main main.c)

