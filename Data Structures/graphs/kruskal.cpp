#include<bits/stdc++.h>
#include "graph.h"
using namespace std;
class UnionFindStructure{
    int v;
    public:
        int* link;
        int* size;
        UnionFindStructure(int v);
        int find(int x);
        bool same(int a, int b);
        void unite(int a, int b);
};

UnionFindStructure::UnionFindStructure(int v){
    this->v = v;
    this->link = new int[v];
    this->size = new int[v];
    for (int i = 1; i <= v; i++)
        link[i] = i;
    for (int i = 1; i <= v; i++) size[i] = 1;
}
int UnionFindStructure::find(int x)
{
    while(x!=link[x])        x = link[x];
    return x;
}

bool UnionFindStructure::same(int a,int b){
    return find(a) == find(b);
}

void UnionFindStructure::unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a]<size[b])
        swap(a, b);
    size[a] += size[b];
    link[b] = a;
}


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



void Kruskal(UnionFindStructure U, vector<tuple<int, int, int>> edges){
    print(U.link, 7);
    for (auto i : edges)
    {
        int a,b,w;
        tie(a, b, w) = i;
        cout << a << " " << b << " " << w << "\n";
        if (!U.same(a, b))
            U.unite(a, b);
        print(U.link, 7);
        cout << "\n\n";
    }
    print(U.link, 7);
}

int main(int argc, char const *argv[])
{
    int v=6,e=5;
    freopen("graph.txt", "r", stdin);
    cin >> v >> e;
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
            if(!graph.isDirected()){
                edges.push_back(tuple<int,int,int>{v, u, z});
                adjMatrix[v][u] = z;
            }
        }
        else{
            graph.addEdge(u,v);
            edges.push_back(tuple<int,int,int>{u, v, 1});
            adjMatrix[u][v] = 1;
        }
    }
    UnionFindStructure KruskalGraph(7);
    Kruskal(KruskalGraph, edges);

    return 0;
}