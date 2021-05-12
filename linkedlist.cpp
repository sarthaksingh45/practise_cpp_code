#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){
        data =  val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtBeg(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void search(Node* head, int key){
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == key){
            cout<< "\n Found\n";
            return ;
        }
        temp = temp->next;
    }

    cout << "\nNot Found\n";
}

void deleteElement(Node* &head, int key){
    if(head == NULL){
        return;
    }

    if(head->data == key){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    
    Node* temp = head;
    while(temp->next->data!=key){

        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

}

Node* reverse(Node* &head){
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

Node* reverseRecursive(Node* &head){

    if(head == NULL || head->next ==NULL){
        return head;
    }

    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node* reversek(Node* &head, int k){
    Node* prevptr= NULL;
    Node* currptr = head;
    Node* nextptr;

    int count =0;
    
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;

        count++;
    }

    if(nextptr!=NULL){
        head->next = reversek(nextptr, k);
    }

    return prevptr;
    
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* ctemp;

    int count = 0;
    while(temp->next!=NULL){
        if(count == pos){
            ctemp = temp;
        }

        temp=temp->next;
        count++;
    }
    temp->next = ctemp;
    
}

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(fast!=slow);

    fast = head;
    while(fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int length(Node* head){
    int l=0;
    Node* temp = head;
    while(temp->next!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

void appendk(Node* &head, int k){
    
    Node* newTail=NULL;
    Node* newHead=NULL;
    Node* tail = head;
    int count =0;
    int l = length(head);
    while(tail->next!=NULL){
        if(count == (l-k)){
            newTail = tail;
        }
        if(count == (l-k+1)){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    head = newHead;

}

void intersect(Node* &head1, Node* &head2, int pos){
    int len = length(head1);
    Node* temp = head2;
    int k = len -pos;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* temp2 = head1;
    int count=0;

    while(temp2->next!=NULL && count!=k){
        temp2=temp2->next;
        count++;
    }
    temp->next = temp2->next;

}

int intersectedEle(Node* head1, Node* head2){
    int len1 = length(head1);
    int len2 = length(head2);
    int d=0;
    Node* temp1;
    Node* temp2;
    if(len1>len2){
        d = len1 - len2;
        temp1 = head1;
        temp2 = head2;
    }
    else{
        d= len2 - len1;
        temp1 = head2;
        temp2 = head1;
    }
    while(d){
        temp1 = temp1->next;
        d--;
    }
    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1 == temp2){
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

Node* merge(Node* head1, Node* head2){
    Node* tempHead = new Node(-1);
    Node* ptr3 = tempHead;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return tempHead->next;
}

Node* mergeRecursive(Node* head1, Node* head2){

    if(head1 == NULL){
        return head2;
    }

    if(head2 == NULL){
        return head1;
    }

    Node* result;
    if(head1->data > head2->data){
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    else{
        result = head1;
        result->next = mergeRecursive(head1->next,head2);
    }
    return result;
}



int main(){
    Node* head = NULL;
    insertAtTail(head,4);
    insertAtTail(head,7);
    insertAtTail(head,11);

    insertAtTail(head,12);
    

    displayList(head);

    cout << endl;
    Node* head2 = new Node(3);
    insertAtTail(head2,5);
    insertAtTail(head2,6);
    insertAtTail(head2,10);
    displayList(head2);
    cout << endl;

    Node* newHead = mergeRecursive(head, head2);
    displayList(newHead);

    
    return 0;

}

