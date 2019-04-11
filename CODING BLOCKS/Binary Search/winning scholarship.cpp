#include<bits/stdc++.h>
using namespace std;

bool check(int students,int coupuns,int mid,int x,int y)
{
    int studsget,studsgiving=0;
    studsget=coupuns/x;        //itno ko mil gyii
    coupuns%=x;     //coupuns left
    while((studsget+studsgiving)!=students)
    {
        studsgiving+=((x-coupuns)/y)+1;
        coupuns+=y*(((x-coupuns)/y)+1);
        studsget+=coupuns/x;
        coupuns%=x;
    }

    if(studsget>=mid)
        return true;
    else return false;

}

int main()
{
        int students,coupuns,x,y,end,start=0,mid,last_true;
        cin>>students>>coupuns>>x>>y;
        end=students;

        do
        {
            mid=(end+start)/2;      //mid=Max studs getting scholarship

            if(!check(students,coupuns,mid,x,y))
                end=mid-1;
            if(check(students,coupuns,mid,x,y))
              {
                  start=mid+1;
                  last_true=mid;
              }

        }while(start<=end);

    cout<<last_true<<endl;
    return 0;
}
