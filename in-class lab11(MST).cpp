#include <iostream>
#include <climits>

#define V 6
using namespace std;

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int j = 0; j < V; j++)
    {
        if (mstSet[j] == false && key[j] < min)
        {
            min = key[j];
            min_index = j;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " -- " << i <<"    "<<graph[i][parent[i]] << endl;
    }
}

void prim(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int k = 0; k < V; k++)
    {
        key[k] = INT_MAX;
        mstSet[k] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < V - 1; c++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};

    prim(graph);

    return 0;
}
