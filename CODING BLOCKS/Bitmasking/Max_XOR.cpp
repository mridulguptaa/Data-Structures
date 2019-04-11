#include<iostream>
using namespace std;

int main()
{
    int a,b,x,y,temp=0;
    cin>>x>>y;
    if(x<y)
    {
        for(a=x;a<=y;a++)
            for(b=y;b>x;b--)
            {
                if((a^b)>temp)
                    temp=a^b;
            }
    }

    else
        {
          for(a=y;a<=x;a++)
            for(b=x;b>y;b--)
            {
                if((a^b)>temp)
                    temp=a^b;
            }
        }
    cout<<temp;
    return 0;
}
