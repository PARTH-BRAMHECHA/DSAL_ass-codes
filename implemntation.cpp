#include<iostream>
#include"Stack.h"
#include"Stack.cpp"
#include<conio.h>
using namespace std;
class expression{
    public:
    string intopost(string s);//function that returns the postfix expression of infix expression
    string intopre(string l);    //function that returns the prefix expression of infix expression
    int prec(char c);            //function that returns the precedence of the operators
    string reverse(string m);   //function which reverses the string
    int evalpostfix(string s);  //function that returns the integer evaluation of postfix expression
    int evalprefix(string s);   //function that returns the integer evaluation of prefix expression
};

string expression:: reverse(string m){
    string rev;
    int a=m.length();
    for(int i=a-1; i>=0; i--){//loop to reverse the string
        if(m[i]=='('){        //opening brace changes to closing brace and vice-versa
            rev=rev+')';
        }
        else if(m[i]==')'){
            rev=rev+'(';
        }
        else{
            rev=rev+m[i];
        }
       
    }
    return rev;
}

int expression::prec(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*'|| c=='/'){
        return 2;
    }
    if(c=='+'|| c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string expression::intopost(string s){
    Stack<char> st;                    //make a stack of operators
    string res;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&& s[i]<='z')     //if the character is a lowerclass aplhabet add to result
            res+=s[i];
        
        else if(s[i]=='(')             //if the charcter is '(' push into the stack 
            st.push('(');
        
        else if(s[i]==')'){              //if the character is ')' pop till '(' is found in stack
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();//pop '('
        }

        else{                   //if the character is a operator
            while(!st.empty()&& prec(s[i])<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){     //pop from the stack till it is empty and append in the string
        res+=st.top();
        st.pop();       
    }
    return res;
}

string expression::intopre(string l){
    string k=reverse(l);
    cout<<k;
    Stack<char> st;     //make a stack of operators
    string res;
    for(int i=0; i<k.length(); i++){
        if(k[i]>='a'&& k[i]<='z'){   //if the character is lowercase alphabet then add it into the answer
            res+=k[i];
        }
        else if(k[i]=='('){         //if the charcter is '(' push into the stack 
            st.push('(');
        }
        else if(k[i]==')'){         //if the character is ')' pop till '(' is found in stack
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();              //pop '(' from the stack
        }

        else{
            while(!st.empty()&& prec(k[i])<=prec(st.top())){ //if the character is a operator
                res+=st.top();
                st.pop();
            }
            st.push(k[i]);
        }
    }

    while(!st.empty()){    //pop from the stack till it is empty and append in the string
        res+=st.top();
        st.pop();       
    }
    string pre=reverse(res);
    return pre;
}

int expression:: evalpostfix(string s){
         Stack<int> st;        //make a stack of operands
       
        for (int i = 0; i < s.length(); i++) {   //push a number in the stack
            if (s[i] >= '0' && s[i] <= '9') {
                st.push(s[i] - '0');
            }

            else if (s[i] == ' ') { //continue if the character is blank space
                continue;
            }

            else {
                int op2 = st.top();  //operand2
                st.pop();
                int op1 = st.top();  //operand1
                st.pop();

                switch (s[i]) {
                    case '+':
                        st.push(op1 + op2);//push operand1+operand2
                        break;

                    case '-':
                        st.push(op1 - op2); //push operand1-operand2
                        break;

                    case '*':
                        st.push(op1 * op2);//push operand1*operand2
                        break;

                    case '/':
                        st.push(op1 / op2);//push operand1/operand2
                        break;
                }
            }
        }
    return st.top();  //return evaluation of postfix expression
}  

int expression:: evalprefix(string s){
         Stack<int> st;
       
        for (int i =s.length()-1 ; i >=0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                st.push(s[i] - '0');
            }
            else if (s[i] == ' ') {
                continue;
            }
            else {
                int op1 = st.top();//operand1
                st.pop();
                int op2 = st.top(); //operand2
                st.pop();

                switch (s[i]) {
                    case '+':
                        st.push(op1 + op2);//push operand1+operand2
                        break;

                    case '-':
                        st.push(op1 - op2);//push operand1-operand2
                        break;

                    case '*':
                        st.push(op1 * op2);//push operand1*operand2
                        break;

                    case '/':
                        st.push(op1 / op2);//push operand1/operand2
                        break;
                }
            }
        }
    return st.top();
}  
//driver method 
int main(){
    expression e; //object of class expression
    int ch;
    string d;
    string c;
    while(ch!=5){
    cout<<endl;
    cout<<"--Menu--"<<endl;
    cout<<"Enter 1 for infix to postfix"<<endl;
    cout<<"Enter 2 for infix to prefix"<<endl;
    cout<<"Enter 3 for Evaluation of postfix"<<endl;
    cout<<"Enter 4 for Evaluation of prefix"<<endl;
    cout<<"Enter 5 for exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    //menu driven program
    switch(ch){
        case 1:
            cout<<endl;
            cout<<"Enter string: ";
            cin>>c;
            cout<<endl;
            cout<<e.intopost(c)<<endl;//calling to convert from infix to postfix
            break;
           
        case 2:
            cout<<endl;
            cout<<"Enter string: ";
            cin>>d;
            cout<<endl;
            cout<<e.intopre(d)<<endl;//calling to convert from infix to prefix
            break;
           
        case 3:
            cout<<endl;
            cout<<"Enter the integer string: ";
            cin>>d;
            cout<<endl;
            cout<<e.evalpostfix(d)<<endl; //calling to evalute postfix expression
            break;
           
        case 4:
            cout<<endl;
            cout<<"Enter the integer string: ";
            cin>>d;
            cout<<endl;
            cout<<e.evalprefix(d)<<endl; //calling to evalute prefix expression
            break;    
    }
    }
    return 0;
}