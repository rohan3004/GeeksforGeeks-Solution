class kQueues {
private:
    int *arr, *next, *front, *rear;
    int freeSpot;
    int n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        // Initialize all queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    void enqueue(int x, int i) {
        if (isFull()) return;

        int index = freeSpot;          // get free index
        freeSpot = next[index];        // update free list

        if (front[i] == -1) {
            front[i] = index;          // first element
        } else {
            next[rear[i]] = index;     // link new element
        }

        next[index] = -1;
        rear[i] = index;
        arr[index] = x;
    }

    int dequeue(int i) {
        if (isEmpty(i)) return -1;

        int index = front[i];
        front[i] = next[index];

        // add freed index back to free list
        next[index] = freeSpot;
        freeSpot = index;

        if (front[i] == -1)
            rear[i] = -1;

        return arr[index];
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return freeSpot == -1;
    }
};
