#ifndef CPU_H
#define CPU_H

#include "Register.h"
#include "Memory.h"
#include "CU.h"
#include "ALU.h"
#include <string>
#include <vector>

using namespace std;

class CPU {
private:
    int programCounter;               // Holds the address of the next instruction
    string instructionRegister;       // Holds the current instruction
    Register reg;                     // The CPU's register set
    ALU alu;                          // ALU for handling arithmetic/logic operations
    CU cu;                            // Control Unit for decoding and executing instructions
    bool PrintAValue;
    // Fetches the next instruction from memory
    void fetch(Memory& mem);

    // Decodes the current instruction into individual components
    vector<int> decode();

    // Executes a decoded instruction
    bool execute(Register& reg, Memory& mem, vector<int> instruction);

public:
    // CPU(); // Constructor

    bool printAVlueToScreen();

    // Executes the next instruction in memory
    bool runNextStep(Memory& mem);

    // Sets the program counter to a specific value
    void setPC(int pc);

    // Returns the current instruction in the instruction register
    string get_instructionRegister();

    // Returns the current value of the program counter
    int get_programCounter();

    // Display the state of all registers
    void displayStatus()const;

};

#endif // CPU_H
