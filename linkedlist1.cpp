#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void insertathead(node* &head, int d){
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertattail(node* &tail, int d){
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
    
}

void insertatposition(node* &tail, node* &head,int position, int d){
    node* temp = head;
    if(position == 1){ 
        insertathead(head,d);
        return;
    }

    if(temp -> next == NULL){
        insertattail(tail,d);
        return;
    }


    
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    node* nodeToInsert = new node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    node* node1 = new node(7);

    
    node* head = node1;
    node* tail = node1;

    insertathead(head, 1);
    print (head);
    insertattail(tail,4);
    insertatposition(tail,head,4,8);
    print(head);

 return 0;
}