//CAN TAKE A ELEMENT MORE THAN ONCE
#include<bits/stdc++.h>
using namespace std;

int KNAPSACK(int n,int capmax,int weight[],int val[])
{
    int DP[capmax+1][n+1]={0};

    for(int i=0;i<=capmax;i++)      //capacity
        for(int j=0;j<=n;j++)       //no.of items
        {

            if(i==0||j==0)
                DP[i][j]=0;
            else
            {
             int inc=0,exc=0;
             if(weight[j-1]<=i)
                inc=val[j-1]+DP[i-weight[j-1]] [j];
             exc=DP[i][j-1];

             DP[i][j]=max(inc,exc);
            }

        }
    return DP[capmax][n];
}

int main()
{
    int n,capmax;
    cin>>n>>capmax;
    int weight[n],val[n];
    for(int i=0;i<n;i++)
        cin>>weight[i];

    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<KNAPSACK(n,capmax,weight,val);

    return 0;

}
