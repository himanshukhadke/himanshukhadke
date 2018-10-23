//============================================================================
// Name        : assign3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
//

//accept,sparse represent,simple transpose,fast transpose,addition
#include <iostream>
using namespace std;

class Sparse
{
	int rows,col,nz;
	int matrix[5][4];
	int sparse_matrix[10][3];
	int sparse_matrix_st[10][3];
	int sparse_matrix_ft[10][3];
	int sparse_matrix_add[20][3];
public:
	void matrix_accept();
	void matrix_display();
	void sparse_display();
	void simple_transpose();
	void fast_transpose();
	void add(Sparse,Sparse);
};

void Sparse::matrix_accept()
{
 nz=0;
 cout<<"\nEnter matrix :";
 cout<<"\nEnter no. of rows(max5):";
 cin>>rows;
 cout<<"\nEnter no. of columns(max4):";
 cin>>col;
 for(int i=0;i<rows;i++)
  {
	 for(int j=0;j<col;j++)
	 {
		 cout<<"\nEnter element a["<<i<<"]["<<j<<"]:";
		 cin>>matrix[i][j];
		 if(matrix[i][j]!=0)
		 {
			 sparse_matrix[nz+1][0]=i;
			 sparse_matrix[nz+1][1]=j;
			 sparse_matrix[nz+1][2]=matrix[i][j];
			 nz++;
		 }
	 }
  }
}

