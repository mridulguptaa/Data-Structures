#include<bits/stdc++.h>
using namespace std;

bool check(int ar[],int n,int cumar[],int pages,int studs)
{
    int student=1,curpage=0;

    for(int i=0;i<n;i++)
    {
        if(curpage+ar[i]>pages)
        {
            curpage=ar[i];
            student++;
            if(student>studs)
                return false;
        }
        else curpage+=ar[i];
    }
    return true;

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,studs,end,start,mid,temp_studs,first_true;
        cin>>n>>studs;
        int ar[n],cumar[n];

        for(int i=0;i<n;i++)
            cin>>ar[i];

        cumar[0]=ar[0];
        for(int i=1;i<n;i++)        //cummulative array formed
            cumar[i]=cumar[i-1]+ar[i];


        start=0;
        end=cumar[n-1];
        do
        {
            mid=(end+start)/2;      //mid=pages jo max read

            if(check(ar,n,cumar,mid,studs))
            {
                end=mid-1;
                first_true=mid;
            }
          if(!check(ar,n,cumar,mid,studs))
              start=mid+1;

        }while(start<=end);

    cout<<first_true<<endl;
    }
    return 0;
}
