//
// Created by Agaru on 6/27/2025.
//
#include <bits/stdc++.h>
using namespace std;
Node* deleteAtPos(Node* &head,int pos) {
   Node* temp = head;
    int i = 1;
    while (temp && i<pos) {
        temp=temp->next;
        i++;
    }
    if (!temp) return head;
    Node* back = temp->prev;
    Node* front = temp->next;
    if (!back && !front) {
        delete temp;
        return nullptr;
    }
    else if (!back) {
        return deleteAtHead(head);
    }
    else if (!front) {
        return deleteAtTail(head);
    }
    front->prev=back;
    back->next=front;
    delete temp;
    return head;
}
int main() {
    return 0;
}