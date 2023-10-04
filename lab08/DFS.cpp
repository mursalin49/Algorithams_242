#include<bits/stdc++.h>
using namespace std;
int nodeCount,edgeCount;
bool vis[1005];
void dfs(int src,vector<int>G[1005])
{
    vis[src]=true;
    cout<<src<<endl;
    for(auto v:G[src])
    {
        if(vis[v]==false)


        {
            vis[v]=true;
            dfs(v,G);
        }
    }
}
int main()
{
    cin>>nodeCount>>edgeCount;
    memset(vis,false,sizeof(vis));
    vector <int>G[1005];
    for(int i=1;i<=edgeCount;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    dfs(2,G);
}
