#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll n, ll val)
{
    ll ans = 0, b = val;
    while(b<=n)
    {
        ans += n/b;
        b *= val;
    }
    return ans;
}

ll cal(ll n, ll r, ll p, ll q, ll val)
{
    ll ans = f(n,val)-f(r,val)-f(n-r,val);
    ll pow = 0;
    while(p%val == 0)
    {
        pow++;
        p/=val;
    }
    ans += pow*q;
    return ans;
}

int main()
{
    ll t,tc=1,n,r,p,q;
    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%lld %lld %lld %lld",&n, &r, &p, &q);
        printf("Case %lld: %lld\n",tc,min(cal(n,r,p,q,2),cal(n,r,p,q,5)));
        tc++;
    }
    return 0;
}
