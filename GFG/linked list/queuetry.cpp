#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
}*front=NULL,*end=NULL,*ptr,*temp;

void push()
{
    ptr=new node;
    if(front==NULL)
        {front=end=ptr;
         cout<<"\nenter roll";
         cin>>ptr->roll;
         return;
        }
    cout<<"\nenter roll";
    cin>>ptr->roll;
    end->next=ptr;
    end=ptr;

}

void display()
{
    ptr=front;
    while(ptr!=NULL)
    {
        cout<<ptr->roll<<"->";
        ptr=ptr->next;
    }
}

void delette()
{

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
          cout<<" Continue? \n ";
          cin>>c;
      }while(c=='y');
  }
