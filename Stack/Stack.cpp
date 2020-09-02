#include<iostream>
using namespace std;

class Stack{
    public:
        int top=-1, capacity;
        int *arr;

        Stack(){
            CreateStack();
        }

        void CreateStack(){
            cout << "Enter the size of Stack" << endl;
            cin >> capacity;
            top = -1;
            arr = new int[capacity];
        }

        bool isFull(){
            if(top == capacity-1){
                return true;
            }
            else
                return false;
        }

        void push(int n){
            if(isFull()){
                cout << "Stack OverFlow" << endl;
            }
            else{
                top ++;
                arr[top] = n;
            }
        }
        int Top(){
            return top;
        }

        bool isEmpty(){
            if(top==-1)
                return true;
            else
                return false;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack UnderFlow" << endl;
            }
            else{
                int x = arr[top];
                top -- ;
                return x;
            }
        }

        void display(){
            for(int i=top; i>-1; i--){
                cout << arr[i] << "\t" << endl;
            }
        }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(8);
    s.push(9);
    s.push(13);
    s.push(15);
    s.CreateStack();
    s.push(12);
    cout << "After Pushing elements to the Stack" << endl;
    cout << "Currently Top is at " << s.Top() << endl;
    s.display();
    s.pop();
    s.pop();
    s.pop();
    cout << "After Popping element from the Stack" << endl;
    s.display();

    return 0;
}
