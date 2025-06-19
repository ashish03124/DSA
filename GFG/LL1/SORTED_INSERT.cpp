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
        next = NULL;
    }
};
void SORTEDINSERT(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (!head) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next!= nullptr && temp->next->data < val) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next=new_node;

}
void printList(Node* head) {
    while (head!=nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL\n";
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    SORTEDINSERT(head, 23);
    printList(head);

    return 0;
}