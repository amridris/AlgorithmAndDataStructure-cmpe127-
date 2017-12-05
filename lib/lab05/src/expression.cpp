#include "../inc/expression.h"
namespace lab5 {

/****Auxillary Function prototypes ****/

    int getWeight(char ch);

    bool IsOperator(char ch);

    bool IsOperand(char ch);

    int HasHigherPrecedence(char op1, char op2);

    int eval(char op1, char op2, char op);

    /****end function prototypes****/


    expression::expression() {

    }

    expression::expression(std::string &input_expression) {

        for (int i = 0; i < input_expression.length(); i++) {

        }

    }

    void expression::convert_to_postfix(std::string &input_expression) {
        //iterate through the expression and apply the shunting yard algorithm to produce RPN ouput
        int i = 0;
        char ch = input_expression[i];
        while (i < input_expression.length()) {
        }

        void expression::parse_to_infix(std::string &input_expression) {

        }

        int expression::calculate_postfix() {
            return 0;
        }

        void expression::print_infix() {

        }

        void expression::print_postfix() {

        }

        std::istream &operator>>(std::istream &steam, expression &RHS) {
//    return <#initializer#>;
        }


//auxillary functions

        //auxillary functions

        int eval(int op1, int op2, char operation) {
            switch (operation) {
                case '*':
                    return op2 * op1;
                case '/':
                    return op2 / op1;
                case '+':
                    return op2 + op1;
                case '-':
                    return op2 - op1;
                default:
                    return 0;

            }
        }

        int getWeight(char ch) {
            switch (ch) {
                case '/':
                    return 2;
                case '*':
                    return 2;
                case '+':
                    return 1;
                case '-':
                    return 1;
                default:
                    return 0;
            }
        }

        bool IsOperator(char ch) {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                return true;
            }
            return false;
        }

        bool IsOperand(char ch) {
            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                return true;
            }
            return false;
        }

        int HasHigherPrecedence(char op1, char op2) {
            int op1Weight = getWeight(op1);
            int op2Weight = getWeight(op2);
        }
    }

}