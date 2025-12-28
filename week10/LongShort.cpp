#include<iostream>
#include<string>
#include<vector>
using namespace std;

void LongShort(vector<string> &s){
    int length=s.size();
    string min,max;
    string temp_min=s[length-1];
    string temp_max=s[length-1];
    int shortest=s[length-1].size();
    int longest=s[length-1].size();
    for(int i=length-1; i>0; i--){
        const string &word=s[i];
        if(word.size()>longest){
            temp_max=word;
            longest=word.size();
        }
        if(word.size()<shortest){
            temp_min=word;
            shortest=word.size();
        }
    }
    min=temp_min;
    max=temp_max;
    cout<<max<<endl<<min;
}

int main(){
    string line;
    getline(cin, line);  
    
    vector<string> words;
    string current_word;
    
    for(char c : line){
        if(c == ' ' || c == '\''){
            if(!current_word.empty()){
                words.push_back(current_word);
                current_word.clear();
            }
        } else {
            current_word += c;
        }
    }
        if(!current_word.empty()){
        words.push_back(current_word);
        }
    
    LongShort(words);
    return 0;
}