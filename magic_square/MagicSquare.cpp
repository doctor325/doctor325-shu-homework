#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// 函数声明
void printMagicSquare(int **square, int n);
void generateOddMagicSquare(int n, int **square, bool showProcess);
void generateDoubleEvenMagicSquare(int n, int **square, bool showProcess);
void generateSingleEvenMagicSquare(int n, int **square, bool showProcess);

int main()
{
    int n;
    cout << "请输入魔方阵的阶数: ";
    cin >> n;

    // 检查输入是否有效
    if (n <= 0)
    {
        cout << "阶数必须为正整数！" << endl;
        return 1;
    }

    // 分配动态二维数组
    int **magicSquare = new int *[n];
    for (int i = 0; i < n; i++)
    {
        magicSquare[i] = new int[n];
        // 初始化为0
        for (int j = 0; j < n; j++)
        {
            magicSquare[i][j] = 0;
        }
    }

    bool showProcess = true;
    char choice;
    cout << "是否显示生成过程? (y/n): ";
    cin >> choice;
    showProcess = (choice == 'y' || choice == 'Y');

    // 根据阶数选择不同的生成算法
    if (n % 2 == 1)
    {
        cout << "生成奇阶魔方阵..." << endl;
        generateOddMagicSquare(n, magicSquare, showProcess);
    }
    else if (n % 4 == 0)
    {
        cout << "生成双偶阶魔方阵..." << endl;
        generateDoubleEvenMagicSquare(n, magicSquare, showProcess);
    }
    else
    {
        cout << "生成单偶阶魔方阵..." << endl;
        generateSingleEvenMagicSquare(n, magicSquare, showProcess);
    }

    // 打印最终结果
    cout << "\n最终魔方阵:" << endl;
    printMagicSquare(magicSquare, n);

    // 验证每行、每列、对角线之和
    int sum = n * (n * n + 1) / 2;
    cout << "每行、每列、对角线之和应为: " << sum << endl;

    // 释放内存
    for (int i = 0; i < n; i++)
    {
        delete[] magicSquare[i];
    }
    delete[] magicSquare;

    return 0;
}

// 打印魔方阵
void printMagicSquare(int **square, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", *(*(square + i) + j));
        }
        cout << endl;
    }
}

// 生成奇阶魔方阵
void generateOddMagicSquare(int n, int **square, bool showProcess)
{
    int num = 1;
    int i = 0, j = n / 2;

    if (showProcess)
    {
        cout << "初始状态:" << endl;
        printMagicSquare(square, n);
        cout << endl;
    }

    while (num <= n * n)
    {
        *(*(square + i) + j) = num;

        if (showProcess)
        {
            cout << "放置 " << num << " 在位置 (" << i << ", " << j << ")" << endl;
            printMagicSquare(square, n);
            cout << endl;
        }

        // 计算下一个位置
        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;

        // 如果下一个位置已被占用，则向下移动一行
        if (*(*(square + next_i) + next_j) != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = next_i;
            j = next_j;
        }

        num++;
    }
}

// 生成双偶阶魔方阵（4的倍数阶）
void generateDoubleEvenMagicSquare(int n, int **square, bool showProcess)
{
    int num = 1;
    // 第1步：顺序填充 1 ~ n*n
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(square + i) + j) = num++;
        }
    }

    if (showProcess)
    {
        cout << "初始状态:" << endl;
        printMagicSquare(square, n);
        cout << endl;
    }

    // 第2步：交换对角线
    // 互补数：x → (n*n + 1 - x)
    int maxVal = n * n + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3))
            {
                //   (i % 4 == j % 4)   --->    当前元素在 4*4 子块的主对角线
                //   ((i % 4 + j % 4 == 3)   --->    当前元素在 4*4 子块的副对角线
                *(*(square + i) + j) = maxVal - *(*(square + i) + j);
            }

        }
    }
}

// 生成单偶阶魔方阵（4k+2阶）- 简化版
void generateSingleEvenMagicSquare(int n, int **square, bool showProcess)
{
    int M = (n - 2) / 4;
    int half = n / 2;

    int **temp_sq = new int *[half];
    for (int i = 0; i < half; i++)
    {
        temp_sq[i] = new int[half];
        for (int j = 0; j < half; j++)
        {
            *(*(temp_sq + i) + j) = 0;
        }
    }

    generateOddMagicSquare(half, temp_sq, false);

    char mark_sq[half][half];
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            if (i < M)
                *(*(mark_sq + i) + j) = 'L';
            else if (i == M)
                *(*(mark_sq + i) + j) = (j == M ? 'U' : 'L');
            else if (i == M + 1)
                *(*(mark_sq + i) + j) = (j == M ? 'L' : 'U');
            else
                *(*(mark_sq + i) + j) = 'X';
        }
    }

    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            int base = 4 * *(*(temp_sq + i) + j) - 4;
            int r = i * 2;
            int c = j * 2;

            if (*(*(mark_sq + i) + j) == 'L')
            {
                *(*(square + r) + c) = base + 4;
                *(*(square + r) + c + 1) = base + 1;
                *(*(square + r + 1) + c) = base + 2;
                *(*(square + r + 1) + c + 1) = base + 3;
            }
            else if (*(*(mark_sq + i) + j) == 'U')
            {
                *(*(square + r) + c) = base + 1;
                *(*(square + r) + c + 1) = base + 4;
                *(*(square + r + 1) + c) = base + 2;
                *(*(square + r + 1) + c + 1) = base + 3;
            }
            else
            {
                *(*(square + r) + c) = base + 1;
                *(*(square + r) + c + 1) = base + 4;
                *(*(square + r + 1) + c) = base + 3;
                *(*(square + r + 1) + c + 1) = base + 2;
            }
        }
    }

    for (int i = 0; i < half; i++)
        delete[] temp_sq[i];
    delete[] temp_sq;
}
