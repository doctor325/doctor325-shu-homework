#include <stdio.h>

int main()
{
    int people_quantity = 0;
    int book_quantity = 0;
    scanf("%d %d", &people_quantity, &book_quantity);
    int like_array[people_quantity][book_quantity];

    for (int i = 0; i < people_quantity; i++)
    {
        for (int j = 0; j < book_quantity; j++)
        {
            scanf("%d", &like_array[i][j]);
        }
    }

    for (int s1 = 1; s1 <= book_quantity; s1++)
    {

        if (like_array[0][s1 - 1] == 1)
        {

            for (int s2 = 1; s2 <= book_quantity; s2++)
            {
                if (s2 != s1 && like_array[1][s2 - 1] == 1)
                {
                    for (int s3 = 1; s3 <= book_quantity; s3++)
                    {
                        if (s3 != s1 && s3 != s2 && like_array[2][s3 - 1] == 1)
                        {
                            printf("(%d, %d, %d)\n", s1, s2, s3);
                        }
                    }
                }
            }
        }
    }

    return 0;
}