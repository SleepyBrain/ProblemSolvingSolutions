#include<bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define mx 100010
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{
    int n,t;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        map<string, int> myMap;
        vii adjList[mx];

        scanf("%d",&n);
        int c=0;
        for(int i=0; i<n; i++)
        {
            cin >> str;
            myMap[str] = ++c;
            int m,v,w;
            scanf("%d",&m);
            for(int i=0; i<m; i++)
            {
                scanf("%d%d",&v,&w);
                adjList[c].push_back(ii(v,w));
                adjList[v].push_back(ii(c,w));
            }
        }
        int r;
        string s,e;
        scanf("%d",&r);
        while(r--)
        {
            vi dist(n+5,inf);
            cin >> s >> e;
            dist[myMap[s]]=0;
            priority_queue< ii, vector<ii>, greater<ii> > pq;
            pq.push(ii(0,myMap[s]));
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
            printf("%d\n",dist[myMap[e]]);
        }
    }
    return 0;
}
