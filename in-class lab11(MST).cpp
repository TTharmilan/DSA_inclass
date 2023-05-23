#include <bits/stdc++.h>
using namespace std;
#define V 6
bool createMST(int u, int v, vector<bool> inMST){
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
        return true;
}
void printMST(int adj[][V]){
    vector<bool> inMST(V, false);
    inMST[0] = true;
    int c = 0;
    while (c < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] < min) {
                    if (createMST(i, j, inMST)) {
                        min = adj[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            cout<<a<<" -- "<<b<<"    "<<min<<endl;
            c++;
            inMST[b] = inMST[a] = true;
        }
    }
}
int main() {
    int adj[][V] =
    { { INT_MAX, 3, INT_MAX, INT_MAX, INT_MAX , 1 },
    { 3, INT_MAX, 2, 1, 10, INT_MAX },
    { INT_MAX, 2, INT_MAX,3, INT_MAX, 5 },
    {   INT_MAX,1,3,  INT_MAX, 5, INT_MAX },
    {  INT_MAX,10, INT_MAX, 5, INT_MAX, 4 },
    { 1,  INT_MAX,5,  INT_MAX, 4, INT_MAX }, };
    printMST(adj);
    return 0;
}
