#include<bits/stdc++.h>
using namespace std;
const int  N=5e4+2;
vector<int>adj[N];
int dp[N][501];
int n,k;
long long int ans=0;
void dfs(int node,int par)
{
  dp[node][0]=1;
  for(auto it:adj[node])
  {
    if(it!=par)
    {
      dfs(it,node);
      for(int i=0;i<=k;i++)
      {
        ans+=(dp[node][i]*dp[it][k-i]);
        dp[node][i]+=dp[it][i];
      }

    }
  }
  for(int i=k;i>=0;i--)
  {
    dp[node][i]=dp[node][i-1];
  }
  dp[node][0]=0;
}
int main()
{
   cin>>n>>k;
   for(int i=1;i<n;i++)
   {
     int x,y;
     cin>>x>>y;
     adj[x].push_back(y);
     adj[y].push_back(x);
   }
   dfs(1,-1);
   cout<<ans<<endl;
}
