// This program was created by Aleksandar Kostic on 15 Oct 2018 for a Western University assignment
// This program calculates the answer for the exponentiation of the base and exponent provided

#include <stdio.h>

// This function is used to calculate the answer for exponentiation of the base and exponent provided as input.

float exp_calculator(float base, int exponent) {

    if (exponent == 0) {

        return 1.0f;

    }

    if (exponent == 1) {

        return base;

    }

    if (exponent % 2 == 0) { // for even exponents, using the provided general form hint

        return (exp_calculator(base, exponent/2) * exp_calculator(base, exponent/2));

    }

    else { // for odd exponents, using the provided general form hint

        return (exp_calculator(base, ((exponent - 1) / 2)) * exp_calculator(base, ((exponent - 1) / 2)) * base);

    }

}

// This function is used to obtain proper base and exponent input from the user.

float calculatorInput() {

    float base;
    int exponent;

    printf("Enter a POSITIVE base: ");
    scanf(" %f", &base);

    if (base < 0) {

        printf("Invalid input: a POSITIVE base is needed \n");
        return calculatorInput(); // invalid input - returns to the start of this function

    }

    else {

        printf("Enter an integer for the exponent: ");
        scanf(" %d", &exponent);

        if (exponent < 0) {

            exponent = exponent * -1; // if exponent is negative, the absolute value of it is used
            base = 1/base; // in the case of negative exponents, the base is changed to reflect the negative exponent

        }

    return exp_calculator(base, exponent);

    }
}

// Start of program.

int main() {

    float finalValue;

    finalValue = calculatorInput();
    printf("The calculated answer is: %f", finalValue);

}