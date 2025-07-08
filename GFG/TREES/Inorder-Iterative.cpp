//
// Created by Agaru on 7/7/2025.
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

vector<int> inorder(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* temp = root;

    while (temp || !st.empty()) {
        while (temp) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        result.push_back(temp->data);
        temp = temp->right;
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> re = inorder(root);
    for (int r : re) {
        cout << r << " -> ";
    }
    cout << "null";

    return 0;
}
