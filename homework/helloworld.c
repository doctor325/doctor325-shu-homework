#include <stdio.h>
#include <string.h> // 添加此头文件以支持 strcpy 函数

int main(){
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

    struct student{
        char name[10];
        int  age;
        int  score;

    };

    struct student arr_student[50];
    struct student *top_student;
    int student_num = 5;

    strcpy(arr_student[0].name , "张三");
    arr_student[0].age = 18;
    arr_student[0].score = 568;

    strcpy(arr_student[1].name , "李四");
    arr_student[1].age = 18;
    arr_student[1].score = 569;

    strcpy(arr_student[2].name , "wushi");
    arr_student[2].age = 18;
    arr_student[2].score = 579;

    strcpy(arr_student[3].name , "李san");
    arr_student[3].age = 18;
    arr_student[3].score = 559;

    strcpy(arr_student[4].name , "wang5");
    arr_student[4].age = 18;
    arr_student[4].score = 519;

    int max_score = 0;
    int max_index = 0;


    for(int i=0; i<student_num; i++){
        if (arr_student[i].score > max_score){
            max_score = arr_student[i].score;
            max_index = i;
        }
    }

    printf("max stuedent i=%d: name=%s, age=%d, score=%d  \n", 
                    max_index,
                    arr_student[max_index].name,
                    arr_student[max_index].age,
                    arr_student[max_index].score

    );

    


    return 0;
    
}

int max(int a, int b){
    int max=0;
    if(a>b){
        max = a;
    }else{
        max = b;
    }
    return max;
}
