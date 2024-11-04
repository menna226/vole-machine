// Register.cpp
#include "Register.h"

int Register::getCell(int address) const {
    // Returns the value in the specified register
    return memory[address];
}

void Register::setCell(int address, int val) {
    // Sets the value in the specified register
    memory[address] = val;
}

int Register::getSize()const{
    return size;
}
