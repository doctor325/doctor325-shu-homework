#include <iostream>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <vector>

int main()
{
    std::vector<std::vector<int>> arr(2,std::vector<int>(10));
    for (int i = 1; i <= 10; i++)
    {
        std::deque<int> temp;
        for (int j = 0; j < 6; j++)
        {
            int score = 0;
            std::cin >> score;
            temp.push_back(score);
        }
        sort(temp.begin(), temp.end());
        temp.pop_back();
        temp.pop_front();
        int result = 0;
        for (int j = 0; j < 4; j++)
        {
            result += temp[j];
        }
        arr[1][i-1]=i;
        arr[0][i-1]=result;
    }

    std::vector<std::pair<int,int>> p;
    for(int i=0;i<arr[0].size(); i++){
        p.push_back({arr[0][i],arr[1][i]});
    }
    std::sort(p.begin(),p.end());

    for (int i = 9; i >= 0; i--)
    {
        std::cout << "No."<< std::left << std::setw(2) << p[i].second << ": ";
        std::cout << std::fixed << std::setprecision(2) <<  static_cast<double>(p[i].first)/4.0 << std::endl;
    }
    return 0;
}