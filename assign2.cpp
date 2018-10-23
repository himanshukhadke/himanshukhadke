//============================================================================
// Name        : assign2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*In a second year Computer Engineering class of m students,set A of students play cricket and set B of students play badminton.Write program to find and display:
1)set of students who play either cricket or badminton or both
2)set of students who play both cricket and badminton
3)set of students who play only cricket
4)set of students who play only badminton
5)no. of students who play neither cricket nor badminton
*/

#include <iostream>
using namespace std;

class CS_student
{
	int rollno[30];
	string s_name[30];
public:
	int no_s;
	static int total_s;
	void getdata();//read data from user
	void set_uni(CS_student,CS_student);//union
	void set_intrst(CS_student,CS_student);//intersection
	void set_diff(CS_student,CS_student);//difference
	void set_complmt(int);//complement
    void display();
};

int CS_student :: total_s;

void CS_student ::getdata()
{
	cout<<"\nEnter total number of students.:";
	cin>>no_s;
	for(int i=0;i<no_s;i++)
	{
		cout<<"\nEnter name:";
		getline(cin>>ws,s_name[i]);
		cout<<"\nEnter roll no.:";
		cin>>rollno[i];
	}
}

void CS_student ::set_uni(CS_student x,CS_student y)
{
	int t=0,count=0;
	for(int i=0;i<x.no_s;i++)
	{
	  rollno[i]=x.rollno[i];
	  s_name[i]=x.s_name[i];
	  count++;
	}

	for(int j=0;j<y.no_s;j++)
	{
		for(int k=0;k<x.no_s;k++)
		{
			if(y.rollno[j]==x.rollno[k])
			{   t=0;
				break;
			}
			else
			{
				t=1;
			}
		}
	if(t==1)
	  {
		rollno[count]=y.rollno[j];
		s_name[count]=y.s_name[j];
		count++;
	  }
	}
no_s=count;
}

void CS_student ::display()
{
	cout<<"\n{";
	for(int i=0;i<no_s;i++)
	{
		cout<<s_name[i]<<"-"<<rollno[i]<<"\t";
	}
	cout<<"}"<<endl;
}

void CS_student ::set_intrst(CS_student a,CS_student b)
{
	int flag=0,count=0;
	for(int i=0;i<a.no_s;i++)
	{
		for(int j=0;j<b.no_s;j++)
		{
			if(a.rollno[i]==b.rollno[j])
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
			}
		}
		if(flag==1)
		{
		 rollno[count]=a.rollno[i];
		 s_name[count]=a.s_name[i];
		 count++;
		}
	}
no_s=count;
}

void CS_student :: set_complmt(int c)
{
	no_s=CS_student::total_s - c;
}
void CS_student :: set_diff(CS_student p,CS_student q)
{
	int flag=0,count=0;
	for(int i=0;i<p.no_s;i++)
	{
		for(int j=0;j<q.no_s;j++)
		{
			if(p.rollno[i]==q.rollno[j])
			{
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
		}
	  if(flag==1)
	  {
		rollno[count]=p.rollno[i];
		s_name[count]=p.s_name[i];
		count++;
	  }
	}
no_s=count;
}

int main() {
	char choice;
	CS_student cric,bm,union1,intrst,diff,complmt;
	cout<<"\nEnter total no. of CS students:";
	cin>>CS_student::total_s;
	cout<<"\nEnter details of students playing cricket:";
	cric.getdata();
	cout<<"\nEnter details of students playing badminton";
	bm.getdata();
	do
	{
	cout<<"\nSelect the option from list given below";
	cout<<"\n1)Students playing either cricket or badminton or both:type 'u'";
	cout<<"\n2)Students playing both cricket and badminton:type 'i'";
	cout<<"\n3)Students playing only cricket:type 'c'";
	cout<<"\n4)Students playing only badminton:type 'b'";
	cout<<"\n5)No. of students who play neither cricket nor badminton:type 'n'";
	cout<<"\n6)Exit:type e";
	cout<<"Enter your choice:";
	cin>>choice;
	  switch(choice)
	  {
	  case 'u':     {
		              union1.set_uni(cric,bm);
                      cout<<"\nStudents playing either cricket or badminton or both"<<endl;
	                  union1.display();
	                  break;
	                }

	  case 'i':     {
		            intrst.set_intrst(cric,bm);
	                cout<<"\nStudents playing both cricket and badminton"<<endl;
	                intrst.display();
	                break;
	                }

	  case 'c':     {
		            diff.set_diff(cric,bm);
	                cout<<"\nStudents playing only cricket"<<endl;
	                diff.display();
	                break;
	                }

	  case 'b':     {
	                diff.set_diff(bm,cric);
	                cout<<"\n Students playing only badminton";
	                diff.display();
	                break;
	                }

	  case 'n':     {
		            complmt.set_complmt(union1.no_s);
	                cout<<"\nNo. of students who play neither cricket nor badminton:"<<complmt.no_s<<endl;
	                break;
	                }
      case 'e':     break;
	  default:      {
		            cout<<"\nEnter valid choice.";
	                }
	  }
	}while(choice!='e');
	return 0;
}
