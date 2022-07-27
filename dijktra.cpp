#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e19;
vector<bool> visited(100005,0);
vector<ll> dist(100005, INF);
vector<pair<ll,ll>> adj[100005];
vector<ll> par(100005,0);

void dijktra(ll source=1)
{
    set<pair<ll,ll>> st;
    st.insert({0, source});
    dist[source] = 0;
    par[source]=1;

    while (st.size() != 0)
    {
        auto node = *st.begin();
        ll v = node.second;
        ll d = node.first;
        st.erase(st.begin());
        if (visited[v] == 1)
            continue;
        visited[v] = 1;
        for (auto child : adj[v])
        {
            ll child_v = child.first;
            ll wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                par[child_v]=v;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    // ll mx = -1;           
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (dist[i] == INF)
    //         return -1;                     return -1 if all
                                              //node are not accessible
                                              // else return max access time
    //     else
    //         mx = max(mx, dist[i]);
    // }
    // return mx;

}

int main()
{
    ll n, m, i;
    cin >> n >> m;
    ll u, v, wt;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
     dijktra();
     vector<ll> path;  // for printing the path
     ll start=n;
     while(start!=-1)
     {
        path.push_back(start);
        start=par[start];
     }
     for(auto it:path)
     cout<<it<<" ";

     cout<<endl;

    
}