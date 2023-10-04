#include<bits/stdc++.h>
using namespace std;

int nodeCount, edgeCount;
bool vis[1005];

void bfs (int src, vector <int>G[1005])
{
    queue <int>q;
    q.push (src);
    vis [src]=true;

    while (!q.empty())
    {
        int u=q.front();
        cout<< u <<endl;
        q.pop();
        for (auto v : G[u])
        {
            if (! vis [v])
            {
                vis [v]=true;
                q.push (v);
            }
        }
    }
}

int main()
{
    cin>>nodeCount>>edgeCount;
        memset(vis,false,sizeof(vis));
        vector <int>G[1005];

    for (int i=1; i<=edgeCount; i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back (b);
    }
    bfs(2,G);
}
