#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "请输入一行字符: ";
    getline(cin, input);
    // 第一问 ： 
    
    int bigLetter = 0;  
    int smallLetter = 0; 
    
    for (int position = 0; position < input.size(); position++) {
        char currentChar = input[position]; 
        
        if (currentChar >= 'A' && currentChar <= 'Z') {
            bigLetter++;
        }
        else if (currentChar >= 'a' && currentChar <= 'z') {
            smallLetter++;
        }
    }
    
    cout << "\n=== 统计结果 ===" << endl;
    cout << "大写字母: " << bigLetter << " 个" << endl;
    cout << "小写字母: " << smallLetter << " 个" << endl;
    
    //第二问： 
	  
    string newString = ""; 
    
    for (int position = 0; position < input.size(); position++) {
        char currentChar = input[position];
        
        if (currentChar >= 'A' && currentChar <= 'Z') {
        	//大小写相差32 
            newString += char(currentChar + 32);
        }
        else if (currentChar >= 'a' && currentChar <= 'z') {
        	
            newString += char(currentChar - 32);
        }
        else {
            // 不是字母
            newString += currentChar;
        }
    }
    
    cout << "\n=== 大小写转换 ===" << endl;
    cout << "原字符串: " << input << endl;
    cout << "新字符串: " << newString << endl;
    
    // 第三问： 
    int wordCount = 0;
    bool nowInWord = false;  //目前不在单词里 
    
    for (int position = 0; position < input.size(); position++) {
        char currentChar = input[position];
        
       
        bool isLetter = false; //目前在单词里 
        if ((currentChar >= 'A' && currentChar <= 'Z') ||
            (currentChar >= 'a' && currentChar <= 'z')) {
            isLetter = true;
        }
        
        if (isLetter) {  
            if (!nowInWord) {  // 若之前不在单词中，说明是新单词开始
                wordCount++;
                nowInWord = true;
            }
        }else {  // 当前字符不是字母
            nowInWord = false;
        }

    }
    
    cout << "\n=== 单词统计 ===" << endl;
    cout << "单词数量: " << wordCount << " 个" << endl;
    
    return 0;
}
