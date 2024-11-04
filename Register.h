#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <iostream>

class Register {
private:
    int memory[16];             // Array to store register values
    static const int size = 16;              // Number of registers

public:
    int getSize() const;

    // Gets the value of a specific register
    int getCell(int address) const;

    // Sets a value in a specific register
    void setCell(int address, int val);

    // Displays the values of all registers
    void display() const;
};

#endif
