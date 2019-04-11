#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node
{
public:
    string key;
    T value;
    node<T>*next;
    node(string key,T value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class hashtable
{
    node<T>**table;
    int tablesize;
    int currentsize;

    void rehash()
    {
        node<T>**oldtable=table;
        int oldtablesize=tablesize;
        table=new node<T>*[2*oldtablesize];
        tablesize=2*oldtablesize;
        int currentsize=0;
        for(int i=0;i<tablesize;i++)
            table[i]=NULL;

        for(int i=0;i<oldtablesize;i++)
        {
            node<T>*temp=oldtable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL)
                delete oldtable[i];
        }
        delete[]oldtable;

    }
public:
    hashtable(int defaultsize=7)
    {
        tablesize=defaultsize;
        table=new node<T>*[tablesize];
        currentsize=0;
        for(int i=0;i<tablesize;i++)
            table[i]=NULL;
    }
    int hashfunction(string key)
    {
		int L = key.length();
		int p = 1;
		int ans = 0;

		for(int i=0;i<L;i++){
			ans = (ans + key[L-i-1]*p)%tablesize;
			p = (p*37)%tablesize;
		}
		return ans;
	}

    void insert(string key,T value)
    {
        int index=hashfunction(key);
        node<T>*n=new node<T>(key,value);
        n->next=table[index];
        table[index]=n;
        currentsize++;

        float loadfactor=currentsize/tablesize;
        if(loadfactor>0.7)
            rehash();
    }

    T* search(string key)
    {
        int index=hashfunction(key);
        node<T>*temp=table[index];
        while(temp!=NULL)
        {
            if(temp->key==key)
                return&temp->value;
        }
        return NULL;

    }

    void print()
    {
        for(int i=0;i<tablesize;i++)
        {
            node<T>*temp=table[i];
            cout<<temp->key<<"--> ";
            while(temp!=NULL)
            {
                cout<<temp->value<<" ,";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

};
int main(){

	hashtable<int>h(7);
	/*h.insert("Mango",120);
	h.insert("Guava",30);
	h.insert("Apple",180);
	h.insert("Pineapple",75);
	h.insert("Litchi",110);
    h.print();
	//int *price = h.search("Guava");
	//cout<<(*price);


	//cout<<h["Kiwi"]<<endl;

*/
	h.print();

	return 0;
}
