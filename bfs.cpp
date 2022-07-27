#include <bits/stdc++.h>
using namespace std;
vector<bool> visit(1e5, 0);
vector<int> level(1e5, 0);
vector<int> adj[100005];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visit[source] = 1;
    while (!q.empty())
    {
        int curr_v = q.front(); // take the first element of queue

        q.pop();
        for (auto child : adj[curr_v])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = 1;
                level[child] = level[curr_v] + 1; // level of child is
                                                  // level of parent plus 1
            }
        }
    }
}

int main()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " level of vertex" << level[i] << endl;
    }
}