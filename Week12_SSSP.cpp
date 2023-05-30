#include <iostream>
#include <climits>
#define V 6 
using namespace std;

int mindis(int distances[],bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int source) {
    int distances[V];
    bool visited[V];
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[source] = 0;

    for (int c = 0; c < V - 1; c++) {
        int u = mindis(distances, visited);
        visited[u] = true;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && graph[u][i] && distances[u] != INT_MAX &&
                distances[u] + graph[u][i] < distances[i]) {
                distances[i] = distances[u] + graph[u][i];
            }
        }
    }

    cout << "source city= " << source << "\n";
    for (int j = 0; j < V; j++) {
        if(j!=source){
            cout << source<<"--->" << j << "   " << distances[j] << "\n";
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
for(int i;i<V;i++){
    int start = i;
    dijkstra(graph, start);
    cout<<"\n";
}


    return 0;
}
