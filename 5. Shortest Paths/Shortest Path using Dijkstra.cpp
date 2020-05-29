#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> dist;

void add_edge(vector<pair<int,int> > adj_list[], int u, int v, int weight)
{
    adj_list[u].push_back(make_pair(v, weight));
    adj_list[v].push_back(make_pair(u, weight));
}

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

void Dijkstra(vector<pair<int,int> > adj_list[], int initial, int V){
    queue<int> q;
    q.push(initial);
    visited[initial] = true;
    dist[initial] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int min = INT_MAX;
        int min_node = -1;
        for (auto it = adj_list[curr].begin(); it!=adj_list[curr].end(); it++)
        {
            if(!visited[it->first] && dist[curr]+(it->second) < dist[it->first] ){
                dist[it->first] = dist[curr]+(it->second);
            }
            if(!visited[it->first] && dist[it->first] < min){
                min=dist[it->first];
                min_node = it->first;
            }
        }
        if(min_node == -1)
            break;

        q.push(min_node);
        visited[min_node] = true;
    }
}

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    visited.assign(V, false);
    dist.assign(V, INT_MAX);
    vector<pair<int,int> > adj_list[V];
    int edges;
    cout << "Enter no of edges you want to have: ";
    cin >> edges;
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
            add_edge(adj_list, u, v, weight);
        }
        cout << "\n";
        printGraph(adj_list, V);
        cout << "\nEnter initial and destination vertices : ";
        int initial, dest;
        cin >> initial >> dest;

        Dijkstra(adj_list, initial, V);
        cout << "\nShortest path length from " << initial << " to " << dest << " is : " << dist[dest];

        cout << "\n";
    }
    return 0;
}
