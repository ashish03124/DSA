//
// Created by Agaru on 7/6/2025.
//
#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

int measure(Node *root, int &dia) {
    if (!root) return 0;
    int lh = measure((root->left), dia);
    int rh = measure((root->right), dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int diameter(Node *root) {
    int dia = 0;
    measure(root, dia);
    return dia;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);

    int result = diameter(root);
    cout << result << "\n" << endl;
    return 0;
}
