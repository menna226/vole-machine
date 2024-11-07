#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <iomanip>

class Register {
private:
    char memory[16] = {0};  // Array to store register values

public:
    static const int size = 16;  // Number of registers 

    // Gets the number of registers
    int getSize() const;

    // Gets the value of a specific register
    int getCell(int address) const;

    // Sets a value in a specific register
    void setCell(int address, int val);

    // Displays the values of all registers
    void display() const;
};

#endif
