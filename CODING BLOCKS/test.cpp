#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float kloc,eaf=1;
    cout<<"\tEnter KLOC: ";
    cin>>kloc;
    float attr[15][5]={{0.75,0.88,1.00,1.15,1.40},
                        {-1,0.94,1.00,1.08,1.16},
                        {0.70,0.85,1.00,1.15,1.30},
                        {-1,-1,1,1.11,1.30},
                        {-1,-1,1.0,1.06,1.21},
                        {-1,.87,1,1.15,1.30},
                        {-1,0.94,1,1.07,1.15},
                        {1.46,1.19,1,0.86,.71},
                        {1.29,1.13,1,0.91,.82},
                        {1.42,1.17,1,.86,.70},
                        {1.21,1.1,1,.9,-1},
                        {1.14,1.07,1,.95,-1},
                        {1.24,1.1,1,.91,.82},
                        {1.24,1.1,1,.91,.83},
                        {1.23,1.08,1.00,1.04,1.1} };
    float a,b,c,d;
    int cd;
    c=2.5;
    cout<<"\n\tEnter the 15 cost driver attributes:(0-4) ";
    for(int i=0; i<15; i++)
    {
        cin>>cd;
        while(cd<0 || cd>4)
        {
            cout<<"\n\tInvalid choice!\n\tEnter the value again: ";
            cin>>cd;
        }
        if(attr[i][cd]!=-1)
        eaf*=attr[i][cd];
    }
    cout<<"\n\tEaf: "<<eaf;
    if(kloc<=50)
    {
        cout<<"\n\tOrganic model is chosen.";
        a=3.2;
        b=1.05;
        d=0.38;
    }
    else if(kloc<=300)
    {
        cout<<"\n\tSemi detached model is chosen.";
        a=3.0;
        b=1.12;
        d=0.35;
    }
    else
    {
        cout<<"\n\tEmbedded model is chosen.";
        a=2.8;
        b=1.20;
        d=0.32;
    }
    int effort=a*pow(kloc,b)*eaf;
    cout<<"\n\tThe effort is: "<<effort<<" PM";
    cout<<"\n\tThe time to develop is:"<<c*pow(effort,d);
    return 0;
}
