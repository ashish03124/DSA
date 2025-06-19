//
// Created by Agaru on 6/20/2025.
//
void DeleteNode(Node* &head, int val, int pos) {
    if(!head) return;
    Node* temp = head;
    if (pos==0) {
        head=head->next;
        delete temp;
        return;
    }
    int i = 0;

    while(temp && i<pos-1) {
        temp=temp->next;
        i++;
    }
    if (!temp->next) return nullptr;
    Node* to_delete = temp->next;
    temp->next=temp->next->next;
    delete to_delete;
}