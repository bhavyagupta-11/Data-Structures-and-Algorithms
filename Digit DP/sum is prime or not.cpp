#include <bits/stdc++.h>
using namespace std;

//SPOJ Question
//find the numbers whose sum of digits is a prime number

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};
 
bool isprime(int sum)
{
	for(auto i:prime)
	{
		if(i==sum)
			return 1;
	}
	return 0;
}

int solve(int pos,int sum,int tight,vector<vector<vector<int>>>&dp,string &a){
    if(pos==a.size()){
        if(isprime(sum)){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[pos][sum][tight]!=-1){
        return dp[pos][sum][tight];
    }
    if(tight==1){
        int ans=0;
        for(int i=0;i<=a[pos]-'0';i++){
            if(i==a[pos]-'0'){
                ans+=solve(pos+1,sum+i,1,dp,a);
            }
            else{
                ans+=solve(pos+1,sum+i,0,dp,a);
            }
        }
        return dp[pos][sum][tight]=ans;
    }
    else{
        int ans=0;
        for(int i=0;i<=9;i++){
            ans+=solve(pos+1,sum+i,0,dp,a);
        }
        return dp[pos][sum][tight]=ans;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        //pos=8+2=10
        //sum=9*10=90
        vector<vector<vector<int>>>dp1(10,vector<vector<int>>(90,vector<int>(2,-1)));
        string s=to_string(r);
        int right=solve(0,0,1,dp1,s);
        vector<vector<vector<int>>>dp2(10,vector<vector<int>>(90,vector<int>(2,-1)));
        l--;
        string a=to_string(l);
        int left=solve(0,0,1,dp2,a);
        cout<<right-left<<endl;
    }
    
    return 0;
}
