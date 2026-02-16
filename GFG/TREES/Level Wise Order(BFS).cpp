//
// Created by Agaru on 7/1/2025.
//
// TIME COMPLEXITY -> O(N)
/*
*          BSF->
 *                     [1]               ------>Level 1
 *                    /    \
 *               [2]         [3]         ------>Level 2
 *              /   \       /  \
 *           [4]    [5]   [6]   [7]      ------>Level 3
 *
 *       arr = {}                          Queue =
 *                                                 |    7   |
 *                                                 |    6   |
 *                                                 |    5   |
 *                                                 |    4   |                                                   |    4  |
 *                                                 |    3   |
 *                                                 |    2   |
 *                                                 |    1   |
 *                                                 __________
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
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
    if (root == nullptr) return arr;

    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node* new_node = Q.front();
            Q.pop();
            level.push_back(new_node->data);
            if (new_node->left) Q.push(new_node->left);
            if (new_node->right) Q.push(new_node->right);
        }
        arr.push_back(level);
    }
    return arr;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = levelWise(root);

    // Printing the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
