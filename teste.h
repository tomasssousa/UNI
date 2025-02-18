int height() {
  return height(root);
}

int height(Node* node) {
  if (node == nullptr) return -1;
  return 1 + max(height(node->left), height(node->right));
}

int level() {
  return level(root);
}

int level(Node* node) {
  if (node == nullptr) return -1;
  int l = level(node->left);
}
