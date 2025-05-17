#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10000;

vector<int> adj[MAXN]; // Danh sách kề
int dist[MAXN];        // dist[i] là số cạnh từ X đến i

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Đồ thị có hướng
    }

    // Khởi tạo khoảng cách ban đầu = -1 (chưa được thăm)
    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;
    }

    // BFS từ đỉnh X
    queue<int> q;
    q.push(X);
    dist[X] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { // Chưa thăm
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[Y] << endl; // In ra số cạnh từ X đến Y
    return 0;
}

