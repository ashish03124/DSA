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
int MaxDepth(Node* root) {
    if (!root) return 0;
    int leftHand = MaxDepth(root->left);
    if (leftHand == -1) return -1;
    int rightHand = MaxDepth(root->right);
    if (rightHand == -1) return -1;
    if (abs(leftHand-rightHand) > 1) return -1;
    return 1 + max(leftHand, rightHand);
}
bool check(Node* root) {
    return MaxDepth(root) != -1;
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

    if (check(root)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}