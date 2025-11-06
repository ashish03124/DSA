#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> t; /// declaring the dp

    int lcs(string &s1, string &s2, int i, int j) {
        if (i == 0 || j == 0) return 0; /// if anyone of the string is empty then return Zero
        if (t[i][j] != -1) return t[i][j]; /// as our dp is filled with -1 so when there is no element as -1 in our dp then return the dp as it is
        if (s1[i-1] == s2[j-1]) // is the element is same
            return t[i][j] = 1 + lcs(s1, s2, i-1, j-1); /// then find the length of the longest common subs with + 1 for the first common one
        return t[i][j] = max(lcs(s1, s2, i-1, j), lcs(s1, s2, i, j-1)); /// or else just return the max of the first length + 1, or second length +1
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        t.assign(n+1, vector<int>(m+1, -1)); /// asssiging the -1 to the whole dp of size m+1
        lcs(str1, str2, n, m);

        string ans = ""; /// empty string
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--; j--;
            }
            else if (t[i-1][j] > t[i][j-1]) {
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }
        while (i > 0) ans += str1[i-1], i--;
        while (j > 0) ans += str2[j-1], j--;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence: " << result << endl;

    return 0;
}
