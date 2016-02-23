#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll in;
    bool flag=false;
    while(scanf("%lld",&in))
    {
        if(in == 42)
        {
            flag = true;
            break;
        }
        if(!flag)
            printf("%lld\n",in);
    }
    while(scanf("%lld",&in) != EOF)
    {

    }
    return 0;
}
