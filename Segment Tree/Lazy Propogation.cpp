#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//lazy propogation for range query updates
//range update for sum

class SGT{
    public:
    vector<int>seg;
    vector<int>lazy;
    SGT(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    void build(int ind,int low,int high,vector<int>&v){
        if(low==high){
            seg[ind]=v[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,v);
        build(2*ind+2,mid+1,high,v);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    void update(int ind,int low,int high,int l,int r,int val){
        //complete any pending updates
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        //no ovverlap
        if(high<l or r<low){
            return;
        }
        //complete overlap
        //update the values and lazy propogate it downwards
        if(low>=l and high<=r){
            seg[ind]+=(high-low+1)*val;
            if(low!=high){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
                return;
            }
        }
        //partial overlap
        int mid=(low+high)/2;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int rangequery(int ind,int low,int high,int l,int r){
        //complete any pending updates
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        //case of no overlap
        if(high<l or r<low){
            return 0;
        }
        //case of complete overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        //case of partial overlap
        int mid=(low+high)/2;
        int left=rangequery(2*ind+1,low,mid,l,r);
        int right=rangequery(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
};
int main()
{
    int n;
    cin>>n;
    SGT sg(n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sg.build(0,0,n-1,v);
    //range update
    int l=0;
    int r=1;
    int val=10;
    sg.update(0,0,n-1,l,r,val);
    //queries
    l=0;
    r=2;
    cout<<sg.rangequery(0,0,n-1,l,r)<<endl;
    return 0;
}
