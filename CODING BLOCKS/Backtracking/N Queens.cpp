#include<bits/stdc++.h>
using namespace std;
int countt=0;

bool checkplace(int ar[][11],int n,int row,int col)
{
    for(int i=0;i<col;i++)     //checking that row
        if(ar[row][i]==1)
            return false;
    for(int j=0;j<row;j++)      //checking that column
        if(ar[j][col]==1)
            return false;
    for(int i=0;i<n;i++)         //checking for diagonals
        for(int j=0;j<n;j++)
            if((j-i)==(col-row) || (i+j)==(row+col))
                if(ar[i][j]==1)
                    return false;
    return true;

}


bool placequeens(int ar[][11],int n,int qleft)
{
    if(qleft==0)    //base case
    {
        countt++;
        cout<<endl<<endl;
        for(int z=0;z<n;z++)
           {
            for(int zz=0;zz<n;zz++)
                cout<<ar[z][zz];
           cout<<endl;
           }
        return false;
    }

    for(int i=0;i<n;i++)                 // i denotes column,
        if(checkplace(ar,n,n-qleft,i))     //rakh skte ho?
        {
            ar[n-qleft][i]=1;            // size-qleft will be row
            if(!placequeens(ar,n,qleft-1));   // recursive call
            {
                ar[n-qleft][i]=0;        //backtrack
            }
        }

    return false;

}

int main()
{
    int ar[11][11];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ar[i][j]=0;

    placequeens(ar,n,n);
    cout<<"Total ways= "<<countt<<endl;
    return 0;
}
