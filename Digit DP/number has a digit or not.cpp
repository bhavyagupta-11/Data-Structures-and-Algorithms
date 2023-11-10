#include <bits/stdc++.h>
using namespace std;

//HackerEarth Question
//exclude the numbers which have digit 3 in them
//int dp[11][2][2]

int solve(int pos,int digit,int tight,vector<vector<vector<int>>>&dp,string &a){
    if(pos==a.size()){
        if(digit==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[pos][digit][tight]!=-1){
        return dp[pos][digit][tight];
    }
    if(tight==1){
        int ans=0;
        for(int i=0;i<=a[pos]-'0';i++){
            int flag=digit;
            if(i==3){
                flag=1;
            }
            if(i==a[pos]-'0'){
                ans+=solve(pos+1,flag,1,dp,a);
            }
            else{
                ans+=solve(pos+1,flag,0,dp,a);
            }
        }
        return dp[pos][digit][tight]=ans;
    }
    else{
        int ans=0;
        for(int i=0;i<=9;i++){
            int flag=digit;
            if(i==3){
                flag=1;
            }
            ans+=solve(pos+1,flag,0,dp,a);
        }
        return dp[pos][digit][tight]=ans;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        //pos=9+2=11
        //digit=2
        vector<vector<vector<int>>>dp(11,vector<vector<int>>(2,vector<int>(2,-1)));
        string s=to_string(n);
        int cnt=solve(0,0,1,dp,s);
        cout<<n-cnt<<endl;
    }
    
    return 0;
}
