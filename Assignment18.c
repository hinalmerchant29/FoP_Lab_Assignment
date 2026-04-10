#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], rev[100];
    int i, len, flag = 0;

    printf("Enter a string: ");
    scanf("%s", str1);


    len = strlen(str1);
    printf("Length of string = %d\n", len);

    
    for(i = 0; i < len; i++) {
        rev[i] = str1[len - i - 1];
    }
    rev[len] = '\0';
    printf("Reversed string = %s\n", rev);


    printf("Enter another string for comparison: ");
    scanf("%s", str2);

    if(strcmp(str1, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

  
    if(strcmp(str1, rev) == 0)
        printf("String is a palindrome\n");
    else
        printf("String is not a palindrome\n");

    if(strstr(str1, str2) != NULL)
        printf("Second string is a substring of first string\n");
    else
        printf("Second string is not a substring of first string\n");

    return 0;
}
