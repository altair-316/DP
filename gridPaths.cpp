#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    char grid[n][n],in;
    int paths[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>in;
        grid[i][j]=in;
        paths[i][j]=0;
        }
    }
    if(grid[n-1][n-1] == '.')
        paths[n-1][n-1]=1;
    else
        paths[n-1][n-1]=0;

    for(int i=n-2;i>=0;i--){
        if( grid[n-1][i] == '.' ){
            if( grid[n-1][i+1] == '.' )
                paths[n-1][i]=(paths[n-1][i+1])% 1000000007;
            else
                paths[n-1][i]=0;
        }
        else
            paths[n-1][i]=0;

        if( grid[i][n-1] == '.' ){
            if( grid[i+1][n-1] == '.' )
                paths[i][n-1]=(paths[i+1][n-1])% 1000000007;
            else
                paths[i][n-1]=0;
        }
        else
            paths[i][n-1]=0;
    }



    for(int i=n-2; i>=0;i--){
        for(int j=i;j>=0;j--){
            if(grid[i][j]=='*')
                paths[i][j]=0;
            else
                paths[i][j]=(paths[i][j+1] + paths[i+1][j])% 1000000007;
            
            if(grid[j][i]=='*')
                paths[j][i]=0;
            else
                paths[j][i]=(paths[j][i+1] + paths[j+1][i])% 1000000007;
        }
    }


/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cout<<paths[i][j]<<" ";
        }
        cout<<endl;
    }
*/

    cout<<paths[0][0];


    return(0);
}