// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Binary Tree
// Last update: 09/11/2024
// -------------------------------------------------------------

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

template <class T> class BTree {
private:
  struct Node {
    T value;            // The value stored on the node
    Node *left, *right; // Pointers to left and right child
  };

  // The tree
  Node *root;           // Pointer to the root node

public:

  // Constructor: initially the tree is empty
  BTree() {
    root = nullptr;
  }

  // Destructor: delete all nodes (garbage collection) [see slide 33]
  ~BTree() {
    destroy(root);
  }

  // Recursively delete left and right subtrees and then current node
  void destroy(Node *n) {
    if (n == nullptr) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
  }


  // ---------------------------------------------------------
  // Count the number of nodes (see slides 13 and 14)
  // ---------------------------------------------------------

  int numberNodes() {
    return numberNodes(root);
  }

  int numberNodes(Node *n) {
    if (n == nullptr) return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
  }

  // ---------------------------------------------------------
  // Height of the tree (see slides 15 and 16)
  // ---------------------------------------------------------

  int height() {
    return height(root);
  }

  int height(Node *n) {
    if (n == nullptr) return -1;
    return 1 + std::max(height(n->left), height(n->right));
  }

  // ---------------------------------------------------------
  // Does the tree contain value 'val'? (see slides 17 and 18)
  // ---------------------------------------------------------

  bool contains(const T & val) {
    return contains(root, val);
  }

  bool contains(Node *n, const T & val) {
    if (n == nullptr) return false;
    if (n->value == val) return true;
    return contains(n->left, val) || contains(n->right, val);
  }

  // ---------------------------------------------------------
  // Print tree in PreOrder (see slides 20 and 21)
  // ---------------------------------------------------------

  void printPreOrder() {
    std::cout << "PreOrder:";
    printPreOrder(root);
    std::cout << std::endl;
  }

  void printPreOrder(Node *n) {
    if (n == nullptr) return;
    std::cout << " " << n->value;
    printPreOrder(n->left);
    printPreOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in InOrder (see slides 22 and 23)
  // ---------------------------------------------------------

  void printInOrder() {
    std::cout << "InOrder:";
    printInOrder(root);
    std::cout << std::endl;
  }

  void printInOrder(Node *n) {
    if (n == nullptr) return;
    printInOrder(n->left);
    std::cout << " " << n->value;
    printInOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in PostOrder (see slides 22 and 24)
  // ---------------------------------------------------------

  void printPostOrder() {
    std::cout << "PostOrder:";
    printPostOrder(root);
    std::cout << std::endl;
  }

  void printPostOrder(Node *n) {
    if (n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    std::cout << " " << n->value;
  }

  // ---------------------------------------------------------
  // Print tree in Breadt-First order using a queue
  // (see slides 25, 26 and 27)
  // ---------------------------------------------------------

  void printBFS() {
    std::cout << "BFS:";

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *cur = q.front();
      q.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        q.push(cur->left);
        q.push(cur->right);
      }
    }

    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Print tree in Depth-First order using a stack
  // (see slides 28 and 29)
  // ---------------------------------------------------------

  void printDFS() {
    std::cout << "DFS:";

    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      Node *cur = s.top();
      s.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        s.push(cur->left);
        s.push(cur->right);
      }
    }

    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Read a tree in PreOrder from standard input
  // (see slides 30, 31 and 32)
  // ---------------------------------------------------------

  void read(std::string null) {
    root = readNode(null);
  }

  Node *readNode(std::string null) {
    std::string buffer;
    std::cin >> buffer;
    if (buffer == null) return nullptr;
    Node *n = new Node;
    std::istringstream ss(buffer);
    ss >> n->value;
    n->left = readNode(null);
    n->right = readNode(null);
    return n;
  }

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  // AED032
  int numberLeafs() {
    return numberLeafs(root);
  }

  int numberLeafs(Node *n) {
    if (n == nullptr) return 0;
    else if (n->left == nullptr && n->right == nullptr) return 1;
    else {return numberLeafs(n->left) + numberLeafs(n->right);}
  }

  // AED033
  bool strict() {
    return strict(root);
  }

  bool strict(Node *n) {
    if (n == nullptr) return true;
    else if (n->left == nullptr && n->right == nullptr) return true;
    else if ((n->left != nullptr && n->right == nullptr) || (n->left == nullptr && n->right != nullptr)) return false;
    else {return strict(n->left) && strict(n->right);}
  }

  // AED034
  T& path(std::string& s) {
    return fpath(root, s);
  }

  T& fpath(Node* n, std::string& s) {
    if (s.empty() || s[0] == '_') return n->value;
    else if (s[0] == 'L') return fpath(n->left, s.substr(1));
    else return fpath(n->right, s.substr(1));
  }

  // AED035
  int nodesLevel(int k) {
    return nodesLevel(root, k, 0);
  }

  int nodesLevel(Node* n, int k, int currentLevel) {
    if (n == nullptr) return 0;
    if (currentLevel == k) return 1;
    return nodesLevel(n->left, k, currentLevel + 1) + nodesLevel(n->right, k, currentLevel + 1);
  }

  // AED036
  int countEven() {
    return countEven(root);
  }

  int countEven(Node* n) {
    if (n == nullptr) return 0;
    int count = (n->value % 2 == 0) ? 1 : 0;
    return count + countEven(n->left) + countEven(n->right);
  }

  // AED037
  std::vector<int> sumLevels() {
    std::vector<int> result;
    if (root == nullptr) return result;

    std::queue<std::pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      Node* current = q.front().first;
      int level = q.front().second;
      q.pop();

      if (level >= result.size()) {
        result.push_back(0);
      }

      result[level] += current->value;

      if (current->left != nullptr) q.push({current->left, level + 1});
      if (current->right != nullptr) q.push({current->right, level + 1});
    }
    return result;
  }

  // AED038
  std::string maxSum() {
    std::string result;
    int maxSum = 0;
    findmaxSum(root, "", 0, maxSum, result);
    return result;
  }

  void findmaxSum(Node* n, std::string path, int currentSum, int& maxSum, std::string& result) {
    if (n == nullptr) return;
    currentSum += n->value;

    if (n->left == nullptr && n->right == nullptr) {
      if (currentSum > maxSum) {
        maxSum = currentSum;
        result = path;
      }
      return;
    }

    findmaxSum(n->left, path + "L", currentSum, maxSum, result);
    findmaxSum(n->right, path + "R", currentSum, maxSum, result);
  }




};



#endif