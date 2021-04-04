#include<bits/stdc++.h>
using namespace std;

vector<int> cash,dp;

int maxCash(int n){
    int r=0,d=0;
    if(n<0)
        return(0);

    if(dp[n]!=0)
        return(dp[n]);

    //rob
    r=cash[n]+maxCash(n-2);
    //dont
    d=maxCash(n-1);
    
    dp[n]=max(r,d);
    return(max(r,d));
}

int main(){
    int n=0,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        cash.push_back(c);
        dp.push_back(0);
    }

    c=maxCash(n-1);

    return(0);
}