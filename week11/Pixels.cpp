#include<iostream>

int main(){
    int rows,columns;
    std::cin>>rows>>columns;
    int pixel[100][100];
    int original[100][100];


    for(int i=0 ; i<rows; i++){
        for(int j=0 ; j<columns; j++){
            std::cin>>pixel[i][j];
            original[i][j]=pixel[i][j];
        }
    }

    for(int i=1 ; i<rows-1; i++){
        for(int j=1 ; j<columns-1; j++){
            pixel[i][j]=(original[i][j] + original[i-1][j] + original[i][j-1] + 
                          original[i+1][j] + original[i][j+1] + 2) / 5;
        }
    }

    for(int i=0 ; i<rows; i++){
        for(int j=0 ; j<columns; j++){
            std::cout<<pixel[i][j];
            if(j<columns-1){
                std::cout<<" ";
            }
        }
    }
    return 0;
}