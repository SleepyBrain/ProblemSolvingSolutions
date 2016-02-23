#include<bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define mx 100010
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{
    int n,m,s,D,t;
    cin >> t;
    while(t--)
    {
        vii adjList[mx];
        cin >> n >> m >> s >> D;
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            cin >> u >> v  >> w;
            adjList[u].push_back(ii(v,w));
            adjList[v].push_back(ii(u,w));
        }
        vi dist(n+5,inf);
        dist[s]=0;

        priority_queue< ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0,s));
        while(!pq.empty())
        {
            ii front = pq.top();
            pq.pop();
            int d=front.first,u=front.second;
            if(d > dist[u])
                continue;
            for(int j=0; j<adjList[u].size(); j++)
            {
                ii v = adjList[u][j];
                if(dist[u]+v.second < dist[v.first])
                {
                    dist[v.first] = dist[u]+v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }
        if(dist[D]== inf)
            cout << "NONE\n";
        else
            cout << dist[D] << endl;
    }
    return 0;
}
