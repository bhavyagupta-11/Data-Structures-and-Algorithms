#include <iostream>
#include <vector>
using namespace std;
/*void primeupton(int n,int *p){
    for(int i=1;i<n;i++){
        if(p[i]==1){
            cout<<i<<" ";
        }
        
    }
}*/
void prime(int *p,vector<int>pr){
    for(int i=3;i<1000002;i+=2){
       p[i] =1;
    }
    for(long long i=3;i<1000002;i+=2){
    
    if(p[i]==1){
        pr.push_back(i);
          for(long long j=i*i;j<1000002;j=j+i){
                p[j]=0;
            }
        
    }
    }
          
    p[0]=p[1]=0;
    p[2]=1;
    pr.push_back(2);
}
bool isprime(long long int no,int *p,vector<int>pr){
    if(no<=p[1000001]){
        if(p[no]==1){
            return true;
        }
        else{
            return false;
        }
    }
    for(int i=0;pr[i]*pr[i]<no;i++){
        
        if(no%pr[i]==0){
            return false;
        }
    }
    return true;
}
int main()
{
    int no;
    cin>>no;
    int p[1000002]={0};
    vector<int>pr;
    prime(p,pr);
    //primeupton(no,p);
    
    if(isprime(no,p,pr)){
        cout<<"yes";
    }
    else{cout<<"no";}

    return 0;
}


