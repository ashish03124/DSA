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
void DELETIONatHead(Node* &head) {
Node* temp = head;
        head=head->next;
    delete temp;
}
void DELETIONatTARGET(Node* &head,int target) {
    Node* temp = head;
    if(target == 0){
        head=head->next;
        delete head;
    }
    int i = 0;
    while (temp!=NULL && i<target-1) {
        temp = temp->next;
        i++;
    }
    if (temp==nullptr || temp->next==nullptr) return;
    Node* to_delete = temp->next;
    temp->next=temp->next->next;
    delete to_delete;
}
void DELETIONatTAIL(Node* &head) {
    Node* temp = head;
    while (temp!=NULL && temp->next!=NULL) {
        temp=temp->next;
    }
    delete temp->next;
}
void printList(Node* head) {
    while (head!=nullptr) {
        cout << head->data << " ";
        head=head->next;
    }
    cout << "NULL\n";
}
int main() {
    Node* head = NULL;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout << "Initial list:\n";
    printList(head);

    DELETIONatHead(head);
    cout << "After deleting head:\n";
    printList(head);

    DELETIONatTARGET(head, 1); // delete node at index 1
    cout << "After deleting index 1:\n";
    printList(head);

    DELETIONatTAIL(head);
    cout << "After deleting tail:\n";
    printList(head);
    return 0;
}