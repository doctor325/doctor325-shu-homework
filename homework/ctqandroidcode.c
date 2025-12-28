#include <stdio.h>

int Check(int standard[], int extra[]);
int Print(int result[], int groups);
int main()
{
    int groups = 0;
    scanf("%d", &groups);
    int result[10000];

    for (int i = 0; i < groups; i++)
    {
        int standard[12];
        int extra[2];

        for (int i = 0; i < 12; i++)
        {
            scanf("%d", &standard[i]);
        }
        for (int i = 0; i < 2; i++)
        {
            scanf("%d", &extra[i]);
        }

        Check(standard, extra);
        result[i] = Check(standard, extra);
    }
    Print(result, groups);
    return 0;
}

int Check(int standard[], int extra[])
{
    int result = 0;
    int count = 0;

    for (int i = 0; i < 12; i++)
    {
        if (standard[i] == extra[1])
        {
            count++;
        }
    }
    if (count < extra[0])
    {
        result = 1;
    }
    return result;
}

int Print(int result[], int groups)
{
    for (int i = 0; i < groups; i++)
    {
        if (result[i] == 1)
        {
            printf("win 颗秒！！！\n");
        }
        else
        {
            printf("lose 棒棒棒棒棒！！！\n");
        }
    }
    return 0;
}