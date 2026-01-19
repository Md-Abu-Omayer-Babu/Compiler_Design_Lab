#include<bits/stdc++.h>
using namespace std;

void identifierValidation(ifstream &file){
    string s = "";

    char ch;
    while(file.get(ch)){
        s += ch;
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