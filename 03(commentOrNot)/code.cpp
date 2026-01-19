#include<bits/stdc++.h>
using namespace std;

void CommentFinder(ifstream &file){
    string line = "";
    char ch;

    while(file.get(ch)){
        line += ch;
    }

    bool isSingleLineComment = false;
    bool isMultiLineComment = false;

    for(int i = 0; i < line.size(); i++){
        if(i + 1 < line.size()){
            if(line[i] == '/' && line[i + 1] == '/'){
                isSingleLineComment = true;
                break;
            }
        }
    }

    for(int i = 0; i < line.size(); i++){
        if(i + 1 < line.size()){
            if(line[i] == '/' && line[i + 1] == '*'){
                for(int j = i + 2; j + 1 < line.size(); j++){
                    if(line[j] == '*' && line[j + 1] == '/'){
                        isMultiLineComment = true;
                        break;
                    }
                }
                if(isMultiLineComment) break;
            }
        }
    }

    if(!isSingleLineComment && !isMultiLineComment){
            cout << "No comment is detected!" << endl;
    }else{
        if(isSingleLineComment){
            cout << "Single-line comment is detected" << endl;
        }
        if(isMultiLineComment){
            cout << "Multiline comment is detected" << endl;
        }
    }

}

int main(){
    ifstream file;
    file.open("input.txt");

    if(!file){
        cout << "file not found!" << endl;
    }

    CommentFinder(file);

    file.close();

    return 0;
}