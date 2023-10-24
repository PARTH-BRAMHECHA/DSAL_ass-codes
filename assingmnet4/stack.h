//header file here we difine the stack using a linked list 
#ifndef STACK_H_
#define STACK_H_
#include<iostream>

using namespace std;

template<class T>     //creating a node
class node{
    public:
       T val;
       node* next;       
};

template<class T>      //creating stack
class Stack{
    public:
      node<T>* head;
      Stack(){
          head=NULL;    //size=0;
      }
      void push(T g);   //function to push into the stack
      void pop();       //function to pop from the stack
      T top();          //function to peek the top of the stack
      bool isempty();     //function to see if the stack is empty
      friend class node<T>;  
};
#endif
