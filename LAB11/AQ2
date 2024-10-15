#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode
{
    char data;
    Tptr leftchild;
    Tptr rightchild;
}TNode;
///*
//Create nodes in the tree
Tptr createNode(char val)
{
    Tptr temp =(Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}
//*/

Tptr stack[MAX];
int top=-1;
int i;

//check if stack is empty
bool isEmpty()
{
    return top==-1;
}

//check if stack is full
bool isFull()
{
    return top==MAX -1;
}

//push element onto stack
void Push(Tptr e)
{
    if(isFull())
    {
        return;
    }
    stack[++top]=e;
}

//pop element from stack
Tptr Pop()
{
    Tptr popped=createNode('\0');
    if(isEmpty())
    {
        free(popped);
    }
    else
    {
        popped=stack[top--];
    }
    return popped;
}

//check if character is operator
bool isOperator(char ch)
{
    bool ret=false;
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch=='^' )
    {
        ret = true;
    }
    return ret;
}

Tptr createExpression(char* postfix)
{
    int i;
    int plen =strlen(postfix);
    char cc;
    for(i=0;i<plen;i++)
    {
        cc = postfix[i];
        if(isalnum(cc))
        {
            Tptr node = createNode(cc);
            Push(node);
        }
        else if(isOperator(cc))
        {
            Tptr node = createNode(cc);
            node->rightchild = Pop();
            node->leftchild = Pop();
            Push(node);
        }
    }
    return stack[top];
}

void inOrderTraversal(Tptr root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->leftchild);
        printf("%c ", root->data);
        inOrderTraversal(root->rightchild);
    }
}

int main()
{
    char postfix[] = "ab*cd/-";
    Tptr expressionTree = createExpression(postfix);

    if (expressionTree != NULL)
    {
        printf("In-Order Traversal of the Expression Tree: ");
        inOrderTraversal(expressionTree);
        printf("\n");
    }

    return 0;
}
