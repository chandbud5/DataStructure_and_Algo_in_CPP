#include<iostream>
#include<cstdlib>

using namespace std;

class LinkedList{

    public:
        struct Node{
        int data;
        struct Node * next = NULL;
    } * head = NULL;

    struct Node * CreateList(){
        Node * lst= new Node();
        if(lst==NULL)
            cout << "Error Occurred while creating Linked List" << endl;
        return lst;
    }

    void insertBegin(int element)
    {
        struct Node * newNode = new Node();
        newNode->data = element;
        newNode->next = head;
        head = newNode;
    }

    void insertAt(int element, int position){
        struct Node *temp=head, *prev, *newNode;
        if(position==0){
            newNode = new Node();
            newNode->data = element;
            newNode->next = head;
            head = newNode;
        }
        else{
            int count = 0;
            while(count<position && temp!=NULL){
                prev = temp;
                temp = temp->next;
                count+=1;
            }
            newNode = new Node();
            newNode->data = element;
            prev->next = newNode;
            newNode->next = temp;
        }
    }

    void insertEnd(int element){
        struct Node * ptr = head;
        struct Node * newNode = new Node();
        newNode->data = element;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    int deleteBegin(){
        if(head==NULL)
            cout << "No entries to delete, UnderFlow" << endl;

        if(head->next==NULL){
            struct Node * ptr = head;
            int x = ptr->data;
            free(ptr);
            head = NULL;
            return x;
        }

        else{
            struct Node * temp = head;
            int x = temp->data;
            head = temp->next;
            temp->next = NULL;
            free(temp);
            return x;
        }
    }

    int deleteAt(int position){
        if(head==NULL)
            cout << "No entries to delete, UnderFlow" << endl;
        else if(position==0){
            struct Node * ptr = head;
            head = ptr->next;
            int x = ptr->data;
            free(ptr);
            return x;
        }
        else{
            int count =0;
            struct Node *temp=head, *prev;
            while(count < position && temp!=NULL){
                prev = temp;
                temp = temp->next;
                count+=1;
            }
            prev->next = temp->next;
            int x = temp->data;
            free(temp);
            return x;
        }
    }

    int deleteEnd(){
        if(head==NULL)
            cout << "No entries to delete, UnderFlow" << endl;

        if(head->next==NULL){
            struct Node * ptr = head;
            int x = ptr->data;
            free(ptr);
            head = NULL;
            return x;
        }

        else{
            struct Node *temp=head, *prev;
            while(temp->next!=NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            int x = temp->data;
            free(temp);
            return x;
        }
    }

    void display(){
        struct Node * ptr = head;
        while(ptr!=NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

};

int main()
{
    LinkedList l1;
    l1.CreateList();
    l1.insertBegin(12);
    l1.insertEnd(16);
    l1.insertAt(45, 3);
    l1.insertAt(18, 0);
    l1.display();
    l1.deleteEnd();
    l1.deleteAt(2);
    l1.display();
    return 0;
}
