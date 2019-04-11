#include<iostream>
#include<math.h>
using namespace std;
 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         int ar[n],cs=0,maxsum=0,i;
         for(i=0;i<n;i++)
            cin>>ar[i];

        for(i=0;i<n;i++)
        {
            cs+=ar[i];
            maxsum=max(cs,maxsum);
            if(cs<0)
            {
                cs=0;
            }
        }
        cout<<maxsum<<endl;




     }

     return 0;
 }
