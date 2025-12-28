#include <bits/stdc++.h>
using namespace std;
int all;
void up(int time, vector<vector<int>> &list, int *x, int *y){
    while(time--){
        *x -= 1;
        list[*x][*y] = all;
        all--;
    }
}
void down(int time, vector<vector<int>> &list, int *x, int *y){
    while(time--){
        *x += 1;
        list[*x][*y] = all;
        all--;
    }
}
void right(int time, vector<vector<int>> &list, int *x, int *y){
    while(time--){
        *y += 1;
        list[*x][*y] = all;
        all--;
    }
}
void left(int time, vector<vector<int>> &list, int *x, int *y){
    while(time--){
        *y -= 1;
        list[*x][*y] = all;
        all--;
    }
}
int main(){
    int n, level_limit;
    bool isOdd;
    // cin >> n;
    n=6;
    cout << setfill(' ');
    all = n * n - 1;
    vector<vector<int>> list(n,vector<int> (n, 0));
    if(n % 2){
        isOdd = true;
    }else{
        isOdd = false;
    }
    if(isOdd){
        level_limit = (n + 1) / 2;
        int x = (n - 1) / 2, y = (n - 1) / 2;
        list[x][y] = n * n;
        for(int i = 2; i <= level_limit; i++){
            up(1, list, &x, &y);
            left(2 * i - 3, list, &x, &y);
            down(2 * i - 2, list, &x, &y);
            right(2 * i - 2, list, &x, &y);
            up(2 * i - 2, list, &x, &y);
        }
    }else{
        level_limit = n / 2;
        int x = n / 2 - 1, y = n / 2 - 1;
        list[x][y] = n * n;
        down(1, list, &x, &y);
        right(1, list, &x, &y);
        up(1, list, &x, &y);
        for(int i = 2; i <= level_limit; i++){
            up(1, list, &x, &y);
            left(2 * i - 2, list, &x, &y);
            down(2 * i - 1, list, &x, &y);
            right(2 * i - 1, list, &x, &y);
            up(2 * i - 1, list, &x, &y);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(4) << list[i][j];
        }
        cout << endl;
    }
    return 0;
}