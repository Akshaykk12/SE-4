#include <iostream>
using namespace std;
// Tree Node Definition
class node
{
public:
    char val;
    node *left, *right;
    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
    // Constructor Method
    node(char val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// Stack to hold the latest node
class Stack
{
public:
    node *treeNode;
    Stack *next;
    // Constructor Method
    Stack(node *treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }
};
class ExpressionTree
{
private:
    Stack *top;
public:
    // Constructor Method
    ExpressionTree()
    {
        top = NULL;
    }
    void push(node *ptr);
    void insert(char val);
    void inOrder(node *root);
    void postOrder(node *root);
   
    node *pop()
    {
        node *ptr = top->treeNode;
        top = top->next;
        return ptr;
    }
    node *treetoproot()
    {
        return top->treeNode;
    }
    
    // function to check if operand
    bool isOperand(char ch)
    {
        return ch >= '0' && ch <= '9' || ch>='A' && ch<='Z' || ch>='a' && ch<='z';
    }
    // function to check if operator
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    // function to construct expression Tree
    void construct(string eqn)
    {
        for (int i = eqn.length() - 1; i >= 0; i--)
            insert(eqn[i]);
    }
    
};


 // function to push a node in stack
void ExpressionTree::push(node *ptr)
    {
        if (top == NULL)
            top = new Stack(ptr);
        else
        {
            Stack *nptr = new Stack(ptr);
            nptr->next = top;
            top = nptr;
        }
    }
    
// function to insert character
void ExpressionTree::insert(char val)
    {
        // If the encountered character is Number make a node an push it on stack
        if (isOperand(val))
        {
            node *nptr = new node(val);
            push(nptr);
        }
        // else if it is operator then make a node and left and
        else if (isOperator(val))
        {
            node *nptr = new node(val);
            nptr->left = pop();
            nptr->right = pop();
            push(nptr);
        }
    }
    
void ExpressionTree::inOrder(node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout<<root->val;
            inOrder(root->right);
        }
    }
void ExpressionTree::postOrder(node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->val;
        }
    }
int main()
{
    string exp;
    ExpressionTree et;
    cout<<"Enter expression in Prefix form: ";
    cin>>exp;
    et.construct(exp);
    cout<<"\nIn-order Traversal of Expression Tree : ";
    et.inOrder(et.treetoproot());
    cout<<"\nPost-order Traversal of Expression Tree : ";
    et.postOrder(et.treetoproot());
    return 0;
};
