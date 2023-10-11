#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
int nodecount ,edgecount;
void dijkstra(int src,vector<vector<int>>G[1005],int dist[])
{
priority_queue <pii,vector<pii>,greater<pii> >pq;
pq.push({0,src});
dist[src]=0;
while(!pq.empty())
{
    int u = pq.top().second;
    pq.pop();
     int sz = G[u].size();
     for(auto v : G[u])
     {
         int cost = dist[u]+ v[1];
         if(dist[v[0]]>cost)
         {

             dist[v[0]]=cost;
             pq.push({cost,v[0]});
         }

     }
}


}
int main (){
cin>> nodecount>>edgecount;
int dist[nodecount];
vector<vector<int>>G[1005];
for (int i=1;i<=nodecount;i++)
{

    dist[i]=INT_MAX /2;
}
for(int i=1;i<= edgecount;i++)
{
     int u,v,weight;
     cin>> v>>weight;
     G[u].push_back({v,weight});
     G[v].push_back({u,weight});
}
dijkstra(0,G,dist);
for(int i=0;i<= nodecount;i++)
    cout<<dist[i]<<endl;
return 0;
}
