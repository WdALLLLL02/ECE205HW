#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;
};


Node* cranode(string value){
    Node*Node_new =new Node();
    Node_new->data=value;
    Node_new->left=nullptr;
    Node_new->right=nullptr;
    return Node_new;
}

bool soperator(char ch){
    if (ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return true;
    }
    else{
        return false;
    }
}

int precedence(char op){
    if (op=='*'||op == '/'){
        return 2;
    }
    else if (op=='+'||op=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

string infixtopostfix(string infix){
    stack<char>operators;
    string postfix="";
    for (int i=0;i<infix.length();i++){
        char ch=infix[i];
        if(ch==' '){
            continue;
        }

        if (isdigit(ch)){
            string number="";
            while (i<infix.length()&&isdigit(infix[i])){
                number = number + infix[i];
                i++;
            }
            postfix=postfix+number;
            postfix=postfix+' ';
            i--;
        }

        else if (ch=='('){
            operators.push(ch);
        }
        else if (ch==')'){
            while (!operators.empty()&&operators.top()!='('){
                postfix=postfix+operators.top();
                postfix=postfix + ' ';
                operators.pop();
            }

            if (!operators.empty()){
                operators.pop();
            }
        }

        else if (soperator(ch)){
            while (!operators.empty() &&
                   operators.top()!='(' &&
                   precedence(operators.top())>=precedence(ch)){
                postfix=postfix+operators.top();
                postfix=postfix+' ';
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()){
        postfix=postfix+operators.top();
        postfix=postfix+' ';
        operators.pop();
    }
    return postfix;
}

Node* tree(string postfix){
    stack<Node*>treeStack;
    for (int i=0;i<postfix.length();i++){
        char ch=postfix[i];
        if (ch==' '){
            continue;
        }

        if (isdigit(ch)){
            string number="";

            while (i<postfix.length()&&isdigit(postfix[i])){
                number=number+postfix[i];
                i++;
            }
            Node* numberNode=cranode(number);
            treeStack.push(numberNode);
            i--;
        }

        else if (soperator(ch)){
            Node* rightNode=treeStack.top();
            treeStack.pop();
            Node* leftNode=treeStack.top();
            treeStack.pop();
            string op="";
            op=op+ch;
            Node* operatorNode=cranode(op);
            operatorNode->left=leftNode;
            operatorNode->right=rightNode;
            treeStack.push(operatorNode);
        }
    }
    return treeStack.top();
}

void postorder(Node* root){
    if (root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " ";
}

int evalpostfix(string postfix){
    stack<int> numbers;
    for (int i=0; i<postfix.length();i++){
        char ch=postfix[i];
        if (ch == ' '){
            continue;
        }  
        if (isdigit(ch)){
            string number = "";
            while (i<postfix.length()&&isdigit(postfix[i])){
                number=number+postfix[i];
                i++;
            }
            int value=stoi(number);
            numbers.push(value);
            i--;
        }
        else if(soperator(ch)){
            int rightValue=numbers.top();
            numbers.pop();
            int leftValue=numbers.top();
            numbers.pop();
            int result;
            if (ch == '+'){
                result=leftValue+rightValue;
            }
            else if (ch=='-'){
                result=leftValue-rightValue;
            }
            else if (ch=='*'){
                result=leftValue*rightValue;
            }
            else{
                result=leftValue/rightValue;
            }
            numbers.push(result);
        }
    }
    return numbers.top();
}

int main(){
    string infix;
    string postfix;
    cout << "enter infix: " << endl;
    getline(cin, infix);
    postfix = infixtopostfix(infix);
    cout<<endl;
    cout<<"postfix: "<<endl;
    cout<<postfix<<endl;
    Node* root=tree(postfix);
    cout<<endl;
    cout<<"binary tree:" << endl;
    cout<<endl;
    cout<<"postorder traversal of binary tree: "<<endl;
    postorder(root);
    cout<<endl;
    cout<<endl;
    cout<<"result: " << endl;
    cout<<evalpostfix(postfix) << endl;
    return 0;
}