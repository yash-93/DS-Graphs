#include <bits/stdc++.h>
using namespace std;

int *parent;
vector<pair<int, pair<int,int> > > MST;

int find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void union_set(int u, int v) {
  parent[u] = parent[v];
}

void add_edge(vector<pair<int,int> > adj_list[], int u, int v, int weight)
{
    adj_list[u].push_back(make_pair(v, weight));
    adj_list[v].push_back(make_pair(u, weight));
}

bool compare(const pair<int, pair<int,int> > f, const pair<int, pair<int,int> > s){
    return (f.first < s.first);
}

void kruskal(vector<pair<int, pair<int,int> > > edgesList, int V){
    sort(edgesList.begin(), edgesList.end(), compare);
    int u, v;
    for(auto it=edgesList.begin(); it!=edgesList.end(); it++){
        u = find_set((it->second).first);
        v = find_set((it->second).second);
        if(u != v && MST.size()<V-1){
            MST.push_back(make_pair(it->first, make_pair((it->second).first,(it->second).second )));
            union_set((it->second).first, (it->second).second);
        }
    }
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
        kruskal(edgesList, V);

        //printGraph(adj_list, V);
        for(auto it=MST.begin(); it!=MST.end(); it++){
            cout << "[" << it->first << ",(" << (it->second).first << "," << (it->second).second << ")]" << endl;
        }
    }

    return 0;
}
