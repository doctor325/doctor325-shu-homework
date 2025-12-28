#include <stdio.h>
#include <string.h> // 添加此头文件以支持 strcpy 函数

int main()
{
    /*
        int arr[10]={100,200,300,400,500,600,700,800,900,1000};

        printf("sizeof(int):%d  \n", sizeof(int));

        printf("arr address:%p  \n", arr);
        printf("arr[0] address:%p  \n", &arr[0]);
        printf("arr+0 address:%p  \n", arr+0);

        printf("arr[1] address:%p  \n", &arr[1]);
        printf("arr+1 address:%p  \n\n\n\n", arr+1);

        printf("arr[2] address:%p  \n", &arr[2]);
        printf("arr+2 address:%p  \n", arr+2);
        printf("arr[2] value:%d  \n", arr[2]);
        printf("arr+2 value:%d  \n", *(arr+2));

        printf("hello world");


        void *p;
        printf("p address:%p  \n", p);
        printf("--------------------------------\n");
    */

    char name[] = "hello world";
    char *name2 = "hello name2 world";

    printf("name =%s, size=%d, strlen=%d \n\n\n",
           name,
           sizeof(name),
           strlen(name));
    // name[4]='\0';//
    name[4] = 0;

    printf("name =%s, size=%d, strlen=%d, \n\n\n",
           name,
           sizeof(name),
           strlen(name));

    printf("name2 =%s, sizeof=%d, strlen=%d,  \n",
           name2,
           sizeof(name2),
           strlen(name2));

    return 0;
}
