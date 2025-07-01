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
vector<vector<int>> levelWise(Node* root) {
    vector<vector<int>> arr;
    if (root==nullptr) arr;
    queue<Node*> Q;
    Q.push<root>;
    while (!Q.empty()) {
        int size = Q.size();
        vector<int> level;
        for (int i=0;i<size;i++) {
            Node* new_node = Q.front();
            Q.pop();
            if (new_node->left) Q.push(new_node->left);
            if (new_node->right) Q.push(new_node->right);
            level.push_back(new_node->data);
        }
        arr.push_back(level);
    }
    return arr;

}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelWise(root);
    cout << "null";



}