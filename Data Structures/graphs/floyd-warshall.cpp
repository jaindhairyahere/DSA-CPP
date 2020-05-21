#include<bits/stdc++.h>
#include "graph.h"
using namespace std;
void print(int* arr,int n){
    for (int i = 0; i < n; i++)
        cout << arr[i]<<" ";
    cout << "\n";
}
void print2(int* arr,int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; i++)
            cout << arr[i]<<" ";
        cout << "\n";
    }
}


void FloydWarshall_ADJ_MATRIX(int* m[7], int v1, int v2, int* distances){
    
    
}


int main(int argc, char const *argv[])
{
    int v=6,e=5;
    freopen("graph.txt", "r", stdin);
    cin >> v >> e;
    int INF = 1e6;  
    
    Graph graph(v,false,true);
    vector<tuple<int, int, int>> edges;
    int adjMatrix[v][v] = {0};
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j]=0;
        }
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        if(graph.isWeighted()) {
            int z;
            cin>>z;
            graph.addEdge(u,v,z);
            edges.push_back(tuple<int,int,int>{u, v, z});
            adjMatrix[u][v] = z;
        }

        else{
            graph.addEdge(u,v);
            edges.push_back(tuple<int,int,int>{u, v, 1});
            adjMatrix[u][v] = 1;
        }
    }
    int v1=0, v2=0;
    cin >> v1;
    int distance[v][v] = {0};
    
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            if (i == j) distance[i][j] = 0;
            else if (adjMatrix[i][j]) distance[i][j] = adjMatrix[i][j];
            else distance[i][j] = INF;
        }
 
    // FloydWarshall_ADJ_MATRIX(adjMatrix, v1, v2, distances);
    for (int k = 0; k < v; k++)
        for (int j = 0; j < v; j++)
            for (int i = 0; i < v; i++)
            {
                distance[i][j] = min(distance[i][j], min(distance[i][k] + distance[k][j],999990));
            }
    
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++)
            cout << distance[i][j]<<"\t";
        cout << "\n";
    }
    return 0;
}