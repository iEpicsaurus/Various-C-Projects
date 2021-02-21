// This program was created by Aleksandar Kostic on 01 Nov 2018 for a Western University assignment.
// This program evaluates simple arithmetic expression.

#include <stdio.h>
#include <stdlib.h>

// Input: none, read from stdin
// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or ’\n’
// ’\n’ indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.
char get_op() {

    char operator;

    scanf("%c", &operator);
    while (operator == ' ') {

        scanf("%c", &operator);

    }

    return operator;

}

// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num() {

    float value;

    scanf("%f", &value);

    return value;
}

// Input: ’sub_exp’: the value of the current sub m_expression
// to the left of ’op’ location in stdin.
// ’op’ : an operator, ’*’ or ’/’. ’op’ could also be
// ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
// "+’, ’-’, or ’\n’ should be pushed back to stdin.
// the rest of the m_expression will be read in from stdin
// Effect: the m_expression is evaluated using recursion:
// get next_num with get_num() and then get next_op with get_op()
// use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the current m_expression
float m_exp(float sub_exp, char op) {

    if (op == '-' || op == '+' || op == '\n') {

        ungetc(op, stdin); // push back op
        return sub_exp;

    }

    else {

        float f1 = get_num();
        char op1 = get_op();

        if (op == '*') {

            f1 = sub_exp * f1;

        }

        else if (op == '/') {

            f1 = sub_exp / f1;

        }

        else {

            printf("Invalid operators in expression: program terminated due to error.\n");
            printf("Valid operators are +, -, /, and * \n");
            exit(EXIT_FAILURE);

        }

        return m_exp(f1, op1);

    }

}

// Input: ’sub_exp’: the value of the sub s_expression to the left of ’op’
// location in stdin.
// ’op’ : an operator, ’+’ or ’-’. ’op’ could also be
// ’\n’ indicating the end of the s_expression
// the rest of the expression will be read in from stdin
// Effect: the whole s_expression is evaluated using recursion:
// get next_num with m_exp() and then get next_op with get_op()
// use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the s_expression
float s_exp(float sub_exp, char op) {

    char op1;
    float f1;
    float final;

    if (op == '\n' || op == '+' || op == '-') {

        if (op == '\n') {

            return sub_exp;

        }

        else {

            f1 = m_exp(1, '*'); // first case of m_exp
            op1 = get_op();

            if (op == '+') {

                final = sub_exp + f1;

            }

            else {

                final = sub_exp - f1;

            }

            return s_exp(final, op1);

        }

    }

    else {

        f1 = m_exp(sub_exp, op);
        op1 = get_op();

        return s_exp(f1, op1);

    }

}

float expressionCalculator() {

    puts("Please enter an algorithmic expression to evaluate: ");

    float result = s_exp(0, '+'); // first case of s_exp

    return result;

}

int main() {

    char flag;
    flag = 'Y';

    while (flag == 'Y') { // expressisons will continue to be evaluated until user enters 'N'

        float result = expressionCalculator();
        printf("The result of the algorithmic expression is: %f \n", result);

        printf("Would you like to continue? Y to continue; N to terminate: ");
        scanf(" %c", &flag);

    }

    printf("Program successfully terminated per user input.\n");
    exit(0);

}