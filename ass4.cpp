//preproccessing statement
#include<iostream>
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
    treenode* getleft(treenode*);
    treenode* getright(treenode*);
    void printroot(treenode*);
    void setLeft(treenode*,treenode*);
    void setRight(treenode*,treenode*);
};

treenode* treenode :: getleft(treenode* root){
    return root->left;
}

treenode* treenode :: getright(treenode* root){
    return root->right;
}

void treenode :: printroot(treenode* root){
    cout<<root->data<<" ";
}

void treenode :: setLeft(treenode* root, treenode* newNode){
    root->left = newNode;
}

void treenode :: setRight(treenode* root, treenode* newNode){
    root->right = newNode;
}

//class exptree:contains all members to perform on postfix 
class exptree{
    //make data members private
    private:string str;
            treenode object;
    //make functions public
    public:
        exptree(){};  //expression tree default constructor
        void input();
        treenode* CreateTree();
        void inorder_recurssive(treenode*);
        void preorder_recurssive(treenode*);
        void postorder_recurssive(treenode*);
        void inorder_nonrecurssive(treenode*);
        void preorder_nonrecurssive(treenode*);
        void postorder_nonrecurssive(treenode*);
           
};

void exptree :: input(){
    cout<<"Please enter an postfix expression"<<endl;
    getline(cin,str);    
}

//functions for inorder recurssive transversal
void exptree :: inorder_recurssive(treenode* root){
    if(root==NULL)
        return;
    inorder_recurssive(object.getleft(root));
    object.printroot(root);
    inorder_recurssive(object.getright(root));    
}

//functions for preorder recurssive transversal
void exptree :: preorder_recurssive(treenode* root){
    if(root==NULL)
        return;
    object.printroot(root);
    preorder_recurssive(object.getleft(root));
    preorder_recurssive(object.getright(root));    
}

//functions for postorder recurssive transversal
void exptree :: postorder_recurssive(treenode* root){
    if(root==NULL)
        return;
    postorder_recurssive(object.getleft(root));
    postorder_recurssive(object.getright(root));
    object.printroot(root);   
}

//functions for inorder nonrecurssive tranversal
void exptree :: inorder_nonrecurssive(treenode* root){

}

//functions for preorder nonrecurssive tranversal
void exptree :: preorder_nonrecurssive(treenode* root){

}

//functions for postorder nonrecurssive tranversal
void exptree :: postorder_nonrecurssive(treenode* root){

}

//functions in which we create the postfix expreession tree
treenode* exptree :: CreateTree(){
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
            op->setLeft(op,n1);
            op->setRight(op,n2);
            st.push(op);
        }
    }
    temp=st.top();
    return temp;
}

int main(){
    exptree obj; //object of the class expression tree
    obj.input();
    treenode* t=obj.CreateTree();
    cout<<"The infix expression is:";
    obj.inorder_recurssive(t);
    cout<<endl;
    cout<<"The prefix expression is:";
    obj.preorder_recurssive(t);
    cout<<endl;
    cout<<"The postfix expression is:";
    obj.postorder_recurssive(t); 
    return 0;
}