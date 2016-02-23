#include<bits/stdc++.h>
using namespace std;
int dp[2][2000005],w[505],v[505],k,n;

int main()
{
    int i,j;
    for(i=0; i<=n; i++)
        dp[i][0] = 0;
    for(i=0; i<=k; i++)
        dp[0][i] = 0;
    scanf("%d %d",&k,&n);
    for(i=1; i<=n; i++)
        scanf("%d %d",&v[i],&w[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=k; j++)
        {
            if(w[i]>j)
                dp[i%2][j] = dp[i%2^1][j];
            else
                dp[i%2][j] = max(dp[i%2^1][j],v[i]+dp[i%2^1][j-w[i]]);
        }
    printf("%d\n",dp[n%2][k]);
    return 0;
}
