#include<iostream>
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,count=1,temp=0,ans=0;
        cin>>n;
        int *ar=new int[n],*cumar=new int[n];
        for(i=0;i<n;i++)
            cin>>ar[i];

        cumar[0]=ar[0];
        for(i=1;i<n;i++)
            cumar[i]=ar[i]+cumar[i-1];

        for(i=0;i<n;i++)
            cumar[i]%=n;



        for(i=0;i<n;i++)
            if(cumar[i]!=-32767)
        {
            count=1;
            temp=cumar[i];
            for(int j=i+1;j<n;j++)
                if(cumar[j]==temp)
                {
                    count++;
                    cumar[j]=-32767;
                }
            if(count>1)
                ans+=factorial(count)/factorial(count-2)/2;
            if(temp==0)
                ans+=count;
        }

        cout<<ans<<endl;
        delete []ar;
        delete []cumar;

    }


    return 0;
}
