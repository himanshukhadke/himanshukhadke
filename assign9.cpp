#include<iostream>
#include<cstring>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

class Stack
{
  int top;
  node *head;
  public:
  Stack()
  {
    head=NULL;
    top=-1;
  }
  void push(int);
  int pop();
  bool isEmpty();
  ~Stack(){}
};

void Stack::push(int str)
{
  if(isEmpty())
  {
     node *temp=new node;
     temp->data=str;
     temp->next=NULL;
     head=temp;
     top++;
  }
  else
  {
    node *p;
    for(p=head;p->next!=NULL;p=p->next);
    node *temp=new node;
    temp->data=str;
    temp->next=NULL;
    p->next=temp;
    top++;
  }
}

int Stack::pop()
{
   if(top==0)
   {
     int temp=head->data;
     node *t=head;
     delete t;
     head=NULL;
     top--;
     return temp;
   }
   else
   {
    node *p,*q;
    for(p=head;p->next!=NULL;p=p->next)
    {
      q=p;
    }
    top--;
    int temp=p->data;
    delete(p);
    q->next=NULL;
    return (temp);
   }
}

bool Stack::isEmpty()
{
  if(top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

    int evaluatePostfix(char* exp)
{
    Stack s;
    int a,b;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]>=48 && exp[i]<=57)
        {
            s.push(exp[i]-'0');
        }
        else if(exp[i]<48 || exp[i]>57)
        {
            b=s.pop();
            a=s.pop();
            switch(exp[i])
            {
                case '+' :  s.push(a+b);
                            break;
                case '-' :  s.push(a-b);
                            break;
                case '*' :  s.push(a*b);
                            break;
                case '/' :  s.push(a/b);
                            break;
            }
        }
    }
    return s.pop();
}

// Driver program to test above functions
int main()
{
    char exp[30];
    cout<<"\nEnter valid postfix expression:";
    cin>>exp;
    cout<<"postfix evaluation: "<< evaluatePostfix(exp);
    return 0;
}

