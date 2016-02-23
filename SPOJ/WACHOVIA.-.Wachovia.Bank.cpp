#include<bits/stdc++.h>
using namespace std;

int dp[55][1010],w[55],p[55],k,m;

int call(int i,int weight)
{
    if(i >= m)
        return 0;
    if(dp[i][weight] != -1)
        return dp[i][weight];
    int profit1 = 0, profit2 = 0;
    if(weight + w[i] <= k)
        profit1 = p[i]+call(i+1,weight+w[i]);
    profit2 = call(i+1,weight);
    return dp[i][weight] = max(profit1,profit2);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&k,&m);
        for(int i=0; i<m; i++)
            scanf("%d %d",&w[i],&p[i]);
        memset(dp,-1,sizeof dp);
        printf("Hey stupid robber, you can get %d.\n",call(0,0));

    }
    return 0;
}
