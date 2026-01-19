#include<bits/stdc++.h>
using namespace std;

vector<string> operators = {
    "+", "-", "*", "/", "%",
    "==", "!=", ">", "<", ">=", "<=", 
    "&&", "||", "!", 
    "=", "+=", "-=", "*=", "/=", "%="
};

bool isOperator(string &s) {
    for(auto &it : operators){
        if(it == s){
            return true;
        } 
    }
    return false;
}

void lexicalAnalyzer(ifstream &file){
    string token;
    
    while(file >> token){
        if(isOperator(token)){
            cout << "'" << token << "' : Valid operator" << endl;
        } else {
            cout << "'" << token << "' : Not an operator" << endl;
        }
    }
}

int main(){
    ifstream file;

    file.open("input.txt");

    if(!file){
        cout << "file not found" << endl;
    }

    lexicalAnalyzer(file);

    return 0;
}