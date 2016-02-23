#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000

int main()
{
    int matrix[110][110],n,e,t,m;
    cin >> n >> e >> t >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            matrix[i][j] = inf;
            matrix[i][i] = 0;
        }
    int u,v,w;
    for(int i=1; i<=m; i++)
    {
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(matrix[i][j] > matrix[i][k]+matrix[k][j])
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
    int c = 0;
    for(int i=1; i<=n; i++)
        if(matrix[i][e] <= t)
            c++;
    cout << c << endl;
    return 0;
}
