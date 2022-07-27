#include<bits/stdc++.h>
using namespace std;
 const int lim =1e5+5;
 //  a tree is a special graph with n vertices having n-1
 // edges and no cycle 


// for dfs in tree we don't need visited array as
// in tree there are no cycles 
// but we need to make sure that we do not visit the parent
// node again from child so we here pass the parent

//    13
//   1 2
//   1 3
//   1 13
//   2 5
//   3 4 
//   5 6
//   5 7
//   5 8
//   8 12 
//   4 9 
//   4 10
//   10 11

vector<int> depth(lim,0),height(lim,0);
vector<int> adj[lim];
void dfs(int vertex,int par=0)
{
    for(auto child:adj[vertex])
    {
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],(height[child]+1));
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
    for(i=1;i<=n;i++)
    {
        cout<<depth[i]<<" " <<height[i]<<endl;
    }
    return 0;
}