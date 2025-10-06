#include<iostream>
#define ROWS 5
#define COLS 5

bool maze(char arr[ROWS][COLS], int row, int col) {

    if (row < 0 || row >= ROWS){return false;} // Out of bound
    if (col < 0 || col >= ROWS){return false;} // Out of bound
    

    char current = arr[row][col]; // Startposition (1,1)
    if(current == 'E'){return true;} // Path exists
    else if(current == 'X'){return false;} // Blind spot 
    else if(current == 'A'){ // Already covered
        return false;
    }

    else if(current == ' '){
        arr[row][col] = 'A'; // Mark as covered
        if(maze(arr, row, col+1)){return true;}
        if(maze(arr, row, col-1)){return true;} 
        if(maze(arr, row+1, col)){return true;}
        if(maze(arr, row-1, col)){return true;}
        
        arr[row][col] = ' ';
        return false;
    }
    
    return false;
    
}