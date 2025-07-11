//
// Created by Agaru on 7/11/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node (int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

// returns 1 if children sum property holds
// for the given node and both of its children
int isSumProperty(Node* root) {

    // If root is NULL
    // then return true
    if (root == nullptr)
        return 1;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // if this node is a leaf node,
        // then continue
        if (curr->left == nullptr &&
            curr->right == nullptr)
            continue;

        int sum = 0;

        // If left child is not present then 0
        // is used as data of left child
        if (curr->left != nullptr) {
            sum += curr->left->data;
        }

        // If right child is not present then 0
        // is used as data of right child
        if (curr->right != nullptr) {
            sum += curr->right->data;
        }

        // if current node does not
        // follow the property, then
        // return 0.
        if (curr->data != sum)
            return 0;

        // Push the left child node
        if (curr->left != nullptr)
            q.push(curr->left);

        // Push the right child node
        if (curr->right != nullptr)
            q.push(curr->right);
    }

    return 1;
}

int main() {

    // Create a hard coded tree.
    //         35
    //       /   \
    //      20    15
    //     /  \  /  \
    //   15   5 10   5
    Node* root = new Node(35);
    root->left = new Node(20);
    root->right = new Node(15);
    root->left->left = new Node(15);
    root->left->right = new Node(5);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    cout << isSumProperty(root) << endl;
    return 0;
}