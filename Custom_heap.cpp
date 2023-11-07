#include <iostream>
#include <queue>
#include <string>
using namespace std;
//to define a comparator function and custom class for priority queue
class person{
    public:
    string name;
    int age;
    person(string n,int a){
        name=n;
        age=a;
    }
};
class personcomp{
    public:
    //here function overloading is done for personalised class
    bool operator()(person a,person b){
        return a.age<b.age;
    }
};
int main()
{
    int n;
    cin>>n;
    priority_queue<person,vector<person>,personcomp> p;
    for(int i=0;i<n;i++){
        int age;
        string name;
        cin>>name>>age;
        person per(name,age);
        p.push(per);
    }
    for(int i=0;i<n;i++){
        person pe=p.top();
        cout<<pe.name<<" "<<pe.age<<endl;
        p.pop();
    }

    return 0;
}

