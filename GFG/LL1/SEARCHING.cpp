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
bool SEARCHING(Node* head,int x) {
    Node* temp = head;
    while (temp!=NULL) {
        if (temp->data==x) {
            return true;
        }

        temp=temp->next;

    }
}
int main() {
    Node* head = new Node(30);
    head->next = new Node(40);
    head->next->next=new Node(50);
    head->next->next->next=new Node(60);
    int key = 40;
    if (SEARCHING(head, key)) {
        cout << key << " found in the list.\n";
    } else {
        cout << key << " not found in the list.\n";
    }

}