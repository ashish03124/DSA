//
// Created by Agaru on 7/4/2025.
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
vector<int> postOrder(Node* root) {
    vector<int> result;
    if (!root) return result;
    stack<Node*> st1;
    st1.push(root);
    stack<Node*> st2;

    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left) st1.push(root->left);
        if (root->right) st1.push(root->right);
    }
    while (!st2.empty()) {
        result.push_back(st2.top()->data);
        st2.pop();
    }
    return result;

}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = postOrder(root);
    for (int val : result) {
        cout << val << " -> ";
    }
    cout << "null\n" << endl;
    return 0;
}