#include<bits/stdc++.h>
using namespace std;

 struct node
 {
     int roll;
     node *next;
 }*ptr=NULL,*frontt=NULL,*temp=NULL;

  void push()
  {
      ptr=new node;
      cout<<" Enter roll";
      cin>>ptr->roll;
      if(frontt==NULL)
      {
          ptr->next=NULL;
          frontt=ptr;
          return;
      }
      temp=frontt;
      ptr->next=temp;
      frontt=ptr;

  }
   void display()
  {
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

  void delette()
 {
     ptr=frontt;
     frontt=frontt->next;
     delete ptr;
 }
   int main()
  {
      int choice;
      char c;
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
              case 3: delette();
          }
          cout<<" Continue? ";
          cin>>c;
      }while(c=='y');

  }
