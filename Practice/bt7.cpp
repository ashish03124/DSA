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
vector<int> inOrder(Node* root) {
    vector<int> result;
    if (!root) return result;
    stack<Node*> st;
    Node* temp = root;
    while (true) {
        if (temp) {
            st.push(temp);
            temp=temp->left;
        }
        else {
            if ( st.empty()) break;
            temp = st.top();
            st.pop();
            result.push_back(temp->data);
            temp = temp->right;
        }
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
    vector<int> result = inOrder(root);
    for (int val : result) {
        cout << val << " -> ";
    }
    cout << "null\n" << endl;
    return 0;
}