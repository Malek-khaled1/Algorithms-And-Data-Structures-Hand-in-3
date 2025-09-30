#include <iostream>
#include<string>

void triangle(int m, int n) {
    if (m > n) return; // return to the calling fuction if m > n

    std::cout << std::string(m, '*') << '\n'; // Start printing the m stars
    if (m == n) { // stop and print n stars
        std::cout << std::string(n, '*') << '\n'; 
        return; // to the calling function
    }
    triangle(m + 1, n); // After the recursive call print the mirrored triangle
    std::cout << std::string(m, '*') << '\n';
}


int main()
{

    triangle(4,6);

    return 0;
}