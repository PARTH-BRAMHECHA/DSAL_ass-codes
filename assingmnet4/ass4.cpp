//preproccessing statement
#include<iostream>
#include<bits/stdc++.h>
#include"Stack.h"
#include"Stack.cpp"
#include<conio.h>
#include<string>
using namespace std;

//class treenode
class treenode{
    //make data members private
    private:
    char data;
    treenode* left;
    treenode* right;
    //make functions public
    public:
    //constructor method
    treenode(char chr){
        data=chr;
        left=NULL;
        right=NULL;
    }
    treenode(){};//default constructor
    treenode* getleft();
    treenode* getright();
    char getValue();
    char printroot(treenode*);
    void answer(treenode*);
    void setLeft(treenode*);
    void setRight(treenode*);
};
char treenode :: getValue() {
        return data;
}
treenode* treenode :: getleft(){
    return left;
}

treenode* treenode :: getright(){
    return right;
}

char treenode :: printroot(treenode* root){
    return(root->data);
}

void treenode :: setLeft( treenode* newNode){
    left = newNode;
}

void treenode :: setRight( treenode* newNode){
    right = newNode;
}

void treenode :: answer(treenode* root){
    cout<<root->data<<" ";
}

//class Exptree:contains all members to perform on postfix 
class Exptree{
    //make data members private
    private:string str;
            treenode object;
    //make functions public
    public:
        Exptree(){};  //expression tree default constructor
        void input();
        treenode* CreateTree();
        void inorder_recurssive(treenode*);
        void preorder_recurssive(treenode*);
        void postorder_recurssive(treenode*);
        void inorder_itta(treenode*);
        void preorder_itta(treenode*);
        void postorder_itta(treenode*);
           
};

void Exptree :: input(){
    cout<<"Please enter an postfix expression"<<endl;
    getline(cin,str);    
}

//functions for inorder recurssive transversal
void Exptree :: inorder_recurssive(treenode* root){
    if(root==NULL)
        return;
    inorder_recurssive(root->getleft());
    object.answer(root);
    inorder_recurssive(root->getright());    
}

//functions for preorder recurssive transversal
void Exptree :: preorder_recurssive(treenode* root){
    if(root==NULL)
        return;
    object.answer(root);
    preorder_recurssive(root->getleft());
    preorder_recurssive(root->getright());    
}

//functions for postorder recurssive transversal
void Exptree :: postorder_recurssive(treenode* root){
    if(root==NULL)
        return;
    postorder_recurssive(root->getleft());
    postorder_recurssive(root->getright());
    object.answer(root);   
}


//functions for inorder nonrecurssive tranversal
void Exptree :: inorder_itta(treenode* root){
    Stack<treenode*> stack;
    treenode* current = root;

    while (!stack.isempty() || current) {
        if (current) {
            stack.push(current);
            current = current->getleft();
        } else {
            current = stack.top();
            stack.pop();
            cout << current->getValue() << ' ';
            current = current->getright();
        }
    }    
}


//functions for preorder nonrecurssive tranversal
void Exptree :: preorder_itta(treenode* root){
    Stack<treenode*> stack;
    stack.push(root);

    while (!stack.isempty()) {
        treenode* current = stack.top();
        stack.pop();
        if (current) {
            std::cout << current->getValue() << ' ';
            stack.push(current->getright());
            stack.push(current->getleft());
        }
    }
}

//functions for postorder nonrecurssive tranversal
//template <class T>
void Exptree :: postorder_itta(treenode* root){
    if (!root) return;
    Stack<treenode*> stack1, stack2;
    stack1.push(root);

    while (!stack1.isempty()) {
        treenode* current = stack1.top();
        stack1.pop();
        stack2.push(current);

        if (current->getleft()) {
            stack1.push(current->getleft());
        }
        if (current->getright()) {
            stack1.push(current->getright());
        }
    }

    while (!stack2.isempty()) {
        cout << stack2.top()->getValue() << ' ';
        stack2.pop();
    }
}

//functions in which we create the postfix expreession tree
treenode* Exptree :: CreateTree(){
    treenode* temp;
    Stack < treenode* > st;
    for(int i=0;i<str.size();i++){
        if(isalpha(str[i])){    //if alphabet:operand
            treenode* New=new treenode(str[i]);
            st.push(New);
        }
        //try eception handling
        else{
            treenode* op=new treenode(str[i]); //if operator           
            treenode* n2=st.top();//poping out the operand-2
            st.pop();
            treenode* n1=st.top();//poping out the operand-1
            st.pop();
            op->setLeft(n1);
            op->setRight(n2);
            st.push(op);
        }
    }
    temp=st.top();
    return temp;
}

int main(){
    Exptree obj; //object of the class expression tree
    obj.input();
    treenode* t=obj.CreateTree();
    vector <treenode*> ans;
    cout<<"The infix expression is:";
    obj.inorder_recurssive(t);
    cout<<endl;
    cout<<"The prefix expression is:";
    obj.preorder_recurssive(t);
    cout<<endl;
    cout<<"The postfix expression is:";
    obj.postorder_recurssive(t); 
    cout<<endl;
    cout<<"The infix expression is:";
    obj.inorder_itta(t);
    cout<<endl;
    cout<<"The prefix expression is:";
    obj.preorder_itta(t);
    cout<<endl;
    cout<<"The postfix expression is:";
    obj.postorder_itta(t);
    return 0;
}