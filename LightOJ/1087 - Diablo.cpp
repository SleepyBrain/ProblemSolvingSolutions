#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100001
#define mx2 50001

typedef vector<int> vi;

class SegmentTree
{
private:
    vi st;
    int n,q;
    int left(int p)
    {
        return p << 1;
    }
    int right(int p)
    {
        return (p << 1)+1;
    }

public:
    SegmentTree(int a,int b)
    {
        n=a;
        q=b;
        st.assign(4*(mx+mx2),0);
        build(1,0,n+q-1);
    }

    void build(int p, int L, int R)
    {
        if(L == R)
        {
            if(L < n)
                st[p] = 1;
            else
                st[p] = 0;
        }
        else
        {
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2 +1, R);
            st[p] = st[left(p)] + st[right(p)];
        }
    }

    void update(int p, int L, int R, int pos)
    {
        if(pos < L || pos > R)
            return;
        if(L==R)
            st[p] = 1;
        else
        {
            update(left(p),L,(L+R)/2,pos);
            update(right(p),(L+R)/2+1,R,pos);
            st[p] = st[left(p)] + st[right(p)];
        }
    }

    int query(int p, int L, int R, int k)
    {
        if(L==R)
        {
            st[p] = 0;
            return L;
        }
        else
        {
            int res;
            if(k-st[left(p)] > 0)
                res = query(right(p),(L+R)/2+1,R,k-st[left(p)]);
            else
                res = query(left(p),L,(L+R)/2,k);
            st[p] = st[left(p)] + st[right(p)];
            return res;
        }
    }
};

int main()
{
    int t,tc=1,n,q;
    scanf("%d",&t);
    while(tc<=t)
    {
        printf("Case %d:\n",tc);
        scanf("%d %d", &n,&q);
        vi army ;
        int b,index;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&b);
            army.push_back(b);
        }
        char a[5];
        SegmentTree st(n,q);
        for(int i=0; i<q; i++)
        {
            scanf("%s%d",a,&b);
            if(a[0] == 'c')
            {
                index = st.query(1,0,n+q-1,b);
                if(index >= army.size())
                    printf("none\n");
                else
                    printf("%d\n",army[index]);
            }
            else
            {
                army.push_back(b);
                st.update(1,0,n+q-1,army.size()-1);
            }
        }
        tc++;
    }
    return 0;
}
