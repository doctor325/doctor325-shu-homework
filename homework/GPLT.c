#include<stdio.h>

struct Number{
    int G_number;
    int P_number;
    int L_number;
    int T_number;
};

int CountG(char orignal[]);
int CountP(char orignal[]);
int CountL(char orignal[]);
int CountT(char orignal[]);
void Print(struct Number num);


int main(){
    char orignal[10000];
    int i=0;
    while(i<10000){
        scanf("%c",&orignal[i]);
        i++;
    }
    orignal[i]='\0';

    struct Number num;
    num.G_number = CountG(orignal);
    num.P_number = CountP(orignal);
    num.L_number = CountL(orignal);
    num.T_number = CountT(orignal);

    Print(num);
    
    return 0;
}

int CountG(char orignal[]){
    int count=0;
    for(int i=0;orignal[i]!='\0';i++){
        if(orignal[i]=='g'||orignal[i]=='G'){
            count++;
        }
    }
    return count;
}

int CountP(char orignal[]){
    int count=0;
    for(int i=0;orignal[i]!='\0';i++){
        if(orignal[i]=='p'||orignal[i]=='P'){
            count++;
        }
    }
    return count;
}

int CountL(char orignal[]){
    int count=0;
    for(int i=0;orignal[i]!='\0';i++){
        if(orignal[i]=='l'||orignal[i]=='L'){
            count++;
        }
    }
    return count;
}

int CountT(char orignal[]){
    int count=0;
    for(int i=0;orignal[i]!='\0';i++){
        if(orignal[i]=='t'||orignal[i]=='T'){
            count++;
        }
    }
    return count;
}


void Print(struct Number num){
    while(num.G_number > 0 || num.P_number > 0 || num.L_number > 0 || num.T_number > 0) {
        // 输出G（如果还有剩余）
        if(num.G_number > 0) {
            printf("G");
            num.G_number--;
        }
        
        // 输出P（如果还有剩余）
        if(num.P_number > 0) {
            printf("P");
            num.P_number--;
        }
        
        // 输出L（如果还有剩余）
        if(num.L_number > 0) {
            printf("L");
            num.L_number--;
        }
        
        // 输出T（如果还有剩余）
        if(num.T_number > 0) {
            printf("T");
            num.T_number--;
        }
    }
}

    