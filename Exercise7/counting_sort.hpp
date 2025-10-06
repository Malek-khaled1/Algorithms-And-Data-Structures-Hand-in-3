#include<iostream>
#include<vector>
#include<algorithm>
void counting_sort(std::vector<int>& vec){

    // Find the maximum element of the vector.
    int max_value = *std::max_element(vec.begin(), vec.end());
    // create a vector with space to k + 1
    std::vector<int> count(max_value + 1); 
    // Create an empty output vector
    std::vector<int> output(vec.size());

    // íterate through the vector
    for (int i = 0; i < vec.size(); ++i)
    {
        // Count occurences
       count[vec[i]]+=1;
    }

    // Calculate the prefix sum
    for (int j = 1; j < count.size(); ++j)
    {
        count[j] = count[j] + count[j - 1];
    }

    // Iterate the original vector backwards
    for (int p = vec.size() - 1; p >= 0; --p)
    {   
        // Insert element at the correct place in output vector
        output[count[vec[p]] - 1] = vec[p];
        // Decrement prefix
        count[vec[p]] -=1; 
    }
    // Move all elements from the output vector to the original vector
    vec = std::move(output);

}