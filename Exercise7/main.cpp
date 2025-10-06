#include "counting_sort.hpp"

int main() {
    // Create unsorted vector 
    std::vector<int> vec = {4, 2, 2, 8, 3, 3, 1};

    // Print vector before sorting
    std::cout << "Before: ";
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // Sort the vector
    counting_sort(vec);

    // Print result 
    std::cout << "After: ";
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
