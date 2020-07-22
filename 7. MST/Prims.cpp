#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<pair<int,int> > adj_list[], int u, int v, int weight)
{
    adj_list[u].push_back(make_pair(v, weight));
    adj_list[v].push_back(make_pair(u, weight));
}

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void prims(vector<pair<int,int> > adj_list[]){
    int V = adj_list.size();
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++){
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }

    }

}

/*
void printGraph(vector<pair<int,int> > adj_list[], int V){
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << ": ";
        for (auto it = adj_list[u].begin(); it!=adj_list[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "(" << v << ", " << w << ")" << "->";
        }
        cout << "\n";
    }
}
*/

int main(){
    int V;

    parent = new int[V];
    for (int i = 0; i < V; i++){
        parent[i] = i;
    }

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<pair<int,int> > adj_list[V];

    int edges;
    cout << "Enter no of edges you want to have: ";
    cin >> edges;

    vector<pair<int, pair<int,int> > > edgesList;

    int max_edges = (V*(V-1))/2;

    if( edges > max_edges ){
        cout << "Max edge limit exceeded. Exiting...";
        exit(0);
    }
    else{
        int u, v, weight;

        for(int i=0; i<edges; i++){
            cout << "Enter vertex endpoints and weight(u v weight): ";
            cin >> u >> v >> weight;
            edgesList.push_back(make_pair(weight, make_pair(u,v)));
            add_edge(adj_list, u, v, weight);
        }

        cout << "\n";
        prims(adj_list);

        //printGraph(adj_list, V);
    }

    return 0;
}
