#include<bits/stdc++.h>
using namespace std;

 struct node
 {
     int roll;
     node *next;
     node *nextback;
 }*ptr=NULL,*frontt=NULL,*back=NULL,*temp=NULL,*store=NULL;

void push()
  {
      temp=ptr;
      ptr=new node;
      ptr->next=NULL;

      cout<<" Enter roll";
      cin>>ptr->roll;

      if(frontt==NULL)
      {
          ptr->nextback=NULL;
          frontt=back=ptr;
          return;
      }
      temp->next=ptr;
      ptr->nextback=temp;

      back=ptr;
  }
   void display()
  {
      ptr=frontt;
      if(ptr==NULL)
      {
          cout<<" stack underflow";
          return;
      }
      ptr=frontt;
      while(ptr!=NULL)
      {
          cout<<ptr->roll<<"-> ";
          ptr=ptr->next;
      }

  }

  void delette(int n)
 {
     int i;
     ptr=frontt;
     for(i=1;i<n;i++)
        ptr=ptr->next;
     temp=ptr->next;
     ptr=ptr->nextback;
     ptr->next=temp;
     ptr=ptr->next;
     delete ptr;
 }
   int main()
  {
      int choice;
      char c;
      int n;
      do
      {
          cout<<" 1 Push \n2.display \n3.delete";
          cin>>choice;
          switch(choice)
          {
              case 1: push();
              break;
              case 2: display();
              break;
              case 3:
              cout<<"\n enter index";
              cin>>n;
              delette(n);
          }
          cout<<" /nContinue? ";
          cin>>c;
      }while(c=='y');

  }
