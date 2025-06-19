//
// Created by Agaru on 6/19/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next=nullptr;
    }
};
void DeleteAtHead(Node* &head) {
    if (!head) return;
Node* temp=head;
    head = head->next;
    delete temp;
}
void DeleteAtTail(Node* &head) {
if(!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}
void DeleteAtTarget(Node* &head ,int pos) {
    Node* temp = head;
    if (pos==0) {
        head=head->next;
        delete temp;
        return;;
    }

    int i=0;
    while (temp && i < pos-1) {
        temp=temp->next;
        i++;
    }
    if (!temp || !temp->next) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* to_delete = temp->next;
    temp->next=temp->next->next;
    delete to_delete;
}
void Display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head=head->next;
    }
    cout << "\n";
}
int main() {
    Node* head = nullptr;
    head = new Node(5);
    head->next = new Node(10);
    head->next->next=new Node(20);
    head->next->next->next = new Node(30);
    DeleteAtHead(head);
    DeleteAtTail(head);
    DeleteAtTarget(head,3);
    Display(head);

    return 0;
}