#include<bits/stdc++.h>
using namespace std;
const int mx=100005;
vector<pair<int,pair<int,int>>> edge;

vector<int> par(mx),siz(mx);

int find(int n)
{
   if(par[n]==n)
   return n;
   else
   {
      return par[n]=find(par[n]);
   }
}
void Union(int a,int b)
{
   a=find(a);
   b=find(b);
   if(a==b)
   return;
   if(siz[a]<siz[b])
   swap(a,b);
   siz[a]+=siz[b];
   par[b]=a;
}


int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
      par[i]=i;
      siz[i]=1;
   }
   int u,v,wt;
   for(int i=0;i<m;i++)
   {
      cin>>u>>v>>wt;
      edge.push_back({wt,{u,v}});
      
   }
   sort(edge.begin(),edge.end());
   long long cost=0;
   for(auto it:edge)
   {
      int wt=it.first;
      int a=it.second.first;
      int b=it.second.second;
      if(find(a)==find(b))
      {
         continue;
      }
      Union(a,b);
      cost+=wt;


   }
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
      if(par[i]==i)
      ++cnt;
   }
   if(cnt>1)
   cout<<"IMPOSSIBLE\n";
   else
cout<<cost<<endl;
   

}
