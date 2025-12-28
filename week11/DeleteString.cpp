#include<iostream>
#include<string>

int main(){
    std::string str;
    getline(std::cin,str);
    int pos,len;
    std::cin>>pos>>len;

    std::string modify= str.erase(pos-1,len);
    std::cout<<modify<<std::endl;
}
