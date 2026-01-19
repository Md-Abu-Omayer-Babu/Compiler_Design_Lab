#include<bits/stdc++.h>
using namespace std;

unordered_set<string>keywords = {"int", "char", "float", "double", "void", "if", "else", "for", "while", "return", "bool", "long", "short"};

void NFA(string s){
    if(s.size() == 0){
        cout << "Rejected" << endl;
        return;
    }

    int state = 0;

    for(char ch : s){
        if(state == 0){
            if(isalpha(ch) || ch == '_'){
                state = 1;
            }else{
                cout << "Rejected" << endl;
                return;
            }
        }else if(state == 1){
            if(isdigit(ch) || isalpha(ch) || ch == '_'){
                state = 1; 
            }else{
                cout << "Rejected" << endl;
                return;
            }
        }
    }

    if(state == 1){
        if(keywords.find(s) != keywords.end()){
            cout << "Rejected" << endl;
            return;
        }else{
            cout << "Accepted" << endl;
        }
    }else{
        cout << "Rejected" << endl;
    }
    
}

int main(){
    while(true){
        string s;
        cin >> s;
        
        NFA(s);
    }
}