/*
 * ============================================================================
 * TEST FILE for DSA.H Library
 * ============================================================================
 * This file demonstrates the usage of all data structures and algorithms
 * implemented in dsa.h
 * ============================================================================
 */

#include "dsa.h"
#include <iostream>
using namespace std;

void testArray() {
    cout << "\n========== TESTING ARRAY ==========\n";
    Array arr;
    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);
    arr.addElement(40);
    arr.addElement(50);
    arr.display();
    
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    
    arr.deleteElement(30);
    cout << "After deleting 30: ";
    arr.display();
    
    arr.reverse();
    cout << "After reverse: ";
    arr.display();
}

void testStack() {
    cout << "\n========== TESTING STACK ==========\n";
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    
    cout << "Top element: " << s.top() << endl;
    cout << "Total elements: " << s.totalElements() << endl;
    
    s.pop();
    cout << "After pop: ";
    s.display();
}

void testQueue() {
    cout << "\n========== TESTING QUEUE ==========\n";
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    
    cout << "Front element: " << q.front() << endl;
    
    q.dequeue();
    cout << "After dequeue: ";
    q.display();
}

void testCircularQueue() {
    cout << "\n========== TESTING CIRCULAR QUEUE ==========\n";
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();
    
    cout << "Dequeued: " << cq.dequeue() << endl;
    cout << "After dequeue: ";
    cq.display();
    
    cq.enqueue(50);
    cq.enqueue(60);
    cout << "After adding 50, 60: ";
    cq.display();
}

void testPriorityQueue() {
    cout << "\n========== TESTING PRIORITY QUEUE ==========\n";
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);
    pq.enqueue(40, 3);
    pq.display();
    
    cout << "Highest priority element: " << pq.peek() << endl;
    
    pq.dequeue();
    cout << "After dequeue: ";
    pq.display();
}

void testSinglyLinkedList() {
    cout << "\n========== TESTING SINGLY LINKED LIST ==========\n";
    SinglyLinkedList sll;
    sll.insertAtHead(30);
    sll.insertAtHead(20);
    sll.insertAtHead(10);
    sll.insertAtTail(40);
    sll.insertAtTail(50);
    sll.display();
    
    cout << "Count: " << sll.count() << endl;
    cout << "Search 30: " << (sll.search(30) ? "Found" : "Not Found") << endl;
    
    sll.deleteAtHead();
    cout << "After delete at head: ";
    sll.display();
    
    sll.deleteAtTail();
    cout << "After delete at tail: ";
    sll.display();
}

void testDoublyLinkedList() {
    cout << "\n========== TESTING DOUBLY LINKED LIST ==========\n";
    DoublyLinkedList dll;
    dll.insertAtHead(30);
    dll.insertAtHead(20);
    dll.insertAtHead(10);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.display();
    
    cout << "Total elements: " << dll.totalElements() << endl;
    
    dll.deleteAtHead();
    cout << "After delete at head: ";
    dll.display();
}

void testCircularLinkedList() {
    cout << "\n========== TESTING CIRCULAR LINKED LIST ==========\n";
    CircularLinkedList cll;
    cll.insertAtHead(30);
    cll.insertAtHead(20);
    cll.insertAtHead(10);
    cll.insertAtTail(40);
    cll.insertAtTail(50);
    cll.display();
}

void testBST() {
    cout << "\n========== TESTING BINARY SEARCH TREE ==========\n";
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    bst.inorder();
    bst.preorder();
    bst.postorder();
    
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;
    
    bst.deleteNode(30);
    cout << "After deleting 30: ";
    bst.inorder();
}

void testAVLTree() {
    cout << "\n========== TESTING AVL TREE ==========\n";
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    
    avl.inorder();
}

void testMinHeap() {
    cout << "\n========== TESTING MIN HEAP ==========\n";
    MinHeap minHeap(10);
    minHeap.insert(12);
    minHeap.insert(11);
    minHeap.insert(13);
    minHeap.insert(5);
    minHeap.insert(6);
    minHeap.insert(7);
    
    minHeap.display();
    cout << "Min element: " << minHeap.getMin() << endl;
    
    cout << "Extracted min: " << minHeap.extractMin() << endl;
    cout << "After extraction: ";
    minHeap.display();
}

void testMaxHeap() {
    cout << "\n========== TESTING MAX HEAP ==========\n";
    MaxHeap maxHeap(10);
    maxHeap.insert(12);
    maxHeap.insert(11);
    maxHeap.insert(13);
    maxHeap.insert(5);
    maxHeap.insert(6);
    maxHeap.insert(7);
    
    maxHeap.display();
    cout << "Max element: " << maxHeap.getMax() << endl;
    
    cout << "Extracted max: " << maxHeap.extractMax() << endl;
    cout << "After extraction: ";
    maxHeap.display();
}

void testSortingAlgorithms() {
    cout << "\n========== TESTING SORTING ALGORITHMS ==========\n";
    
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    cout << "Original array: ";
    SortingAlgorithms::printArray(arr1, n);
    
    int arr2[7], arr3[7], arr4[7], arr5[7], arr6[7];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] = arr1[i];
    }
    
    SortingAlgorithms::bubbleSort(arr2, n);
    cout << "Bubble Sort: ";
    SortingAlgorithms::printArray(arr2, n);
    
    SortingAlgorithms::selectionSort(arr3, n);
    cout << "Selection Sort: ";
    SortingAlgorithms::printArray(arr3, n);
    
    SortingAlgorithms::insertionSort(arr4, n);
    cout << "Insertion Sort: ";
    SortingAlgorithms::printArray(arr4, n);
    
    SortingAlgorithms::mergeSort(arr5, 0, n - 1);
    cout << "Merge Sort: ";
    SortingAlgorithms::printArray(arr5, n);
    
    SortingAlgorithms::quickSort(arr6, 0, n - 1);
    cout << "Quick Sort: ";
    SortingAlgorithms::printArray(arr6, n);
    
    int arr7[] = {64, 34, 25, 12, 22, 11, 90};
    SortingAlgorithms::heapSort(arr7, n);
    cout << "Heap Sort: ";
    SortingAlgorithms::printArray(arr7, n);
}

void testSearchingAlgorithms() {
    cout << "\n========== TESTING SEARCHING ALGORITHMS ==========\n";
    
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;
    
    cout << "Array: ";
    SortingAlgorithms::printArray(arr, n);
    
    int key = 50;
    int result = SearchingAlgorithms::linearSearch(arr, n, key);
    cout << "Linear Search for " << key << ": ";
    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;
    
    result = SearchingAlgorithms::binarySearch(arr, n, key);
    cout << "Binary Search for " << key << ": ";
    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;
    
    result = SearchingAlgorithms::binarySearchRecursive(arr, 0, n - 1, key);
    cout << "Binary Search (Recursive) for " << key << ": ";
    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;
}

int main() {
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════════╗\n";
    cout << "║      COMPREHENSIVE DSA LIBRARY TEST SUITE                ║\n";
    cout << "╚═══════════════════════════════════════════════════════════╝\n";
    
    testArray();
    testStack();
    testQueue();
    testCircularQueue();
    testPriorityQueue();
    testSinglyLinkedList();
    testDoublyLinkedList();
    testCircularLinkedList();
    testBST();
    testAVLTree();
    testMinHeap();
    testMaxHeap();
    testSortingAlgorithms();
    testSearchingAlgorithms();
    
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════════╗\n";
    cout << "║      ALL TESTS COMPLETED SUCCESSFULLY!                   ║\n";
    cout << "╚═══════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    
    return 0;
}
