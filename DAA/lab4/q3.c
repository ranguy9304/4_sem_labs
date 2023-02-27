#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100;

int n; // number of vertices
vector<int> adj_list[MAX_N]; // adjacency list representation of the graph
bool visited[MAX_N]; // array to keep track of visited vertices

void bfs(int v) {
    queue<int> q;
    q.push(v); // push the starting vertex onto the queue
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "Visited vertex " << u << endl;
        for (int i = 0; i < adj_list[u].size(); i++) {
            int w = adj_list[u][i];
            if (!visited[w]) {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}

int main() {
    n = 6;
    adj_list[0].push_back(1);
    adj_list[0].push_back(2);
    adj_list[1].push_back(2);
    adj_list[2].push_back(0);
    adj_list[2].push_back(3);
    adj_list[3].push_back(3);
    adj_list[3].push_back(4);
    adj_list[4].push_back(5);
    adj_list[5].push_back(5);
    bfs(2); // start from vertex 2
    return 0;
}
