#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<vector<int>> &v, int n)
{

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        temp = v[i][i];
        v[i][i] = v[i][n - 1 - i];
        v[i][n - 1 - i] = temp;
    }

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
    {
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> square;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int m = 0;
            cin >> m;
            temp.push_back(m);
        }
        square.push_back(temp);
    }
    Reverse(square, n);
    return 0;
}