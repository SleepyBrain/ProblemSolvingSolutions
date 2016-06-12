#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mx 100005
#define LSOne(a) (a&(-a))

ll ft[mx];
pair<ll,ll> a[mx];

class bit
{
    int n;
public:
    bit(int a)
    {
        n = a;
        for(int i=0; i<=n; i++)
            ft[i] = 0;
    }

    ll query(int a)
    {
        ll sum=0;
        for(; a; a-=LSOne(a))
            sum = (sum + ft[a])%mod;
        return sum;
    }

    ll query(int a, int b)
    {
        if(a > n || b > n)
            return 0;
        if(a > b)
            return 0;
        if(a==1)
            return query(b);
        return (query(b)-query(a-1)+mod)%mod;
    }

    void update(int i,ll val)
    {
        for(; i<=n; i+=LSOne(i))
            ft[i] = (ft[i]+(val%mod))%mod;
    }
};

int main()
{
    ll t,tc=1,n;
    freopen("in.in","r",stdin);
    scanf("%lld",&t);
    while(tc<=t)
    {
        printf("Case %lld: ", tc);
        scanf("%lld",&n);
        ll v;
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&v);
            a[i]=make_pair(v,i);
        }
        sort(a+1, a+n+1);
        ll result[n+1];
        bit b(n);
        for(int i=n; i>=1; i--)
        {
            if(i!=n && a[i].first == a[i+1].first)
            {
                result[a[i].second] = (b.query(a[i].second + 1,a[i+1].second-1)+result[a[i+1].second])%mod;
                b.update(a[i].second, result[a[i].second]);
            }
            else
            {
                result[a[i].second] = (1 + b.query(a[i].second + 1,n))%mod;
                b.update(a[i].second, result[a[i].second]);
            }
        }
        ll total = 0;
        for(ll i = 1; i<=n; i++)
            total = (total + result[i])%mod;
        printf("%lld\n",total);
        tc++;
    }
    return 0;
}
