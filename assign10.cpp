#include<iostream>
using namespace std;

class Deque
{
public:
    int *a;
    int size,front_ptr,rear_ptr;
    void push_back(int x);
    void push_front(int x);
    int pop_back();
    int pop_front();
    int front();
    int back();
    bool empty();
    bool full();
    Deque()
    {
        size=0;
        front_ptr=-1;
        rear_ptr=-1;
        cout<<"\nEnter size:";
        cin>>size;
        a=new int[size];
        for(int i=0;i<size;i++)
            a[i]=-1;
    }
    ~Deque(){}
};


int Deque::front(){ return a[front_ptr]; }

int Deque::back() { return a[rear_ptr]; }

bool Deque::empty() { return front_ptr==-1&&rear_ptr==-1; }

bool Deque::full() { return (rear_ptr+1)%size==front_ptr; }

void Deque::push_back(int x)
{
    if(full())
    {
        cout<<"\nDeque is full cannot push";
    }
    else
    {
        if(rear_ptr+1==size)
        {
           cout<<"\nCannot push as rear position is occupied";
        }
        else if(rear_ptr==-1)
        {
            front_ptr++;
            rear_ptr++;
            a[rear_ptr]=x;
        }
        else
        {
           rear_ptr++;
           a[rear_ptr]=x;
        }
    }
}

void Deque::push_front(int x)
{
       if(!front_ptr)
       {
         cout<<"\nCannot push as front position is occupied";
       }
       else if(front_ptr=-1)
       {
          front_ptr++;
          rear_ptr++;
          a[front_ptr]=x;
       }
       else if(front_ptr>0)
       {
          front_ptr--;
          a[front_ptr]=x;
       }
}

int Deque::pop_back()
{
    int x=back();
    a[rear_ptr]=-1;
    if(front_ptr==rear_ptr)
    {
        rear_ptr=-1;
        front_ptr=-1;
    }
    else
    {
        rear_ptr--;
    }
    return x;
}

int Deque::pop_front()
{
      int x=front();
      a[front_ptr]=-1;
      if(front_ptr==rear_ptr)
      {
          front_ptr=-1;
          rear_ptr=-1;
      }
      else
      {
          front_ptr++;
      }
      return x;
}


void display_deque(Deque d)
{
   if(d.empty())
      cout<<"\nDeque is empty";
   else
   {
       cout<<"\nDeque contains: ";
       for(int i=0;i<d.size;i++)
       {
           if(d.a[i]>=0)
             cout<<d.a[i]<<" ";
       }
   }
}


int main()
{
    Deque dq;
    int choice,x;
    do
    {
        cout<<"\nSelect deque operations to be performed.Enter positive numbers only";
        cout<<"\n1.Push back";
        cout<<"\n2.Push front";
        cout<<"\n3.Pop back";
        cout<<"\n4.Pop front";
        cout<<"\n5.Front";
        cout<<"\n6.Back";
        cout<<"\n7.Empty";
        cout<<"\n8.Full";
        cout<<"\n9.Display";
        cout<<"\n10.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:  cout<<"\nEnter element to be pushed:";
                     cin>>x;
                     dq.push_back(x);
                     break;

            case 2:  cout<<"\nEnter element to be pushed:";
                     cin>>x;
                     dq.push_front(x);
                     break;

            case 3:  if(dq.empty())
                        cout<<"\nDeque is empty cannot pop element";
                     else
                     {
                         x=dq.pop_back();
                         cout<<"\nPopped element is:"<<x;
                     }
                     break;

            case 4:  if(dq.empty())
                        cout<<"\nDeque is empty cannot pop element";
                     else
                     {
                         x=dq.pop_front();
                         cout<<"\nPopped element is:"<<x;
                     }
                     break;

            case 5:  cout<<"\nFront:"<<dq.front();
                     break;

            case 6:  cout<<"\nBack:"<<dq.back();
                     break;

            case 7:  if(dq.empty())
                        cout<<"\nDeque is empty";
                     else
                        cout<<"\nDeque is not empty";
                     break;

            case 8:  if(dq.full())
                        cout<<"\nDeque is full";
                     else
                        cout<<"\nDeque is not full";
                     break;

            case 9:  display_deque(dq);
                     break;

            case 10: break;

            default:  cout<<"\nEnter valid choice";

        }

    }while(choice!=10);
    return 0;
}
