//
// Created by Agaru on 7/1/2025.
//
#include <bits/stdc++.h>
using namespace std;
struct Node {
public:
    int data;
    Node* next;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        next = nullptr;
        left = nullptr;
        right = nullptr;
    }
};
void preOrder(Node* root) {
    if (root==nullptr) return;
    cout << root->data << " -> ";
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    preOrder(root);
    cout << "null" << endl;


}