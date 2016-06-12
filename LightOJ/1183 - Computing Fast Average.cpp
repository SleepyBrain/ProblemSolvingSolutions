#include<bits/stdc++.h>
using namespace std;
#define mx 100001
#define ll long long

int t[4*mx],sum[4*mx];

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b,a%b);
}

void push(int v,int l, int r)
{
    if(t[v] != -1)
    {
        t[v*2] = t[v*2 + 1] = t[v];
        sum[v*2] = t[v*2]*((l+r)/2   -l+1);
        sum[v*2 + 1] = t[v*2 + 1]*(r-  (l+r)/2);
        t[v]=-1;
    }
}

void update(int v, int tl, int tr, int l, int r, int value)
{
    if(l > r)
        return;
    if(l == tl && tr == r)
    {
        t[v] = value;
        sum[v] = t[v]*(r-l+1);
    }
    else
    {
        push(v,tl,tr);
        int tm = (tl + tr)/2;
        update(v*2,tl,tm,l,min(tm,r),value);
        update(v*2+1,tm+1,tr,max(tm+1,l),r,value);
        sum[v] = sum[v*2] + sum[v*2 + 1];
    }
}

ll get(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
    {
        return sum[v];
    }
    push(v,tl,tr);
    int tm = (tl + tr)/2;
    return get(v*2,tl,tm,l,min(tm,r)) + get(v*2 + 1,tm+1,tr,max(tm+1,l),r);
}


int main()
{
    int T,tc=1,n,q;
    scanf("%d",&T);
    while(tc<=T)
    {
        scanf("%d %d",&n,&q);
        for(int i=1; i<=4*n; i++)
        {
            t[i]=-1;
            sum[i] = 0;
        }
        printf("Case %d:\n",tc);
        for(int i=1; i<=q; i++)
        {
            int a,x,y,v;
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d%d%d",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                scanf("%d%d",&x,&y);
                ll sum = get(1,0,n-1,x,y),p;
                p = (y-x+1);
                ll gc = gcd(sum, p);
                if(gc!=1)
                {
                    sum /= gc;
                    p /= gc;
                }
                if(p != 1)
                    printf("%lld/%lld\n",sum,p);
                else
                    printf("%lld\n",sum);
            }
        }
        tc++;
    }
    return 0;
}
