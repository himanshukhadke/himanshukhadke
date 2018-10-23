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
		a=new Student[size];
		this->size=size;
   }
	void accept();
	void display_top5();
    void bubble_sort();
	void selection_sort();
};

void Students::bubble_sort()
{
	for(int i=1;i<=size-1;i++)
	{
		cout<<"Pass "<<i<<":\n";
		for(int j=0;j<size-i;j++)
		{
			if(a[j].percent<a[j+1].percent)
			{
				Student temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void Students::selection_sort()
{
	int min;
	Student temp;
	for(int i=0;i<size;i++)
	{
		min=i;
		for(int j=i;j<size;j++)
		{
			if(a[j].percent>a[min].percent)
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

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

int main()
{
    int choice,no;
    do
    {
    	cout<<"\nEnter total no. of students(>5):";
    	cin>>no;
    	Students stu(no);
    	cout<<"\nSelect a choice from below options:";
    	cout<<"\n1.Sort by bubble sort and display top 5.";
    	cout<<"\n2.Sort by selection sort and display top 5.";
    	cout<<"\n3.Exit.";
    	cout<<"\nEnter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    	   case 1:  {
    		           stu.accept();
                       stu.bubble_sort();
                       stu.display_top5();
    		           break;
    	            }
    	   case 2:  {
    		           stu.accept();
    		           stu.selection_sort();
    		           stu.display_top5();
    		           break;
    	            }
    	   case 3:  {
    		           break;
    	            }
    	   default: cout<<"\nEnter valid choice.";
    	}
      //cout<<"\nDo you want to continue(y/n):";

    }while(choice!=3);
	return 0;
}
