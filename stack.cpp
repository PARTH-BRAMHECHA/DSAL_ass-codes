#include<iostream>
#include"Stack.h"
using namespace std;
template<class T>
//defination of function push() into the stack class i.e add a node at head in linked list
void Stack<T>:: push(T g){
     node<T>* temp= new node<T>;
     temp->val= g;
     temp->next=head;
     head=temp;
     //cout<<"Element pushed :"<<g<<endl;   
}

//defination of function pop() from the stack class i.e remove node at head in linked list
template<class T>
void Stack<T>:: pop(){
    if(head==NULL)         //check if the stack is empty
        cout<<"Stack is empty";
    else{      
        node<T>* temp=head;
        //cout<<"Poped : "<<temp->val<<endl;
        head= temp->next;
        temp->next=NULL;
        delete temp;
    }
}

//defination of function top() from the stack class i.e look at the head node
template<class T>
T Stack<T>:: top(){

        //cout<<"Element at top: "<<head->val<<endl;
        return head->val;
}


//defination of function empty() from the stack class i.e check if the head is NULL
template<class T>
bool Stack<T>:: isempty(){
    if(head==NULL){
       return 1;
    }
    else{
       return 0;
    }
}

