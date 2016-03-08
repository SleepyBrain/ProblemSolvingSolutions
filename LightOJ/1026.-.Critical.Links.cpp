#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10010

ll t,tc=1,n,m,a,b,tim,c,low[mx],d[mx],parent[mx];
bool artPoint[mx],visited[mx];
vector<ll> adjList[mx];
vector< pair<ll,ll> > bridge;

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

            if(d[u] < low[v])
            {
                artPoint[u]=true;
                c++;
                bridge.push_back(make_pair(min(u,v),max(u,v)));
            }
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
        scanf("%lld",&n);
        for(ll i=0; i<n; i++)
        {
            scanf("%lld %*c%lld%*c",&a,&m);
            for(ll j=0; j<m; j++)
            {
                scanf("%lld",&b);
                adjList[a].push_back(b);
            }
        }
        for(ll i=0; i<n; i++)
        {
            visited[i]=false;
            parent[i]=-1;
            low[i]=d[i]=0;
            artPoint[i]=false;
        }
        c=0;
        tim = 0;
        for(ll i=0; i<n; i++)
            if(!visited[i])
                findArticulationPoint(i);

        printf("Case %lld:\n",tc);
        printf("%lld critical links\n",c);
        sort(bridge.begin(),bridge.end());
        for(ll i=0; i<bridge.size(); i++)
            printf("%lld - %lld\n",bridge[i].first,bridge[i].second);
        for(ll i=0; i<=n; i++)
            adjList[i].clear();
        bridge.clear();
        tc++;
    }
    return 0;
}
