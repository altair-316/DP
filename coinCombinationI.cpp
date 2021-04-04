#include<bits/stdc++.h>
using namespace std;

vector<long long int> coins,dp;


/*
For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input:
3 9
2 3 5
Output:
8
*/



int main(){
    long long int n=0,sum=0,temp=0;
    cin>>n>>sum;
    dp.resize(sum+1,-1);

    for(long long int i=0;i<n;i++){
        cin>>temp;
        if(temp<=sum)
            dp[temp]=1;
        coins.push_back(temp);
    }
/*
    if(n==1 && sum<coins[0]){
        cout<<0;
        return(0);
    }
*/
    for(long long int i=0;i<=sum;i++){
        //cout<<i<<"==";

        //for(long long int j=0;j<=sum;j++){
        for(auto j:coins){
            if( j>i || dp[i-j]==-1 || dp[j]==-1)
                continue;
            if(dp[i]==-1)
                dp[i]=0;
            dp[i]+=dp[i-j];
        //    cout<<"("<<i-j<<","<<j<<")\t";
        }
        dp[i]=dp[i]%(1000000007);
        //cout<<endl<<"--------------\n";

    }

    //cout<<"\n\n\n+++++++\n";
    //for(long long int i=0;i<=sum;i++){
    //    cout<<i<<"--"<<dp[i]<<"\t";
    //}
    if(dp[sum]==-1)
        cout<<0;
    else
        cout<<dp[sum];

    return(0);
}