#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string arr[3];
    
    // 读入三个字符串
    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    
    // 对字符串数组进行排序
    sort(arr, arr + 3);
    
    // 输出排序后的结果
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}