//
// Created by Agaru on 6/27/2025.
//
#include <bits/stdc++.h>
using namespace std;
Node* deleteAtHead(Node* &head) {
    Node* temp = head;
    head = head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
Node* deleteAtTail(Node* &head) {
    Node* temp = head;
    while (temp->next) {
        temp=temp->next;
    }
    Node* back = temp->prev;
    back->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
Node* deleteAtPos(Node* head, int pos) {
    Node* temp = head;
    int i = 1;
    while (temp && i<pos) {
        temp=temp->next;
        i++;
    }
    if (!temp) return nullptr;
    Node* back = temp->prev;
    Node* front = temp->next;
    if (!back && front) {
        delete temp;
        return nullptr;
    }
    else if (!back) {
        return deleteAthead(head);
    }
    else if (!front) {
        return deleteAtTail(head);
    }
    back = front->prev;
    front = back->next;
    delete temp;
    return head;

}
int main() {
    return 0;
}