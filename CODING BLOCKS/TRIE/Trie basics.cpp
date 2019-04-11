#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    bool terminal;
    map<char,node*>alphabet;
    node *next;

    friend class trie;
};

class trie
{
    node*root;
public:
    friend class node;

    trie()
    {
        root=new node;
    }

    void addword(string w)
    {
        node*temp=root;
        for(long long int i=0;w[i]!=NULL;i++)
        {
            if(!temp->alphabet[w[i]])
            {
                node*n=new node();
                temp->alphabet[w[i]]=n;
                temp=n;
            }
            else temp=temp->alphabet[w[i]];
        }
        temp->terminal=true;
    }
    void print(char ar[],node*temp,long long int k,string w)
    {
        if(temp->terminal)
            cout<<w<<ar<<endl;
        map<char,node*>::iterator it=temp->alphabet.begin();
        map<char,node*>::iterator itend=temp->alphabet.end();
        for(;it!=itend;++it)
        {
            ar[k]=it->first;
            ar[k+1]=NULL;
            print(ar,temp->alphabet[it->first],k+1,w);
            ar[k]='\0';
        }
    }

    void Search(string w)
    {
        node*temp=root;
        for(long long int i=0;w[i]!=NULL;i++)
        {
            if(!temp->alphabet[w[i]])   //not present
            {
                cout<<"No suggestions"<<endl;
                return;
            }
            else
            {
                temp=temp->alphabet[w[i]];
            }
        }
        //Now we will print
        char ar[200000];
        ar[0]=NULL;
        long long int k=0;
        print(ar,temp,k,w);
    }
};


int main()
{
    trie t;
    long long int n;
    cin>>n;
    while(n--)
    {
        string a;
        cin>>a;
        t.addword(a);
    }
    long long int q;
    cin>>q;
    while(q--)
    {
        string b;
        cin>>b;
        t.Search(b);
    }

    return 0;
}
