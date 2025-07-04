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
    Node* curr = (root);
    stack<Node*> st;
    while (curr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr=curr->left;
        }
        else {
            Node* temp = st.top()->right;
            if (!temp) {
                temp = st.top();
                st.pop();
                result.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->data);
                }
            }
                else {
                    curr = temp;
                }

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
    vector<int> result = postOrder(root);
    for (int val : result) {
        cout << val << " -> ";
    }
    cout << "null\n" << endl;
    return 0;
}
