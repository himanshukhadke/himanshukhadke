//============================================================================
// Name        : string_fun.cpp
// Author      : AjinkyaM(SECOA162)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int len(char* arr )//to calculate length of string
{
	int i;
	for (i=0;arr[i]!='\0';i++);
	return i;
}
void cpy(char* a,char* b)//to perform string copy
{
	int i;
	for (i=0;i<len(b);i++)
	 {
	 	a[i]=b[i];
	 }	
	for (i=len(b);a[i]!='\0';i++)
          	a[i]='\0';
}
void cat(char* a,char* b)//to concatenate two strings
{
	int i,x,j;
	x=len(a);
	for(int i=x,j=0;b[j]!='\0';i++,j++)
		a[i]=b[j];
}

void rev(char* str,char* rev)//to reverse a string
{
	int i,j=0;
	j=len(str)-1;
	for (i=0 ; j>=0 ; i++,j--)
		rev[i]=str[j];
}
void special(char* str)//to display string without special chars
{
	int i,y;
	for (i=0;str[i]!='\0';i++)
	{
		y=str[i];
		if ((y>=65 && y<=90) || (y>=97 && y<=122) )
			cout<<str[i];//displaying result
	}
}

void str_cmp(char* s1,char* s2)
  {
    int i;
    int a=0;
    int s1_length=len(s1);
    int s2_length=len(s2);
    
      for(i=0; s1[i]!='\0'||s2[i]!='\0' ;i++)
      {
        a=a+s1[i]-s2[i];
      }
      if(a>0)
      {
       cout<<"\n"<<s1<<" is greater than "<<s2<<endl;
      } 
      else if(a==0)
      {
       cout<<"\n"<<s1<<" is equal to "<<s2<<endl;
      }
      else
      {
       cout<<"\n"<<s2<<" is greater than "<<s1<<endl;
      }
  }
  

int main()
{
	char a[20];
	char b[20];
	char c[20];
	int x,choice=0;
	cout<<"\n Enter First String :";
	cin.getline(a,20);//read first string
	cout<<"\n Enter Second String:";
	cin.getline(b,20);//read second string
	do
	{ //menu choices
	 cout<<"\n\n Menu: ";
	 cout<<"\n 1) String Length";
	 cout<<"\n 2) String Copy ";
	 cout<<"\n 3) String concatenate";
	 cout<<"\n 4) Compare";
	 cout<<"\n 5) Reverse ";
	 cout<<"\n 6) Display string without Special Characters";
	 cout<<"\n 7) Exit";
	 cout<<"\n Enter your choice:";
	 cin>>choice;
	switch (choice)//pass choice in switch case to execute particular case
	{
		case 1:{
			x=len(a);
			cout<<"\n Length of first string is "<<x;
			x=len(b);
			cout<<"\n Length of second string is:"<<x;
			break;
                       }
		case 2:{
			cout<<"\n Copy from \n\t i) First -> Second \n\t ii) Second -> First";
			cout<<"\n Enter your choice:";
			cin>>x;
			if (x==1)
			{
			        cout<<"\nBefore string copy ";
			        cout<<"First = "<<a<<" \t Second ="<<b;
				cpy(b,a);
				cout<<"\n Succesfullly copied ";
				cout<<"First = "<<a<<" \t Second ="<<b;//displaying result
			}
			else if (x==2)
			{    
			        cout<<"\nBefore string copy ";
			        cout<<"First = "<<a<<" \t Second ="<<b;
				cpy(a,b);
				cout<<"\n Succesfullly copied ";
				cout<<"First = "<<a<<" \t Second ="<<b;//displaying result
			}
			else cout<<"\n!! Invalid!!";
			break;
                       }
		case 3:{
			cout<<"\n Concatenated from \n\t i) First -> Second \n\t ii) Second -> First";
			cin>>x;
			if (x==1)
			{
			        cout<<"\nBefore concatenation ";
			        cout<<"First = "<<a<<" \t Second ="<<b;
				cat(a,b);
				cout<<"\n Succesfullly concatenated ";
				cout<<"First = "<<a<<" \t Second ="<<b;//displaying result
			}
			else if (x==2)
			{       
			        cout<<"\nBefore concatenation ";
			        cout<<"First = "<<a<<" \t Second ="<<b;
				cat(b,a);
				cout<<"\n Succesfullly concatenated ";
				cout<<"First = "<<a<<" \t Second ="<<b;//displaying result
			}
			else cout<<"\n!! Invalid!!";
			break;
		       }	
                case 4:{ 
		        str_cmp(a,b);
		        break;
		       } 	
		case 5:{
			cout<<"\n You want to Reverse which string ? First (1) or Second (2)";
			cin>>x;
			if (x==1)
			{
				rev(a,c);
				cout<<"\n Succesfullly concatenated ";
				cout<<"Reversed string is "<<c;//displaying result
			}
			else if (x==2)
			{
				rev(b,c);
				cout<<"\n Succesfullly Reversed ";
				cout<<"Reversed String is "<<c;//displaying result
			}
			else cout<<"\n!! Invalid!!";
			break;
		       }	
		case 6:{
			cout<<"\non which string you want to perform ? First (1) or Second (2)";
			cin>>x;

			if (x==1)
				special(a);
			else if (x==2)
				special(b);
			else cout<<"\n !!Invalid!!";
			break;
                       }		
		case 8:{ 
		         cout<<"\nExiting menu...";
		        break;
		       }         
	       default:{
			 cout<<"\n Invalid choice Enter a valid choice";
	               }
            }
	}while (choice!=8);
	return 0;
}
