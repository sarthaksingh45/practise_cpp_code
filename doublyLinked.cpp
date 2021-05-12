#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtBeg(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    n->prev = NULL;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtEnd(Node* &head, int val){
    Node* n = new Node(val);

    if(head ==NULL){
        head=n;
        n->prev = NULL;
        n->next = NULL;
    }

    
    Node* temp=head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = NULL;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }

}

void deleteNode(Node* &head, int pos){
    Node* todelete = NULL;
    Node* temp = head;

    int count =1;
    while(temp->next!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }
    todelete =temp;
    if(temp == head){
        head->next->prev=NULL;
        head = head->next;
        delete todelete;
        return;
    }
    temp->prev->next = temp->next;
    
    temp->next->prev = temp->prev;
    delete todelete;

}

int main(){
    Node* head= new Node(8);
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    insertAtEnd(head,7);
    displayList(head);
    cout << endl;
    insertAtBeg(head,1);
    displayList(head);

    deleteNode(head,1);
    cout<< endl;
    displayList(head);

    return 0;

}