#include<bits/stdc++.h>
using namespace std;
/*
For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2  NO
5+2+2  NO
3+3+3
2+2+2+3
2+2+3+2  NO
2+3+2+2  NO
3+2+2+2  NO

Input:
3 9
2 3 5
Output:
3
*/
vector<long long int> coins,dp;
long long int n=0,sum=0,temp=0;
    

int totalWays(int i)
{


    return(0);
}

int main(){
    cin>>n>>sum;
    dp.resize(sum+1,-1);
    for(long long int i=0;i<n;i++){
        cin>>temp;
        if(temp<=sum)
            dp[temp]=1;
        coins.push_back(temp);
    }

    totalWays(0);



/*
    cout<<"\n\n\n+++++++\n";
    for(long long int i=0;i<=sum;i++){
        if(dp[i]==-1)
            cout<<i<<"--"<<0<<"\t";
        else
            cout<<i<<"--"<<dp[i]<<"\t";
    }
    cout<<endl;
*/

    if(dp[sum]==-1)
        cout<<0;
    else
        cout<<dp[sum];

    return(0);
}