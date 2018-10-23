#include<iostream>
#include<cstring>
using namespace std;

struct node
{
  char data;
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
  void push(char);
  char pop();
  bool isEmpty();
  ~Stack(){}
};

void Stack::push(char str)
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

char Stack::pop()
{
   if(top==0)
   {
     char temp=head->data;
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
    delete(p);
    q->next=NULL;
    return (q->data);
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

bool check(char *str)
{
   Stack stk;
   bool valid=0;
   for(int i=0;str[i]!='\0';i++)
   {
     if(str[i]=='('||str[i]=='['||str[i]=='{')
     {
       stk.push(str[i]);
     }
     else if(str[i]==')'||str[i]==']'||str[i]=='}')
     {
        char temp=stk.pop();
        if(str[i]-temp)
        {
          valid=1;
        }
        else
        {
          valid=0;
          break;
        }
     }
   }
  return valid;
}

int main()
{
  char s[10];
  cout<<"\nEnter expression :";
  cin>>s;
  bool correct;
  correct=check(s);
  if(correct==1)
  {
    cout<<"\nEntered expression "<<s<<" is correct.";
  }
  else
  {
   cout<<"\nEntered expression is incorrect.";
  }
  return 0;
}
