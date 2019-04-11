#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int k,n,i,j,z,temp,m,zzz;
    cin>>k>>n;
    long long int *ptr=new long long int[k];
    for(i=0;i<k;i++)
        ptr[i]=0;

    long long int**ar=new long long int*[k];
    for(i=0;i<k;i++)
        ar[i]=new long long int[n+1];
    for(i=0;i<k;i++)
        {for(j=0;j<n;j++)
            cin>>ar[i][j];
         ar[i][j]=INT_MAX;
        }
    priority_queue<long long int,vector<long long int>,greater<long long int>>QP; //contains temporary k elements, one from each array
    queue<long long int>Q;    //contains final sorted array

    for(z=0;z<k;z++)
    {
        QP.push(ar[z][0]);
    }
    for(long long int pp=k+1;pp<=k*n+k;pp++)    //itni bar karna hai ab
    {
        long long int index;
        temp=QP.top();
        //cout<<temp<<" ";

        Q.push(temp);
        QP.pop();
        for(m=0;m<k;m++)
            if(ar[m][ptr[m]]==temp)
            {
                index=m;
                break;
            }
        ptr[index]++;
        QP.push(ar[index][ptr[index]]);
    }

    //lets print our final answer
    while(!Q.empty())
    {
        long long int o=Q.front();

        cout<<o<<" ";
        Q.pop();
    }
    return 0;
}
