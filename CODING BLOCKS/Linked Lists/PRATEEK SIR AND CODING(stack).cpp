#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    stack<int>s;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==2)
        {
            int p;
            cin>>p;
            s.push(p);
        }
        if(n==1)
        {
            if(s.empty())
                cout<<"No Code"<<endl;
            else
            {
                int temp=s.top();
                s.pop();
                cout<<temp<<endl;
            }
        }
    }

    return 0;
}
