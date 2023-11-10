#include <bits/stdc++.h>
using namespace std;

//numbers with difference between adjacent digits not greater than 2
//int dp[12][12]

int solve(int pos,int prev,vector<int>&v,int&n,vector<vector<int>>&dp,string temp){
    if(dp[pos][prev]!=-1){
        return dp[pos][prev];
    }
    if(pos==n){
        cout<<temp<<" ";
        return 1;
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
        if(prev==0 or (abs(v[i]-prev)<=2)){
            ans+=solve(pos+1,v[i],v,n,dp,temp+to_string(v[i]));
        }
    }
    return dp[pos][prev]=ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int>v(m);
        for(int i=0;i<m;i++){
            cin>>v[i];
        }
        //n digit lies upto 10 so pos=10+2=12
        //prev value lies upto 10 so prev=10+2=12
        vector<vector<int>>dp(12,vector<int>(12,-1));
        string t;
        cout<<solve(0,0,v,n,dp,t)<<endl;
    }
    
    return 0;
}
