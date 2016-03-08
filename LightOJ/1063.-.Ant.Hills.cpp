#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10010

ll t,tc=1,n,m,a,b,tim,low[mx],d[mx],parent[mx];
bool artPoint[mx],visited[mx];
vector<ll> adjList[mx];

void findArticulationPoint(ll u)
{
    tim++;
    low[u]=d[u]=tim;
    visited[u]=true;
    ll noChild=0;

    for(ll i=0; i<adjList[u].size(); i++)
    {
        ll v=adjList[u][i];
        noChild++;

        if(visited[v]==false)
        {
            parent[v] = u;
            findArticulationPoint(v);
            low[u]=min(low[u],low[v]);

            if(d[u] <= low[v] && parent[u] != -1)
                artPoint[u]=true;
            if(noChild > 1 && parent[u] == -1)
                artPoint[u]=true;
        }
        else
        {
            if(v != parent[u])
                low[u] = min(low[u],d[v]);
        }
    }

}

int main()
{
    scanf("%lld",&t);
    while(tc<=t)
    {
        scanf("%lld %lld",&n,&m);
        for(ll i=0; i<m; i++)
        {
            scanf("%lld %lld",&a,&b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);

        }

        for(ll i=1; i<=n; i++)
        {
            artPoint[i]=false;
            visited[i]=false;
            low[i]=d[i]=0;
            parent[i]=-1;
        }

        tim = 0;
        for(ll i=1; i<=n; i++)
        {
            if(!visited[i])
                findArticulationPoint(i);
        }

        ll c=0;
        for(ll i=1; i<=n; i++)
            if(artPoint[i])
                c++;


        printf("Case %lld: %lld\n",tc,c);
        for(ll i=0; i<=n; i++)
            adjList[i].clear();
        tc++;
    }
    return 0;
}
