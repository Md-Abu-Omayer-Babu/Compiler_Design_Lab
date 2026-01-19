#include <bits/stdc++.h>
using namespace std;

int main() {
    // List of valid operators in C++
    unordered_set<string> operators = {
        "+", "-", "*", "/", "%", "=", "<", ">", "!", "&", "|", "^", "~",
        "++", "--", "+=", "-=", "*=", "/=", "%=", "==", "!=", "<=", ">=", "&&", "||", "&=", "|=", "^=", "<<", ">>"
    };

    string s;
    while(true) {
        cout << "Enter operator: ";
        cin >> s;

        if(operators.find(s) != operators.end()) {
            cout << "Valid operator\n";
        } else {
            cout << "Invalid operator\n";
        }
    }

    return 0;
}
