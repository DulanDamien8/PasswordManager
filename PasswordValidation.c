#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 66

void clean_buffer_for_password(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void passwordValidation(char *password) {
    while(1){
        if(strlen(password) < 8) {
            printf("The password should have at least 8 characters.\n");
        } else if (strlen(password) > 64){
            printf("Password length is too long, only a maximum of 64 characters are allowed.\n");
        } else {
            int is_uppercase = 0;
            int is_lowercase = 0;
            int is_some_digit = 0;
            int has_symbols = 0;
            int has_space = 0;

            for (int x = 0; x < strlen(password); x++) {
                if (isupper(password[x])) {
                    is_uppercase = 1;
                } else if (islower(password[x])) {
                    is_lowercase = 1;
                } else if (isdigit(password[x])) {
                    is_some_digit = 1;
                } else if (ispunct(password[x])) {
                    has_symbols = 1;
                } else if (isspace(password[x])) {
                    has_space = 1;
                }
            }
            if (has_space) {
                printf("The password should not contain spaces.\n");
            } else if (is_uppercase && is_lowercase && is_some_digit && has_symbols) {

                char recheck_password[MAX_PASSWORD_LENGTH];

                printf("Please retype the password to confirm.\n");
                if(fgets(recheck_password, MAX_PASSWORD_LENGTH, stdin) == NULL){
                    printf("Error reading input");
                }

                recheck_password[strcspn(recheck_password, "\n")] = 0;
                if (strlen(recheck_password) == MAX_PASSWORD_LENGTH - 1 && recheck_password[MAX_PASSWORD_LENGTH - 2] != '\n') {
                    clean_buffer_for_password();
                }

                while(strcmp(password, recheck_password) != 0){
                    printf("Passwords do not match:\n");
                    if (fgets(recheck_password, MAX_PASSWORD_LENGTH, stdin) == NULL) {
                        printf("Error Reading Input");
                    }

                    recheck_password[strcspn(recheck_password, "\n")] = 0;
                    if (strlen(recheck_password) == MAX_PASSWORD_LENGTH - 1 && recheck_password[MAX_PASSWORD_LENGTH - 2] != '\n') {
                        clean_buffer_for_password();
                    }
                }
                break;
            } else {
                if (!is_uppercase) {
                    printf("The password requires at least one upper case character.\n");
                }
                if (!is_lowercase) {
                    printf("The password requires at least one lower case character.\n");
                }
                if (!is_some_digit) {
                    printf("The password requires at least one digit.\n");
                }
                if (!has_symbols) {
                    printf("The password requires at least one symbol.\n");
                }
            }
        }
        printf("Please try again:\n");
        if (fgets(password, MAX_PASSWORD_LENGTH, stdin) == NULL) {
            printf("Error Reading Input");
        }
        password[strcspn(password, "\n")] = 0;
        if (strlen(password) == MAX_PASSWORD_LENGTH - 1 && password[MAX_PASSWORD_LENGTH - 2] != '\n') {
            clean_buffer_for_password();
        }
    }
}

struct structure{
    char password[MAX_PASSWORD_LENGTH];
}s2;