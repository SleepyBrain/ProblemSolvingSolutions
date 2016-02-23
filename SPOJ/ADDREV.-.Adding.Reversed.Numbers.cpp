#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t,tc=1,a,b,ans;
    char str1[50],str2[50];
    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%s %s",&str1, &str2);
        a =0, b=0, ans=0;
        for(ll i=strlen(str1)-1; i>=0; i--)
            a = a*10 + str1[i]-'0';
        for(ll i=strlen(str2)-1; i>=0; i--)
            b = b*10 + str2[i]-'0';
        ans = a + b;
        bool flag = false;
        while(1)
        {
            ll p = ans%10;
            if(p==0 && !flag)
            {
                ans/=10;
                continue;
            }
            else
                flag = true;
            ans /= 10;
            printf("%lld",p);
            if(ans==0)
                break;
            if(ans < 10)
            {
                printf("%lld",ans);
                break;
            }
        }
        printf("\n");
        tc++;
    }
    return 0;
}
