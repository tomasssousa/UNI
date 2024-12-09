// -------------------------------------------------------------
// Algorithms and Data Structures 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

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
    bool visited; 
    int distance;       // Has the node been visited in a graph traversal?
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

  int outDegree(int v) {
    return nodes[v].adj.size();
  }
  
  int weightedOutDegree(int v){
    int result = 0;
    for(auto i: nodes[v].adj) {
      result += i.weight;
    }
    return result;
  }

  int nrConnectedComponents() {
    int nr = -1;
    for(int v = 0; v <= n; v++) {
      nodes[v].visited = false;
    }
    for(int v = 0; v <= n; v++) {
      if(!nodes[v].visited) {
        nr++;
        nrCC(v);
      }
    }
    return nr;
  }

  void nrCC(int v) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
      int w = e.dest;
      if (!nodes[w].visited)
        nrCC(w);
    }
  }

    //aed058
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

    //aed059
    int diameter() {
        int res = 0;
        int dist = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i != j) {
                    dist = distance(i, j);
                }
                res = std::max(res, dist);
            }
        }
        return res;
    }

};

#endif