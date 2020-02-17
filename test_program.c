/**
 * test_program.c
 * Testing program
 */
#include <stdio.h>
#include "Utils.h"
#include <stdlib.h>

int main() {

    char* result = NULL;

    // Example 1: 2.56 x 5  
    result = multiplyStrNumberByInteger(5, "2.56");
    printf("The result is: %s\n", result);
    free(result);

    // Example 2: 100.99 x 45
    result = multiplyStrNumberByInteger(45, "100.99");
    printf("The result is: %s\n", result);
    free(result);

    // Example 3: 489.87 x 23
    result = multiplyStrNumberByInteger(23, "489.87");
    printf("The result is: %s\n", result); 
    free(result); 

    return 0;
}