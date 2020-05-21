#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

ostream& operator<<(ostream& stream, const vector<int>& g){
    for (size_t i = 0; i < g.size(); i++)
    {
        stream << g[i]<<",";
    }
    return stream;
}

ostream& operator<<(ostream& stream, const vector<vector<int>>& g){
    for (size_t i = 0; i < g.size(); i++)
    {
        stream <<'\t'<<i<<"->"<< g[i]<<endl;
    }
    return stream;
}

bool is_connected(int u,int v, const vector<vector<int>>& g){
    for (size_t i = 0; i < g[u].size(); i++)
    {
        if(g[u][i] == v )
            return true;
    }
    for (size_t i = 0; i < g[v].size(); i++)
    {
        if(g[v][i] == u )
            return true;
    }
    return false;
}

// void DFS(int* visited,vector<vector<int>> g,int root){
//     //visit root
//     if (visited[root]==0)
//     {
//         cout << root;
//         visited[root] = 1;
//     }
//     //visit first child
//     // else()
//     int t = 0;
//     while(visited[g[root][t]])
//         t++;
//     DFS(visited, g, g[root][t]);
// }

int main(int argc, char const *argv[])
{
    freopen("graph.txt", "r", stdin);
    int n = 6, e = 5;
    // cout << "Input N and E: ";
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        // printf("Pair %d : ", i+1);
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<"Printing Graph\n"<< graph<<endl;
    cout << is_connected(1, 2, graph);
    // int visited[6] = {0,0,0,0,0,0};
    // DFS(visited, graph, 1);
    return 0;
}
