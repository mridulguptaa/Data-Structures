#include<bits/stdc++.h>
using namespace std;

bool check(int ar[][9],int size,int k,int m,int n)
{
   if(m!=size &&n!=size)
   {

    for(int i=0;i<size;i++)     //row mei check
        if(ar[m][i]==k)
            return false;
    for(int i=0;i<size;i++)    //column mei check
        if(ar[i][n]==k)
            return false;
    for(int i=m-m%3;i<m-m%3+3;i++)  //particular box check
        for(int j=n-n%3;j<n-n%3+3;j++)
            if(ar[i][j]==k)
                return false;
    return true;
   }
   return false;
}

bool solvekaro(int ar[][9],int size,int m,int n)        //m for row, n for col
{
    //base case
    if(ar[size-1][size-1]!=0 && m>=size-1 && n>=size-1)
    {
        for(int p=0;p<size;p++)
        {
            for(int pp=0;pp<size;pp++)
                cout<<ar[p][pp]<<" ";
            cout<<endl;
        }
        return true;
    }
    //recursive
    if(ar[m][n]>0)
        {if(n<size-1)
            solvekaro(ar,size,m,n+1);
         else solvekaro(ar,size,m+1,0);
        }
    else
    {
        for(int k=1;k<=9;k++)
            if(check(ar,size,k,m,n))
            {
              ar[m][n]=k;
              if(n<size-1)
                {if(!solvekaro(ar,size,m,n+1))
                    ar[m][n]=0;     //backtrack
                }
              else if(!solvekaro(ar,size,m+1,0))
                        ar[m][n]=0;     //backtrack
            }
    }
    return false;
}

int main()
{
    int size,ar[9][9],i,j;
    cin>>size;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            cin>>ar[i][j];
    solvekaro(ar,size,0,0);

    return 0;
}
