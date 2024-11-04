// Register.h
#ifndef REGISTER_H
#define REGISTER_H

#include <vector>

class Register {
private:
    int memory[16];             // Array to store register values
    int size = 16;              // Number of registers

public:
    // Gets the value of a specific register
    int getCell(int address) const;

    // Sets a value in a specific register
    void setCell(int address, int val);
};

#endif
