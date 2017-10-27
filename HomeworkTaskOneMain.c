#include <stdio.h>

typedef enum {
    ZERO_INPUT = 1,
    NEGATIVE_INPUT = 2
} ErrorCode;

void printError(ErrorCode errorCode);
int fibonacci(int number);


int main ()
{
    int validChoice = 0;
    int inputNumber = 0;

    while(validChoice == 0) {

        printf("Input number:");
        scanf("%d", &inputNumber);

        if(inputNumber == 0) {
            printError(ZERO_INPUT);
        } else if (inputNumber < 0) {
            printError(NEGATIVE_INPUT);
        } else {
            validChoice = 1;
        }
    }

    printf("%d - %d", inputNumber, fibonacci(inputNumber));

    return 0;
}

void printError(ErrorCode errorCode) {

    switch (errorCode) {
        case ZERO_INPUT:
            printf("Error: Input larger number than 0\n");
            break;
        case NEGATIVE_INPUT:
            printf("Error: Input positive number\n");
            break;
        default:
            printf("Error: Unknown error\n");
            break;
    }
}

int fibonacci(int number) {
    if (number <= 1) {
        return number;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}