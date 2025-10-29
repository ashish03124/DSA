//
// Created by Agaru on 10/29/2025.
//
// Longest Palindrome Substring

// s = babad ==> bab,aba
 /*ITERATIVE
  *
  *     i = 0
  *     j = n-1
  *     while(i<=j){
  *     if(s[i] == s[j]{
  *     i++;
  *     j--;
  *     }
  *     else{
  *     return false;
  *     }
  *
  *
  *RECURSIVE
  *     solve(int i, int j){
  *     if(i >=j ){
  *     return true;
  *     }
  *     if(s[i]==s[j]){
  *     return solve(i++, j--);
  *     }
  *     else {
  *     return false;
  *     }
  *     }
  */
//Dry RUN
/* s = b a b a d
 *     0 1 2 3 4
 * i = 0;
 * j = j - i + 1;
 *maxlength = 0;
 * use the Recursion + memoization
 */
// #include <bits/stdc++.h>
// using namespace std;
// bool solve(string s, int i, int j) {
//     if (i >= j) {
//         return true;
//     }
//     if (s[i]==s[j]) {
//         return solve(s, i+1, j-1);
//     }
//     return false;
//
// }
// string longestpalindrome(string s) {
//     int n = s.length();
//     int maxlength = INT_MIN;
//     int sp = 0;
//     for (int i=0;i<n;i++) {
//         for (int j =i; j<n;j++) {
//
//             if (solve(s, i, j) == true && (j-i+1 > maxlength)) {
//                 maxlength = j - i + 1;
//                 sp = i;
//             }
//         }
//     }
//     return s.substr(sp, maxlength);
// }
// #include <bits/stdc++.h>
// using namespace std;
// int t[1001][1001];
// bool solve(string s, int i, int j) {
//     if (i >= j) {
//         return true;
//     }
//     if (t[i][j] != -1) {
//         return t[i][j];
//     }
//     if (s[i]==s[j]) {
//         return solve(s, i+1, j-1);
//     }
//     return t[i][j] = 0;
//
// }
// string longestpalindrome(string s) {
//     int n = s.length();
//     memset(t, -1, sizeof(t));
//     int maxlength = INT_MIN;
//     int sp = 0;
//     for (int i=0;i<n;i++) {
//         for (int j =i; j<n;j++) {
//
//             if (solve(s, i, j) == true && (j-i+1 > maxlength)) {
//                 maxlength = j - i + 1;
//                 sp = i;
//             }
//         }
//     }
//     return s.substr(sp, maxlength);
// }

//          BOTTOM UP approach
    // t[i][j]  -> True  s[i ... j] -> palindrome
    //          -> False  s[i ... j] -> not a palindrome
    // length of 1 string is always palindrome
    /// t[0][0] = true;
    /// t[1][1] = true;
    /// t[2][2] = true;
    /// t[3][3] = true;
    /// t[4][4] = true;
    ///
    /// if Len >= 2
    /// for(int i = 2; i<=n ;i++ ){
    ///
    /// }
int main() {
    string s;
    cin >> s;
    cout << longestpalindrome(s) << endl;
    return 0;
}