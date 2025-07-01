//
// Created by Agaru on 7/1/2025.
//
// TIME COMPLEXITY -> O(N)
#include <bits/stdc++.h>
using namespace std;
struct Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void preorder(Node* root) {
    if (root==nullptr) return;
    cout << root->data << " -> ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout << "null";



}