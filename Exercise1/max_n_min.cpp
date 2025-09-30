#include<iostream>
#include<utility>

// Time Complexity: For every function call
// 1 base case check: O(1)
// 1 funktion call: O(1)
// 1 cmp : O(1)
// 1 return: O(1)
// total 4*O(1) = O(1)
// And the function calls itself N times therefore:
// Worst Case Complexity: O(1*N) = O(N) 
template<typename T> T findMax(T* arr, unsigned int n){
    
    if(n == 1){return arr[0];} // if size is 1 --> return the element

    T rest = findMax(arr+1, n-1); // find maximum value in the rest of the array

    if (arr[0] > rest)
        return arr[0]; // compare the first element with the rest

    return rest; // else return the rest. 
}

// Time Complexity: For every function call
// 1 base case check: O(1)
// 1 funktion call: O(1)
// 1 cmp : O(1)
// 1 return: O(1)
// total 4*O(1) = O(1)
// And the function calls itself N times therefore:
// Worst Case Complexity: O(1*N) = O(N) 
template<typename T> T findMin(T* arr, unsigned int n){
    
    if(n == 1){return arr[0];} // if size is 1 --> return the element

    T rest = findMin(arr+1, n-1); // find minimum value in the rest of the array

    if (arr[0] < rest)
        return arr[0]; // compare the first element with the rest

    return rest; // else return the rest. 
}


int main(){

    unsigned int n = 7;
    int arr[] = {2, 1,5,11,56,12, 86};
    int maxVal  = findMax<int>(arr, n);
    int minVal  = findMin<int>(arr, n);

    std::cout << "Max: " << maxVal << '\n';
    std::cout << "Min: " << minVal << '\n';
}