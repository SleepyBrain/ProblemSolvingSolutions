#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t,tc=1,n,numZero[25],fivePow[25];
    numZero[0]=0;
    fivePow[0]=1;
    for(ll i=1; i<=22; i++)
    {
        fivePow[i] = fivePow[i-1]*5;
        numZero[i] = numZero[i-1]*5+1;
//        cout << fivePow[i] << " " << numZero[i] << endl;
    }
    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%lld",&n);
        ll ans =0;
        while(n)
        {
            for(ll i=0; i<22; i++)
                if(fivePow[i] > n)
                {
                    ans += numZero[i-1];
                    n -= fivePow[i-1];
//                    cout << ans  << " " << n << endl;
                    break;
                }
                else if(fivePow[i]==n)
                {
                    ans += numZero[i];
                    n -= fivePow[i];
//                    cout << ans  << " " << n << endl;
                    break;
                }
        }
        printf("%lld\n",ans);
        tc++;
    }
    return 0;
}
