#include <bits/stdc++.h>
using namespace std;
vector<bool> visit(100005);
vector<int> adj[100005];
vector<int> dis;
void dfs(int n)
{
    visit[n] = true;
    cout << n << " ";
    for (auto child : adj[n])
    {
        // take action on node after entering the node
        if (!visit[child])
        {
            // take action on child before entering child node
            dfs(child);
            // take action on child after exiting child node
        }
        // take axtion on node before exiting the node 
    }
}
int main()
{
    int n, m;
    cout << "enter the nodes\n";
    cin >> n;
    cout << "enter the number of edges\n";
    cin >> m;
    while (m-- > 0)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
            dfs(i);
    }
}