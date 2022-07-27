#include<bits/stdc++.h>
using namespace std;
const int lim=1e5+5;
vector<int> adj[lim];
vector<int> depth(lim,0);
// diameter of a tree is the max dist bw any two nodes
// brute force way can be to calculate the dist of every node
// from each node and find the max 
// but since this will go as n*n we do not apply this

// max dist bw any nodes is going to be the dist
// bw two nodes with greatest depth 

// so first we do the dfs and find one vertex with max depth
// then we will set the depth of all equal to zero
// and do the bfs again but now from the finded vertex as root
// finally we find the max depth from this vertex
// and that is our answer.

void dfs(int vertex,int par=0)
{
    for(auto child:adj[vertex])
    {
        if(child==par)
        continue;
        depth[child]=depth[vertex]+1;
           dfs(child,vertex);
    }
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
     int mx_depth=-1,mx_depth_vert;
     for(i=1;i<=n;i++)
     {
         cout<<i<<" "<<depth[i]<<endl;
     }
    for(i=1;i<=n;i++)
    {
      if(depth[i]>mx_depth) 
      {
          mx_depth=depth[i]; // finding one node with mx depth
          mx_depth_vert=i;
      }
      depth[i]=0; // setting all depth equal to zero 
    }

    dfs(mx_depth_vert); // performing dfs from finded vertex
    for(i=1;i<=n;i++)
     {
         cout<<i<<" "<<depth[i]<<endl;
     }
    int ans=-1;
    for(i=1;i<=n;i++)
    {
        ans=max(ans,depth[i]);
    }
    cout<<"diameter of the tree " <<ans<<endl;
    return 0;
}