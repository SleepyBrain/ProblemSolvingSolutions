#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    ll t,tc=1,x1,y1,x2,y2;
    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%lld %lld %lld %lld",&x1, &y1, &x2, &y2);
        if(x1==x2)
            printf("Case %lld: %lld\n",tc,abs(y1-y2)+1);
        else if(y1==y2)
            printf("Case %lld: %lld\n",tc,abs(x1-x2)+1);
        else
        {
            ll dx = abs(x1-x2);
            ll dy = abs(y1-y2);
            printf("Case %lld: %lld\n",tc,gcd(dx,dy)+1);
        }
        tc++;
    }
    return 0;
}
