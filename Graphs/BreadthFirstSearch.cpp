#include <iostream>
#include <queue>
using namespace std;

void Bfs(int i, int graph[][8], int n) {
  queue<int> q;
  int visited[8] = {0};
  cout << i << "," << flush;
  visited[i] = 1;
  q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v <= n; v++) {
      if (graph[u][v] == 1 && visited[v] == 0) {
        cout << v << "," << flush;
        visited[v] = 1;
        q.push(v);
      }
    }
  }
  cout << endl;
}
int main() {
  int graph[8][8] = {{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 0, 0, 0},
                     {1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0},
                     {0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}};
  int n = 7;
  Bfs(0, graph, n);

  return 0;
}
