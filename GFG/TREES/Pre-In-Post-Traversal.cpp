//
// Created by Agaru on 7/5/2025.
//
//
// Created by Agaru on 7/5/2025.
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
    vector<int> pre;
    vector<int> in;
    vector<int> post;

    stack<pair<Node*,int>> st;
    st.push({root, 1});
    if (!root) return post;
    while (!st.empty()){
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }
    return post;
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