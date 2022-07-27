#include<bits/stdc++.h>
using namespace std;
int par[500005];
int siz[500005];
void make_set(int i)
{
    par[i]=i;
    siz[i]=1;
}
int find(int i)
{
if(par[i]==i)
return i;

return par[i]=find(par[i]);// path compression
}
void set_union(int a,int b)
{
       a=find(a);
       b=find(b);
       if(a!=b)
       {
          // union by size 
       if(siz[a]<siz[b])
       swap(a,b);
       par[b]=a;
       siz[a]+=siz[b];
}
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        make_set(i);
    }
    int u,v;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v;
        set_union(u,v);
    }
    int connected=0;
    for(int i=1;i<=n;i++)
    {
        if(par[i]==i)
        ++connected;
    }
    cout<<connected<<endl;
}
