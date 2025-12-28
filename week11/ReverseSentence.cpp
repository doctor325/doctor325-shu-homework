#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string sentence;
    getline(std::cin, sentence);
    std::vector<std::string> reversed;
    std::vector<char> number;
    // number.clear();
    // reversed.clear();
    std::string word;

    for (size_t i = 0; i < sentence.size(); i++)
    {
        char ch=sentence[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
            word += ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 32;
            word += ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            number.push_back(ch);
        }
        else if (ch == ' ')
        {
            if (!number.empty())
            {
                std::reverse(number.begin(), number.end());
                std::string temp(number.begin(), number.end());
                reversed.push_back(temp);
                number.clear();
                // word.clear();
            }
            else if (!word.empty())
            {
                reversed.push_back(word);
                word.clear();
            }
        }
    }
    if (!number.empty()) {
        std::reverse(number.begin(), number.end());
        std::string numStr(number.begin(), number.end());
        reversed.push_back(numStr);
    }
    if (!word.empty()) {
        reversed.push_back(word);
    }

    std::reverse(reversed.begin(), reversed.end());
    for (size_t i=0; i < reversed.size(); i++)
    {
        std::cout << reversed[i];
        if(i!=reversed.size()-1){
            std::cout<<" ";
        }
    }
    return 0;
}