void Sparse::matrix_display()
{
    cout<<"\nEntered matrix is:\n";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
       cout<<endl;
    }
}
void Sparse::sparse_display()
{
	sparse_matrix[0][0]=rows;
	sparse_matrix[0][1]=col;
	sparse_matrix[0][2]=nz;
	cout<<"\nSparse matrix is:\n";
	for(int i=0;i<=nz;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<sparse_matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Sparse::simple_transpose()
{   int count=1,temp;
	sparse_matrix_st[0][0]=col;
	sparse_matrix_st[0][1]=rows;
	sparse_matrix_st[0][2]=nz;
   for(int i=0;i<col;i++)
   {
	  for(int j=1;j<=nz;j++)
	  {
		if(sparse_matrix[j][1]==i)
		{
			sparse_matrix_st[count][0]=sparse_matrix[j][1];
			sparse_matrix_st[count][1]=sparse_matrix[j][0];
			sparse_matrix_st[count][2]=sparse_matrix[j][2];
			count++;
		}
	  }
   }

  cout<<"\nSparse matrix after simple transpose:\n";
   for(int i=0;i<=nz;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<sparse_matrix_st[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Sparse::fast_transpose()
{
	sparse_matrix_ft[0][0]=col;
	sparse_matrix_ft[0][1]=rows;
	sparse_matrix_ft[0][2]=nz;
    int terms[col],rpos[col];
	for(int i=0;i<col;i++)
	{
		terms[i]=0;
	}
	for(int i=1;i<=nz;i++)
	{
		terms[sparse_matrix[i][1]]++;
	}
	rpos[0]=1;
	for(int i=1;i<col;i++)
	{
		rpos[i]=rpos[i-1]+terms[i-1];
	}
	int j;
	for(int i=1;i<=nz;i++)
	{
		j=rpos[sparse_matrix[i][1]];
		rpos[sparse_matrix[i][1]]++;
		sparse_matrix_ft[j][0]=sparse_matrix[i][1];
		sparse_matrix_ft[j][1]=sparse_matrix[i][0];
		sparse_matrix_ft[j][2]=sparse_matrix[i][2];
	}
	cout<<"\nSparse Matrix by fast transpose:\n"<<endl;
	for(int i=0;i<=nz;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<sparse_matrix_ft[i][j]<<" ";
		}
		cout<<endl;
	}
}

 void Sparse::add(Sparse s1,Sparse s2)
{
    int i=1,j=1,k=1;
 if(s1.sparse_matrix[0][0]==s2.sparse_matrix[0][0] && s1.sparse_matrix[0][1]==s2.sparse_matrix[0][1])
 {
   sparse_matrix_add[0][0]=s1.sparse_matrix[0][0];
   sparse_matrix_add[0][1]=s1.sparse_matrix[0][1];
 while(i<=s1.sparse_matrix[0][2] && j<=s2.sparse_matrix[0][2])
 {
    if(s1.sparse_matrix[i][0]==s2.sparse_matrix[j][0])
   {
       if(s1.sparse_matrix[i][1]==s2.sparse_matrix[j][1])
       {
          sparse_matrix_add[k][0]=s1.sparse_matrix[i][0];
          sparse_matrix_add[k][1]=s1.sparse_matrix[i][1];
          sparse_matrix_add[k][2]=s1.sparse_matrix[i][2]+s2.sparse_matrix[j][2];
          i++; j++; k++;
       }
       else if(s1.sparse_matrix[i][1]>s2.sparse_matrix[j][1])
       {
          sparse_matrix_add[k][0]=s2.sparse_matrix[j][0];
          sparse_matrix_add[k][1]=s2.sparse_matrix[j][1];
          sparse_matrix_add[k][2]=s2.sparse_matrix[j][2];
          j++; k++;
       }
       else
       {
           sparse_matrix_add[k][0]=s1.sparse_matrix[i][0];
           sparse_matrix_add[k][1]=s1.sparse_matrix[i][1];
           sparse_matrix_add[k][2]=s1.sparse_matrix[i][2];
           i++; k++;
       }
   }
   else if(s1.sparse_matrix[i][0]>s2.sparse_matrix[j][0])
    {
      sparse_matrix_add[k][0]=s2.sparse_matrix[j][0];
      sparse_matrix_add[k][1]=s2.sparse_matrix[j][1];
      sparse_matrix_add[k][2]=s2.sparse_matrix[j][2];
      j++; k++;
    }
   else
   {
      sparse_matrix_add[k][0]=s1.sparse_matrix[i][0];
      sparse_matrix_add[k][1]=s1.sparse_matrix[i][1];
      sparse_matrix_add[k][2]=s1.sparse_matrix[i][2];
      i++; k++;
   }
 }
 while(i<=s1.sparse_matrix[0][2])
 {
    sparse_matrix_add[k][0]=s1.sparse_matrix [i][0];
    sparse_matrix_add[k][1]=s1.sparse_matrix[i][1];
    sparse_matrix_add[k][2]=s1.sparse_matrix[i][2];
    i++; k++;
 }
 while(j<=s2.sparse_matrix[0][2])
 {
  sparse_matrix_add[k][0]=s2.sparse_matrix[j][0];
  sparse_matrix_add[k][1]=s2.sparse_matrix[j][1];
  sparse_matrix_add[k][2]=s2.sparse_matrix[j][2];
  j++; k++;
 }
sparse_matrix_add[0][2]=k-1;
 cout<<"\nSparse matrix of addition result:\n";
   for(int i=0;i<=k-1;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<sparse_matrix_add[i][j]<<" ";
		}
		cout<<endl;
	}
 }
 else
 {
     cout<<"\nAddition not possible.";
 }
}

int main()
{
  int choice;
  do
  {
      cout<<"\n1.Simple transpose";
      cout<<"\n2.Fast transpose";
      cout<<"\n3.Addition of two sparse matrix";
      cout<<"\n4.Exit";
      cout<<"\nEnter your choice:";
      cin>>choice;
      switch(choice)
      {
          case 1:  {
                     Sparse sm1;
                     sm1.matrix_accept();
                     sm1.matrix_display();
                     sm1.sparse_display();
                     cout<<"Performing simple transpose:\n";
                     sm1.simple_transpose();
                     break;
                   }

          case 2:  {
                     Sparse sm1;
                     sm1.matrix_accept();
                     sm1.matrix_display();
                     sm1.sparse_display();
                     cout<<"\nAfter fast transpose:\n";
                     sm1.fast_transpose();
                     break;
                   }

          case 3:  {
                     cout<<"\nFor matrix 1:";
                     Sparse sm1;
                     sm1.matrix_accept();
                     cout<<"\nFor matrix 2:";
                     Sparse sm2;
                     sm2.matrix_accept();
                     Sparse sm3;
                     cout<<"\nSparse Matrix 1 is:";
                     sm1.sparse_display();
                     cout<<"\nSparse Matrix 2 is:";
                     sm2.sparse_display();
                     cout<<"\nAddition result Sparse Matrix is:";
                     sm3.add(sm1,sm2);
                     break;
                   }

           case 4: {
                     break;
                   }

         default:  {
                     cout<<"\nEnter valid choice.";
                   }
      }
  }while(choice!=4);
  return 0;
}
