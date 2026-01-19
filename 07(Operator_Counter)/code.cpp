#include<bits/stdc++.h>
using namespace std;


void Operator_Counter(ifstream &file){
    string s = "";
    char ch;
    while(file.get(ch)){
        s += ch;
    }

    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(i + 1 < s.size()){
            string op = "";
            op += s[i];
            op += s[i + 1];

            if(op == "++" || op == "--" || op == "==" || op == "!=" ||
               op == "<=" || op == ">=" || op == "&&" || op == "||"){
                count++;
                i++;
                continue;
            }
        }

        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || 
           s[i] == '/' || s[i] == '%' || s[i] == '=' || 
           s[i] == '>' || s[i] == '<' || s[i] == '!' || 
           s[i] == '&' || s[i] == '|'){
            count++;
        }
    }
    
    cout << "Number of operators: " << count << endl;
}

int main(){
    ifstream file;

    file.open("input.txt");

    if(!file){
        cout << "file not found" << endl;
    }

    Operator_Counter(file);

    return 0;
}