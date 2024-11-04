#include "Register.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Register::getCell(int address) const {
    // Returns the value in the specified register
    return memory[address];
}

void Register::setCell(int address, int val) {
    // Sets the value in the specified register
    memory[address] = val;
}

void Register::display() const {
    cout << "Register State:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "R" << setw(2) << i << ": " << setw(4) << memory[i] << endl;
    }
    cout << endl;
}

int Register::getSize()const {
    return size;
}
