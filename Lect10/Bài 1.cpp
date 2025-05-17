#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000; // Giới hạn số đỉnh

vector<int> adj[MAXN];  // Danh sách kề
bool visited[MAXN];     // Đánh dấu đỉnh đã duyệt

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Đọc các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  // Vì đồ thị vô hướng
    }

    int connectedComponents = 0;

    // Duyệt các đỉnh, bắt đầu DFS nếu chưa được thăm
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ++connectedComponents;
            dfs(i);
        }
    }

    cout << connectedComponents << endl;

    return 0;
}
