#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

class Graph {
  struct Edge {
    int dest;   // Destination node
    int weight; // An integer weight
  };

  struct Node {
    std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    bool visited;        // Has the node been visited in a graph traversal?
  };

  int n;                   // Graph size (vertices are numbered from 1 to n)
  bool hasDir;             // false: undirected; true: directed
  std::vector<Node> nodes; // The list of nodes being represented

public:
  // Constructor: nr nodes and direction (default: undirected)
  Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num+1) {}

  // Add edge from source to destination with a certain weight
  void addEdge(int src, int dest, int weight = 1) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
  }

  // --------------------------------------------------------------

  // Read a graph in the format:
  // nr_nodes directed/undirected weighted/unweighted
  // nr_edges
  // src_1 dest_1 <weight_1>
  // src_2 dest_2 <weight_2>
  // ...
  // src_n dest_n <weight_n>
  static Graph *readGraph() {
    int n;
    std::string sdirection, sweight;
    std::cin >> n >> sdirection >> sweight;
    bool directed = (sdirection == "directed")?true:false;
    bool weighted = (sweight == "weighted")?true:false;

    Graph *g = new Graph(n, directed);
    int e;
    std::cin >> e;
    for (int i=0; i<e; i++) {
      int u, v, w = 1;
      std::cin >> u >> v;
      if (weighted) std::cin >> w;
      g->addEdge(u, v, w);
    }
    return g;
  }

  // --------------------------------------------------------------
  // Depth-First Search (DFS): example implementation
  // --------------------------------------------------------------
  void dfs(int v) {
    std::cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        dfs(w);
    }
  }

  // --------------------------------------------------------------
  // Breadth-First Search (BFS): example implementation
  // --------------------------------------------------------------
  void bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    std::queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
      int u = q.front(); q.pop();
      std::cout << u << " ";  // show node order
      for (auto e : nodes[u].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
          q.push(w);
          nodes[w].visited = true;
        }
      }
    }
  }


  // --------------------------------------------------------------
  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------


  // AED051
  int nrConnectedComponents() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
      nodes[i].visited = false;
    }
    for (int i = 1; i <= n; i++) {
      if (!nodes[i].visited) {
        count++;
        exploreComponent(i);
      }
    }
    return count;
  }

  void exploreComponent(int v) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited) {
        exploreComponent(w);
      }
    }
  }


  // AED052
  int largestComponent() {
    int largest = 0;
    for (int i = 1; i <= n; i++) {
      nodes[i].visited = false;
    }
    for (int i = 1; i <= n; i++) {
      if (!nodes[i].visited) {
        int size = exploreComponentSize(i);
        largest = std::max(largest, size);
      }
    }
    return largest;
  }

  int exploreComponentSize(int v) {
    nodes[v].visited = true;
    int size = 1;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if(!nodes[w].visited) {
        size += exploreComponentSize(w);
      }
    }
    return size;
  }


  // AED053
  std::list<int> topologicalSorting() {
    std::vector<int> indegree(n + 1, 0);
    std::list<int> order;
    std::queue<int> q;

    for (int i = 1; i <= n; i++) {
        for (auto e : nodes[i].adj) {
            indegree[e.dest]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order.push_back(v);

        for (auto e : nodes[v].adj) {
            int w = e.dest;
            indegree[w]--;
            if (indegree[w] == 0) {
                q.push(w);
            }
        }
    }

    return order;
  }


  // AED054
  bool hasCycle() {
    std::vector<int> state(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            if (dfsCycle(i, state)) {
                return true;
            }
        }
    }
    return false;
  }

  bool dfsCycle(int v, std::vector<int>& state) {
    state[v] = 1;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (state[w] == 1) {
            return true;
        }
        if (state[w] == 0) {
            if (dfsCycle(w, state)) {
                return true;
            }
        }
    }
    state[v] = 2;
    return false;
  }


  // AED055
  bool isBipartite() {
    std::vector<int> color(n + 1, -1);
    std::queue<int> q;
    q.push(1);
    color[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : nodes[v].adj) {
            int w = e.dest;
            if (color[w] == -1) {
                color[w] = 1 - color[v];
                q.push(w);
            } else if (color[w] == color[v]) {
                return false;
            }
        }
    }
    return true;
  }


  // AED058
  int distance(int a, int b) {
    if(a == b) return 0;

    for(int i = 1; i <= n; i++) {
      nodes[i].visited = false;
      nodes[i].distance = 0;
    }

    std::queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    while(!q.empty()){
      int u = q.front();
      q.pop();

      for(auto& e : nodes[u].adj){
        int w = e.dest;
        if(!nodes[w].visited){
          q.push(w);
          nodes[w].visited = true,
          nodes[w].distance = nodes[u].distance +1;
          if(w == b){
            return nodes[w].distance;
          }
        }
      }
    }
    return -1;
  }


  //AED059
  int diameter() {
    if (!isConnected()) return -1;
    int farthestNode = bfsFarthestNode(1);
    return bfsLongestShortestPath(farthestNode);
  }

  bool isConnected() {
    std::vector<bool> visited(n + 1, false);
    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    int visitedCount = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visitedCount++;
        for (auto e : nodes[v].adj) {
            int w = e.dest;
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
    return visitedCount == n;
  }

  int bfsFarthestNode(int start) {
    std::vector<int> distance(n + 1, -1);
    std::queue<int> q;
    q.push(start);
    distance[start] = 0;
    int farthestNode = start;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : nodes[v].adj) {
            int w = e.dest;
            if (distance[w] == -1) {
                distance[w] = distance[v] + 1;
                q.push(w);
                if (distance[w] > distance[farthestNode]) {
                    farthestNode = w;
                }
            }
        }
    }
    return farthestNode;
  }

  int bfsLongestShortestPath(int start) {
    std::vector<int> distance(n + 1, -1);
    std::queue<int> q;
    q.push(start);
    distance[start] = 0;
    int maxDistance = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : nodes[v].adj) {
            int w = e.dest;
            if (distance[w] == -1) {
                distance[w] = distance[v] + 1;
                q.push(w);
                maxDistance = std::max(maxDistance, distance[w]);
            }
        }
    }
    return maxDistance;
  }


  // AED062



};

#endif