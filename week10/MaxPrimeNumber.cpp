#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// int GetMaxNum(vector<int> &n)
// {
//     int result = 0;
//     int length = n.size();
//     for (int i = length - 1; i >= 0; i--)
//     {
//         result = result * 10 + n[i];
//     }
//     return result;
// }

// int GetMinNum(vector<int> &n)
// {
//     // sort(n.begin(),n.end());
//     int result = 0;
//     int length = n.size();
//     for (int i = 0; i < length; i++)
//     {
//         result = result * 10 + n[i];
//     }
//     return result;
// }

bool IsPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else if (n % 2 == 0)
    {
        return false;
    }
    else
    {
        int sqrt_n = sqrt(n);
        for (int i = 3; i <= sqrt_n; i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// bool IsTrue(vector<int> &v, int n)
// {
//     vector<int> temp;
//     do
//     {
//         int temp_word = n % 10;
//         temp.push_back(temp_word);
//         n /= 10;
//     } while (n > 0);
//     sort(temp.begin(), temp.end());
//     if (temp == v)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void GetResult(int min, int max, vector<int> &v)
// {
//     vector<int> temp;
//     temp.clear();
//     bool is_prime = true;
//     bool is_true = true;
//     for (int i = max; i >= min; i--)
//     {
//         is_prime = IsPrime(i);
//         is_true = IsTrue(v, i);
//         if (is_prime && is_true)
//         {
//             temp.push_back(i);
//             cout << i << endl;
//             break;
//         }
//     }
//     if (temp.empty())
//     {
//         cout << "None!" << endl;
//     }
// }

void GetResult(vector<int> &digits){
    
    do {
        int number = 0;
        for(int i = 0; i < digits.size(); i++){
            number = number * 10 + digits[i];
        }
        
        if(IsPrime(number)){
            cout << number << endl;
            return;
        }
    } while(prev_permutation(digits.begin(), digits.end()));//排序可以指定头尾
    
    cout << "None!" << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end(),greater<int>());

    // int max_number = GetMaxNum(num);
    // int min_number = GetMinNum(num);
    // cout<<min_number;
    GetResult(num);
    return 0;
}