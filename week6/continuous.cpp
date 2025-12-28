#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned long min, max;
    cin >> min >> max;

    if (min < 1 || max > 1000000000 || min > max || max - min >= 1000)
    {
        return 0;
    }

    vector<vector<unsigned long>> arr(2, vector<unsigned long>(max - min+1));

    for (int i = 0; i <= max - min; i++)
    {
        unsigned long temp = min + i;
        // unsigned long  num = 1;
        // int j;
        int count=0;
        arr[1][i] = temp;

        // do
        // {
        //     num *= temp % 10;
        //     temp /= 10;
        // } while (temp != 0);

        unsigned long current = temp;
        while (current >= 10) {
            unsigned long product = 1;
            unsigned long num = current;
            do
            {
                product *= num % 10;
                num /= 10;
            } while (num != 0);
            current = product;
            count++;
        }
        arr[0][i] = count;
    }

    unsigned long max_persistence = arr[0][0];
    for (int i = 1; i <= max - min; i++)
    {
        if (arr[0][i] > max_persistence)
        {
            max_persistence = arr[0][i];
        }
    }

    vector<unsigned long> max_numbers;
    for (int i = 0; i <= max - min; i++)
    {
        if (arr[0][i] == max_persistence)
        {
            max_numbers.push_back(arr[1][i]);
        }
    }

    cout << max_persistence << endl;
    for (int i = 0; i < max_numbers.size(); i++)
    {
        cout << max_numbers[i];
        if (i < max_numbers.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}