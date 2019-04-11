#include<bits/stdc++.h>
using namespace std;

bool palindrome(int num,int&copy)
{
    if(num/10==0)
        return((num==copy%10));
    if(num!=0)
        if(!palindrome(num/10,copy))
            return false;

    copy/=10;
    return(num%10==copy%10);


}

int main()
{
    int copy,num;
    cin>>num;
    copy=num;
    if(palindrome(num,copy)==false)
        cout<<"NO";
    else cout<<"yes";


}
