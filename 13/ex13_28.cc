#include <string>

class TreeNode {
public:
  TreeNode(): count(new int(1)), left(nullptr), right(nullptr) { }
  TreeNode(const TreeNode &rhs): 
    value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
  TreeNode& operator=(const TreeNode &rhs) {
    ++*rhs.count;
    if (--*count == 0) {
      delete left;
      delete right;
      delete count;
    }
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    count = rhs.count;
    return *this;
  }
  ~TreeNode() {
    if (--*count == 0) {
      delete left;
      delete right;
      delete count;
    }
  }

private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};   

class BinStrTree {
public:
  BinStrTree(): root(new TreeNode()) { }
  BinStrTree(const BinStrTree &bst): root(new TreeNode(*bst.root)) { }
  BinStrTree& operator=(const BinStrTree &bst) {
    auto newr = new TreeNode(*bst.root);
    delete root;
    root = newr;
    return *this;
  }
  ~BinStrTree() { delete root; }

private:
  TreeNode *root;
};     


int main()
{
  return 0;
}
