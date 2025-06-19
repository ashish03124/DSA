//
// Created by Agaru on 5/20/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
void Palindrome(Node* head) {
    Node* slow= head;
    Node* fast = head;
    while (fast && fast->next) {
        slow= slow->next;
        fast = fast->next->next;
    }
    Node* pre = NULL;
    while (slow) {
        Node* nxt = slow->next;
        slow->next= pre;
        pre = slow;
        slow = nxt;
    }
    Node* left = head;
    Node* right = pre;
    while (right) {
        if (left->val!=right->val) return false;
        left = left->next;
        right = right->next;
    }
    return  true;
}
int main() {
    return 0;
}