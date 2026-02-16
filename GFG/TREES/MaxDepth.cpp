class Solution {
public:

    int solve(Node* root, int level) {
        if(root == NULL)
            return INT_MAX;

        // If leaf node
        if(root->left == NULL && root->right == NULL) {
            if(level % 2 == 1)
                return level;
            else
                return INT_MAX;
        }

        return min(
            solve(root->left, level + 1),
            solve(root->right, level + 1)
        );
    }

    int depthOfOddLeaf(Node *root) {
        int ans = solve(root, 1);

        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};
