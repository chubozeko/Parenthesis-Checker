#include <cstdlib>
#include <iostream>
//#define STACKSIZE 10;

struct stack{
    int items[10];
    int top;
};
struct stack s;

void initStack(struct stack *s);
int is_empty(struct stack *s);
int is_full(struct stack *s);
void push(struct stack *s, char [],int);
int pop(struct stack *s);

using namespace std;

int main(int argc, char *argv[])
{
    int valid = 1;
    char symb[20],p;
    int i=0;
    initStack(&s);
    cin>>symb;
    while(symb[i]!=NULL)
    {
        if(symb[i] == '(' || symb[i] == '[' || symb[i] == '{' )
            push(&s, symb, i);
        if(symb[i] == ')' || symb[i] == ']' || symb[i] == '}' )
        {    
            if(is_empty(&s))
                valid = 0;
            else
            {
                 p = pop(&s);
                 if((p=='(' && symb[i]!=')') || (p=='[' && symb[i]!=']') || (p=='{' && symb[i]!='}'))
                     valid = 0;
            }
        }
        i++;
    }
    if(!(is_empty(&s)))
        valid = 0;
    if(valid==1)
        cout<<"String is valid"<<endl;
    else
        cout<<"String is not valid (invalid)"<<endl; 
    system ("PAUSE");
    return 0;
}

void initStack(struct stack *s)
{
        s->top = -1;
}

int is_empty(struct stack *s)
{
        if(s->top == -1)
            return 1;
        else
            return 0;
}

int is_full(struct stack *s)
{
        if(s->top == 49)
            return 1;
        else
            return 0;
}

void push(struct stack *s, char x[], int i)
{
    if(is_full(s))        
    {
        printf("Overflow: Stack is full");
        exit(1);
    }
    s->top++;
    s->items[s->top]=x[i];
}

int pop(struct stack *s)
{
    if(is_empty(s)==1)    
    {
        printf("Underflow: Stack is empty");
        exit(1);
    }
    return s->items[(s->top)--];
}

