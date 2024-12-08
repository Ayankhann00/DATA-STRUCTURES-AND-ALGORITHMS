void DFS(int graph[][8], int start, int n, int visited[]) {
  if (visited[start] == 0) {
    cout << start << ", " << flush;
    visited[start] = 1;

    for (int v = 0; v < n; v++) {
      if (graph[start][v] == 1 && visited[v] == 0) {
        DFS(graph, v, n, visited);
      }
    }
  }
}
