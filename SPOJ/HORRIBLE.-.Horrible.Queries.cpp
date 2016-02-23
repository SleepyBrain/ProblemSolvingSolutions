#include<bits/stdc++.h>
using namespace std;

long long  sum[400000], childSum[400000];

void update(long long at, long long L, long long R, long long l, long long r,long long value)
{
    if(R<l || r<L)
        return;
    if(l<=L && R<=r)
        sum[at] += value;
    else
    {
        long long  mid = (L+R)/2;
        update(at*2,L,mid,l,r,value);
        update(at*2+1,mid+1,R,l,r,value);
        childSum[at] = childSum[at*2] + childSum[at*2+1] + (mid-L+1)*sum[at*2] + (R-mid)*sum[at*2+1];
    }
}

long long query(long long at,long long L, long long R, long long l, long long r)
{
    if(R<l || r<L)
        return 0;

    long long ret = (min(R,r)-max(L,l)+1)*sum[at];

    if(L>=l && R<=r)
        ret += childSum[at];
    else
    {

        long long mid=(L+R)/2;
        ret += query(at*2,L,mid,l,r) + query(at*2+1,mid+1,R,l,r);
    }
    return ret;
}


int main()
{
    long long  T,N,C,p,q,v,a,i;
    scanf("%lld",&T);

    while(T--)
    {
        memset(sum,0,sizeof sum);
        memset(childSum,0,sizeof childSum);

        scanf("%lld %lld",&N,&C);
        for(i=1; i<=C; i++)
        {
            scanf("%lld",&a);
            if(a == 0)
            {
                scanf("%lld %lld %lld",&p,&q,&v);
                update(1,1,N,p,q,v);
            }
            else
            {
                scanf("%lld %lld",&p,&q);
                printf("%lld\n",query(1,1,N,p,q));
            }
        }
    }
    return 0;
}
