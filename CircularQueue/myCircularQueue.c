


typedef struct 
{
    int* data;
    int front;
    int back;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->back = 0;
    obj->k = k;

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    return obj->back == obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
    return (obj->back + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if (myCircularQueueIsFull(obj))
        return false;

    obj->data[obj->back] = value;
    ++obj->back;
    obj->back %= (obj->k + 1);

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
        return false;

    ++obj->front;
    obj->front %= (obj->k + 1);

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
        return -1;

    // if(obj->back == 0)
    //     return obj->data[obj->k]
    // else
    //     return obj->data[obj->back - 1];

    return obj->data[(obj->back - 1 + obj->k + 1) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/