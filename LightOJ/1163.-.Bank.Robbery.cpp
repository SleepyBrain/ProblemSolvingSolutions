#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main()
{
    ll t,tc=1,ans;
    scanf("%llu",&t);
    while(tc<=t)
    {
        scanf("%llu",&ans);
        if(ans%9==0)
            printf("Case %llu: %llu %lld\n",tc,(ans*10)/9-1,(ans*10)/9);
        else
            printf("Case %llu: %llu\n",tc,(ans*10)/9);
        tc++;
    }
    return 0;
}
