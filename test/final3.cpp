#include <iostream>

using std::cout, std::endl;

// TODO: Write this function
void duplicateOddNumbers(int*& ary, unsigned int& size){
    
    unsigned int count = 0;
    for (int i = 0; i < size; i++){
        if (ary[i] % 2 == 1){
            count++;
        }
    }
    size = size + count;
    int* newarray = new int[size];
    unsigned int j = 0;
    unsigned int i = 0;
    while(j < size){
        newarray[j] = ary[i];
        if(ary[i] % 2 == 1){
            j++;
            newarray[j] = ary[i];
        }
        i++;
        j++;

    }
    delete [] ary;
    ary = newarray;
}

void printAry(const int* ary, unsigned int size) {
    cout << size << " elements:" << endl;
    for (unsigned int i=0; i<size; ++i) {
        cout << ary[i] << endl;
    }
}

int main() {
    unsigned int size = 8;
    int* ary = new int[size] {3, 4, 2, 1, 6, 8, 9};
    printAry(ary, size);
    duplicateOddNumbers(ary, size);
    printAry(ary, size);
    delete [] ary;
}