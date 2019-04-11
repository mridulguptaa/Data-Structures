#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    stack<int>pos;
    stack<int>height;
    pos.push(0);
    height.push(ar[0]);
    int maximum=INT_MIN;
    int curpos=1;
    while(curpos<n)
    {
        cout<<curpos<<" ";
        if(ar[curpos]>=height.top() or height.size()==0)
        {
            pos.push(curpos);
            height.push(ar[curpos]);
        }
        else
        {
            while(height.top()>ar[curpos] && !height.empty())
            {
                cout<<"elements no. in height "<<height.size()<<endl;
                maximum=max(maximum,height.top()*(curpos-pos.top()));
                height.pop();
                pos.pop();
            }
            height.push(ar[curpos]);
            pos.push(curpos);
        }
        curpos++;
    }
    cout<<maximum;

    return 0;
}
