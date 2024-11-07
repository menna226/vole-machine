#include "Register.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Register::getCell(int address) const {
    return memory[address];
}

void Register::setCell(int address, int val) {
    memory[address] = val;
}

void Register::display() const {
    cout << "Register State:" << '\n';
    for (int i = 0; i < size; ++i) {
        cout << "R" << setw(2) << i << ": " << setw(4) << (int)memory[i] << '\n';
    }
    cout << '\n';
}

int Register::getSize() const {
    return size;
}
