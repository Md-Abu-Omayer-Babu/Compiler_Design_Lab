#include <bits/stdc++.h>
using namespace std;

// -------- Keywords --------
bool isKeyword(const string &s) {
    return (s=="int" || s=="float" || s=="double" || s=="char" ||
            s=="if" || s=="else" || s=="for" || s=="while" ||
            s=="do" || s=="return" || s=="void" || s=="main");
}

// -------- Identifier --------
bool isIdentifier(const string &s) {
    if(s.empty()) return false;
    if(!isalpha(s[0]) && s[0]!='_') return false;
    for(char c : s) {
        if(!isalnum(c) && c!='_') return false;
    }
    return true;
}

// -------- Number --------
bool isNumber(const string &s) {
    if(s.empty()) return false;
    for(char c : s) if(!isdigit(c)) return false;
    return true;
}

// -------- Operator --------
bool isSingleOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' ||
            c=='=' || c=='<' || c=='>' || c=='!');
}

bool isDoubleOperator(char a, char b) {
    string op = ""; op += a; op += b;
    return (op=="==" || op=="!=" || op==">=" || op=="<=" ||
            op=="&&" || op=="||" || op=="++" || op=="--");
}

// -------- Delimiter --------
bool isDelimiter(char c) {
    return (c=='(' || c==')' || c=='{' || c=='}' ||
            c==';' || c==',' || c=='[' || c==']');
}

// -------- Lexical Analyzer --------
void lexicalAnalyzer(const string &code) {
    for(int i = 0; i < code.size(); ) {

        // -------- Ignore spaces, tabs, newlines --------
        if(isspace(code[i])) {
            i++;
            continue;
        }

        // -------- Single-line comment --------
        if(code[i]=='/' && (i+1)<code.size() && code[i+1]=='/') {
            while(i < code.size() && code[i]!='\n') i++;
            continue;
        }

        // -------- Multi-line comment --------
        if(code[i]=='/' && (i+1)<code.size() && code[i+1]=='*') {
            i += 2; // skip /*
            while(i+1 < code.size() && !(code[i]=='*' && code[i+1]=='/')) i++;
            i += 2; // skip */
            continue;
        }

        // -------- Double-character operator --------
        if(i+1 < code.size() && isDoubleOperator(code[i], code[i+1])) {
            cout << "Operator: " << code[i] << code[i+1] << endl;
            i += 2;
            continue;
        }

        // -------- Single-character operator --------
        if(isSingleOperator(code[i])) {
            cout << "Operator: " << code[i] << endl;
            i++;
            continue;
        }

        // -------- Delimiter --------
        if(isDelimiter(code[i])) {
            cout << "Delimiter: " << code[i] << endl;
            i++;
            continue;
        }

        // -------- Identifier, Keyword, or Number --------
        string token = "";
        while(i < code.size() &&
              !isspace(code[i]) &&
              !isSingleOperator(code[i]) &&
              !isDelimiter(code[i]) &&
              !(i+1<code.size() && isDoubleOperator(code[i], code[i+1]))) {
            token += code[i];
            i++;
        }

        if(isKeyword(token))
            cout << "Keyword: " << token << endl;
        else if(isNumber(token))
            cout << "Number: " << token << endl;
        else if(isIdentifier(token))
            cout << "Identifier: " << token << endl;
        else
            cout << "Unknown token: " << token << endl;
    }
}

// -------- Main --------
int main() {
    ifstream file("input.txt");
    if(!file) {
        cout << "File not found!" << endl;
        return 0;
    }

    // read whole file into string
    string code = "", line;
    while(getline(file, line)) {
        code += line + '\n';
    }
    file.close();

    lexicalAnalyzer(code);
    return 0;
}
