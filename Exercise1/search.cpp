#include <iostream>


template<typename T> bool search(T* arr, T x , unsigned int n){
    
    // return false if size is 0
    if(n <= 0) {return false;} 
    // return true if element found
    if(arr[0] == x) {return true;}
    // recursive call: increment pointer and deacrease size
    return search(arr+1, x, n-1);
}

int main(void)
{
    char x = 'X';
    char arr[] = "MalcolmX";
    unsigned int n = sizeof(arr);

    if(search<char>(arr, x, n))
        std:: cout << "Element: "<< x << " found!" << '\n';

    return 0;
}