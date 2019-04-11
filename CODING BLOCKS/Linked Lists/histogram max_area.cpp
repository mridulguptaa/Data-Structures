#include<bits/stdc++.h>
using namespace std;

long long int findmax(long long int ar[],long long int n)
{
    stack<long long int>s;
    long long int maxarea=0,i=0;
    while(i<n)
    {
        if(ar[i]>=ar[s.top()] ||s.size()==0)
        {
            s.push(i++);
            //cout<<s.top()<<" "<<ar[s.top()]<<" test"<<endl;
        }
        else
        {
            if(s.size()==1)
             {
                 maxarea=max(maxarea,ar[s.top()]*(i));
                s.pop();
                //s.push(i);
             }
             else

              {
                long long int temp=s.top();
                s.pop();
                if(s.size()!=0)
                    maxarea=max(maxarea,ar[temp]*(i-temp-1));
                else maxarea=max(maxarea,ar[temp]*(i-1));
             }
        }
    }
    while(s.size()!=0)
        {
            long long int temp=s.top();
            s.pop();
            maxarea=max(maxarea,ar[temp]*(i-temp));
        }
    return maxarea;
}
int main()
{
    long long int n;
    cin>>n;
    long long int ar[n];
    for(long long int i=0;i<n;i++)
        cin>>ar[i];
    cout<<findmax(ar,n);

    return 0;
}
