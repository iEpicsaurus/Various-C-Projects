// This program was created by Aleksandar Kostic on 01 Nov 2018 for a Western University assignment.
// This program displays integers using seven-segment display.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char flag;
    flag = 'Y';
    int i;

    char stringInteger[15];
    int integer;
    const char segments[10][3][3] =
            {{{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}}, // 0 representation
             {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, // 1 representation
             {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}}, // 2 representation
             {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}}, // 3 representation
             {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}}, // 4 representation
             {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}}, // 5 representation
             {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}}, // 6 representation
             {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, // 7 representation
             {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}}, // 8 representation
             {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}}; // 9 representation

    while (flag == 'Y') { // 7-segment display will continue to be output until user enters 'N'

        printf("Please enter an integer: ");
        scanf("%d", &integer);
        sprintf(stringInteger, "%d", integer);

        // THIS SECTION PRINTS THE TOP SECTION OF THE NUMBERS PROVIDED BY THE USER.

        if (integer < 0) { // used for the printing of the negative sign only in cases when the integer is negative

            printf("   ");

        }

        for (i = 0; i < strlen(stringInteger); i++) { // used for printing the numbers

            char temp = stringInteger[i];

            if (temp == '0') {

                printf("%c%c%c", segments[0][0][0], segments[0][0][1], segments[0][0][2]);

            }

            else if (temp == '1') {

                printf("%c%c%c", segments[1][0][0], segments[1][0][1], segments[1][0][2]);

            }

            else if (temp == '2') {

                printf("%c%c%c", segments[2][0][0], segments[2][0][1], segments[2][0][2]);

            }

            else if (temp == '3') {

                printf("%c%c%c", segments[3][0][0], segments[3][0][1], segments[3][0][2]);

            }

            else if (temp == '4') {

                printf("%c%c%c", segments[4][0][0], segments[4][0][1], segments[4][0][2]);

            }

            else if (temp == '5') {

                printf("%c%c%c", segments[5][0][0], segments[5][0][1], segments[5][0][2]);

            }

            else if (temp == '6') {

                printf("%c%c%c", segments[6][0][0], segments[6][0][1], segments[6][0][2]);

            }

            else if (temp == '7') {

                printf("%c%c%c", segments[7][0][0], segments[7][0][1], segments[7][0][2]);

            }

            else if (temp == '8') {

                printf("%c%c%c", segments[8][0][0], segments[8][0][1], segments[8][0][2]);

            }

            else if (temp == '9') {

                printf("%c%c%c", segments[9][0][0], segments[9][0][1], segments[9][0][2]);

            }
        }

        printf("\n");

        // THIS SECTION PRINTS THE MIDDLE SECTION OF THE NUMBERS PROVIDED BY THE USER.

        if (integer < 0) { // used for the printing of the negative sign only in cases when the integer is negative

            printf(" _ ");

        }

        for (i = 0; i < strlen(stringInteger); i++) { // used for printing the numbers

            char temp = stringInteger[i];

            if (temp == '0') {

                printf("%c%c%c", segments[0][1][0], segments[0][1][1], segments[0][1][2]);

            }

            else if (temp == '1') {

                printf("%c%c%c", segments[1][1][0], segments[1][1][1], segments[1][1][2]);

            }

            else if (temp == '2') {

                printf("%c%c%c", segments[2][1][0], segments[2][1][1], segments[2][1][2]);

            }

            else if (temp == '3') {

                printf("%c%c%c", segments[3][1][0], segments[3][1][1], segments[3][1][2]);

            }

            else if (temp == '4') {

                printf("%c%c%c", segments[4][1][0], segments[4][1][1], segments[4][1][2]);

            }

            else if (temp == '5') {

                printf("%c%c%c", segments[5][1][0], segments[5][1][1], segments[5][1][2]);

            }

            else if (temp == '6') {

                printf("%c%c%c", segments[6][1][0], segments[6][1][1], segments[6][1][2]);

            }

            else if (temp == '7') {

                printf("%c%c%c", segments[7][1][0], segments[7][1][1], segments[7][1][2]);

            }

            else if (temp == '8') {

                printf("%c%c%c", segments[8][1][0], segments[8][1][1], segments[8][1][2]);

            }

            else if (temp == '9') {

                printf("%c%c%c", segments[9][1][0], segments[9][1][1], segments[9][1][2]);

            }
        }

        printf("\n");

        // THIS SECTION PRINTS THE BOTTOM SECTION OF THE NUMBERS PROVIDED BY THE USER.

        if (integer < 0) { // used for the printing of the negative sign only in cases when the integer is negative

            printf("   ");

        }

        for (i = 0; i < strlen(stringInteger); i++) { // used for printing the numbers

            char temp = stringInteger[i];


            if (temp == '0') {

                printf("%c%c%c", segments[0][2][0], segments[0][2][1], segments[0][2][2]);

            }

            else if (temp == '1') {

                printf("%c%c%c", segments[1][2][0], segments[1][2][1], segments[1][2][2]);

            }

            else if (temp == '2') {

                printf("%c%c%c", segments[2][2][0], segments[2][2][1], segments[2][2][2]);

            }

            else if (temp == '3') {

                printf("%c%c%c", segments[3][2][0], segments[3][2][1], segments[3][2][2]);

            }

            else if (temp == '4') {

                printf("%c%c%c", segments[4][2][0], segments[4][2][1], segments[4][2][2]);

            }

            else if (temp == '5') {

                printf("%c%c%c", segments[5][2][0], segments[5][2][1], segments[5][2][2]);

            }

            else if (temp == '6') {

                printf("%c%c%c", segments[6][2][0], segments[6][2][1], segments[6][2][2]);

            }

            else if (temp == '7') {

                printf("%c%c%c", segments[7][2][0], segments[7][2][1], segments[7][2][2]);

            }

            else if (temp == '8') {

                printf("%c%c%c", segments[8][2][0], segments[8][2][1], segments[8][2][2]);

            }

            else if (temp == '9') {

                printf("%c%c%c", segments[9][2][0], segments[9][2][1], segments[9][2][2]);

            }
        }

        printf("\n\n");

        printf("Would you like to continue? Type Y to continue with another input; N to terminate: ");
        scanf(" %c", &flag);

    }

    printf("Program successfully terminated per user input.\n");
    exit(0);

}
