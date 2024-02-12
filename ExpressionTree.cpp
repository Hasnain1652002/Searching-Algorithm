#include <iostream>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;

class Tree {
    public:
    char data;
    Tree *left , *right ;

    Tree(char data){
        this->data = NULL ;
        this->left = NULL ;
        this->right = NULL ;
    }
    
};

int Pre(char c){
    
    if(c == '^') return 3;
    
    else if(c == '*' || c == '/' || c == '%') return 2;
    
    else if (c == '+' || c == '-') return 1;

    else return -1;
}

string InfixtoPostfix(string exp){
    
    stack<char> stk;
    string postfix;
    string output;

    for(int i = 0; i<exp.length(); i++){
        if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
            postfix += exp[i] ;
        }
        else if (isdigit(exp[i])){
            postfix += exp[i] ;
        }
        else if(exp[i] == '('){
            stk.push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(!stk.empty() && stk.top() != '('){
                postfix += stk.top() ;
                stk.pop();
            }
            if(!stk.empty()){
                stk.pop();
            }
        }
        else {
            while(!stk.empty() && Pre(stk.top()) > Pre(exp[i])){
                postfix += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
    }
    while(!stk.empty()){
        postfix += stk.top();
        stk.pop();
    }

    for (int i=0; i<postfix.length();i++){
        output += postfix.substr(i,1) + " ";
    }
    
    return output;
}

int ExpressionTree(string output){
    stack<char> s;

    for(int i=0; i<output.length(); i++){
        if((output[i] >= 'a' && output[i] <= 'z') || (output[i] >= 'A' && output[i] <= 'Z')){
            s.push(output[i]);
        }
    }
}

int main(){
    cout<<InfixtoPostfix("a+b-c");

    return 0;
}