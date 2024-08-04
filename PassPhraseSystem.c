#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 50

static void clean_buffer_for_pass_phrase(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void phrase_Validation(char *buffer, int buffer_size) {
    while(1) {
        buffer[strcspn(buffer, "\n")] = 0;

        if(strlen(buffer) == buffer_size -1 && buffer[buffer_size - 2] != '\n'){
            clean_buffer_for_pass_phrase();
        }

        if (strlen(buffer) < 3){
            printf("The word must have at least 3 characters.\n");
        } else if (strlen(buffer) > 8) {
            printf("The word can have a maximum of 8 characters.\n");
        } else {
            int word_is_uppercase = 1;
            int word_has_lowercase = 0;
            int word_has_digits = 0;
            int word_has_punctuation = 0;
            int has_space = 0;

            for (int x = 0; x < strlen(buffer); x++) {
                if (!isupper(buffer[x])) {
                    word_is_uppercase = 0;
                }
                if (islower(buffer[x])) {
                    word_has_lowercase = 1;
                }
                if (isdigit(buffer[x])) {
                    word_has_digits = 1;
                }
                if (ispunct(buffer[x])) {
                    word_has_punctuation = 1;
                }
                if (isspace(buffer[x])) {
                    has_space = 1;
                }
            }
            if (has_space) {
                printf("Space detected. Spaces are not allowed on phrases.\n");
                printf("Please type a word in uppercase characters: \n");
                if (fgets(buffer, MAX_BUFFER_SIZE, stdin) == NULL) {
                    printf("Error Reading Input");
                    break;
                }
                continue;
            }

            if (word_is_uppercase && !word_has_digits && !word_has_punctuation && !word_has_lowercase) {
                char recheck_Buffer[MAX_BUFFER_SIZE];

                printf("Re-type the word to verify :");
                if (fgets(recheck_Buffer, sizeof(recheck_Buffer), stdin) == NULL) {
                    printf("Error\n");
                    continue;
                }
                recheck_Buffer[strcspn(recheck_Buffer, "\n")] = 0;

                if (strlen(recheck_Buffer) == sizeof(recheck_Buffer) - 1 &&
                    recheck_Buffer[sizeof(recheck_Buffer) - 2] != '\n') {
                    clean_buffer_for_pass_phrase();
                }

                while (strcmp(buffer, recheck_Buffer) != 0) {
                    printf("Phrases Don't match, Please try again :\n");
                    if (fgets(recheck_Buffer, sizeof(recheck_Buffer), stdin) == NULL) {
                        printf("Error\n");
                        continue;
                    }
                    recheck_Buffer[strcspn(recheck_Buffer, "\n")] = 0;

                    if (strlen(recheck_Buffer) == sizeof(recheck_Buffer) - 1 &&
                        recheck_Buffer[sizeof(recheck_Buffer) - 2] != '\n') {
                        clean_buffer_for_pass_phrase();
                    }
                }
                printf("The phrases match and entire word is uppercase.\n");
                break;

            } else {
                if (word_has_lowercase) {
                    printf("Lowercase characters detected..\n");
                }
                if (word_has_digits) {
                    printf("Digits detected..\n");
                }
                if (word_has_punctuation) {
                    printf("Punctuation characters detected..\n");
                }
            }
        }
        printf("Please use ONLY uppercase characters:\n");
        if (fgets(buffer, buffer_size, stdin) == NULL) {
            printf("Input error.\n");
            break;
        }
    }
}