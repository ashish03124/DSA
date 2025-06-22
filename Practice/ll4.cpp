//
// Created by Agaru on 6/22/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data= val;
        next = nullptr;
    }
};
// void reverse(Node* head) {
//     Node* temp = head;
//     Node* next = nullptr;
//     Node* pre = nullptr  ;
//     while (temp!=nullptr) {
//         next=temp->next;
//         temp->next=pre;
//     }
// }
void recursive(Node* head) {
    if (!head) return;
    recursive(head->next);
    cout << head->data << " ";
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    recursive(head);

    return 0;
}