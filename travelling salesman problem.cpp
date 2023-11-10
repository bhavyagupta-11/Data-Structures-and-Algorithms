#include <bits/stdc++.h>
using namespace std;

//TRAVELLING SALESMAN PROBLEM
//here n is the total cities with values from 0 to n-1
//int dp[n][1<<n]

//2 type of questions
//type:1
//minimum cost to join all nodes once with no returning to original point
//here same dp can be used for all the starting nodes,since the base case would be same
//type:2 
//we need to go back to the starting node, different dp for different starting nodes,since the base case would be different

int tsp(int pos,int mask,int &start,int &n,vector<vector<int>>&dp){
    if(mask==((1<<n)-1)){
        return 0;
    }
    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }
    int ans=INT_MAX;
    //going to and unvisited city
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            ans=min(ans,dist[pos][i]+tsp(i,mask|(1<<i),start,n,dp));
        }
    }
    return dp[pos][mask]=ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>dist(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(1<<n,-1));
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,tsp(i,1<<i,i,n,dp));
    }
    cout<<ans;
    return 0;
}
