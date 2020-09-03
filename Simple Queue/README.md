# Queue
It is a data structure where insertion and deletion takes place at different ends. Insertion is done at *REAR* end of Queue. While deletion is done at *FRONT* end of a Queue.<br><br>

**Methods of class Queue**
  - ```CreateQueue()``` - Create a Queue of size as described by user and it will initialize front and rear pointer to -1. By default this method will be called by default constructor. On calling this method the queue associated with that object will be replaced by new queue.
  - ```Enqueue(int n)``` - Insertion at Rear end of a Queue.
  - ```Dequeue()``` - Deletion of an element at front end of a Queue. The deleted element is also returned by this method.
  - ```display()``` - Traverse through the queue and display all elements from front to rear end of the queue.
  - ```isEmpty()``` - To check whether queue is empty or not. Returns boolean value.
  - ```isFull()``` - To check whether queue is full or not. Returns boolean value.
