#include<iostream>

struct node{
    int data;
    node* prev;
    node* next;
};

void InsertBack(node*& head, int n){
    node* temp=new node;
    temp->data=n;
    if(head==nullptr){
        temp->next=temp;
        temp->prev=temp;
        head=temp;
    }else{
    node* tail=head->prev;

    tail->next=temp;

    temp->prev=tail;
    temp->next=head;

    head->prev=temp;
    }
}

void PrintList(node* head){
    if(head==nullptr) return;
    node* temp=head;
    do{
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

void DeleteNode(node*& head,int n){
    node* temp=head;
    while(temp->data!=n){
        temp=temp->next;
    }
    if(temp==head){
        if(temp->next==head){
            head=nullptr;
        }
        else{
            head=temp->next;
        }
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}

void Yuesefu(node*& head,int n, int m, int k){
    node* p=head;
    int count=n;
    int i=1;
    while(count>0){
        if(i%2!=0){
            for(int j=1;j<m;j++){
                p=p->prev;
            }
            node* temp=p;
            p=p->prev;
            std::cout<<temp->data<<" ";
            DeleteNode(head,temp->data);
        }
        else{
            for(int j=1;j<k;j++){
                p=p->next;
            }
            node* temp=p;
            p=p->next;
            std::cout<<temp->data<<" ";
            DeleteNode(head,temp->data);
        }
        i++;
        count--;
    }
}

int main(){
    int n,m,k;
    std::cin>>n>>m>>k;
    node* head=nullptr;
    for(int i=1;i<=n;i++){
        InsertBack(head,i);
    }
    // PrintList(head);
    Yuesefu(head,n,m,k);
    return 0;
}