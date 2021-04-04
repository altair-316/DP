#include<bits/stdc++.h>
using namespace std;

vector<int> dpSubMax;

int findMax(int num){

    if(dpSubMax[num]!=-1)
        return(dpSubMax[num]);

    int x=100000,ans=0,temp=num;

    while(num%x==num)
        x=x/10;

    while( num > 10 ){
        ans=max(ans,num%10);
        num=num/10;
        x=x/10;
    }

    if(num==10)
        ans=max(ans,1);
    else
        ans=max(ans,num);
    
    dpSubMax[temp]=ans;
    return(ans);
}


int main(){
    int n=0,a=0,t=0;
    cin>>n;
    dpSubMax.resize(n+1,-1);
    for(int i=0;i<10;i++)
        dpSubMax[i]=i;
    
    while(n>9)
    {
        a+=1;
        t=findMax(n);
        //cout<<n<<"-"<<t<<"\t";
        n = n - t;
        
    }
    //cout<<n;

    cout<<a+1;




    return(0);
}