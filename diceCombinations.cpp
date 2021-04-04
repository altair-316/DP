#include<bits/stdc++.h>
using namespace std;

vector<long long int> dp;
int diceComb(int n){

    return(0);

}

int main(){
    long long int n=0;
    cin>>n;

    dp.push_back(0);
    dp.push_back(1);

    

    for(long long int i=2;i<=n;i++){
        dp.push_back(0);
        if(i<=6)
            dp[i]=1;
        for(int j=1;j<7;j++){
            if(j>=i)
                break;
            dp[i]+=dp[i-j];
        }
        dp[i]=dp[i]%(1000000007);
    }

    cout<<dp[n];

    

    //cout<<dp[n]%(10000007);

    return(0);

}