
#include <stdio.h>
#include <math.h>

// Function declarations
double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double power(double a, double b);
double squareRoot(double a);
int modulo(int a, int b);

// Input buffer cleaner
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Addition
double addition(double a, double b) {
    return a + b;
}

// Subtraction
double subtraction(double a, double b) {
    return a - b;
}

// Multiplication
double multiplication(double a, double b) {
    return a * b;
}

// Division
double division(double a, double b) {
    return a / b;
}

// Power
double power(double a, double b) {
    return pow(a, b);
}

// Square root
double squareRoot(double a) {
    return sqrt(a);
}

// Modulo
int modulo(int a, int b) {
    return a % b;
}

// Main function
int main(void) {
    int choice;

    while (1) {
        printf("Welcome to Basic Calculator\n\n");

        printf("[1] Addition (a + b)\n");
        printf("[2] Subtraction (a - b)\n");
        printf("[3] Multiplication (a * b)\n");
        printf("[4] Division (a / b)\n");
        printf("[5] Power (a ^ b)\n");
        printf("[6] Square Root (sqrt a)\n");
        printf("[7] Modulo (a %% b)\n");
        printf("[8] Exit\n\n");

        printf("Your choice: ");

        // Menu input validation
        if (scanf("%d", &choice) != 1) {
            printf("ERROR Invalid choice.\n");
            clearInputBuffer();
            continue;
        }

        if (choice < 1 || choice > 8) {
            printf("ERROR Invalid choice.\n");
            continue;
        }

        // Exit
        if (choice == 8) {
            printf("GOOD BYE\n");
            break;
        }

        // Square Root
        if (choice == 6) {
            double a;

            if (scanf("%lf", &a) != 1) {
                printf("ERROR Invalid operand.\n");
                clearInputBuffer();
                continue;
            }

            if (a < 0) {
                printf("ERROR Square root of a negative number.\n");
                continue;
            }

            printf("Result: %.2f\n", squareRoot(a));
        }

        // Modulo
        else if (choice == 7) {
            int a, b;

            if (scanf("%d", &a) != 1) {
                printf("ERROR Invalid operand.\n");
                clearInputBuffer();
                continue;
            }

            if (scanf("%d", &b) != 1) {
                printf("ERROR Invalid operand.\n");
                clearInputBuffer();
                continue;
            }

            if (b == 0) {
                printf("ERROR Modulo by zero.\n");
                continue;
            }

            printf("Result: %d\n", modulo(a, b));
        }

        // Operations 1-5
        else {
            double a, b;

            if (scanf("%lf", &a) != 1) {
                printf("ERROR Invalid operand.\n");
                clearInputBuffer();
                continue;
            }

            if (scanf("%lf", &b) != 1) {
                printf("ERROR Invalid operand.\n");
                clearInputBuffer();
                continue;
            }

            // Division by zero
            if (choice == 4 && b == 0.0) {
                printf("ERROR Division by zero.\n");
                continue;
            }

            // Power error checks
            if (choice == 5) {

                if (a == 0.0 && b == 0.0) {
                    printf("ERROR 0 raised to the power 0.\n");
                    continue;
                }

                if (a == 0.0 && b < 0.0) {
                    printf("ERROR 0 raised to a negative power.\n");
                    continue;
                }
            }

            double res = 0.0;

            switch (choice) {
                case 1:
                    res = addition(a, b);
                    break;

                case 2:
                    res = subtraction(a, b);
                    break;

                case 3:
                    res = multiplication(a, b);
                    break;

                case 4:
                    res = division(a, b);
                    break;

                case 5:
                    res = power(a, b);
                    break;
            }

            printf("Result: %.2f\n", res);
        }

        printf("\n");
    }

    return 0;
}

