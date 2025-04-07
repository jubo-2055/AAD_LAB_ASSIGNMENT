
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int tree[MAX_SIZE];  
int size = 0;        

void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;  
    }
}

// Insert a value into the BST
void insert(int value) {
    int index = 0;  // Start at the root

    while (index < MAX_SIZE) {
        if (tree[index] == -1) {  // Found an empty spot
            tree[index] = value;
            size++;
            return;
        }
        if (value < tree[index]) {
            index = 2 * index + 1;  // Move to left child
        } else {
            index = 2 * index + 2;  // Move to right child
        }
    }

    cout << "Error: Tree is full or too deep to insert " << value << endl;
}

// In-order traversal to print sorted order
void inorder(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) return;

    inorder(2 * index + 1); // Left subtree
    cout << tree[index] << " ";
    inorder(2 * index + 2); // Right subtree
}

// Function to perform BST Sort
void bstSort(int arr[], int n) {
    initializeTree();  // Ensure tree is empty before sorting
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    // Print the sorted elements using in-order traversal
    inorder(0);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid number of elements (must be between 1 and " << MAX_SIZE << ")." << endl;
        return 1;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sorted array: ";
    bstSort(arr, n);
    cout << endl;

    delete[] arr;
    return 0;
}
