#include <fstream>
#include <iostream>

using namespace std;

/*
(5 pts) Suppose a file exists called numbers.txt and it is filled with integers,
one integer per line, with 1 to 10 integers in the file. Write a modular C++
program that:
*/
void openFile(ifstream &, string);
int countNums(ifstream &);
void loadNums(ifstream &, int[]);
void displayNums(int[], int);
void reverseNums(int[], int);

int main() {
  int num = 0;
  int size = 0;
  ifstream inFile;
  string fileName = "numbers.txt";

  openFile(inFile, fileName);
  size = countNums(inFile);
  inFile.close();
  cout << "read " << size << " nums from the file" << endl;

  int array[size];
  openFile(inFile, fileName);
  loadNums(inFile, array);
  inFile.close();
  displayNums(array, size);

  reverseNums(array, size);
  displayNums(array, size);

  return 0;
}

// Opens numbers.txt for reading and checks that the file opened
// successfully. If the file did not open successfully, terminate the program.
void openFile(ifstream &inFile, string fileName) {
  inFile.open(fileName);
  if (!inFile.is_open()) {
    cout << "Failed to open file" << endl;
    exit(-1);
  }
}

int countNums(ifstream &inFile) {
  int num, size = 0;
  while (!inFile.eof()) {
    inFile >> num;
    if (!inFile.bad()) {
      cout << "num: " << num << endl;
      size++;
    }
  }
  return size;
}

// Reads the integers from numbers.txt and stores them in an array. You are
// guaranteed there is at least one integer but no more than 10 integers in the
// file. Declare your array appropriately.
void loadNums(ifstream &inFile, int array[]) {
  int num, i = 0;
  while (!inFile.eof()) {
    inFile >> num;
    if (!inFile.bad()) {
      array[i] = num;
      i++;
    }
  }
}

// Prints the integers to the console. Each integer should be separated by a
// comma and a space. For example: 1, 2, 3, 4, 5
void displayNums(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << endl;
}

// Reverses the integers in the array. For example, 1 2 3 4 5 reversed is 5 4 3
// 2 1. After you reverse the array, print the array again.
void reverseNums(int array[], int size) {
  int num;
  cout << "Reversing!" << endl;

  int j = size - 1;
  for (int i = 0; i < size / 2; i++) {
    num = array[i]; // save value before
    array[i] = array[j];
    array[j] = num;
    j--;
  }
}