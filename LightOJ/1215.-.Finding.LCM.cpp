#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

int main()
{
    ll t,tc=1,a,b,l;
    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%lld %lld %lld",&a, &b, &l);
        ll lm=lcm(a,b);
        if(l%lm==0)
        {
            ll c=l/lm;
            ll g = gcd(lm,c);
            while(g!=1)
            {
                c*=g;
                lm/=g;
                g = gcd(c,lm);
            }
            printf("Case %lld: %lld\n",tc,c);
        }
        else
            printf("Case %lld: impossible\n",tc);
        tc++;
    }
    return 0;
}
