#include <stdio.h>

#include "nameValidation.c"
#include "PasswordValidation.c"
#include "PassPhraseSystem.c"

int main(void){
    // Call for Name Validation
    printf("Enter the website name :\n");
    fgets(s1.name, sizeof(s1.name), stdin);

    s1.name[strcspn(s1.name, "\n")] = 0;
    if (strlen(s1.name) == MAX_NUMBER_LENGTH - 1 && s1.name[MAX_NUMBER_LENGTH - 2] != '\n') {
        clean_buffer_for_name();
    }
    nameValidation(s1.name);

    // Call for Password Validation
    printf("Enter the Password, with at least one upper case, one lower case, one digit and one symbol :\n");
    fgets(s2.password, sizeof(s2.password), stdin);

    s2.password[strcspn(s2.password, "\n")] = 0;
    if (strlen(s2.password) == MAX_PASSWORD_LENGTH - 1 && s2.password[MAX_PASSWORD_LENGTH - 2] != '\n') {
        clean_buffer_for_password();
    }
    passwordValidation(s2.password);


    // Call for Pass Phrase Mechanism
    char buffer1[MAX_BUFFER_SIZE];
    char buffer2[MAX_BUFFER_SIZE];
    char buffer3[MAX_BUFFER_SIZE];
    char buffer4[MAX_BUFFER_SIZE];

    char *words[] = {"first", "second", "third", "fourth"};
    char *buffers[] = {buffer1, buffer2, buffer3, buffer4};

    printf("***CREATE A PASS PHRASE FOR YOUR LOGIN***\n");

    for(int i = 0; i < 4; i++){
        printf("Enter the %s word of your choice between 3 - 8 characters AND must be uppercase:\n", words[i]);
        if (fgets(buffers[i],MAX_BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading input.\n");
            return 1;
        }
        phrase_Validation(buffers[i], MAX_BUFFER_SIZE);
    }

    printf("*****Your Information*****\n\n");
    printf("Site name           : %s\n", s1.name);
    printf("Password            : %s\n", s2.password);
    printf("Your pass phrase is : %s %s %s %s\n", buffer1,buffer2,buffer3,buffer4);

    return 0;
}