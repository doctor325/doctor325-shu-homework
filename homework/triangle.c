#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    if(n<0||n>50){
        return 1;
    }

    int total_length = 3*(n*2-1);
    const int part_length = n*2-1;

    for(int i=0 ;i<n;i++){
        for(int j=part_length ; j<=total_length ; j+=part_length){

            for(int x = 0; x <n-(i+1); x++){
            printf(" ");
            }

            for(int y = 0; y < 2*i+1; y++)
            printf("*");

            for(int z = 0; z < n-(i+1); z++){
            printf(" ");
            }

        }

        printf("\n");
    }
    return 0;
}
