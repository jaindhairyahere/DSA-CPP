#include<bits/stdc++.h>
#include "graph.h"
using namespace std;

int BellmanFord_ADJ_LIST(Graph& g, int v, int start, int* distances){
    distances[start] = 0;
    for (int k = 0; k < v-1; k++)
    {
        vector<int> q;
        for (size_t j = 0; j < g.adj.size(); j++)
        {
            if (distances[j]==1e6){
                q.push_back(j);
            }
            else
            for (auto &&i : g.adj[j])
                distances[i.first] = min(distances[j] + i.second, distances[i.first]);
        }
        for (auto j : q)
        {
            for (auto &&i : g.adj[j])
                distances[i.first] = min(distances[j] + i.second, distances[i.first]);
            
        }
        
    }
    
}
void print(int* arr,int n){
    for (int i = 0; i < n; i++)
        cout << arr[i]<<" ";
    cout << "\n";
}
void BellmanFord_EDGE_LIST(vector<tuple<int,int,int>> edges, int nodes, int* distances, int start){
    distances[start] = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            if (distances[a] + w < distances[b])
                distances[b] = distances[a] + w;
        }
    }
    print(distances, 7);
    for (int i = 0; i < nodes - 1; i++)
    {
        for (auto &&e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            if (distances[a] + w < distances[b])
                distances[b] = distances[a] + w;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int v=6,e=5;
    freopen("graph.txt", "r", stdin);
    cin >> v >> e;
    int INF = 1e6;  
    
    Graph graph(v,false,true);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        if(graph.isWeighted()) {
            int z;
            cin>>z;
            graph.addEdge(u,v,z);
            edges.push_back(tuple<int,int,int>{u, v, z});
        }

        else{
            graph.addEdge(u,v);
            edges.push_back(tuple<int,int,int>{u, v, 1});
        }
    }
    int v1=0, v2=0;
    cin >> v1 >> v2;
    int distances[graph.adj.size()];
    for (int i = 0; i < graph.adj.size(); i++)
        distances[i] = INF;
    BellmanFord_EDGE_LIST(edges, v, distances,v1);
    print(distances, graph.adj.size());

    for (int i = 0; i < graph.adj.size(); i++)
        distances[i] = INF;
    
    BellmanFord_ADJ_LIST(graph, v, v1, distances);
    print(distances, graph.adj.size());
    return 0;
}