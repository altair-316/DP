#include<bits/stdc++.h>
using namespace std;


/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
    int w[] = {5, 4, 6, 3};  
	int V[] = {10, 40, 30, 50};    
	int  W = 10; 
	int n = 4;
*/

vector<int> v,w;
vector<vector<int>> dp;
    

int kSack(int c,int n){
    int p=0,d=0;
    if(dp[n][c-1]!=INT_MAX)
        return(dp[n][c-1]);

    if(c<=0 || n<0 || w[n]>c)
        return(0);
    
    //pick
    p=v[n]+kSack(c-w[n],n-1);
    //drop
    d=kSack(c,n-1);
    dp[n][c-1]=max(p,d);
    return(max(p,d));
}

int main(){
    int n=0,c=0,ans=0,x=0;
    cin>>n>>c;
    vector<int> temp(c,INT_MAX);
    for(int i=0;i<n;i++){
        cin>>x;
        w.push_back(x);
        dp.push_back(temp);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    ans=kSack(c,n-1);
    
    cout<<ans;
        


    return(0);
}