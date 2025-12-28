#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 6 || n < 1)
    {
        return 0;
    }

    vector<vector<int>> group(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> group[i][j];
        }
    }

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int current = group[i][j];
            bool is_row_max = true;
            for (int k = 0; k < n; k++)
            {
                if (current < group[i][k])
                {
                    is_row_max = false;
                    break;
                }
            }
            if (is_row_max)
            {
                bool is_line_min = true;
                for (int k = 0; k < n; k++)
                {
                    if (current > group[k][j])
                    {
                        is_line_min = false;
                        break;
                    }
                }
                if (is_line_min)
                {
                    found = true;
                    cout << "(" << i  << "," << j << ")" << endl;
                }
            }
        }
    }
    if (!found)
    {
        cout << "NONE" << endl;
    }

    return 0;
}