#include<iostream>
#include<list>
#include<stdio.h>
#include<vector>
#include "graph.h"
using namespace std;
bool Graph::isCyclic(){
    // Method 1 - E>=V-1
    // RUN DFS
    bool visited[this->vertices];
        for (int j = 0; j < this->vertices; j++)
            visited[j] = false;
        

    for (int i = 0; i < this->vertices; i++){
        if (visited[i] == false) 
            {
                cout << "New Component";
                Graph::DFSUtil(i, visited);
                if (this->iscyclic == true)
                    return true;}}
    return false;
}

int main(int argc, char const *argv[])
    {
        int v=6,e=5;
        freopen("graph.txt", "r", stdin);
        cin >> v >> e;
        Graph graph(v,false);
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u,v);
        }
        cout << graph;
        cout<<graph.isCyclic();
        return 0;
    }