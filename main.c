#include <stdio.h>
#include <math.h>

// Function definitions
float add(int a, int b) { return a + b; }
float subtract(int a, int b) { return a - b; }
float multiply(int a, int b) { return a * b; }
float divide(int a, int b) {
    if(b != 0) return (float)a / b;
    else {
        printf("Error: division by zero!\n");
        return 0;
    }
}
int mod(int a, int b) {
    if(b != 0) return a % b;
    else {
        printf("Error: modulo by zero!\n");
        return 0;
    }
}
float squareRoot(int a) {
    if(a >= 0) return sqrt(a);
    else {
        printf("Error: square root of negative number!\n");
        return 0;
    }
}
float power(int a, int b) { return pow(a, b); }

int main() {
    int num1, num2, choice;
    float result = 0;
    int usePrevious = 0; // flag for using previous result
    FILE *history;       // file pointer for history

    // open file in append mode (adds new lines without deleting old ones)
    history = fopen("history.txt", "a");
    if(history == NULL) {
        printf("Error: could not open history file!\n");
        return 1;
    }

    do {
        printf("\n--- Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulo\n");
        printf("6. Square Root\n");
        printf("7. Power\n");
        printf("8. Show previous result\n");
        printf("9. Use previous result in next operation\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1) {
            printf("Error: please enter a number!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                if(usePrevious) {
                    printf("Enter second number: ");
                    scanf("%d", &num2);
                    result = add((int)result, num2);
                    fprintf(history, "Addition: %.2f + %d = %.2f\n", result - num2, num2, result);
                    usePrevious = 0;
                } else {
                    printf("Enter first number: ");
                    scanf("%d", &num1);
                    printf("Enter second number: ");
                    scanf("%d", &num2);
                    result = add(num1, num2);
                    fprintf(history, "Addition: %d + %d = %.2f\n", num1, num2, result);
                }
                printf("Result: %.2f\n", result);
                break;
            case 2:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = subtract(num1, num2);
                fprintf(history, "Subtraction: %d - %d = %.2f\n", num1, num2, result);
                printf("Result: %.2f\n", result);
                break;
            case 3:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = multiply(num1, num2);
                fprintf(history, "Multiplication: %d * %d = %.2f\n", num1, num2, result);
                printf("Result: %.2f\n", result);
                break;
            case 4:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = divide(num1, num2);
                fprintf(history, "Division: %d / %d = %.2f\n", num1, num2, result);
                printf("Result: %.2f\n", result);
                break;
            case 5:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                result = mod(num1, num2);
                fprintf(history, "Modulo: %d %% %d = %.0f\n", num1, num2, result);
                printf("Result: %.0f\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%d", &num1);
                result = squareRoot(num1);
                fprintf(history, "Square Root: sqrt(%d) = %.2f\n", num1, result);
                printf("Result: %.2f\n", result);
                break;
            case 7:
                printf("Enter base number: ");
                scanf("%d", &num1);
                printf("Enter exponent: ");
                scanf("%d", &num2);
                result = power(num1, num2);
                fprintf(history, "Power: %d ^ %d = %.2f\n", num1, num2, result);
                printf("Result: %.2f\n", result);
                break;
            case 8:
                printf("Previous result: %.2f\n", result);
                break;
            case 9:
                printf("Previous result will be used in the next operation.\n");
                usePrevious = 1;
                break;
            case 10:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 10);

    fclose(history); // close file before exiting
    return 0;
}

