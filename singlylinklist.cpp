#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtPosition function below.

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* temp =new SinglyLinkedListNode(data);
    SinglyLinkedListNode* hhead =head;
    if (position==0)
        {
            temp->next=head;
            head=temp;
            
        }
    else if(position==1)
    {
        temp->next=head->next;
        head->next=temp;
    }
    else
    {while(--position)
    {
        hhead=hhead->next;
    }
    temp->next=hhead->next;
        hhead->next=temp;
    }
  return head;  
}

// Complete the insertNodeAtTail function below.

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    
	SinglyLinkedListNode* temp =new SinglyLinkedListNode(data);
    temp->data =data;
    temp->next=NULL ;

    SinglyLinkedListNode* hhead =head;

    if(head ==NULL)
    {
        head = temp;
        return head;
    }
    else
    {
    while(hhead->next!=NULL)
    {
        hhead=hhead->next;
    }
    hhead->next =temp;
    return head;
    }

}

// Complete the deleteNode function below.

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

     if(head==NULL)
     return head;

 SinglyLinkedListNode* temp=head;


if (position==0)
{
    head=temp->next;
    delete temp;
}

else
{
   for (int i=0; temp!=NULL && i<position-1; i++)
    {
            temp=temp->next;
    }
     SinglyLinkedListNode* p=temp->next->next;
   
    delete temp->next;
    temp->next=p;
}

return head;
  
}
// Complete the reverse function below.

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* pre = NULL;
    SinglyLinkedListNode* nex = NULL;
    SinglyLinkedListNode* curr= head;

    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nex;
    }
    head=pre;
    return head;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    	SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
      	llist->head = llist_head;
    }


    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();

    return 0;
}
