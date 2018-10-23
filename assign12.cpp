#include<iostream>
using namespace std;

class Training
{
    int *a;
    int n;
public:
    void read();
    void search_linear(int);
    void search_binary(int);
    void search_fibonacci(int);
    Training()
    {
        cout<<"\nEnter total no. of students for training program:";
        cin>>n;
        a=new int[n];
    }
};

int partition(int *a,int low,int high)
{
   	int pivot=a[high];
   	int i,j,temp;
   	i=low-1;
   	for(j=low;j<high;j++)
   	{
   		if(a[j]<=pivot)
   		{
   			i++;
   			temp=a[i];
   			a[i]=a[j];
   			a[j]=temp;
   		}
   	}
   	temp=a[i+1];
   	a[i+1]=a[high];
   	a[high]=temp;
   	return (i+1);
}

void quick_sort(int *a,int low,int high)
{
    if(low<high)
    {
    	int pi=partition(a,low,high);
    	quick_sort(a,low,pi-1);
    	quick_sort(a,pi+1,high);
    }
}


void Training::read()
{
   cout<<"\nEnter roll. no of students who attended the program:";
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   quick_sort(a,0,n);
}


void Training::search_linear(int key)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            flag=1;
            cout<<"\nStudent attended the program";
            break;
        }
    }
    if(!flag)
        cout<<"\nStudent not attended the program.";
}


void Training::search_binary(int key)
{
    int u=n-1;
	int l=0,m;
	while(l!=u)
	{
		m=(l+u)/2;
		if(key<a[m])
		{
			u=m-1;
		}
		else if(key>a[m])
		{
			l=m+1;
		}
	}
	if(a[l]==key)
	{
		cout<<"\nStudent attended the program";
	}
	else
	{
		cout<<"\nStudent not attended the program.";
	}
}


void Training::search_fibonacci(int key)
{
    int f = n,a1,b;
    int *fibo=new int[n];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<n;i++)
    {
    	fibo[i]=fibo[i-1]+fibo[i-2];
    }
    b=fibo[f-2];
    a1=fibo[f-3];
    int flag=0;
    int k=1;
    while(f>0 && f<=n)
    {
    	k++;
      	if(key<a[f-1])
      	{
      		f=f-a1;
      		a1=b-a1;
      		b=b-a1;
      	}
      	else if(key>a[f-1])
      	{
      		f=f+a1;
      		b=b-a1;
      		a1=a1-b;
      	}
      	else if(key==a[f-1])
      	{
      		flag=1;
      		cout<<"\nStudent attended the program ";
      		break;
      	}
    }
    if(flag==0)
    {
    	cout<<"\nStudent not attended the program.";
    }
}


int main()
{
    Training t;
    t.read();
    int choice,k;
    do
    {
        cout<<"\n1.Linear search";
        cout<<"\n2.Binary search";
        cout<<"\n3.Fibonacci search";
        cout<<"\n4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\nEnter roll no of student to be checked:";
                    cin>>k;
                    t.search_linear(k);
                    break;

            case 2: cout<<"\nEnter roll no of student to be checked:";
                    cin>>k;
                    t.search_binary(k);
                    break;

            case 3: cout<<"\nEnter roll no of student to be checked:";
                    cin>>k;
                    t.search_fibonacci(k);
                    break;

            case 4: break;

            default: cout<<"\nEnter valid choice";
        }
    }while(choice!=4);
    return 0;
}
