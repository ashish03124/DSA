//
// Created by Agaru on 7/6/2025.
//
#include <bits/stdc++.h>
using namespace std;
struct Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

bool identity(Node* root1, Node* root2) {
    if (!root1 || !root2) {
        return root1==root2;
    }
    return (root1->data == root2->data) &&
    identity(root1->left, root2->left) &&
    identity(root1->right, root2->right);
}
int main() {
    struct Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left= new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    root1->right->right->right = new Node(8);
    struct Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left= new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    root2->right->right->right = new Node(8);

    bool result = identity(root1, root2);
    cout <<  result << "\n" << endl;
    return 0;
}
