#include <iostream>
#include <string>
using namespace std;

void PrintNumber(string str)
{
    int count_uc = 0;   // 大写字母个数
    int count_lc = 0;   // 小写字母个数
    int count_else = 0; // 非字母个数

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            count_uc++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            count_lc++;
        }
        else
        {
            count_else++;
        }
    }

    // cout << "大写字母个数：" << count_uc << endl;
    // cout << "小写字母个数：" << count_lc << endl;
    // cout << "非字母个数：" << count_else << endl;

    cout << "uppercase:" << count_uc << endl;
    cout << "lowercase:" << count_lc << endl;
    cout << "else:" << count_else << endl;
}

void PrintModified(string str)
{
    string modified = str;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            modified[i] = str[i] + 32;//ascll中大写字母比小写字母小32
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            modified[i] = str[i] - 32;
        }
        else
        {
            modified[i] = str[i];//非字母的保持原样输出
        }
    }
    cout << modified << endl;
}

void PrintVocabularyNumber(string str)
{
    int count = 0;

    if (str.empty())
    {
        cout << "vocabulary number :0" << endl; //如果输入为单个空格，则输出0
        return;
    }
    for (size_t i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            count++;
        }
    }
    if (str[0] != ' ')
    {
        count++;
    }
    cout << "vocabulary number :" << count << endl;
}

int main()
{

    string str;
    // cin >> str;（遇到空格就停止）
    getline(cin, str); // 可整行读入（包含空格）

    PrintNumber(str);
    PrintModified(str);
    PrintVocabularyNumber(str);

    return 0;
}