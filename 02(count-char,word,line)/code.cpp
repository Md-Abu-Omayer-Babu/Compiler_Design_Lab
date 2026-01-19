#include<bits/stdc++.h>
using namespace std;

void Counter(ifstream &file){
    int characters = 0, words = 0, lines = 0;
    bool inWord = false;
    bool hasCharInLine = false;

    char ch;

    while(file.get(ch)){
        if(ch != ' ' && ch != '\n' && ch != '\t'){
            characters++;
            hasCharInLine = true;

            if(!inWord){
                words++;
                inWord = true;
            }
        }else{
            inWord = false;
        }

        if(ch == '\n'){
            if(hasCharInLine){
                lines++;
            }

            hasCharInLine = false;
        }
    }

    if(hasCharInLine){
        lines++;
    }

    cout << "Characters = " << characters << endl;
    cout << "Words = " << words << endl;
    cout << "Lines = " << lines << endl;
}


int main(){
    ifstream file;
    file.open("input.txt");

    if(!file){
        cout << "file not found!" << endl;
    }

    Counter(file);

    file.close();

    return 0;
}