#include<bits/stdc++.h>
using namespace std;
#define MAX 300010

struct edge
{
    long long u,v,w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

long long par[MAX];
vector<edge> e;

long long find(long long n)
{
    return (par[n]==n) ? n : par[n] = find(par[n]);
}

long long mst(long long n)
{
    sort(e.begin(), e.end());
    for(long long  i=1; i<=n; i++)
        par[i] = i;
    long long count=0,sum=0;
    for(long long i=0; i<(long long)e.size(); i++)
    {
        long long u = find(e[i].u);
        long long v = find(e[i].v);
        if(u != v)
        {
            par[u] = v;
            count++;
            sum += e[i].w;
            if(count == n-1)
                break;
        }
    }
    return sum;
}

int main()
{
    long long n,m,total;
    while(cin >> n >> m && n && m)
    {
        total = 0;
        for(long long i=1; i<=m; i++)
        {
            long long  u,v,w;
            cin >> u >> v >> w;

            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            total += w;
            e.push_back(get);
        }
        cout << total-mst(n) << endl;
        e.clear();
    }
    return 0;
}
