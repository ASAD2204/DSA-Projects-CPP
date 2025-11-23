/*
 * ============================================================================
 * DSA.H - Comprehensive Data Structures & Algorithms Library
 * ============================================================================
 * This header file contains implementations of:
 * - Linear Data Structures (Array, Stack, Queue, Linked Lists)
 * - Tree Data Structures (BST, AVL, Heap)
 * - Sorting Algorithms (Bubble, Selection, Insertion, Merge, Quick, Heap)
 * - Searching Algorithms (Linear, Binary)
 * ============================================================================
 */

#ifndef DSA_H
#define DSA_H

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// ============================================================================
// ARRAY CLASS - Dynamic Array with Auto Resize/Shrink
// ============================================================================
class Array {
private:
    int* arr;
    int size;
    int currentsize;

    void resize() {
        int newsize = size * 2;
        int* temp = new int[newsize];
        for (int i = 0; i < currentsize; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size = newsize;
    }

    void shrink() {
        if (size <= 5) return;
        int newsize = size / 2;
        int* temp = new int[newsize];
        for (int i = 0; i < currentsize; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size = newsize;
    }

    int find(int element) const {
        for (int i = 0; i < currentsize; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

public:
    Array() {
        size = 5;
        arr = new int[size];
        currentsize = 0;
    }

    Array(int s) {
        size = (s > 5) ? s : 5;
        arr = new int[size];
        currentsize = 0;
    }

    bool addElement(int element) {
        if (currentsize == size) {
            resize();
        }
        arr[currentsize++] = element;
        return true;
    }

    void display() const {
        cout << "Array: ";
        for (int i = 0; i < currentsize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool deleteElement(int element) {
        int i = find(element);
        if (i == -1) {
            return false;
        }
        for (int j = i; j < currentsize - 1; j++) {
            arr[j] = arr[j + 1];
        }
        currentsize--;
        if (currentsize < size / 2) {
            shrink();
        }
        return true;
    }

    bool deleteAllOccurrences(int element) {
        bool found = false;
        while (deleteElement(element)) {
            found = true;
        }
        return found;
    }

    void reverse() {
        for (int i = 0; i < currentsize / 2; i++) {
            swap(arr[i], arr[currentsize - 1 - i]);
        }
    }

    int getSize() const { return currentsize; }
    int getCapacity() const { return size; }
    int& operator[](int index) { return arr[index]; }

    ~Array() {
        delete[] arr;
        arr = NULL;
    }
};

// ============================================================================
// STACK CLASS - Dynamic Stack with Auto Resize/Shrink
// ============================================================================
class Stack {
private:
    int size;
    int noOfElements;
    int* data;

    void resize() {
        int newsize = size * 2;
        int* temp = new int[newsize];
        for (int i = 0; i < noOfElements; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = newsize;
    }

    void shrink() {
        if (size <= 5) return;
        int newsize = size / 2;
        int* temp = new int[newsize];
        for (int i = 0; i < noOfElements; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = newsize;
    }

public:
    Stack() {
        size = 5;
        noOfElements = 0;
        data = new int[size];
    }

    Stack(int Size) {
        size = (Size > 5) ? Size : 5;
        noOfElements = 0;
        data = new int[size];
    }

    bool push(int element) {
        if (noOfElements == size) {
            resize();
        }
        data[noOfElements++] = element;
        return true;
    }

    int top() const {
        return (noOfElements > 0) ? data[noOfElements - 1] : -1;
    }

    bool pop() {
        if (noOfElements > 0) {
            noOfElements--;
            if (noOfElements <= size / 2) {
                shrink();
            }
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Stack: ";
        for (int i = 0; i < noOfElements; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int totalElements() const { return noOfElements; }
    bool isEmpty() const { return noOfElements == 0; }

    ~Stack() {
        delete[] data;
        data = NULL;
    }
};

// ============================================================================
// QUEUE CLASS - Linear Queue with Auto Resize/Shrink
// ============================================================================
class Queue {
private:
    int size;
    int noOfElements;
    int* data;

    void resize() {
        int newsize = size + 5;
        int* temp = new int[newsize];
        for (int i = 0; i < noOfElements; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = newsize;
    }

    void shrink() {
        if (size <= 10) return;
        int newsize = size - 5;
        int* temp = new int[newsize];
        for (int i = 0; i < noOfElements; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = newsize;
    }

public:
    Queue() {
        size = 10;
        data = new int[size];
        noOfElements = 0;
    }

    Queue(int s) {
        size = (s > 10) ? s : 10;
        data = new int[size];
        noOfElements = 0;
    }

    bool enqueue(int element) {
        if (noOfElements == size) {
            resize();
        }
        data[noOfElements++] = element;
        return true;
    }

    bool dequeue() {
        if (noOfElements == 0) {
            return false;
        }
        for (int i = 1; i < noOfElements; i++) {
            data[i - 1] = data[i];
        }
        noOfElements--;
        if (noOfElements == size - 5) {
            shrink();
        }
        return true;
    }

    int front() const {
        return (noOfElements > 0) ? data[0] : -1;
    }

    void display() const {
        cout << "Queue: ";
        for (int i = 0; i < noOfElements; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const { return noOfElements == 0; }
    int getSize() const { return noOfElements; }

    ~Queue() {
        delete[] data;
        data = NULL;
    }
};

// ============================================================================
// CIRCULAR QUEUE CLASS
// ============================================================================
class CircularQueue {
private:
    int front, rear, size;
    int* data;

public:
    CircularQueue() {
        size = 10;
        data = new int[size];
        front = -1;
        rear = -1;
    }

    CircularQueue(int s) {
        size = (s > 10) ? s : 10;
        data = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull() const {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty() const {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        data[rear] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = data[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return item;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty" << endl;
            return;
        }
        cout << "Circular Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << data[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << data[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] data;
        data = NULL;
    }
};

// ============================================================================
// PRIORITY QUEUE CLASS
// ============================================================================
class PriorityQueue {
private:
    class Item {
    public:
        int value;
        int priority;

        Item() : value(0), priority(0) {}
        Item(int v, int p) : value(v), priority(p) {}
    };

    Item* data;
    int capacity;
    int currentSize;

    void resize() {
        int newCapacity = capacity * 2;
        Item* newData = new Item[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    int peekIndex() const {
        if (currentSize == 0) {
            return -1;
        }
        int highestPriority = data[0].priority;
        int ind = 0;
        for (int i = 1; i < currentSize; i++) {
            if (highestPriority < data[i].priority) {
                highestPriority = data[i].priority;
                ind = i;
            } else if (highestPriority == data[i].priority && data[ind].value < data[i].value) {
                ind = i;
            }
        }
        return ind;
    }

public:
    PriorityQueue() : capacity(10), currentSize(0) {
        data = new Item[capacity];
    }

    ~PriorityQueue() {
        delete[] data;
        data = NULL;
    }

    void enqueue(int value, int priority) {
        if (currentSize == capacity) {
            resize();
        }
        data[currentSize++] = Item(value, priority);
    }

    void dequeue() {
        int ind = peekIndex();
        if (ind != -1) {
            for (int i = ind; i < currentSize - 1; i++) {
                data[i] = data[i + 1];
            }
            currentSize--;
        }
    }

    int peek() const {
        int ind = peekIndex();
        return ind == -1 ? -1 : data[ind].value;
    }

    void display() const {
        cout << "Priority Queue: ";
        for (int i = 0; i < currentSize; i++) {
            cout << "(" << data[i].value << "," << data[i].priority << ") ";
        }
        cout << endl;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }
};

// ============================================================================
// SINGLY LINKED LIST CLASS
// ============================================================================
class SinglyLinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteAtHead() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    bool search(int value) const {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() const {
        cout << "Singly Linked List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int count() const {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ~SinglyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ============================================================================
// DOUBLY LINKED LIST CLASS
// ============================================================================
class DoublyLinkedList {
private:
    class Node {
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(NULL), prev(NULL) {}
    };

    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtHead(int value) {
        Node* newnode = new Node(value);
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insertAtTail(int value) {
        Node* newnode = new Node(value);
        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    void deleteAtHead() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtTail() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void display() const {
        cout << "Doubly Linked List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int totalElements() const {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
        head = NULL;
    }
};

// ============================================================================
// CIRCULAR LINKED LIST CLASS
// ============================================================================
class CircularLinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() const {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        cout << "Circular Linked List: ";
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)" << endl;
    }

    ~CircularLinkedList() {
        if (head == NULL) return;
        Node* temp = head;
        Node* nextNode;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
        head = NULL;
    }
};

// ============================================================================
// BINARY SEARCH TREE CLASS
// ============================================================================
class BST {
private:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(NULL), right(NULL) {}
    };

    Node* root;

    Node* insertHelper(Node* node, int element) {
        if (node == NULL) {
            return new Node(element);
        }
        if (element < node->data) {
            node->left = insertHelper(node->left, element);
        } else if (element > node->data) {
            node->right = insertHelper(node->right, element);
        }
        return node;
    }

    void inorderHelper(Node* node) const {
        if (node == NULL) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    void preorderHelper(Node* node) const {
        if (node == NULL) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(Node* node) const {
        if (node == NULL) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteHelper(Node* node, int element) {
        if (node == NULL) return NULL;

        if (element < node->data) {
            node->left = deleteHelper(node->left, element);
        } else if (element > node->data) {
            node->right = deleteHelper(node->right, element);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }

    void destroyTree(Node* node) {
        if (node != NULL) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(NULL) {}

    void insert(int element) {
        root = insertHelper(root, element);
    }

    bool search(int element) const {
        Node* temp = root;
        while (temp != NULL) {
            if (element == temp->data) {
                return true;
            } else if (element > temp->data) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return false;
    }

    void deleteNode(int element) {
        root = deleteHelper(root, element);
    }

    void inorder() const {
        cout << "Inorder: ";
        inorderHelper(root);
        cout << endl;
    }

    void preorder() const {
        cout << "Preorder: ";
        preorderHelper(root);
        cout << endl;
    }

    void postorder() const {
        cout << "Postorder: ";
        postorderHelper(root);
        cout << endl;
    }

    ~BST() {
        destroyTree(root);
    }
};

// ============================================================================
// AVL TREE CLASS - Self-Balancing BST
// ============================================================================
class AVLTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node* node) {
        return node ? height(node->right) - height(node->left) : 0;
    }

    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* insertHelper(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        } else {
            return node;
        }

        updateHeight(node);
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor < -1 && value < node->left->data) {
            return rightRotate(node);
        }
        if (balanceFactor > 1 && value > node->right->data) {
            return leftRotate(node);
        }
        if (balanceFactor < -1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanceFactor > 1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderHelper(Node* node) const {
        if (!node) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void inorder() const {
        cout << "AVL Inorder: ";
        inorderHelper(root);
        cout << endl;
    }

    ~AVLTree() {
        destroyTree(root);
    }
};

// ============================================================================
// MIN HEAP CLASS (Array-based)
// ============================================================================
class MinHeap {
private:
    int* arr;
    int capacity;
    int heapSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heapSize && arr[l] < arr[smallest]) {
            smallest = l;
        }
        if (r < heapSize && arr[r] < arr[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int cap) {
        capacity = cap;
        heapSize = 0;
        arr = new int[capacity];
    }

    void insert(int key) {
        if (heapSize == capacity) {
            cout << "Heap overflow" << endl;
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        arr[i] = key;
        heapifyUp(i);
    }

    int extractMin() {
        if (heapSize <= 0) {
            return -1;
        }
        if (heapSize == 1) {
            heapSize--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        heapifyDown(0);
        return root;
    }

    int getMin() const {
        return (heapSize > 0) ? arr[0] : -1;
    }

    void display() const {
        cout << "Min Heap: ";
        for (int i = 0; i < heapSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap() {
        delete[] arr;
    }
};

// ============================================================================
// MAX HEAP CLASS (Array-based)
// ============================================================================
class MaxHeap {
private:
    int* arr;
    int capacity;
    int heapSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heapSize && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < heapSize && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        heapSize = 0;
        arr = new int[capacity];
    }

    void insert(int key) {
        if (heapSize == capacity) {
            cout << "Heap overflow" << endl;
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        arr[i] = key;
        heapifyUp(i);
    }

    int extractMax() {
        if (heapSize <= 0) {
            return -1;
        }
        if (heapSize == 1) {
            heapSize--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        heapifyDown(0);
        return root;
    }

    int getMax() const {
        return (heapSize > 0) ? arr[0] : -1;
    }

    void display() const {
        cout << "Max Heap: ";
        for (int i = 0; i < heapSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

// ============================================================================
// SORTING ALGORITHMS NAMESPACE
// ============================================================================
namespace SortingAlgorithms {

    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }

    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// ============================================================================
// SEARCHING ALGORITHMS NAMESPACE
// ============================================================================
namespace SearchingAlgorithms {

    int linearSearch(int arr[], int n, int key) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int arr[], int n, int key) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int binarySearchRecursive(int arr[], int left, int right, int key) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[mid] > key) {
                return binarySearchRecursive(arr, left, mid - 1, key);
            }
            return binarySearchRecursive(arr, mid + 1, right, key);
        }
        return -1;
    }
}

#endif // DSA_H