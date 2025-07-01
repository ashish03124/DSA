//
// Created by Agaru on 7/1/2025.
//
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* left;
    Node* right;
    Node(int val) {
        next = nullptr;
        left = nullptr;
        right  = nullptr;
    }
};
void levelWise(Node* root) {
    vector<vector<int>> and;
    queue<int> Q;

}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

}
