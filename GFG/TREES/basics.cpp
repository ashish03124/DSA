//
// Created by Agaru on 7/1/2025.
//
 /*TREES
  *Parent/root
  *Nodes/Leaf
  *SubTrees
  *Ancestors
  *Children
  *TYPES OF BINARY TREE
  *     1] full binary TREE
  *     2] complete binary TREE
  *     3] perfect binary TREE
  *     4] balanced binary TREE
  *     5] Degenerate binary TREE
  */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data=val;
        left=nullptr;
        right=nullptr;

    }

};
int main() {
    struct Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right = new Node(5);
}