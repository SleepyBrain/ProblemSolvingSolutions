#include<bits/stdc++.h>
using namespace std;

map<long long ,long long> dp;

long long rec(long long coin)
{
    if(coin == 0)
        return 0;
    long long ans = dp[coin];
    if(ans == 0)
    {
        ans = max(coin, rec(coin/2)+rec(coin/3)+rec(coin/4));
        return dp[coin] = ans;
    }
    return ans;
}

int main()
{
    long long n;
    while(cin >> n)
    {
        printf("%lld\n",rec(n));
    }
    return 0;
}
