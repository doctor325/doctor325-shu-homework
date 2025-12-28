#include <stdio.h>
int main()
{
    char str_arr[100];
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && i < 99)
    {
        str_arr[i] = ch;
        i++;
    }
    str_arr[i] = '\0';

    char processed[100];
    int processed_count = 0;

    for (int j = 0; j < i; j++)
    {
        char current_upper = str_arr[j];
        if (current_upper >= 'a' && current_upper <= 'z')
        {
            current_upper = current_upper - 32;
        }

        if (current_upper < 'A' || current_upper > 'Z')
        {
            continue;
        }

        int already_processed = 0;
        for (int p = 0; p < processed_count; p++)
        {
            if (processed[p] == current_upper)
            {
                already_processed = 1;
                break;
            }
        }

        if (already_processed)
        {
            continue;
        }

        int count = 0;
        for (int k = 0; k < i; k++)
        {
            char compare_char = str_arr[k];
            if (compare_char >= 'a' && compare_char <= 'z')
            {
                compare_char = compare_char - 32;
            }

            if (current_upper == compare_char)
            {
                count++;
            }
        }

        if (count > 1)
        {
            processed[processed_count] = current_upper;
            processed_count++;
            printf("%c ", current_upper);
            for (int l = 0; l < count; l++)
            {
                printf("*");
            }

            printf("\n");
        }
    }
    return 0;
}

//用strchr函数更简洁，更适合这一题