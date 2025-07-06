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

int isBalanced(Node* root) {
    if (!root) return 0;
    int lh = isBalanced(root->left);
    if (lh == -1) return -1;
    int rh = isBalanced(root->right);
    if (rh == -1) return -1;
    if((lh - rh) > 1) return -1;
    return 1 + max(lh , rh);
}
bool check(Node* root) {
    return isBalanced(root) != -1;
}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if ( check(root)) {
        cout  << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
        return 0;
}