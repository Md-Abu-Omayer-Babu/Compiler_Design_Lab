#include<bits/stdc++.h>
using namespace std;

vector<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "inline", "int", "long", "register", "return", "short", "signed", 
    "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while", "floor"
};

void identifierValidation(ifstream &file){
    string s = "";

    char ch;
    while(file.get(ch)){
        s += ch;
    }
    
    for(auto &it : keywords){
        if(it == s){
            cout << "Invalid Indetifier because of using keywords" << endl;
            return;
        }
    }

    bool isValid = true;

    if(!isalpha(s[0]) && s[0] != '_'){
        isValid = false;
    }

    for(int i = 1; i < s.size(); i++){
        if(!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '_'){ 
            isValid = false;
            break; 
        }
    }

    if(isValid){
        cout << "Valid Identifier" << endl;
    }else{
        cout << "Invalid Indentifier" << endl;
    }
}

int main(){
    ifstream file;

    file.open("input.txt");

    if(!file){
        cout << "file not found" << endl;
    }

    identifierValidation(file);

    return 0;
}