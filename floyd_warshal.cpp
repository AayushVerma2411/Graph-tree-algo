#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9;
int dist[N][N];
int main()
{

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                dist[i][j] = 0; // distance of a vertex to itself is zero
            else
                dist[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    int u, v, wt;
  for (int j = 0; j < m; j++) // taking input of edges
    {
        cin >> u >> v >> wt;
        if(dist[u][v]>wt)
        dist[u][v] = wt;
        if(dist[v][u]>wt)
        dist[v][u]=wt;// updating the dist from u to v as wt
    }

    // Floyd warshal algorithm
    // complexity =n^3

    for (int k = 1; k <= n; k++) // including  kth node
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][k]!=INF and dist[k][j]!=INF)
                // updating distance after including kth node
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]==INF)
            cout<<"I ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}