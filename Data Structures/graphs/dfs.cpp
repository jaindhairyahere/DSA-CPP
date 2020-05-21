#include<iostream>
#include<list>
#include<stdio.h>
#include<vector>
using namespace std;
ostream& operator<<(ostream& stream,const list<int> l){
    for (auto it: l){
        stream << it<<",";
    }
    return stream;
}
ostream& operator<<(ostream& stream,const vector<list<int>>& v){
    for (size_t i = 0; i < v.size(); i++){
        stream <<'\t'<<i<<"->"<< v[i] <<endl;
    }
    return stream;
}
class Graph{
        int vertices;
        vector<list<int>> adj;
        void DFSUtil(int v, bool visited[]);
    public:
        Graph(int v); //Constructor
        void addEdge(int v, int u);
        void DFS(int v);
        friend ostream &operator<<(ostream &stream, const Graph &g){
            stream << g.adj << endl;
            return stream;
        }
};
Graph::Graph(int v){
    this->vertices = v;
    this->adj.resize(this->vertices);
}
void Graph::addEdge(int v,int u){
    adj[v].push_back(u);
    // adj[u].push_back(v);
}

void Graph::DFSUtil(int v, bool* visited){
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = this->adj[v].begin(); i != this->adj[v].end(); i++)
    {
        if(visited[*i] == false) DFSUtil(*i,visited);
    }
}
void Graph::DFS(int v){
      bool visited[this->vertices];
    for (int i = 0; i < this->vertices; i++)
        visited[i] = false;

    for (int i = 0; i < this->vertices; i++)
        if (visited[i] == false) 
            DFSUtil(i, visited);
}

int main(int argc, char const *argv[])
{
    int v=6,e=5;
    freopen("graph.txt", "r", stdin);
    cin >> v >> e;
    Graph graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(v,u);
    }
    cout << graph;
    graph.DFS(1);
    return 0;
}
