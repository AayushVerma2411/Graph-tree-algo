#include<bits/stdc++.h>
using namespace std;
const int lim =1e5+5;

vector<int> adj[lim];
vector<int> subtree_sum(lim,0);
// given q queries where q<=1e5
// find the subtree sum of node v 
// here weight of a vertex is equal to number of that vertex

// generally subtree se related problem hum neeche se upar
// ya keh skte hai backtrack krte hue krte hai 
// aur generally humko subtree related problems mei
// humko pre compute krke rkhna padta hai 
void dfs(int vertex,int par=0)
{ 
    subtree_sum[vertex]+=vertex;
    for(auto child:adj[vertex])
    {
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }  
    
}
int main()
{
    int n,i;
    int a,b;
    cout<<"enter the number of vertices in the tree\n";
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
      cout<<subtree_sum[i]<<endl;
    }
    return 0;
}