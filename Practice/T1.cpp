//
// Created by Agaru on 7/3/2025.
//
vector<int> preorder(Node* &root) {
    vector<int> result;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        result.push_back(root->val);
        if (root->right) st.push(root->right);
        if (root->left) st.push(root->left);
    }
}