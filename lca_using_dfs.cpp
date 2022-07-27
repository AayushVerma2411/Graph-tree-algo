#include<bits/stdc++.h>
using namespace std;
const int lim=1e5+5;
vector<int> adj[lim];
vector<int> parent(lim);
// lca ->lowest common ancestor
// it means the vertex which is on lowest level
// and is common to both other vertex

// first we will store parent of each vertex using dfs
// and the we will find the path from root to both vertex
// and the last common node in both the path is our LCA

// the method performed below calculates lca in O(n)

void dfs(int vertex,int par=-1)
{
    parent[vertex]=par;
    for(auto child:adj[vertex])
    {
        if(child==par)
        continue;
        
           dfs(child,vertex);
    }
}
vector<int> path(int v)
{
    vector<int> ans;
    while(v!=-1)
    {
       ans.push_back(v);
       v=parent[v];

    }
    reverse(ans.begin(),ans.end());

    return ans;
}
int main()
{
    int n,i;
    int a,b;
    cout<<"enter the number of vertices in the graph\n";
    cin>>n;
     for(i=0;i<n-1;i++)
     {
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
     }
     dfs(1);

     cout<<"enter the two nodes bw which we have to find the lca\n";
     cin>>a>>b;
     vector<int> path_a=path(a);
     vector<int> path_b=path(b);;
     int ans=-1;
     for(i=0;i<min(path_a.size(),path_b.size());i++)
     {
         if(path_a[i]==path_b[i])
         {
             ans=path_a[i];
         }
         else
         break;
     }
    
   cout<<ans<<endl;
    return 0;
}