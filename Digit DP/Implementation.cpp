#include <bits/stdc++.h>
using namespace std;

//conditions
//when range (l,r) is given and find the numbers whose digits satify a particular property

//steps
//1.if the constraint is 1e8 then pos=8+2=10
//2.if asked to find the sum of all numbers in the range 1 to l then sum=9*10=90
//3.tight so that the number does not exceed the value return

//string digit

int solve(int pos,int sum,int tight,vector<vector<vector<int>>>&dp){
    if(pos==digit.size()){
        return sum;
    }
    if(dp[pos][sum][tight]!=-1){
        return dp[pos][sum][tight];
    }
    if(tight==1){
        int ans=0;
        for(int i=0;i<=digit[pos];i++){
            if(i==digit[pos]){
                ans+=solve(pos+1,sum+i,1,dp);
            }
            else{
                ans+=solve(pos+1,sum+i,0,dp);
            }
        }
        return dp[pos][sum][tight]=ans;
    }
    else{
        int ans=0;
        for(int i=0;i<=9;i++){
            ans+=solve(pos+1,sum+i,0,dp);
        }
        return dp[pos][sum][tight]=ans;
    }
}

int main()
{
    
    
    return 0;
}
