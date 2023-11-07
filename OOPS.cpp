#include <iostream>
#include <cstring>
using namespace std;
class car{
    private:
    int price;
    public:
    char *name;
    const int msp;
    //const is used when you dont want to update the vale in further cases, and cnst function cannot update the value of class object
    float discount(const float x) const{
        return price*((100.0-x)/100.0);
    }
    void print(){
        cout<<name<<endl<<price<<endl;
    }
    //this updates the price
    int apply(float x){
        price=price*((100.0-x)/100.0);
        return price;
    }
    //this sets the price after analysing the given conditions are correct
    void set_price(int p){
        
        if(p<111){
            price=111;
        }
        else{
            price =p;
        }
        
    }
    //creating constructors and initialising the constant part
    car(int p,char *n,int min=89):msp(min){
        price=p;
        //for creating heap memory we use self made copy constructors. benifit is we can alter the size acc to input
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }
    //creating copy constructors
    car(car &x):msp(x.msp){
        cout<<"inside copy constructor";
        price=x.price;
        name=new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }
    //copy assignment operator can be used as many times
    void operator=(car &x){
        price=x.price;
        name=new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }
    //to save memory we delete the classes,in case of pointers we need to define the destructor
    ~car(){
        if(name!=NULL){
            delete [] name;
        }
    }
};
int main()
{
    /*car c;
    float x;
    int p;
    cin>>c.name>>p>>x;
    c.set_price(p);*/
    car d(1000,"bkj");
    car e(d);
    d.print();
    cout<<d.msp<<endl;
    cout<<endl;
    e.print();
    cout<<endl;
    car a(500,"abh");
    a=d;
    a.print();
    //cout<<c.name<<endl<<c.price<<endl<<c.discount(x);
    //to simply print use c.print();
   /*cout<<c.apply(x);
    c.print();*/
    
    return 0;
}
