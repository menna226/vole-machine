// Machine.h
#ifndef MACHINE_H
#define MACHINE_H

#include "CPU.h"
#include "Memory.h"

class Machine {
private:
    CPU processor;    // The CPU instance, containing ALU, CU, and Register
    Memory memory;    // Memory instance for program and data storage
    bool loadedprogram = false; 
    int counterPosition = 10;

public:
    // Loads a program file into memory
    void loadProgramFile(string filename);

    // Displays the current state of CPU, memory, and registers
    void outputState();

    bool executeProgram();

    void setCounterPosition(int cp);

    bool getloadedprogram();
};

#endif