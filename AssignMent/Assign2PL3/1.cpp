// Given an array A[0…n-1] of n numbers containing repetition of some number. Given an algorithm for checking whether there are repeated element or not. Assume that we are not allowed to use additional space (i.e., we can use a few temporary variable, O(1) storage).

//use Floyd's Tortoise and Hare (Cycle Detection) algorithm
//by using Hashing insert the nodes in the hashmap and when a node is encountered that is already present in hashmap then return 1

#include <iostream>

bool hasDuplicate(int A[], int n) {
    int slow = A[0];
    int fast = A[0];

    do {
        slow = A[slow];
        fast = A[A[fast]];
    } while (slow != fast);

    // Reset one pointers to the beginning
    slow = A[0];

    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }

    return slow == fast;
}

int main() {
    int A[] = {2, 3, 1, 4, 2}; 
    int n = sizeof(A) / sizeof(A[0]);

    if (hasDuplicate(A, n)) {
        std::cout << "Duplicates exist in the array." << std::endl;
    } else {
        std::cout << "No duplicates found in the array." << std::endl;
    }

    return 0;
}
