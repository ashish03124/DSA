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
int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);

}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    int result = height(root);
    cout << result << " -> ";
    cout << "null\n" << endl;
    return 0;
}