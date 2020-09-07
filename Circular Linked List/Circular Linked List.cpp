#include<iostream>
#include<cstdlib>

using namespace std;

class CircularList{

    public:
        struct Node{
        int data;
        struct Node * next = NULL;
    } * head = NULL;

        void insertBegin(int element){
            struct Node *newNode = new Node();
            newNode -> data = element;

            if(head == NULL){
                newNode -> next = newNode;
                head = newNode;
            }

            else{
                struct Node *ptr = head;
                newNode -> next = head;
                while(ptr->next != head){
                    ptr = ptr -> next;
                }
                head = newNode;
                ptr -> next = newNode;
            }
        }

        void insertAt(int element, int position){
            if(position == 0)
                insertBegin(element);
            else{
                struct Node *temp, *ptr = head, *newNode = new Node();
                int c = 0;
                while(ptr->next != head && c!=position){
                    temp = ptr;
                    ptr = ptr->next;
                    c++;
                }
                if(c!=position){
                    insertEnd(element);
                    return;
                }
                newNode -> data = element;
                temp->next = newNode;
                newNode->next = ptr;
            }
        }

        void insertEnd(int element){
            struct Node *newNode = new Node();
            newNode -> data = element;

            if(head == NULL){
                newNode -> next = newNode;
                head = newNode;
            }
            else{
                struct Node *ptr = head;
                newNode -> next = head;
                while(ptr->next != head){
                    ptr = ptr -> next;
                }
                ptr -> next = newNode;
            }
        }

        int deleteBegin(){
            if(head == NULL)
                cout << "No element to delete" << endl;
            else{
                int x = head -> data;
                struct Node *ptr=head, *temp = head;
                while(ptr->next != head){
                    ptr = ptr->next;
                }
                ptr->next = temp->next;
                head = temp->next;
                temp->next = NULL;
                free(temp);
                return x;
            }
        }

        int deleteAt(int position){
            int x, c=0;
            if(position==0)
                x = deleteBegin();
            else if(head == NULL)
                cout << "No element to delete" << endl;
            else{
                struct Node *ptr = head, *temp;
                while(ptr->next != head && c!=position)
                {
                    c++;
                    temp = ptr;
                    ptr = ptr->next;
                }
                if(c != position)
                    cout << "No element present at that position" << endl;
                else{
                    x = ptr->data;
                    temp->next = ptr->next;
                    ptr->next = NULL;
                    free(ptr);
                    return x;
                }
            }
        }

        int deleteEnd(){
            if(head == NULL){
                cout << "No element to delete" << endl;
            }
            else{
                int x;
                struct Node *ptr=head, *temp;
                while(ptr->next != head){
                    temp = ptr;
                    ptr = ptr->next;
                }
                temp->next = head;
                ptr->next = NULL;
                free(ptr);
                return x;
            }
        }

        void display(){
            if(head == NULL){
                cout << "Circular Linked List is Empty" << endl;
                return;
            }
            struct Node *ptr = head;
            do{
                cout << ptr->data << "\t" ;
                ptr = ptr->next;
            }while(ptr!=head);
            cout << "" << endl;
        }
};

int main(){

    CircularList cl;
    cl.display();
    cl.deleteEnd();
    cl.deleteBegin();
    cl.insertBegin(10);
    cl.insertBegin(20);
    cl.display();
    cl.insertEnd(12);
    cl.insertBegin(2);
    cl.insertAt(34, 8);
    cl.display();
    cl.deleteBegin();
    cl.display();
    cl.deleteAt(9);
    cl.display();
    cl.deleteEnd();
    cl.deleteEnd();
    cl.display();
    return 0;
}
