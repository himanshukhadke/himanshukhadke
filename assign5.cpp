//============================================================================
// Name        : assign5.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
using namespace std;

//Structure of linked list
struct node
{
  string name;
  int prn;
  struct node *next;//pointer to next node
};

class Pinnacle
{
  node *head,*tail;//start and end pointers of a linked list
  public:
  Pinnacle()//default constructor of class Pinnacle
  {
    head=NULL;
    tail=NULL;
  }
  void create();//to create member list
  void change();//to add/delete a member
  void cal_members();//to calculate total no. of members in a list
  void display_members();//to display list of members
  void reverse_list();//to reverse member list
  void concat(Pinnacle,Pinnacle);//to merge two lists
  void add_member();//to add a member
  void delete_member();//to delete a member
};


void Pinnacle::create()
{
  //Creating member list
  int i=1,total;
  node *temp=new node;//allocates a new memory space
  cout<<"Enter total no. of members:";
  cin>>total;
  //Creating 1st node
  cout<<"Enter name of "<<i<<"st member:";
  cin>>temp->name;
  cout<<"Enter prn of "<<i<<"st member:";
  cin>>temp->prn;
  temp->next=NULL;
  head=temp;
  tail=temp;
  //Creating remaining nodes
  for(i=2;i<=total;i++)//run loop till final node number
 {
  temp=new node;
  cout<<"Enter name of member "<<i<<":";
  cin>>temp->name;
  cout<<"Enter prn of member "<<i<<":";
  cin>>temp->prn;
  temp->next=NULL;
  tail->next=temp;
  tail=tail->next;
 }
}


void Pinnacle::display_members()
{
    //Displaying member list
 node *temp;
 if(!head)//for empty list
 {
     cout<<"\nList is empty";
 }
 if(head->next==NULL)//for single member in list
 {
    cout<<"\nPresident and Secretary both are "<<head->name<<" and his prn is "<<head->prn<<endl;
 }
 for(temp=head;temp!=NULL;temp=temp->next)//temp!=NULL condition runs loop till end of linked list
 {
   if(temp==head)//to display first member in list as president
   {
   cout<<"\n-----------------------------------------------------------";
   cout<<"\nPresident is "<<temp->name<<" and his prn is "<<temp->prn;
   cout<<"\n-----------------------------------------------------------";
   temp=temp->next;
   }
   if(temp->next==NULL)//to display last member in list as secretary
   {
    cout<<"\n-----------------------------------------------------------";
    cout<<"\nSecretary is "<<temp->name<<" and his prn is "<<temp->prn<<endl;
    cout<<"\n-----------------------------------------------------------";
    break;
   }
   cout<<"\nMember name is "<<temp->name<<" and prn is "<<temp->prn;//display remaining members
 }

}


void Pinnacle::cal_members()
{//take a counter initiale to zero and run the loop till end of linked list after each node covered increment counter
  int count=0;//counter count<-0
  node *temp;//create a node pointer
  for(temp=head;temp!=NULL;temp=temp->next)//traverse linked list till end
  {
   count++;//increment count so as to get total no. of nodes i.e. members
  }
 cout<<"Total number of members are :"<<count<<endl;//display count value as total no. of members
}


void Pinnacle::add_member()
{
 //new member to be added before secretary
  node *temp;
  for(temp=head;temp->next->next!=NULL;temp=temp->next);//traverse list till member before secretary
  node *newnode = new node;//create a new node
  newnode->next=tail;//point next of new node to tail
  cout<<"\nEnter name of member to be added:";
  cin>>newnode->name;//fill name space
  cout<<"\nEnter prn of the respective member:";
  cin>>newnode->prn;//fill the prn space
  temp->next=newnode;//link last member before secretary to the new node
}


void Pinnacle::delete_member()
{
   int prn_remove;//holds prn of member to be removed
   int flag=0;
   cout<<"\nEnter prn number of member to be removed:";
   cin>>prn_remove;//accept the prn
   node *temp,*temp1;//create two node* pointers
   if(head->prn==prn_remove)//if first member is to be removed
   {
           flag=1;//to flag that member has be found and will be removed
	   temp1=head;//create a temp1 pointer pointing to head
	   temp=head->next;//make temp to traverse by 1
	   head=temp;//make temp as head i.e. second member on the list
	   delete(temp1);//delete first member using temp1
   }
   else if(tail->prn==prn_remove)//if last member is to be removed
   {
           flag=1;//to flag that member has be found and will be removed
	   for(temp=head;temp->next!=tail;temp=temp->next);//traverse using temp till member before secretary i.e. upto 2nd last member
	   temp1=tail;//temp1 points last member
	   temp->next=NULL;//make 2nd last member's next->NULL
	   tail=temp;//make 2nd last member now tail i.e last member
	   delete(temp1);//delete previous last member using temp1
   }
   else//for remaining members
   {
           flag=1;//to flag that member has be found and will be removed
	   for(temp=head;temp->next->prn!=prn_remove;temp=temp->next);//traverse using temp till a member having next member to be removed
	   temp1=temp->next; //make temp1 point to member to be removed
	   temp->next=temp1->next;//make temp->next point to next member of member to be removed
	   delete(temp1);//delete member to be removed using temp1
   }
   if(flag==1)//if member was deleted then display message
   {
      cout<<"\nMember successfully removed";
   }
   else
   {
      cout<<"\nMember not on the list";
   }
}


