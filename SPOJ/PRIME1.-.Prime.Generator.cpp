#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000001
bitset<10000001> bs;
vector<ll> primes;

bool isPrime(ll n)
{
    if(n<=mx)
        return bs[n];
    ll l = primes.size();
    for(ll i=0; i<l && primes[i]<=sqrt(n); i++)
        if(n%primes[i]==0)
            return false;
    return true;
}

int main()
{
    ll t,tc=1,n,m;
    bs.set();
    for(ll i=4; i<mx; i+=2)
        bs[i]=0;
    primes.push_back(2);
    for(ll i=3; i<=mx; i+=2)
        if(bs[i])
        {
            for(ll j=i*i; j<1000001; j += 2*i)
                bs[j]=0;
            primes.push_back(i);
        }

    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%lld %lld",&n,&m);
        if(n<=2)
            printf("2\n");
        if(n%2==0)
            n++;
        for(ll i=n; i<=m; i+=2)
        {
            if(i==1 || i==2)
                continue;
            if(isPrime(i))
                printf("%lld\n",i);
        }
        printf("\n");
        tc++;
    }
    return 0;
}
