#include<iostream>
#include<cstring>
using namespace std;

struct node
{
  struct node *prev;
  bool bit;
  struct node *next;
};

class Binary
{
  node *head,*tail,*head1,*head2;
  int size;
  public:
  Binary()
  {
    head=NULL;
    head1=NULL;
    head2=NULL;
    tail=NULL;
    size=0;
  }
  void accept();
  void display();
  void calc_1scmpl();
  void calc_2scmpl();
  Binary operator+(Binary);
};

void Binary::accept()
{
   int i,n;
   cout<<"\nEnter number of bits:";
   cin>>n;
   node *temp=new node;
   temp->prev=NULL;
   temp->next=NULL;
   head=temp;
   node *p=temp;
   for(i=1;i<n;i++)
   {
     node *temp=new node;
     temp->next=NULL;
     temp->prev=p;
     p->next=temp;
     p=temp;
   }
   tail=p;
   size=n;
   cout<<"\nEnter binary number:";
   for(temp=head;temp!=NULL;temp=temp->next)
   {
     cin>>temp->bit;
   }
}

void Binary::display()
{
   node *temp;
   cout<<"Binary number is : ";
   for(temp=head;temp!=NULL;temp=temp->next)
   {
      cout<<temp->bit;
   }
   cout<<endl;
}

void Binary::calc_1scmpl()
{
   node *temp=new node;
   node *temp1=head;
   temp->prev=NULL;
   temp->next=NULL;
   node *p=temp;
   head1=temp;
   if(head->bit==0)
   {
     temp->bit=1;
   }
   else
   {
     temp->bit=0;
   }
   for(temp1=head->next;temp1!=NULL;temp1=temp1->next)
   {
      node *temp=new node;
      temp->prev=p;
      temp->next=NULL;
      p->next=temp;
      p=temp;
      if(temp1->bit==0)
      {
        temp->bit=1;
      }
      else
      {
        temp->bit=0;
      }
   }
  if(head2==NULL)
  {
     cout<<"\n1s compliment:";
     for(temp=head1;temp!=NULL;temp=temp->next)
    {
      cout<<temp->bit;
    }
    cout<<endl;
  }
}

void Binary::calc_2scmpl()
{
   node *temp,*temp1,*p;
   temp=new node;
   temp->prev=NULL;
   temp->next=NULL;
   head2=temp;
   if(head1==NULL)
   {
     calc_1scmpl();
   }
   head2->bit=head1->bit;
   p=temp;
   for(temp1=head1->next;temp1!=NULL;temp1=temp1->next)
   {
     node *temp=new node;
     temp->next=NULL;
     temp->prev=p;
     temp->bit=temp1->bit;
     p->next=temp;
     p=temp;
   }
   bool carry=1;
  for(temp1=p;temp1!=NULL;temp1=temp1->prev)
  {
     if(temp1->bit==1 && carry==1)
     {
        temp1->bit=0;
        carry=1;
     }
     else if(temp1->bit==1 && carry==0)
     {
        carry=0;
     }
     else if(temp1->bit==0 && carry==0)
     {
        carry=0;
     }
     else if(temp1->bit==0 && carry==1)
     {
         temp1->bit=1;
         carry=0;
     }
  }
   cout<<"\n2s compliment:"<<carry;
     for(temp1=head2;temp1!=NULL;temp1=temp1->next)
    {
      cout<<temp1->bit;
    }
    cout<<endl;
}

Binary Binary::operator+(Binary obj)
{
  Binary o;
  if(size>=obj.size)
  {
      o.size=size;
  }
  else
  {
      o.size=obj.size;
  }
  node *temp=new node;
  node *temp1=head;
  node *temp2=obj.head;
  temp->next=NULL;
  temp->prev=NULL;
  temp->bit=0;
  node *p=temp;
  o.head=temp;
  for(int i=2;i<=o.size;i++)
  {
	  node *temp=new node;
	  temp->next=NULL;
	  temp->prev=p;
	  temp->bit=0;
	  p->next=temp;
	  p=temp;
  }
  o.tail=p;
  bool carry=0;
  if(size>=obj.size)
  {
      int diff=size-obj.size;
      for(int i=diff;i>0;i--)
      {
          node *temp=new node;
          temp->prev=NULL;
          temp->next=obj.head;
          temp->bit=0;
          obj.head->prev=temp;
          obj.head=temp;
      }
  }
  else
  {
      int diff=obj.size-size;
      for(int i=diff;i>0;i--)
      {
          node *temp=new node;
          temp->prev=NULL;
          temp->next=head;
          temp->bit=0;
          head->prev=temp;
          head=temp;
      }
  }
  temp1=tail;
  temp2=obj.tail;
  for(node *temp=o.tail;temp!=NULL;temp=temp->prev)
  {
	  if(temp1->bit==1 && temp2->bit==1)
	  {
		  temp1=temp1->prev;
		  temp2=temp2->prev;
		  if(carry==0)
		  {
			  temp->bit=0;
			  carry=1;
		  }
		  else
		  {
			  temp->bit=1;
			  carry=1;
		  }
	  }
	  else if((temp1->bit==1 && temp2->bit==0)||(temp1->bit==0 && temp2->bit==1))
	  {
		  temp1=temp1->prev;
		  temp2=temp2->prev;
		  if(carry==1)
		  {
			  temp->bit=0;
			  carry=1;
		  }
		  else
		  {
			  temp->bit=1;
			  carry=0;
		  }
	  }
	  else if(temp1->bit==0 && temp2->bit==0)
	  {
		  temp1=temp1->prev;
		  temp2=temp2->prev;
		  if(carry==1)
		  {
			  temp->bit=1;
			  carry=0;
		  }
		  else
		  {
			  temp->bit=0;
			  carry=0;
		  }
	  }
  }
    cout<<"\nAddition is: "<<carry;
    for(temp=o.head;temp!=NULL;temp=temp->next)
    {
        cout<<temp->bit;
    }
    cout<<endl;
  return o;
}

int main()
 {
  Binary b1,b2,b3;
  cout<<"\nBinary number 1:\n";
  b1.accept();
  b1.display();
  b1.calc_1scmpl();
  b1.calc_2scmpl();
  cout<<"\nBinary number 2:\n";
  b2.accept();
  b2.display();
  b2.calc_1scmpl();
  b2.calc_2scmpl();
  cout<<"\nPerforming addition of two binary nos.\n";
  b3=b1+b2;
  return 0;
 }
