#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (char c : exp) {
        // If operand, add to output
        if (isalnum(c))
            result += c;

        // If '(', push to stack
        else if (c == '(')
            s.push(c);

        // If ')', pop till '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        }

        // Operator
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all operators
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix: " << infixToPostfix(exp) << endl;
    return 0;
}
