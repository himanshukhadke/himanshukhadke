//============================================================================
// Name        : assign10.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Student
	{
		string name;
		float percent;
	};
class Students
{
    Student *a;
	int size;
public:
	Students(int size)
   {
       if(size>5)
       {
		a=new Student[size];
		this->size=size;
       }
       else
       {
           a=new Student[5];
           this->size=5;
       }
   }
	void accept();
	void display_top5();
	void quick_sort(int,int);
	int partition_qs(int,int);
};




void Students::accept()
{
  cout<<"\nEnter data.";
  for(int i=0;i<size;i++)
  {
	  cout<<"\nEnter name:";
	  cin>>a[i].name;
	  cout<<"\nEnter percentage obtained:";
	  cin>>a[i].percent;
  }
}

void Students::display_top5()
{
   cout<<"\nTop 5 students are:\n";
   for(int i=0;i<5;i++)
   {
	   cout<<i+1<<") Name: "<<a[i].name<<" Percentage:"<<a[i].percent<<endl;
   }
}

int Students::partition_qs(int low,int high)
{
   	float pivot=a[high].percent;
   	int i,j;Student temp;
   	i=low-1;
   	for(j=low;j<high;j++)
   	{
   		if(a[j].percent>=pivot)
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

void Students::quick_sort(int low,int high)
{
    if(low<high)
    {
    	int pi=partition_qs(low,high);
    	quick_sort(low,pi-1);
    	quick_sort(pi+1,high);
    }
}


int main()
{
    int n;
    cout<<"\nEnter no. of students(>=5):";
    cin>>n;
    Students s(n);
    s.accept();
    s.quick_sort(0,n-1);
    s.display_top5();
	return 0;
}
