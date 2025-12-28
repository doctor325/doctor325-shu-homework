#include<iostream>

int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        int sq[50][50]={0};
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                std::cin>>sq[i][j];
            }
        }
        bool is_sym_up_and_down=true;
        bool is_sym_left_and_right=true;

        int round=n/2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < round; j++){
                if(sq[i][j] != sq[i][n-1-j]){
                    is_sym_left_and_right = false;
                    break;
                }
            }
            if(!is_sym_left_and_right) break;
        }
        for(int i = 0; i < round; i++){
            for(int j = 0; j < n; j++){
                if(sq[i][j] != sq[n-1-i][j]){
                    is_sym_up_and_down = false;
                    break;
                }
            }
            if(!is_sym_up_and_down) break;
        }
        if(is_sym_left_and_right&&is_sym_up_and_down) std::cout<<"yes"<<std::endl;
        else std::cout<<"no"<<std::endl;
    }
}