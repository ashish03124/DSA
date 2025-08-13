//
// Created by Agaru on 8/13/2025.
//
/*elements with  their weight and values , and max capacity of a bag
 *to find max profit, by choosing the items which fits most
 *bag = {p1, p2, p3, p4}
 *W[] = {1,  3,  4,  5}
 *V[] = {1,  4,  5,  7}
 *Capacity = 7
 *if elements weight is greater than the bags capacity then discard that item
 *if it's smaller than the capacity, consider it
 *dp = t[n+1][C+1]
 *fill whole matrix with -1
 *
 */
#include <bits/stdc++.h>
using namespace std;
int dp[102][1002];
int Knapsack(int weight[], int value[], int C, int n) {
    //base condition
    if (n == 0 || C==0) {
        return 0;
    }
    if (dp[n][C]!= -1) {
        return dp[n][C];
    }
    if (weight[n-1] <= C) {
        return dp[n][C]= max(value[n-1] + Knapsack(weight, value, C-weight[n-1], n-1), Knapsack(weight, value, C, n-1));
    }else if (weight[n-1]>C) {
     return dp[n][C] = Knapsack(weight, value, C, n-1);
    }
    // choice diagram



}
int main() {
    int weight[] = {1, 3, 4, 5};
    int value[]  = {1, 4, 5, 7};
    int C = 7;
    int n = sizeof(weight) / sizeof(weight[0]);

    // fill dp with -1
    memset(dp, -1, sizeof(dp));

    cout << "Max profit: " << Knapsack(weight, value, C, n) << endl;
    return 0;
}