#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//to point update for aLternate or zor

class SGT{
    public:
    vector<int>seg;
    SGT(int n){
        seg.resize(4*n+1);
    }
    void build(ll ind,ll low,ll high,vector<ll>&v,int orr){
        if(low==high){
            seg[ind]=v[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*ind+1,low,mid,v,!orr);
        build(2*ind+2,mid+1,high,v,!orr);
        if(orr){
            seg[ind]=seg[2*ind+1]|seg[2*ind+2];
        }
        else{
            seg[ind]=seg[2*ind+1]^seg[2*ind+2];
        }
    }
    void update(ll ind,ll low,ll high,ll i,ll val,vector<ll>&v,int orr){
        if(low==high){
            seg[ind]=val;
            return;
        }
        ll mid=(low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val,v,!orr);
        }
        else{
            update(2*ind+2,mid+1,high,i,val,v,!orr);
        }
        if(orr){
            seg[ind]=seg[2*ind+1]|seg[2*ind+2];
        }
        else{
            seg[ind]=seg[2*ind+1]^seg[2*ind+2];
        }
    }
    int query(ll ind,ll low,ll high,ll l,ll r){
        //case of no overlap
        if(high<l or r<low){
            return INT_MAX;
        }
        //case of complete overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        //case of partial overlap
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
};
int main()
{
    ll n,m;
    cin>>n>>m;
    ll ele=pow(2,n);
    vector<ll>v(ele);
    for(ll i=0;i<ele;i++){
        cin>>v[i];
    }
    SGT sg(ele);
    int orr;
    if(n%2==1){
        orr=1;
    }
    else{
        orr=0;
    }
    sg.build(0,0,ele-1,v,orr);
    for(ll i=0;i<m;i++){
        ll ind,val;
        cin>>ind>>val;
        sg.update(0,0,ele-1,ind-1,val,v,orr);
        cout<<sg.seg[0]<<endl;
    }
    return 0;
}
