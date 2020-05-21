#include<bits/stdc++.h>
#include "graph.h"
using namespace std;
void print(int* arr,int n){
    for (int i = 0; i < n; i++)
        cout << arr[i]<<" ";
    cout << "\n";
}
int Dijkastra_ADJ_LIST(Graph& g, int v1, int v2,int* distances){
    distances[v1] = 0;
    int relax = 0;
    while (relax <= 2*g.adj.size() - 1)
    {
        bool visited[g.adj.size()] = {0};
        bool update = 0;
        list<int> q;
        q.push_back(v1);
        while (!q.empty())
        {
            int f = q.front();
            visited[f] = 1;
            for (auto &i : g.adj[f])
            {
                if(!visited[i.first]){
                if(i.second + distances[f] < distances[i.first]){
                    distances[i.first] = i.second + distances[f];
                    update = 1;}
                q.push_back(i.first);}
            }
            q.pop_front();
        }
        relax += 1;
        if (relax>=g.adj.size() && update)
        {
            cout << "NEGATIVE CYCLE ENCOUNTERED! ABORTING";
            return -1e7;
        }
    }
    return distances[v2];
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
    Dijkastra_ADJ_LIST(graph, v1, v2, distances);
    print(distances, graph.adj.size());
    return 0;
}