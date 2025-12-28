#include<iostream>
#include<string>
#include<vector>

typedef struct{
    std::string id;
    std::string name;
    int total_score;
} Student;

int main(){
    int n;
    std::cin>>n;
    std::vector<Student> arr;
    for(int i=0; i<n;i++){
        Student student;
        student.total_score=0;
        std::cin>>student.id>>student.name;
        for(int j=0;j<3;j++){
            int temp;
            std::cin>>temp;
            student.total_score+=temp;
        }
        arr.push_back(student);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].total_score>arr[j+1].total_score){
                Student temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    std::cout<<arr[n-1].name<<" "<<arr[n-1].id<<" "<<arr[n-1].total_score<<std::endl;
    return 0;
}