#include <iostream>

void bookletPrint(int startPage, int endPage){

    if (startPage > endPage)
    {
        return;
    }
    std::cout << "Sheet " <<  (startPage + 1)/2 << " contains pages " 
    <<startPage << "," << startPage+1 << "," << endPage-1 << "," << endPage << '\n';
    bookletPrint(startPage+2, endPage-2);
}


int main(){


    bookletPrint(1,12);


    return 0;
}