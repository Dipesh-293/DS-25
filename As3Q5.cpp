#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) {
            s.push(c - '0');  // push numbers
        } 
        else {
            if (s.size() < 2) {
                cout << "Error: Invalid postfix expression!" << endl;
                return -1;
            }

            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return -1;
                    }
                    s.push(val1 / val2); 
                    break;
                default:
                    cout << "Error: Unknown operator " << c << endl;
                    return -1;
            }
        }
    }

    if (s.size() != 1) {
        cout << "Error: Invalid postfix expression!" << endl;
        return -1;
    }

    return s.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    int result = evaluatePostfix(exp);
    if (result != -1)
        cout << "Result: " << result << endl;

    return 0;
}
