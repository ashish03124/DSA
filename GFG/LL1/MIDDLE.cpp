//
// Created by Agaru on 6/7/2025.
//

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
void MIDDLE(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout << slow->data << endl;
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    MIDDLE(head);

    return 0;
}