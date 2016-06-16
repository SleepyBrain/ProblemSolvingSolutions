#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1<<30

ll calc(vector<ll> &num, ll cap)
{
    ll cur=0,ans=1;
    for(ll i=0; i<num.size(); i++)
    {
        if(num[i] > cap)
            return inf;
        if(cur+num[i] <= cap)
            cur += num[i];
        else
        {
            cur = num[i];
            ans++;
        }
    }
    return ans;
}

int main()
{
    ll t,tc=1,n,m;
    scanf("%lld",&t);

    while(tc<=t)
    {
        scanf("%lld %lld",&n,&m);
        vector<ll> num(n);
        ll mx = -1;
        for(ll i=0; i<n; i++)
        {
            scanf("%lld",&num[i]);
            mx = max(mx,num[i]);
        }
        printf("Case %lld: ",tc);
        if(m >= n)
            printf("%lld\n",mx);
        else
        {
            ll low=0, hi=inf;
            while(low < hi)
            {
                if(low + 1 == hi)
                {
                    if(calc(num, low) > m)
                        low = hi;
                    break;
                }
                ll mid = (low + hi) >> 1;
                if(calc(num,mid) <= m)
                    hi = mid;
                else
                    low = mid + 1;
            }
            printf("%lld\n",low);
        }
        tc++;
    }
    return 0;
}
