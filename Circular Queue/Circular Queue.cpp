#include <iostream>
using namespace std;

class CircularQueue{
    public:
        int front_ptr, rear_ptr;
        int *arr;
        int capacity;

        CircularQueue(){
            CreateQueue();
        }

        void CreateQueue(){
            front_ptr = -1;
            rear_ptr = -1;
            cout << "Enter the size of an Array" << endl;
            cin >> capacity;
            while(capacity==0){
                cout << "Enter valid size" << endl;
                cin >> capacity;
            }
            arr = new int[capacity];
        }

        void display(){
            if(front_ptr==-1 && rear_ptr==-1)
                cout << "Queue Empty" << endl;
            else{
                if (rear_ptr >= front_ptr)
                {
                    for (int i = front_ptr; i <= rear_ptr; i++)
                        cout << arr[i] << "\t";
                }
                else
                {
                    for (int i = front_ptr; i < capacity; i++)
                        cout << arr[i] << "\t";

                    for (int i = 0; i <= rear_ptr; i++)
                        cout << arr[i] << "\t";
                }
                cout << "" << endl;
            }
        }

        void Enqueue(int n){
            if(isFull())
                cout << "Queue OverFlow" << endl;
            else{
                rear_ptr = (rear_ptr+1)%capacity;
                arr[rear_ptr] = n;
                if(front_ptr==-1)
                    front_ptr++;
            }
        }

        int Dequeue(){
            if(isEmpty())
                cout << "Queue UnderFlow" << endl;
            else{
                int x = arr[front_ptr];
                front_ptr = (front_ptr+1)%capacity;
                if(isEmpty() || front_ptr == rear_ptr){
                    front_ptr = -1;
                    rear_ptr = -1;
                }
                return x;
            }
        }

        bool isFull(){
            if((front_ptr==0 && rear_ptr==capacity-1) ||  (rear_ptr == (front_ptr-1)%(capacity+1)))
                return true;
            else
                return false;
        }

        bool isEmpty(){
            if(front_ptr==-1 && rear_ptr==-1)
                return true;
            else
                return false;
        }
};

int main(){
    CircularQueue cq;
    cq.Enqueue(3);
    cq.Enqueue(5);
    cq.Enqueue(7);
    cq.Enqueue(6);
    cq.Enqueue(9);
    cout << "After Enqueue operation" << endl;
    cq.display();
    cq.Dequeue();
    cq.Dequeue();
    cout << "After Dequeue Operation" << endl;
    cq.display();
    cq.Enqueue(5);
    cq.Enqueue(7);
    cq.Enqueue(6);
    cq.Enqueue(9);
    cout << "Finally" << endl;
    cq.display();

    return 0;
}
