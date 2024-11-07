// CU.h
#ifndef CU_H
#define CU_H

#include "Register.h"
#include "Memory.h"

class CU {
public:
    // Loads a value from memory into a register
    void load(int idxReg, int intMem, Register& reg, Memory& mem);

    // Loads an immediate value into a register
    void load(int idxReg, int val, Register& reg);

    // Stores a value from a register into memory
    void store(int idxReg, int idxMem, Register& reg, Memory& mem);

    // Moves a value between two registers
    void move(int idxReg1, int idxReg2, Register& reg);

    // Jumps to a specified address based on condition
    void jumpEqual(int idxReg, int idxMem, Register& reg, int& programCounter);
    void jumpGreater(int idxReg, int idxMem, Register& reg, int& programCounter);

    void rotateRight(int idxReg, int steps, Register& reg);

    // Halts the CPU
    void halt();
};

#endif
