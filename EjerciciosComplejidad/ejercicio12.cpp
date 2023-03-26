#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int get_precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

double apply_operation(char op, double a, double b) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0.0;
    }
}

double evaluate_expression(string expression) {
    stack<double> operands;
    stack<char> operators;

    stringstream ss(expression);
    char current_char;
    while (ss >> current_char) {
        if (isdigit(current_char) || current_char == '.') {
            ss.putback(current_char);
            double value;
            ss >> value;
            operands.push(value);
        } else if (current_char == '(') {
            operators.push(current_char);
        } else if (current_char == ')') {
            while (operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                double result = apply_operation(op, a, b);
                operands.push(result);
            }
            operators.pop();
        } else if (current_char == '+' || current_char == '-' ||
                   current_char == '*' || current_char == '/') {
            while (!operators.empty() && operators.top() != '(' &&
                   get_precedence(operators.top()) >= get_precedence(current_char)) {
                char op = operators.top();
                operators.pop();
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                double result = apply_operation(op, a, b);
                operands.push(result);
            }
            operators.push(current_char);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        double b = operands.top();
        operands.pop();
        double a = operands.top();
        operands.pop();
        double result = apply_operation(op, a, b);
        operands.push(result);
    }

    return operands.top();
}

int main() {
    string expression = "3 + (8 - 7.5) * 10 / 5 - (2 + 5 * 7)";
    double result = evaluate_expression(expression);
    cout << "El resultado de la expresión " << expression << " es " << result << endl;
    return 0;
}

O(n^2)
