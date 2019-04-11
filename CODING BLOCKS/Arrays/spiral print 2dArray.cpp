#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int row,col;
    cin>>col>>row;
    int ar[row][col],i,j,k=0,terminate;     //terminate is kitne baar circular type mei loop chalana hai
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            cin>>ar[row][col];

   terminate=min(row,col)/2;
        if(min(row,col)%2==1)
            terminate++;

    while(k<terminate)
    {
        for(i=k;i<col-k;i++)
            cout<<ar[k][i]<<" ";
        for(i=k+1;i<row-k;i++)
            cout<<ar[i][col-1-k]<<" ";
        for(i=col-2-k;i>=k;i--)
            cout<<ar[row-1-k][i]<<" ";
        for(i=row-2-k;i>k;i--)
            cout<<ar[i][k];

        k++;
    }

    return 0;
}
