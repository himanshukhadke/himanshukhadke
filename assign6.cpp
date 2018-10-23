//============================================================================
// Name        : assign6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;

struct node
{
  struct node *prev;
  string name;
  char status;
  struct node *next;
};


class Ticket_Booking
{
   node *head[10];
   public:
   Ticket_Booking();
   void book_ticket();
   void cancel_ticket();
   void display_seats();
};

Ticket_Booking::Ticket_Booking()
{
	for(int i=0;i<10;i++)
	     {
	    	node *temp=new node;
	    	temp->prev=NULL;
	    	temp->next=NULL;
	    	temp->name="";
	    	temp->status='A';
	    	head[i]=temp;
	    	node *p=temp;
	    	for(int j=1;j<7;j++)
	    	{
	    		node *temp=new node;
	    		temp->prev=p;
	    		temp->next=NULL;
	        	temp->name="";
	   	    	temp->status='A';
	   	    	p->next=temp;
	   	    	p=p->next;
	    	}
	     }
}


void Ticket_Booking::book_ticket()
{
	int row_no,col_no;
	cout<<"\nEnter row number and column number of your desired seat:";
	cout<<"\nRow_no:";
	cin>>row_no;
	cout<<"\nColumn_no:";
	cin>>col_no;
	node *temp=head[row_no - 1];
	for(int i=1;i<col_no;i++)
	{
		temp=temp->next;
	}
	if(temp->status=='A')
	{
	    cout<<"\nEnter your name:";
	    cin>>temp->name;
	    temp->status='B';
	}
	else
	{
		cout<<"\nTicket already booked.";
	}
}


void Ticket_Booking::cancel_ticket()
{
	string search;
	int flag=0;
	cout<<"\nEnter your name:";
	cin>>search;
	node *temp;
	for(int i=0;i<10;i++)
	{
		temp=head[i];
		for(int j=0;j<7;j++)
		{
			if(temp->name==search)
			{
			   flag=1;
			   break;
			}
			else
			{
				temp=temp->next;
			}
		}
       if(flag==1){break;}
	}
	if(flag==1)
	{
	   temp->name="";
	   temp->status='A';
	   cout<<"\nBooking successfully canceled.";
	}
	else
	{
		cout<<"\nBooking under your name not found.Please check the entered details";
	}
}



void Ticket_Booking::display_seats()
{
	node *temp;
	cout<<"\n                   Booking Status                    ";
	cout<<"\n-----------------------------------------------------"<<endl;
    cout<<"     ";
    for(int i=1;i<=7;i++){cout<<i<<"   ";}
    for(int i=0;i<10;i++)
	 {
	    if(i<9)
	    cout<<"\n "<<i+1<<"   ";
	    if(i==9)
	    cout<<"\n"<<i+1<<"   ";
	    for(temp=head[i];temp!=NULL;temp=temp->next)
	    {
	      cout<<temp->status<<"   ";
	    }
     }
    cout<<"\n-----------------------------------------------------"<<endl;
}

int main()
{
    int choice;
    Ticket_Booking t;

    do
    {
    	t.display_seats();
    	cout<<"\nSelect a choice from below mentioned choices.";
    	cout<<"\n1.Book a ticket.";
    	cout<<"\n2.Cancel a ticket.";
    	cout<<"\n3.Exit.";
    	cout<<"\nEnter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    	   case 1:    t.book_ticket();
    	              break;

    	   case 2:    t.cancel_ticket();
    	              break;

    	   case 3:    break;

    	   default:   cout<<"\nEnter a valid choice.";

    	}
    }while(choice!=3);
	return 0;
}
