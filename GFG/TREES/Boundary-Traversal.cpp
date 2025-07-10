#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Left boundary (excluding leaf nodes)
void leftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (curr->left || curr->right) res.push_back(curr->data);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// Leaf nodes (in-order)
void leaves(Node* root, vector<int>& res) {
    if (!root) return;
    leaves(root->left, res);
    if (!root->left && !root->right) res.push_back(root->data);
    leaves(root->right, res);
}

// Right boundary (excluding leaf nodes) — stored in reverse
void rightBoundary(Node* root, vector<int>& res) {
    vector<int> temp;
    Node* curr = root->right;
    while (curr) {
        if (curr->left || curr->right) temp.push_back(curr->data);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; --i)
        res.push_back(temp[i]);
}

// Main function
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    res.push_back(root->data); // root is always part of boundary

    leftBoundary(root, res);
    leaves(root, res);
    rightBoundary(root, res);

    return res;
}

// Driver code
int main() {
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
            / \
           8   9
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> boundary = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    for (int val : boundary)
        cout << val << " ";
    cout << endl;

    return 0;
}
