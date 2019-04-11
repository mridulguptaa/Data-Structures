#include<bits/stdc++.h>
using namespace std;

bool check(int ar[],int n,int maxtime,int painters)
{
    int current_time=0,temppainter=1;

    for(int i=0;i<n;i++)
    {
        if(current_time+ar[i]>maxtime)
        {
            current_time=ar[i];
            temppainter++;
            if(temppainter>painters)
                return false;
            if(current_time>maxtime)
                return false;
        }
        else current_time+=ar[i];
    }
    return true;

}


int main()
{
        int n,painters,end=0,start=0,mid,first_true;
        cin>>painters>>n;      //n is no.of Boards
        int ar[n];

        for(int i=0;i<n;i++)
            {
                cin>>ar[i];
                end+=ar[i];
            }

        do
        {
            mid=(end+start)/2;      //mid=Max time required

            if(check(ar,n,mid,painters))
            {
                end=mid-1;
                first_true=mid;
            }
          if(!check(ar,n,mid,painters))
              start=mid+1;

        }while(start<=end);

    cout<<first_true<<endl;

    return 0;
}
