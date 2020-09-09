#include<iostream>
#include<cstdlib>

using namespace std;

class DoublyList{
    public:
        struct Node{
            int data;
            struct Node *next;
            struct Node *prev;
        }*head=NULL;

        void insertBegin(int element){
            struct Node *newNode = new Node();
            newNode->data = element;
            if(head==NULL){
                newNode->next = NULL;
                newNode->prev = NULL;
                head = newNode;
            }
            else{
                newNode->next = head;
                newNode->prev = NULL;
                head->prev = newNode;
                head = newNode;
            }
        }

        void insertAt(int element, int position){
            if(head==NULL || position==0){
                insertBegin(element);
                return;
            }
            struct Node *newNode = new Node(), *ptr=head, *temp=head;
            newNode->data = element;
            int c=0;
            while(c<position && ptr->next!=NULL){
                temp = ptr;
                ptr = ptr->next;
                c+=1;
            }

            if(c!=position){
                insertEnd(element);
                return;
            }

            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = ptr;
            ptr->prev = newNode;
        }

        void insertEnd(int element){
            struct Node *newNode = new Node();
            newNode->data = element;
            if(head==NULL){
                insertBegin(element);
                return;
            }
            else{
                struct Node *ptr = head;
                newNode->next = NULL;
                newNode->data = element;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next = newNode;
                newNode->prev = ptr;
            }
        }

        int deleteBegin(){
            if(head==NULL){
                cout << "No Element to delete" << endl;
            }
            else{
                int x = head->data;
                struct Node *ptr = head;
                head = head->next;
                head->prev = NULL;
                free(ptr);
                return x;
            }
        }

        int deleteAt(int position){
            int c=0, x;
            if(head==NULL){
                cout << "No Element to delete" << endl;
            }
            else{
                struct Node *ptr = head, *temp, *del;
                if(position==0){
                    return deleteBegin();
                }
                while(ptr->next != NULL && c<position){
                    temp = ptr;
                    ptr = ptr->next;
                    c++;
                }
                if(c!=position){
                    cout << "No Element present at that location" << endl;
                }
                else{
                    del = temp->next;
                    ptr = ptr->next;
                    temp->next = ptr;
                    ptr->prev = temp;
                    x = del->data;
                    return x;
                }
            }
        }

        int deleteEnd(){
            int x;
            if(head==NULL){
                cout << "No Element to delete" << endl;
            }
            else{
                struct Node *ptr = head, *temp;
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                temp = ptr->prev;
                x = ptr->data;
                temp->next = NULL;
                free(ptr);
                return x;
            }
        }

        void display(){
            if(head==NULL){
                cout << "No elements in List" << endl;
                return;
            }
                struct Node *ptr = head;
                while(ptr != NULL)
                {
                    cout << ptr->data << "\t";
                    ptr = ptr->next;
                }
                cout << "" << endl;
        }
};

int main(){

    DoublyList dL;
    dL.deleteAt(4);
    dL.insertBegin(12);
    dL.deleteAt(4);
    dL.insertBegin(23);
    dL.insertEnd(13);
    dL.insertAt(15, 0);
    dL.insertBegin(3);
    dL.deleteBegin();
    dL.display();
    dL.insertAt(2, 9);
    dL.display();
    dL.insertBegin(99);
    dL.display();
    dL.deleteAt(1);
    dL.display();
    dL.insertEnd(32);
    dL.display();
    return 0;
}
