#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int days = 0;
    int count = n;
    int appleday = 0;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    if (n >= 1 && n <= 1000000000)
    {
        while (count > 0)
        {
            days++;

            // 检查编号为n的苹果是否在今天被拿走
            for (int i = 0; i < count; i += 3)
            {
                if (arr[i] == n)
                {
                    appleday = days;
                    break;
                }
            }

            // 重新排列剩余苹果
            int new_count = 0;
            for (int i = 0; i < count; i++)
            {
                if (i % 3 != 0)
                { // 不是今天拿走的苹果
                    arr[new_count++] = arr[i];
                }
            }
            count = new_count;
        }

        printf("%d %d\n", days, appleday);
    }
    else
    {
        printf("输入错误");
        return 1;
    }

    return 0;
}