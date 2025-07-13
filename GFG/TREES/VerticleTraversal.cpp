#include <bits/stdc++.h>
using namespace std;

struct Node {
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

vector<vector<int>> verticalTraversal(Node* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        
        if (node->left) {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right) {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    vector<vector<int>> result = verticalTraversal(root);
    for (auto col : result) {
        for (int val : col)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
