#include<iostream>
using namespace std;

class Queue{
    public:
        int front_ptr, rear_ptr;
        int *arr;
        int capacity;

        Queue (){
            CreateQueue();
        }

        void CreateQueue(){
            front_ptr = -1;
            rear_ptr = -1;
            cout << "Create size of Queue you want to create" << endl;
            cin >> capacity;
            arr = new int[capacity];
        }

        void Enqueue(int n){
            if(isEmpty()){
                front_ptr++;
                rear_ptr++;
                arr[rear_ptr] = n;
            }
            else if(isFull())
                cout << "Queue OverFlow" << endl;
            else{
                rear_ptr++;
                arr[rear_ptr] = n;
            }
        }

        int Dequeue(){
            if(isEmpty())
                cout << "Queue UnderFlow" << endl;
            else{
                int x = arr[front_ptr];
                front_ptr++;
                if(isEmpty()){
                    front_ptr = -1;
                    rear_ptr = -1;
                }
                return x;
            }
        }

        void display(){
            if(isEmpty())
                cout << "Queue is Empty" << endl;
            else{
                for(int i=front_ptr; i<=rear_ptr; i++){
                    cout << arr[i] << "\t";
                }
                cout << "" << endl;
            }
        }

        bool isEmpty(){
            return (front_ptr > rear_ptr || (front_ptr==-1 && rear_ptr==-1)) ? true : false;
        }

        bool isFull(){
            return rear_ptr==capacity-1 ? true : false;
        }

};

int main(){
    Queue q;
    cout << "Performing enqueue" << endl;
    q.Enqueue(2);
    q.Enqueue(23);
    q.Enqueue(7);
    q.Enqueue(6);
    q.Enqueue(90);
    cout << "After all Enqueue operations" << endl;
    q.display();
    cout << "Performing Dequeue" << endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout << "After Dequeue Operations" << endl;
    q.display();
    return 0;
}
