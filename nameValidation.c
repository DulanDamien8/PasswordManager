#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_LENGTH 17

static void clean_buffer_for_name(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int remove_Trailing_Spaces(char *str) {
    int len = (int)strlen(str);
    int spaces_removed = 0;

    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[len - 1] = '\0';
        len--;
        spaces_removed = 1;
    }
    return spaces_removed;
}

void nameValidation(char *name){
    while(1){
        if (strlen(name) < 3 || strlen(name) > 15 || (isspace(*name)) || remove_Trailing_Spaces(name)){
            printf("Enter a name with at least 3 - 15 characters :\n");
            if(fgets(name, MAX_NUMBER_LENGTH, stdin) == NULL){
                printf("Error reading input.\n");
                clean_buffer_for_name();
            }
            name[strcspn(name, "\n")] = 0;
            if (strlen(name) == MAX_NUMBER_LENGTH - 1 && name[MAX_NUMBER_LENGTH - 2] != '\n') {
                clean_buffer_for_name();
            }
        } else {
            break;
        }
    }
}

struct var{
    char name[MAX_NUMBER_LENGTH];
}s1;