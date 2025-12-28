#include<iostream>
#include<string>

int main(){
    std::string str;
    getline(std::cin,str);
    int arr[100];
    // std::int temp_arr[100];
    int j=0;
    int temp=0;
    bool in_number= false;

    for(size_t i=0; i<str.size(); i++){
        
        if(str[i]>='0'&&str[i]<='9'){
            temp=temp*10+(str[i]-'0');
            in_number=true;
          }
        else{
            if(in_number)
            arr[j++]=temp;
            temp=0;
            in_number=false;
            }
    }
    if(in_number){
        arr[j++]=temp;
    }

    std::cout<<j<<std::endl;

    for(int i=0; i<j; i++){
        std::cout<<arr[i];
        if(i<j-1){
            std::cout<<" ";
        }
    }
    return 0;
}
