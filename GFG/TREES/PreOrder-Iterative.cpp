//
// Created by Agaru on 7/3/2025.
//
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
        next= nullptr;

    }
};
vector<int> preOrder(Node* &root) {
    vector<int> pre;
    if (!root) return pre;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        pre.push_back(root->data);
        if (root->right) {
            st.push(root->right);
        }
        if (root->left) {
            st.push(root->left);
        }

    }
    return pre;
}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    vector<int> result = preOrder(root);
    for (int val : result) {
        cout << val << "-> ";
    }
    cout << "null\n";
    return 0;
}