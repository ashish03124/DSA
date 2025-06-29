//
// Created by Agaru on 6/29/2025.
//
NOde*  reversingadoubly(Node* &head) {
    Node* temp = head;
    Node* back=nullptr;
    while (temp) {
        back = temp->prev;
        temp->prev=temp->next;
        temp->next=back;

        head=temp;
        temp=temp->prev;
    }
    return head;
}