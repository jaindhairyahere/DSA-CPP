#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &stream, const list<pair<int,int>> l)
{
    for (auto it: l){
        stream << it.first<<" "<<it.second<<",\t";
    }
    return stream;
}
ostream& operator<<(ostream& stream,const vector<list<pair<int,int>>>& v){
    for (size_t i = 0; i < v.size(); i++){
        stream <<'\t'<<i<<"->"<< v[i] <<"\n";
    }
    return stream;
}
class Graph{
    bool directed;
    bool weighted;
    int vertices;
    void DFSUtil(int v, bool visited[]);
    void BFSUtil(int v, bool *visited);
    bool iscyclic;
    bool isbipirite;
public:
    vector<list<pair<int,int>>> adj;
    Graph(int v, bool directed, bool weighted); //Constructor
    void addEdge(int v, int u, int z);
    void DFS(int v);
    void BFS(int v);
    friend ostream &operator<<(ostream &stream, const Graph &g)
    {
        stream << g.adj << "\n";
        return stream;
        }
    bool isWeighted(){
        return weighted;
    }
    bool isDirected(){
        return directed;
    }
    bool isCyclic();
    bool isBipirite();
        
};
Graph::Graph(int v,bool directed=true, bool weighted = false){
    this->vertices = v;
    this->directed = directed;
    this->adj.resize(this->vertices);
    this->weighted = weighted;
}
void Graph::addEdge(int v,int u, int z=1){
    adj[v].push_back({u,z});
    if(!this->directed)
        adj[u].push_back({v,z});
}

void Graph::DFSUtil(int v, bool* visited){
    visited[v] = true;
    cout << v << " ";
    list<pair<int,int>>::iterator i;
    for (i = this->adj[v].begin(); i != this->adj[v].end(); i++)
    {
        if(visited[i->first] == false) DFSUtil(i->first,visited);
        else{this->iscyclic = true;}
    }
}
void Graph::DFS(int v){
      bool visited[this->vertices];
    for (int i = 0; i < this->vertices; i++)
        visited[i] = false;

    DFSUtil(v, visited);
    for (int i = 0; i < this->vertices; i++)
        if (visited[i] == false) 
            DFSUtil(i, visited);
}
void Graph::BFSUtil(int v, bool* visited){

    list<int> queue; 
    list<pair<int,int>>::iterator i;

    visited[v] = true;
    queue.push_back(v);
    
    while (!queue.empty())
    {
        v = queue.front();
        cout << v <<" ";
        queue.pop_front();

        for ( i = adj[v].begin(); i != adj[v].end(); i++)
        {   
        if(visited[i->first] == false){
            
            visited[i->first] = true;
            queue.push_back(i->first);
        }
        }
        
    }
}
void Graph::BFS(int v){
      bool visited[this->vertices];
    for (int i = 0; i < this->vertices; i++)
        visited[i] = false;

    for (int i = 0; i < this->vertices; i++) {
        if (visited[i] == false) 
    BFSUtil(i, visited);}
}
#endif