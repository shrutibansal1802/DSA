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
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
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

// Complete the compare_lists function below.

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

SinglyLinkedListNode* temp1=head1;
SinglyLinkedListNode* temp2=head2;
int c1=0,c2=0;

if(head1==NULL&&head2==NULL)
return 1;

else if(head1==NULL || head2==NULL)
return 0;

else
{
    while(temp1!=NULL)
    {
        c1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        c2++;
        temp2=temp2->next;
    }
    if(c1==c2)
    {
        while(head1!=NULL)
        {
            if(head1->data==head2->data)
            {c1++;
            }
            else
            return 0;
            
            head1=head1->next;
             head2=head2->next;
        }
        if(c1==2*c2)
        return 1;
        else
        return 0;
    }
    else
    return 0;
}
}
    

int main()
