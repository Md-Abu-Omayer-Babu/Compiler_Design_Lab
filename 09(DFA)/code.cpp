#include <bits/stdc++.h>
using namespace std;

// Keywords
unordered_set<string> keywords = {
    "int", "char", "float", "double", "void",
    "if", "else", "for", "while", "return",
    "bool", "long", "short"
};

// Operators
unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "<", ">", "!",
    "==", "!=", "<=", ">=", "++", "--", "+=", "-=", "*=", "/="
};

// Check identifier
bool Identifier(string s){
    if(s.empty()) return false;

    int state = 0;

    for(char ch : s){
        if(state == 0){
            if(isalpha(ch) || ch == '_'){
                state = 1;
            }else{
                return false;
            }
        }else if(state == 1){
            if(isalpha(ch) || isdigit(ch) || ch == '_'){
                state = 1;
            }else{
                return false;
            }
        }
    }

    if(state == 1){
        if(keywords.find(s) != keywords.end()) return false;
        return true;
    }
    return false;
}

// Check constant (integer or float)
bool Constant(string s){
    int state = 0; // start
    int i = 0;

    if(s.empty()) return false;

    while(i < s.size()){
        char ch = s[i];

        if(state == 0){
            if(isdigit(ch)) state = 1; // q0 -> q1
            else return false;
        } else if(state == 1){
            if(isdigit(ch)) state = 1;      // q1 -> q1
            else if(ch == '.') state = 2;   // q1 -> q2
            else return false;
        } else if(state == 2){
            if(isdigit(ch)) state = 3;      // q2 -> q3
            else return false;
        } else if(state == 3){
            if(isdigit(ch)) state = 3;      // q3 -> q3
            else return false;
        }
        i++;
    }

    // Accepting states: q1 (integer), q3 (float)
    return (state == 1 || state == 3);
}

// Check operator
bool Operator(string s){
    return operators.find(s) != operators.end();
}

// DFA for Operator
/*
bool Operator(string s) {
    int state = 0;

    if(s.empty()) return false;

    char first = s[0];
    char second = (s.size() > 1) ? s[1] : '\0';

    switch(state) {
        case 0:
            if(first == '+') state = 1;
            else if(first == '-') state = 2;
            else if(first == '*') state = 3;
            else if(first == '/') state = 4;
            else if(first == '%') state = 5;
            else if(first == '=') state = 6;
            else if(first == '<') state = 7;
            else if(first == '>') state = 8;
            else if(first == '!') state = 9;
            else return false;
            break;
    }

    // Check double character operators
    if(second == '\0') {
        // Single char operators
        return (state >=1 && state <= 9);
    } else {
        switch(state) {
            case 1: return (second == '+' || second == '=');  // ++, +=
            case 2: return (second == '-' || second == '=');  // --, -=
            case 3: return (second == '=');                   // *=
            case 4: return (second == '=');                   // /=
            case 6: return (second == '=');                   // ==
            case 7: return (second == '=' );                  // <=
            case 8: return (second == '=' );                  // >=
            case 9: return (second == '=' );                  // !=
            default: return false;
        }
    }
}

*/

// DFA for token type
void DFA(string s){
    if(Identifier(s)) cout << "identifier" << endl;
    else if(Constant(s)) cout << "constant" << endl;
    else if(Operator(s)) cout << "operator" << endl;
    else cout << "undefined" << endl;
}

int main(){
    string s;
    while(true){
        cout << "Enter token: ";
        cin >> s;
        DFA(s);
    }
}