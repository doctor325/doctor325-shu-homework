#include<stdio.h>

int main(){
    char ch;
    int count=0;

    while(1){
        scanf("%c", &ch);
        if(ch=='@'){
            break;
        }
        if(ch != ' '&&ch !='\n' ){
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
            count++;}
        }
    }
    printf("%d\n", count);
    return 0;
}