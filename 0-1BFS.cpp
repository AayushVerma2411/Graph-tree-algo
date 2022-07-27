#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
vector<int> level(1e5, INF);   // we basically play with level
vector<pair<int, int>> adj[100005];  // for storing edge and wt

int n, m;       // n-> no of nodes m-> no of edges

// at a time nodes having at max 2 diff level can be in the queue
// we dont use visited array as a node level can be updated at max 2 time
// first by using an edge weight 1 and next time by using 0 weight edge if exist
// if wt of edge is zero then insert it in front of queue else insert at back 


// Time complexity same as BFS 
int bfs(int source)
{
    deque<int> q;
    q.push_back(source);
    while (!q.empty())
    {
        int curr_v = q.front(); // take the first element of queue
        q.pop_front();
        for (auto child : adj[curr_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (level[curr_v] + wt < level[child_v])
            {

                level[child_v] = level[curr_v] + wt;
                if (wt == 1)
                {
                    q.push_back(child_v);
                }
                else
                {
                    q.push_front(child_v);
                }
            }
        }
    }
    return (level[n]);
}

int main()
{
    int n, u, v, wt;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    bfs(0);
}