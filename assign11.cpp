//============================================================================
// Name        : assign9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
#define size 10

class Pizza_parlor
{
  struct Queue
  {
	  int q[size];
	  int front,rear;
  }Q;
  public:
  Pizza_parlor()
  {
	  Q.front=-1;
	  Q.rear=-1;
  }
  bool Qfull();
  bool Qempty();
  void Place_order(int);
  void Ready_order(int);
  void Display_orderlist();
};

bool Pizza_parlor::Qempty()
{
   if(Q.front==-1 && Q.rear==-1)
   {
	   return 1;
   }
   else
   {
	   return 0;
   }
}

bool Pizza_parlor::Qfull()
{
   if((Q.rear+1)!=Q.front)
   {
     if(Q.front==((Q.rear+1)%size))
     {
    	return 1;
     }
     else
     {
    	return 0;
     }
   }
   else
   {
	   return 1;
   }
}

void Pizza_parlor::Place_order(int a)
{
	if(Qempty())
	{
		Q.front=0;
		Q.rear=0;
		Q.q[Q.rear]=a;
		cout<<"\nOrder successfully placed.";
	}
	else if(Qfull())
    {
	   cout<<"\nOrder list full.Cannot place more orders.";
    }
	else if(Q.rear==size-1)
	{
          Q.rear=0;
          Q.q[Q.rear]=a;
          cout<<"\nOrder successfully placed.";
	}
	else
	{
		Q.rear++;
		Q.q[Q.rear]=a;
		cout<<"\nOrder successfully placed.";
	}

}

void Pizza_parlor::Ready_order(int a)
{
   if(Q.front==-1)
   {
	   cout<<"\nThere is no order in the list.";
	   return;
   }

   if(Q.q[Q.front]==a)
   {
	   cout<<"\nYour order with no: "<<Q.q[Q.front]<<" is ready.Thank you for placing an order.";
       Q.q[Q.front]=0;
       if(Q.front==Q.rear)
       {
    	   Q.front=-1;
    	   Q.rear=-1;
       }
       else if(Q.front==size-1)
       {
    	   Q.front=0;
       }
       else
       {
    	   Q.front++;
       }
   }
   else
   {
	   cout<<"\nYour order is not ready.Please wait.";
   }
}

void Pizza_parlor::Display_orderlist()
{
    if(Qempty())
    {
    	cout<<"\nOrder list is empty.";
    }
    cout<<"\nOrders in waiting list are:\n";
    if(Q.front<=Q.rear)
    {
    	int count=0;
    	for(int i=Q.front;i<=Q.rear;i++)
    	{
    			count++;
    			cout<<count<<") "<<Q.q[i]<<endl;
    	}
    }
    else
    {
    	int count=0;
    	for(int i=Q.front;i<size-1;i++)
    	{
    		count++;
    		cout<<count<<") "<<Q.q[i]<<endl;
    	}
    	for(int i=0;i<=Q.rear;i++)
    	{
    		count++;
    		cout<<count<<") "<<Q.q[i]<<endl;
    	}
    }
}

int main()
{
  Pizza_parlor p;
  int choice;
  do
  {
    cout<<"\n1.Place order";
    cout<<"\n2.Ready order";
    cout<<"\n3.Display list of orders";
    cout<<"\n4.Exit";
    cout<<"\nEnter your choice:";
    cin>>choice;
    switch(choice)
    {
      case 1: {
    	        int order_no;
    	        cout<<"\nEnter order no:";
    	        cin>>order_no;
    	        p.Place_order(order_no);
                break;
              }

      case 2: {
    	        int order_no;
    	        cout<<"\nEnter order no to check if ready:";
    	        cin>>order_no;
    	        p.Ready_order(order_no);
                break;
              }

      case 3: {
    	        p.Display_orderlist();
                break;
              }

      case 4: {
                 break;
              }

     default: {
    	        cout<<"\nEnter valid choice.";
              }
      }
    }while(choice!=4);
  return 0;
}
