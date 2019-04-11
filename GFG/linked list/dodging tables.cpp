#include<iostream>
#include<ctype.h>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>
#include<cstdio.>
#include<math.h>
#include<time.h>
using namespace std;

void multi_manual()
{
    int x,y,ans,k=0;
    cout<<"enter number 1 ";
    cin>>x;
    cout<<"enter number 2 ";
    cin>>y;

    do
    {
    cout<<"enter product" ;
    cin>>ans;
    if(ans==x*y)
        {cout<<"Shabaash "<<endl;
        k++;}
    else
        cout<<" Dubara soch "<<endl;

    }while(k==0);

}
void multi_auto()
{
  int n,u,l,i,answ,k=0,x,y,num;
  cout<<"enter upper limit"<<endl;
  cin>>u;
  cout<<"lower minit"<<endl;
  cin>>l;
  cout<<"kitni bar khelega..?"<<endl;
  cin>>num;
  for(i=0;i<num;i++)
  {


  srand(time(NULL));
  x=rand()%(u-l) + l;
  y=rand()%(u-l) + l;
  do
{
  cout<<x<<"*"<<y<<"=  "<<endl;
  cin>>answ;
  if(answ==x*y)
    {cout<<"Correct"<<endl;
     k++;}

  else cout<<"WRONG ";
}  while(k==0);
  }
}

void sqr_auto()
{
 int u,l,ans,x,k=0,num;
  cout<<"enter upper and lower limits "<<endl;
  cin>>u>>l;
  cout<<"kitni bar khelega?";
  cin>>num;
  for(int i=0;i<num;i++)
  {x=rand()% (u-l) + l;
  do
  {


  cout<<x<<"*"<<x<<"=";
  cin>>ans;
  if(ans==x*x)
   {cout<<"correct"<<endl;
     k++;}
  else cout<<"wrong";
  }while(k==0);

}}
int main()
{   int choice;
    char continuee;
    do
    {

 cout<<"press 1 for MULTIPLICATION (manual input)"<<endl;
 cout<<"press 2 for MULTIPLLICATION (automatic) "<<endl;
 cout<<"press 3 for SQUARE (automatic) "<<endl;
 cin>>choice;
  switch(choice)
  { case 1: multi_manual();
    case 2: multi_auto();
    case 3: sqr_auto();

  }

  cout<<"wanna continue..(y/n)"<<endl;
  cin>>continuee;
    }while(continuee=='y');

}
