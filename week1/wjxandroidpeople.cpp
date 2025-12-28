#include <iostream>
#include <string>
using namespace std;

char input[101];
int i, j, temp, coun[26], check[26];

void output()
{
    if (check[temp - 65] != 1 && coun[temp - 65] >= 2)
    {
        cout << (char(temp)) << " ";
        for (j = coun[temp - 64 - 1]; j > 0; j--)
        {
            cout << "*";
        }
        check[temp - 65] = 1;
        cout << endl;
    }
}
int main()
{
    // 读取字符串
    cin.getline(input, 101, '\n');
    // 计数
    for (i = 1; i <= 26; i++)
    {
        for (j = 0; j < 101; j++)
        {
            if (input[j] == (i + 64) || input[j] == i + 96)
            {
                coun[i - 1]++;
            }
        }
    }
    // 预备输出
    for (i = 0; i < 101; i++)
    {
        temp = static_cast<int>(input[i]);
        // 小写情况
        if (temp - 96 > 0 && temp - 96 < 27)
        {
            temp -= 32;
            output();
            // 大写情况
        }
        else if (temp - 64 > 0 && temp - 64 < 27)
        {
            output();
        }
    }
    return 0;
}