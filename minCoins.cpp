#include<bits/stdc++.h>
using namespace std;
 
vector<double> cVal,dp;
double n=0;
 
double maxCoin(double cap){
    if(cap==0)
        return(0);
    if(dp[cap]!=INT_MAX)
        return(dp[cap]);
 
      
    int temp=INT_MAX;
    for(double i=n-1;i>=0;i--){
        double c=0;
        if(cVal[i]<=cap){
            c=1+maxCoin(cap-cVal[i]);
        }
        if(c<temp && c>0){
            temp=c;
        }
    }

    if(temp!=INT_MAX){
        dp[cap]=temp;
        return(temp);
    }
    else{
        dp[cap]=temp+1;
        return(INT_MAX);
    }
 
}
 
int main()
{
    double c=0,temp=0,coins=INT_MAX;
 
    cin>>n>>c;
 
    dp.resize(c+1,INT_MAX);
    dp[0]=0;
 
    for(double i=0;i<n;i++){
        cin>>temp;
        if(temp<=c)
            dp[temp]=1;
        cVal.push_back(temp);
    }
  
    coins = maxCoin(c);
 
    if(coins!=INT_MAX)
        cout<<int(coins);
    else
        cout<<(-1);
 
    return(0);
}