#include <stdio.h>

int main()
{
    int a = 0, p = 0, f = 0;
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n < 0)
        {
            break;
        }
        if (90 <= n && n <= 100)
        {
            a = a + 1;
        }
        else if (60 <= n && n <= 89)
        {
            p = p + 1;
        }
        else if (0 <= n && n <= 59)
        {
            f = f + 1;
        }
    }

    printf("A等级%d人\n", a);
    printf("P等级%d人\n", p);
    printf("F等级%d人\n", f);

    return 0;
}