#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Prints the elements in the vector and their memory locations 
 * 
 * @param v - vector of integers
 */
void printMemVec(const vector<int>& v) {
    printf("Vector - Each int is worth %lu bytes\n", sizeof(int)); // Print size of int
    for (size_t i = 0; i < v.size(); i++) {
        printf("Value : %i at Memory Location: %p\n", v[i], (void*)(&v[i])); // Print value and memory address
    }
}

/**
 * @brief Increments all of the elements in v by 10
 * 
 * @param v - reference to a vector of integers
 */
void incVecBy10(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i] += 10; // Increment each element by 10
    }
}

int main() {
    // Create a constant integer called SIZE that is of value 5
    const int SIZE = 5;

    // Create a vector of integers called vec that can hold up to 5 elements
    vector<int> vec(SIZE);

    // Use a for loop to populate vec with the values 100 to 104
    for (int i = 0; i < SIZE; i++) {
        vec[i] = 100 + i;
    }

    printf("Before Increment------------\n");
    // Call printMemVec on vec
    printMemVec(vec);

    // Increment vector elements by 10
    incVecBy10(vec);

    printf("After Increment------------\n");
    // Call printMemVec on vec again
    printMemVec(vec);

    return 0;
}