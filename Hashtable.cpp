#include <iostream>
#include <string>
using namespace std;
template<typename T>
class node{
    public:
    string key;
    T value;
    node <T>*next;
    node(string k,T v){
        key=k;
        value=v;
    }
};
template<typename T>
class hashtable{
    
    node<T>**table;
    int currsize;
    int tablesize;
    int hashfunc(string key){
        int idx=0;
        int p=1;
        for(int i=0;i<key.length();i++){
            idx=idx+(key[i]*p)%tablesize;
            idx=idx%tablesize;
            p=(p*27)%tablesize; //here 27 is the total letters +1 space
        }
        return idx;
    }
    void rehash(){
        node<T>**oldtable=table;
        int oldtablesize=tablesize;
        tablesize=2*tablesize;
        table= new node<T>* [tablesize];
        for(int i=0;i<tablesize;i++){
            table[i]=NULL;
        }
        currsize=0;
        //now shift the elements from old table to the new table;
        for(int i=0;i<oldtablesize;i++){
            node<T>*temp=oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
                currsize++;
            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }
    public:
    hashtable(int ts=7){  //instead of 7 take a prime upto 1003
        tablesize=ts;
        table=new node<T>*[tablesize]; //creates and array of node pointers
        currsize=0;
        for(int i=0;i<tablesize;i++){
            table[i]=NULL;
        }
    }
    void insert(string key,T val){  //insertion at head3
        int idx=hashfunc(key);
        node<T>*n=new node<T>(key,val);
        n->next=table[idx];
        table[idx]=n;
        currsize++;
        //if the load factor ie the currsize/ tablesize exceeds 0.75 we can rehash it
        float loadfactor=(currsize/(1.0 *tablesize));
        if(loadfactor>0.75){
            rehash();  //rehashing is done to avoid the creation of huge linked list
        }
    }
    void print(){
        for(int i=0;i<tablesize;i++){
            cout<<"Bucket "<<i<<"->";
            node<T>*temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<" "<<temp->value;
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string key){
        int idx=hashfunc(key);
        node<T>*temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp=temp->next;
        }
        return NULL;
    }
    /* doubt
    void erase(string key){
        int idx=hashfunc(key);
        node<T>*temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                node<T>*t1=temp->next;
                node<T>*t2=table[idx];
                while(t2->next!=temp){
                    t2=t2->next;
                }
                
                t2=t1;
                break;
            }
            temp=temp->next;
        }
    }*/
    //this operation overloading can be used for insertion update and output as well..here it updates the value of garbage to the given value
    T& operator[](string key){  //return type of the operator is an address hence it is t&
        T*f=search(key);
        if(f==NULL){
            T garbage;
            insert(key,garbage);
            f=search(key);
        }
        return *f;
    }
};
int main()
{
    hashtable <int> menu;
    menu.insert("burger", 50);
    menu.insert("pizza",120);
    menu.insert("chocolate",60);
    menu.insert("oreo icecream",60);
    menu.insert("momos",60);
    menu.insert("gola",60);
    cout<<*menu.search("chocolate")<<endl;
    //menu.erase("gola");
    menu["sanwitch"]=60;
    
    menu.print();

    return 0;
}
