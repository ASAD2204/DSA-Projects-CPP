/*
 * ============================================================================
 * PROJECT #9: SORTING ALGORITHM VISUALIZER
 * ============================================================================
 * Data Structure: Arrays
 * Features: Bubble, Selection, Insertion, Merge, Quick, Heap Sort
 * Displays step-by-step visualization and performance metrics
 * ============================================================================
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 20;

class SortingVisualizer {
private:
    int arr[MAX_SIZE];
    int size;
    int comparisons;
    int swaps;

    void resetMetrics() {
        comparisons = 0;
        swaps = 0;
    }

    void visualize(int highlightIdx1 = -1, int highlightIdx2 = -1) {
        cout << "\n  ";
        for (int i = 0; i < size; i++) {
            if (i == highlightIdx1 || i == highlightIdx2) {
                cout << "[" << arr[i] << "] ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            comparisons++;
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
            swaps++;
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSortHelper(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortHelper(left, mid);
            mergeSortHelper(mid + 1, right);
            merge(left, mid, right);
        }
    }

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            comparisons++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
        swap(arr[i + 1], arr[high]);
        swaps++;
        return i + 1;
    }

    void quickSortHelper(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSortHelper(low, pi - 1);
            quickSortHelper(pi + 1, high);
        }
    }

    void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n) {
            comparisons++;
            if (arr[left] > arr[largest])
                largest = left;
        }

        if (right < n) {
            comparisons++;
            if (arr[right] > arr[largest])
                largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            swaps++;
            heapify(n, largest);
        }
    }

public:
    SortingVisualizer() : size(0) {
        srand(time(0));
    }

    void generateRandom(int n) {
        size = min(n, MAX_SIZE);
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
        cout << "✅ Generated " << size << " random numbers" << endl;
    }

    void inputArray() {
        cout << "  Enter size: ";
        cin >> size;
        size = min(size, MAX_SIZE);
        cout << "  Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "\n  Current Array: ";
        visualize();
    }

    void bubbleSort() {
        resetMetrics();
        cout << "\n🔄 BUBBLE SORT\n";
        
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                    visualize(j, j + 1);
                }
            }
        }
        
        cout << "\n✅ Sorted! Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }

    void selectionSort() {
        resetMetrics();
        cout << "\n🔄 SELECTION SORT\n";
        
        for (int i = 0; i < size - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < size; j++) {
                comparisons++;
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
                swaps++;
                visualize(i, minIdx);
            }
        }
        
        cout << "\n✅ Sorted! Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }

    void insertionSort() {
        resetMetrics();
        cout << "\n🔄 INSERTION SORT\n";
        
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                comparisons++;
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            if (j >= 0) comparisons++;
            arr[j + 1] = key;
            visualize(j + 1, i);
        }
        
        cout << "\n✅ Sorted! Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }

    void mergeSort() {
        resetMetrics();
        cout << "\n🔄 MERGE SORT\n";
        mergeSortHelper(0, size - 1);
        visualize();
        cout << "\n✅ Sorted! Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }

    void quickSort() {
        resetMetrics();
        cout << "\n🔄 QUICK SORT\n";
        quickSortHelper(0, size - 1);
        visualize();
        cout << "\n✅ Sorted! Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }

    void heapSort() {
        resetMetrics();
        cout << "\n🔄 HEAP SORT\n";
        
        // Build heap
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(size, i);
        }
        
        // Extract elements
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            swaps++;
            heapify(i, 0);
            visualize(0, i);
        }
        
        cout << "\n✅ Sorted! Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }
};

int main() {
    SortingVisualizer visualizer;

    cout << "\n========================================================\n";
    cout << "         SORTING ALGORITHM VISUALIZER                   \n";
    cout << "========================================================\n";

    int choice;
    while (true) {
        cout << "\n  1. Generate Random Array\n";
        cout << "  2. Input Array Manually\n";
        cout << "  3. Display Array\n";
        cout << "  4. Bubble Sort\n";
        cout << "  5. Selection Sort\n";
        cout << "  6. Insertion Sort\n";
        cout << "  7. Merge Sort\n";
        cout << "  8. Quick Sort\n";
        cout << "  9. Heap Sort\n";
        cout << "  10. Exit\n";
        cout << "  Choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "  Enter size (max 20): ";
            cin >> n;
            visualizer.generateRandom(n);
            visualizer.display();
        }
        else if (choice == 2) {
            visualizer.inputArray();
            visualizer.display();
        }
        else if (choice == 3) visualizer.display();
        else if (choice == 4) visualizer.bubbleSort();
        else if (choice == 5) visualizer.selectionSort();
        else if (choice == 6) visualizer.insertionSort();
        else if (choice == 7) visualizer.mergeSort();
        else if (choice == 8) visualizer.quickSort();
        else if (choice == 9) visualizer.heapSort();
        else if (choice == 10) {
            cout << "\n  📊 Thanks for using Sorting Visualizer!\n";
            break;
        }
    }

    return 0;
}
