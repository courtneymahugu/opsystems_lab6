#include <stdio.h>
#include <stdlib.h>

/* Declare the function prototypes */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(void) {
    int a, b;
    char choice;

    // Prompt the user to enter the initial operands
    printf("Enter operand 'a': ");
    scanf("%d", &a);
    printf("Enter operand 'b': ");
    scanf("%d", &b);

    /* Declare a function pointer */
    int (*operation)(int, int) = NULL;

    // Loop until the user chooses to exit
    while (1) {
        printf("\nOperand 'a': %d | Operand 'b': %d\n", a, b);
        printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : multiply | 3 : divide | 4 : exit): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '0':
                operation = &add;
                printf("Adding 'a' and 'b'\n");
                printf("x = %d\n", operation(a, b));
                break;
            case '1':
                operation = &subtract;
                printf("Subtracting 'b' from 'a'\n");
                printf("x = %d\n", operation(a, b));
                break;
            case '2':
                operation = &multiply;
                printf("Multiplying 'a' and 'b'\n");
                printf("x = %d\n", operation(a, b));
                break;
            case '3':
                if (b != 0) {
                    operation = &divide;
                    printf("Dividing 'a' by 'b'\n");
                    printf("x = %d\n", operation(a, b));
                } else {
                    printf("Error: Division by zero is undefined.\n");
                }
                break;
            case '4':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/* Define the functions */
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}
