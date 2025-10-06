#include "insertion_sort.h"



int main() {
    // Test 1: Allerede sorteret
    vector<int> v1 = {1, 2, 3, 4, 5};
    cout << "Før sortering (allerede sorteret): ";
    printVector(v1);
    selected_sort(v1);
    cout << "Efter sortering: ";
    printVector(v1);
    cout << "---------------------\n";

    // Test 2: Omvendt sorteret
    vector<int> v2 = {5, 4, 3, 2, 1};
    cout << "Før sortering (omvendt): ";
    printVector(v2);
    selected_sort(v2);
    cout << "Efter sortering: ";
    printVector(v2);
    cout << "---------------------\n";

    // Test 3: Tilfældig rækkefølge
    vector<int> v3 = {8, 2, 7, 1, 4};
    cout << "Før sortering (tilfældig): ";
    printVector(v3);
    selected_sort(v3);
    cout << "Efter sortering: ";
    printVector(v3);
    cout << "---------------------\n";

    // Test 4: Med duplikater
    vector<int> v4 = {5, 1, 3, 1, 2, 5};
    cout << "Før sortering (duplikater): ";
    printVector(v4);
    selected_sort(v4);
    cout << "Efter sortering: ";
    printVector(v4);
    cout << "---------------------\n";

    // Test 5: Én enkelt værdi
    vector<int> v5 = {42};
    cout << "Før sortering (1 element): ";
    printVector(v5);
    selected_sort(v5);
    cout << "Efter sortering: ";
    printVector(v5);
    cout << "---------------------\n";

    return 0;
}