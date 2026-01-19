#include<bits/stdc++.h>
using namespace std;

bool pattern_a(string &s){
    if(s == "a"){
        return true;
    }
    return false;
}

bool patter_aStarbPlus(string &s){
    int i = 0;
    int n = s.size();

    while(i < n && s[i] == 'a'){
        i++;
    }

    if(i == n){
        if(s[i] != 'b'){
            return false;
        }
    }

    while(i < n && s[i] == 'b'){
        i++;
    }
    
    return i == n;
}

bool pattern_abb(string &s){
    if(s == "abb"){
        return true;
    }

    return false;
}

void patterRecognization(ifstream &file){
    string s;

    char ch;
    while(file.get(ch)){
        s += ch;
    }

    if(pattern_a(s)){
        cout << "a pattern matched" << endl;
    }
    
    if(patter_aStarbPlus(s)){
        cout << "a start b plus pattern matched" << endl;
    }
    
    if(pattern_abb(s)){
        cout << "abb pattern matched" << endl;
    }

    if(!pattern_a(s) && !patter_aStarbPlus(s) && !pattern_abb(s)){
        cout << "no given pattern is found" << endl;
    }
}

int main(){
    ifstream file;

    file.open("input.txt");

    if(!file){
        cout << "file not found" << endl;
    }

    patterRecognization(file);

    return 0;
}