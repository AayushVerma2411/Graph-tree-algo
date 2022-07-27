#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<bool> visited(100005,0);
vector<int> parent(100005,-1);
int cycle_start, cycle_end;

bool dfs(int v, int par)
{ 
    visited[v] = true;
    for (int u : adj[v])
    {
        if (u == par)
            continue;
        if (visited[u])
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle(int n,int m)
{
    
    cycle_start = -1;

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        //cout << "Acyclic" << endl;
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        //cout << "Cycle found: ";
        cout<<cycle.size()<<endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    find_cycle(n,m);

}