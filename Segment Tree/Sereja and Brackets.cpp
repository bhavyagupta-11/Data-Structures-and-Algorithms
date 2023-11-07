#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

//for finding the valid brackets in a range under given query
class Node{
    public:
    int open;
    int close;
    int full;
    Node(){
        this->open=0;
        this->close=0;
        this->full=0;
    }
};

class SGT{
    public:
    vector<Node>seg;
    SGT(int n){
        seg.resize(4*n+1);
    }
    Node merge(Node left,Node right){
        int f=min(left.open,right.close);
        Node temp;
        temp.open=left.open+right.open-f;
        temp.close=left.close+right.close-f;
        temp.full=left.full+right.full+f;
        return temp;
    }
    void build(int ind,int low,int high,string &s){
        if(low==high){
            if(s[low]=='('){
                seg[ind].open=1;
            }
            else{
                seg[ind].close=1;
            }
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,s);
        build(2*ind+2,mid+1,high,s);
        seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
    }
    /*void update(int ind,int low,int high,int i,int val,vector<int>&v){
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
    }*/
    Node query(int ind,int low,int high,int l,int r){
        //case of no overlap
        if(high<l or r<low){
            Node temp;
            return temp;
        }
        //case of complete overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        //case of partial overlap
        int mid=(low+high)/2;
        Node left=query(2*ind+1,low,mid,l,r);
        Node right=query(2*ind+2,mid+1,high,l,r);
        return merge(left,right);
    }
};
int main()
{
    string s;
    cin>>s;
    int m;
    cin>>m;
    int n=s.size();
    SGT st(n);
    st.build(0,0,n-1,s);
    
    while(m--){
        int l;
        int r;
        cin>>l>>r;
        Node ans=st.query(0,0,n-1,l-1,r-1);
        cout<<2*ans.full<<endl;
    }
    return 0;
}
