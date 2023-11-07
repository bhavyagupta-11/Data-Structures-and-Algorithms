#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
class student{
    public:
    string firstname;
    string lastname;
    int roll;
    student(string f,string l,int m){
        firstname=f;
        lastname=l;
    roll=m;
    }
    bool operator==(const student &s) const{
        return roll==s.roll?true:false;
    }
};
class hashfunc{
    public:
    size_t operator()(const student &s) const{     //size_t is a data type for operator that returns length
        return s.firstname.length()+s.lastname.length();
    }
};
int main()
{
    unordered_map<student,int,hashfunc> s;
    student s1("a","b",199);
    s[s1]=100;
    cout<<s[s1];

    return 0;
}
