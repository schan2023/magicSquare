#include <iostream>
#include "pa1.h"
#include <cmath>
using namespace std;


//Main Method
  int main () {

    cout <<"Enter the size of a magic square: ";
    int odd;
    cin >> odd;


//Checks if input is valid
  while (!isValid(odd)) {
    cout<<"Invalid Input. Please enter odd integer between 3 and 15: ";
    cin >> odd;
  }

//Creates 2D Array of max size 15
  int arr[15][15];

//Initializes every element to zero and calls each of the four squares
  init(arr, odd);
cout<<"Magic Square #1 is: " << endl;
  createSquare1(arr, odd);
  init(arr, odd);
cout<<"\nMagic Square #2 is: " << endl;
  createSquare2(arr, odd);
  init(arr, odd);
cout<<"\nMagic Square #3 is: " << endl;
  createSquare3(arr, odd);
  init(arr, odd);
cout<<"\nMagic Square #4 is: " << endl;
  createSquare4(arr, odd);

  return 0;
}

//End Main Method

//Checks if value is correct
bool isValid(int n) {
    if ((n % 2 == 0) || (n < 3 || n > 15)) {
      return false;
    }

    else {
      return true;
    }
  }

//Initializes array to zero
void init(int array[15][15], int val) {
  int def = 0;
  for(int i = 0; i < val; ++i) {
    for(int j = 0; j < val; ++j) {
      array[i][j] = def;
    }
  }
}

//Create Magic Squares: Used Siamese method for computing Magic Squares

//   /* Magic Square #1
//     Start at last column, middle row
//     Move one up and one to the right
//     If element is filled, move one to the left
//   */
void createSquare1(int array[15][15], int val) {
  int row = val/2;
  int col = val - 1;
  int max = val*val;
  for (int num = 1; num <= max; num++) {
      array[row][col] = num;
    //If row or column is out of bounds,
    //mod by original value so current position would reset
      int currentRow = (row - 1 + val) % val;
      int currentCol = (col + 1) % val;

    //When the index is not empty, set element and move one column left
      if(array[currentRow][currentCol] != 0) {
        col = (col - 1) % val;
      }
      else {
        row = currentRow;
        col = currentCol;
      }
    }
    printArray(array, val);
    cout <<"Checking the sums of every row: ";
    sumRows(array, val);
    cout <<"\nChecking the sums of every column: ";
    sumCol(array, val);
    cout<<"\nChecking the sums of every diagonal: ";
    sumDiag(array, val);

  }

/*Magic Square #2
Start at first column, middle row
Move one down and one to the left
If element is filled, move one to the right
*/
void createSquare2(int array[15][15], int val) {
      int row = val/2;
      int col = 0;
      int max = val*val;
      for (int num = 1; num <= max; num++) {

          array[row][col] = num;

        //If row or column is out of bounds, "wraps" around to next index
          int currentRow = (row + 1) % val;
          int currentCol = (col - 1 + val) % val;

        //When the index is not empty, set element and move to next column
          if(array[currentRow][currentCol] != 0) {
            col = (col + 1) % val;
          }
          else {
            row = currentRow;
            col = currentCol;
          }
  }
      printArray(array, val);
      cout <<"Checking the sums of every row: ";
      sumRows(array, val);
      cout <<"\nChecking the sums of every column: ";
      sumCol(array, val);
      cout<<"\nChecking the sums of every diagonal: ";
      sumDiag(array, val);

}

/*Magic Square #3
Start at first row, middle column
Move one up and one to the right
If element is filled, move one down
*/
void createSquare3(int array[15][15], int val) {
    int row = 0;
    int col = val/2;
    int max = val*val;
    for (int num = 1; num <= max; num++) {

        array[row][col] = num;

      //If row or column is out of bounds, "wraps" around to next index
        int currentRow = (row - 1 + val) % val;
        int currentCol = (col + 1) % val;

      //When the index is not empty, set element and move to next row
        if(array[currentRow][currentCol] != 0) {
          row = (row + 1) % val;
        }
        else {
          row = currentRow;
          col = currentCol;
        }

      }
      printArray(array, val);
      cout <<"Checking the sums of every row: ";
      sumRows(array, val);
      cout <<"\nChecking the sums of every column: ";
      sumCol(array, val);
      cout<<"\nChecking the sums of every diagonal: ";
      sumDiag(array, val);
}

/*Magic Square #4
Start at middle column, last row
Move one down and one to the left
If element is filled, move one to the right
*/
void createSquare4(int array[15][15], int val) {
    int row = val - 1;
    int col = val/2;
    int max = val*val;
    for (int num = 1; num <= max; num++) {

        array[row][col] = num;

      //If row or column is out of bounds, "wraps" around to next index
        int currentRow = (row + 1) % val;
        int currentCol = (col - 1 + val) % val;

      //When the index is not empty, set element and move to previous row
        if(array[currentRow][currentCol] != 0) {
          row = (row - 1) % val;
        }
        else {
          row = currentRow;
          col = currentCol;
        }

    }
    printArray(array, val);
    cout <<"Checking the sums of every row: ";
    sumRows(array, val);
    cout <<"\nChecking the sums of every column: ";
    sumCol(array, val);
    cout<<"\nChecking the sums of every diagonal: ";
    sumDiag(array, val);
}

//Sum of Rows
void sumRows(int array[15][15], int size) {
  for(int i = 0; i < size; i++) {
    int sum = 0;
    for(int j = 0; j < size; j++) {
      sum += array[i][j];
    }

      cout << sum << ' ';
  }

}

//Sum of columns
void sumCol(int array[15][15], int size) {
  for(int i = 0; i < size; i++) {
    int sum = 0;
    for(int j = 0; j < size; j++) {
      sum += array[j][i];
    }
      cout << sum << ' ';
  }
}

//Sum of diagonal
void sumDiag(int array[15][15], int size) {

  int sum = 0;
  for(int i = 0; i < size; i++) {
      sum += array[i][i];

  }
  cout << sum << ' ';
  sum = 0;

  for(int i = 0; i < size; i++) {
      sum += array[i][size - i - 1];
  }
 cout << sum << ' ';

}

//Prints 2D Array
void printArray(int array[15][15], int arraySize) {
  for(int i = 0; i < arraySize; ++i) {
      for(int j = 0; j < arraySize; ++j) {
          cout << array[i][j] << "\t";
      }
      cout << "\n";
  }

}
