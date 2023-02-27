#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 100;

int n; // number of vertices
vector<int> adj_list[MAX_N]; // adjacency list representation of the graph
bool visited[MAX_N]; // array to keep track of visited vertices

void dfs(int v) {
    stack<int> s;
    s.push(v); // push the starting vertex onto the stack
    visited[v] = true;
    cout << "Pushed vertex " << v << endl;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << "Popped vertex " << u << endl;
        for (int i = 0; i < adj_list[u].size(); i++) {
            int w = adj_list[u][i];
            if (!visited[w]) {
                s.push(w);
                visited[w] = true;
                cout << "Pushed vertex " << w << endl;
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
    dfs(2); // start from vertex 2
    return 0;
}
