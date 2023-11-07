#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//for finding the minimum in a query range, and point update

class SGT{
    public:
    vector<int>seg;
    SGT(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,vector<int>&v){
        if(low==high){
            seg[ind]=v[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,v);
        build(2*ind+2,mid+1,high,v);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    void update(int ind,int low,int high,int i,int val,vector<int>&v){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val,v);
        }
        else{
            update(2*ind+2,mid+1,high,i,val,v);
        }
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind,int low,int high,int l,int r){
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
    int n;
    cin>>n;
    SGT sg(n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sg.build(0,0,n-1,v);
    //queries
    int l=3;
    int r=6;
    cout<<sg.query(0,0,n-1,l,r)<<endl;
    //point update
    int i=4;
    int val=1;
    sg.update(0,0,n-1,i,val,v);
    //queries
    cout<<sg.query(0,0,n-1,l,r)<<endl;
    return 0;
}

