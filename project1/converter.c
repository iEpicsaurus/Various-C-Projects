// This program was created by Aleksandar Kostic on 15 Oct 2018 for a Western University assignment.
// This program performs simple conversions (e.g. conversion of miles to kilometers and kilometers to miles).

#include <stdio.h>
#include <stdlib.h>

// Converts kilometers to miles and miles to kilometers.

#define SCALE_FACTOR_KM_M 1.609344f

float kilometersAndMiles() {

    char conversion;
    float inputValue;

    printf("Type K to convert from kilometers to miles or M to convert from miles to kilometers (case insensitive): ");
    scanf(" %c", &conversion);

    if (conversion == 'K') { // the two if statements check for the correct input; else, the else statement is triggered

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return (inputValue / SCALE_FACTOR_KM_M);

    }

    else if (conversion == 'M') {

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return (inputValue * SCALE_FACTOR_KM_M);

    }

    else {

        printf("Invalid input: please enter either M or K (case sensitive) \n");
        return kilometersAndMiles();  // for incorrect input, returns to the beginning of this function

    }
}

// Converts meters to feet and feet to meters.

#define SCALE_FACTOR_M_FT 3.28084f

float feetAndMeters() {

    char conversion;
    float inputValue;

    printf("Type M to convert from meters to feet or F to convert from feet to meters: ");
    scanf(" %c", &conversion);

    if (conversion == 'M') { // the two if statements check for the correct input; else, the else statement is triggered

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return (inputValue * SCALE_FACTOR_M_FT);

    }

    else if (conversion == 'F') {

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return (inputValue / SCALE_FACTOR_M_FT);

    }

    else {

        printf("Invalid input: please enter either M or F (case sensitive) \n");
        return feetAndMeters();  // for incorrect input, returns to the beginning of this function

    }
}

// Converts centimetres to inches or inches to centimetres.

#define SCALE_FACTOR_CM_IN 2.54f

float centimetresAndInches() {

    char conversion;
    float inputValue;

    printf("Type C to convert from centimetres to inches or I to convert from inches to centimetres: ");
    scanf(" %c", &conversion);

    if (conversion == 'C') { // the two if statements check for the correct input; else, the else statement is triggered

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return (inputValue / SCALE_FACTOR_CM_IN);

    }

    else if (conversion == 'I') {

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return (inputValue * SCALE_FACTOR_CM_IN);

    }

    else {

        printf("Invalid input: please enter either C or I (case sensitive) \n");
        return centimetresAndInches();  // for incorrect input, returns to the beginning of this function

    }
}

// Converts Fahrenheit to Celsius or Celsius to Fahrenheit.

#define FREEZING_POINT 32.0f
#define SCALE_FACTOR_C_F (9.0f / 5.0f)

float fahrenheitAndCelsius() {

    char conversion;
    float inputValue;

    printf("Type C to convert from Celsius to Fahrenheit or F to convert from Fahrenheit to Celsius: ");
    scanf(" %c", &conversion);

    if (conversion == 'C') { // the two if statements check for the correct input; else, the else statement is triggered

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return ((inputValue * SCALE_FACTOR_C_F) + FREEZING_POINT);

    }

    else if (conversion == 'F') {

        printf("Input the value you would like to convert: ");
        scanf("%f", &inputValue);

        return ((inputValue - FREEZING_POINT) / SCALE_FACTOR_C_F);

    }

    else {

        printf("Invalid input: please enter either C or F (case sensitive) \n");
        return fahrenheitAndCelsius();  // for incorrect input, returns to the beginning of this function

    }
}

// Converts 4 different metrics into their counterparts.

void conversion() {

    char number;
    float convertedValue;

    printf("What would you like to do? Type ONE number from 1 to 5 to make your selection: ");
    scanf(" %c", &number);


    if (number == '1') { // the if statements check for correct input; else, the else statement is triggered

        convertedValue = kilometersAndMiles(); // function for kilometers and miles conversion is called
        printf("The converted value is: %f \n", convertedValue);

    }

    else if (number == '2') {

        convertedValue = feetAndMeters(); // function for feet and meters conversion is called
        printf("The converted value is: %f \n", convertedValue);

    }

    else if (number == '3') {

        convertedValue = centimetresAndInches(); // function for centimetres and inches conversion is called
        printf("The converted value is: %f \n", convertedValue);

    }

    else if (number == '4') {

        convertedValue = fahrenheitAndCelsius(); // function for Fahrenheit and Celsius conversion is called
        printf("The converted value is: %f \n", convertedValue);

    }

    else if (number == '5') { // termination character - this will terminate the program

        printf("Program terminated.");
        exit(0);

    }

    else {

        printf("Invalid input: please enter ONE number from 1 to 5 to indicate your selection \n");

    }

    conversion(); // the program repeats after providing conversions or invalid input is given; termination only
                  // when the character 5 is provided as input.
}

// Start of program.

int main() {

    conversion();
    return 0;

}