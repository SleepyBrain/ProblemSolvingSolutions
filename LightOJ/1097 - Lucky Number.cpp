#include<bits/stdc++.h>
using namespace std;
#define mx 1429431
#define vi vector<int>

int ans[mx+1];

class SegmentTree
{
    vi st;
    int left(int p)
    {
        return p<<1;
    }
    int right(int p)
    {
        return (p<<1)+1;
    }
public:
    SegmentTree()
    {
        st.assign(4*mx+1,0);
        build(1,1,mx);
    }
    void build(int p, int L, int R)
    {
        if(L==R)
        {
            st[p]=1;
            return;
        }
        else
        {
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            st[p] = st[left(p)]+st[right(p)];
        }
    }

    void update(int p, int L, int R, int pos)
    {
        if(L==R)
        {
            st[p]=0;
        }
        else
        {
            if(st[left(p)]>=pos)
                update(left(p),L,(L+R)/2,pos);
            else
                update(right(p),(L+R)/2+1,R,pos-st[left(p)]);
            st[p] = st[left(p)]+st[right(p)];
        }
    }

    int query(int p, int L, int R, int n)
    {
        if(L==R)
            return L;
        else
        {
            if(n-st[left(p)] > 0)
                return query(right(p),(L+R)/2+1,R,n-st[left(p)]);
            else
                return query(left(p),L,(L+R)/2,n);
        }
    }
};


int main()
{
//    freopen("in.in","r",stdin);
    int t,tc=1,n,c=1;
    scanf("%d",&t);

    SegmentTree st;
    int b=0,a;
    for(int i=2; i<=mx; i+=2)
    {
        st.update(1,1,mx,i-b);
        b++;
    }
    ans[c++] = 1;
    for(int i=2; i<=mx; i++)
    {
        a  = st.query(1,1,mx,i);
        ans[c++] = a;
        b = 0;
        for(int j=a; j<=mx; j+=a)
        {
            st.update(1,1,mx,j-b);
            b++;
        }

    }

    while(tc<=t)
    {
        printf("Case %d: ",tc);
        scanf("%d",&n);
        printf("%d\n",ans[n]);
        tc++;
    }
    return 0;
}
