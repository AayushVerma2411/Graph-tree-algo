#include<bits/stdc++.h>
using namespace std;
const int mx=100005;
vector<int> indegree(mx,0);
vector<int> adj[mx];

int main()
{
   int n,m;
   cin>>n>>m;
   int u,v;
   for(int i=0;i<m;i++)
   {
     cin>>u>>v;
     indegree[v]++;
     adj[u].push_back(v);

   }
   vector<int> toposort;
   queue<int> q;
   for(int i=1;i<=n;i++)
   {
      if(indegree[i]==0)
      q.push(i);
   }
   int count=0;
   while(q.size())
   {
     int curr_v=q.front();
     q.pop();
     toposort.push_back(curr_v);
     ++count;
     for(auto child:adj[curr_v])
     {
         indegree[child]--;
         if(indegree[child]==0)
         q.push(child);
     }
   }
   if(count==n)
   {
      for(auto it:toposort)
      cout<<it<<" ";
      cout<<endl;
   }
   else
   {
    // in case of cycle count will be greater than n
      cout<<"IMPOSSIBLE\n"; 
   }

}
