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
         int ar[n],cs=0,totalsum=0,minsum=0,i;
         for(i=0;i<n;i++)
            {cin>>ar[i];
             totalsum+=ar[i];
            }

        for(i=0;i<n;i++)
        {
            cs+=ar[i];
            minsum=min(cs,minsum);
            if(cs>0)
            {
                cs=0;
            }
        }
        cout<<totalsum-minsum<<endl;




     }

     return 0;
 }
