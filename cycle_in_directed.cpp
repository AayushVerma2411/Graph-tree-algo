#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100005];
vector<char> color(100005,0);
vector<int> parent(100005,-1);
int cycle_start, cycle_end;

bool dfs(int v)
{
    color[v] = 1;
    for (int u : adj[v])
    {
        if (color[u] == 0)
        {
            parent[u] = v;
            if (dfs(u))
                return true;
        }
        else if (color[u] == 1)
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle()
{
  
    cycle_start = -1;

    for (int v = 0; v < n; v++)
    {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1)
    {
       // cout << "Acyclic" << endl;
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

       // cout << "Cycle found: ";
       cout<<cycle.size()<<endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
int main()
{
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
      cin>>u>>v;
      adj[u].push_back(v);
    }
    find_cycle();

}