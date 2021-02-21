// This program was created by Aleksandar Kostic on 15 Nov 2018 for a Western University assignment.
// This program determines an approximation of pi based on the precision provided by the user.

#include <stdio.h>
#include <math.h>

int main() {

    double result = 0.0f;
    double eInput;
    long long i;

    printf("Please enter a number for E: ");
    scanf("%lf", &eInput); // prompts user for E input

    double nTemp = (((4.0f / eInput) - 1.0f) / 2.0f); // rearranges the inequality provided to determine n
    double nSmallestRounded = round(nTemp) + 1.0f; // rounds n to nearest integer, adds 1 to get smallest n

    for (i = 1; i <= nSmallestRounded; i++) { // this section determines the approximation of pi

        if (i % 2) {

            result = result + (4.0f / (2.0f * i - 1.0f)); // case when we would add to the result

        }

        else {

            result = result - (4.0f / (2.0f * i - 1.0f)); // case when we would subtract from the result

        }
    }

    printf("The result is %.12lf", result); // will be as precise as number of zeroes in E
                                            // professor mentioned to print 10-17 numbers in the answer when I asked him

    return 0;
}