void Pinnacle::change()
{
  int choice;//choice for menu
  do
  {
   cout<<"\n       Menu";
   cout<<"\n------------------";
   cout<<"\n1.Add member";
   cout<<"\n2.Remove member";
   cout<<"\n3.Exit";
   cout<<"\n------------------";
   cout<<"\nEnter your choice:";
   cin>>choice;//accept choice entered by user
     switch(choice)//switch case to execute entered choice
     {
        case 1 : {
                     add_member();
                     break;
                 }
        case 2:  {
                     delete_member();
                     break;
                 }
        case 3:  {
                     break;
                 }
        default: {
                   cout<<"\nEnter valid choice";
                 }
     }
  }while(choice!=3);//exit loop if choice is to exit

}

void Pinnacle::reverse_list()
{
       node *p,*q;//create two node* pointers to reverse list
       q=head;//make q point to head
       if(!head)//empty list
        return;

       if(head->next==NULL)//only single node
        return;

       if(tail->next==NULL)//to check if tail->next is pointing to NULL or previous member
       {
           for(p=head;p->next!=NULL;p=p->next){}
           tail->next=p;
       }
       for(p=head->next ; p->next->next!=q->next ; p=p->next)//find partial circular linking in list
       {
          q=q->next;
       }
       p->next=q;//break the partial circular looping and form preceeding loop with previous node

       if(p->next!=head)//condition to specify no. of recursions
       {
          reverse_list();//recursion
       }
       else
       {  //for final step of reverse break the previous head node by making its next=NULL
          q->next=NULL;
          //interchange head and tail pointers
          node *temp;
          temp=head;
          head=tail;
          tail=temp;
          return;
       }
}

void Pinnacle::concat(Pinnacle obj1,Pinnacle obj2)
{
   node *p,*q,*s;
   p=obj1.head;
   q=obj2.head;
	   if(p==NULL)//if list 1 is empty
	   {
		 head=q;
		 tail=obj2.tail;
	   }
	   if(q==NULL)//if list 2 is empty
	   {
		 head=p;
		 tail=obj1.tail;
	   }
       if(p&&q)//start to sort first member
       {
    	   if(p->prn <= q->prn)
    	   {
    		   s=p;
    		   head=p;
    		   p=p->next;
    	   }
    	   else
    	   {
    		   s=q;
    		   head=q;
    		   q=q->next;
    	   }
       }
      while(p&&q)//sort rest of members
      {
           if(p->prn < q->prn)
           {
                s->next=p;
                s=p;
                p=p->next;

           }
           else if(p->prn > q->prn)
           {
                s->next=q;
                s=q;
                q=q->next;
           }
           else
           {
                s->next=p;
                s=p;
                p=p->next;
                q=q->next;
           }

      }
     while(p!=NULL)//to merge remaining members of p if left
     {
         s->next=p;
         s=p;
         p=p->next;
     }
     while(q!=NULL)//to merge remaining members of q if left
     {
         s->next=q;
         s=q;
         q=q->next;
     }
  tail=s;//assign new tail node to tail
}

int main()
{
 Pinnacle p1,p2,p3;
 int x;
 do
 {
         cout<<"\n------------------";
	 cout<<"\n1.Create member list.";
	 cout<<"\n2.Calculate total no. of members.";
	 cout<<"\n3.Display member list.";
	 cout<<"\n4.Change members";
	 cout<<"\n5.Merging two lists.";
	 cout<<"\n6.Reverse the list.";
	 cout<<"\n7.Exit.";
	 cout<<"\n------------------";
	 cout<<"\nEnter your choice:";
	 cin>>x;
	 switch(x)
	 {
	   case 1:  {
                      p1.create();
                      break;
	            }

	   case 2:  {
                      p1.cal_members();
                      break;
	   	        }

	   case 3:  {
                      p1.display_members();
                      break;
	   	        }

	   case 4:  {
                      p1.change();
                      cout<<"\nModified list is:\n";
                      p1.display_members();
                      break;
	   	        }

	   case 5:  {
		              cout<<"\nEnter first list.\n";
		              p1.create();
		              cout<<"\nEnter second list.\n";
		              p2.create();
		              cout<<"\nFirst list is:\n";
		              p1.display_members();
		              cout<<"\nSecond list is:\n";
		              p2.display_members();
		              cout<<"\nMerge list is:\n";
		              p3.concat(p1,p2);
		              p3.display_members();
		              break;
	            }

           case 6:  {
                              p1.reverse_list();
                              cout<<"\nReverse list is:";
                              p1.display_members();
                              break;
                    }

	   case 7:  {
                      break;
                }

	   default: {
		             cout<<"\nEnter valid choice.";
	            }
	 }
 }while(x!=7);
 return 0;
}
