//
// Created by Agaru on 6/7/2025.
//
Node* OddEven(Node* head) {
    Node* temp = head;
    Node* odd = temp;
    Node* even = temp->next;
    Node* evenStart = head->next;
    while (even && even->next) {
        odd->next = odd->next->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next=evenStart;
    return head;
}