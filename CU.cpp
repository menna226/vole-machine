// CU.cpp
#include "CU.h"
#include <iostream>

void CU::load(int idxReg, int intMem, Register& reg, Memory& mem) {
    // Loads a memory value at intMem into register idxReg
    reg.setCell(idxReg, std::stoi(mem.getCell(intMem), nullptr, 16));
}

void CU::load(int idxReg, int val, Register& reg) {
    // Loads an immediate value into register idxReg
    reg.setCell(idxReg, val);
}

void CU::store(int idxReg, int idxMem, Register& reg, Memory& mem) {
    // Stores the value in register idxReg into memory at address idxMem
    char numinhex[4] ;
    sprintf(numinhex,"%X", reg.getCell(idxReg));
    mem.setCell(idxMem, string(numinhex));
}

void CU::move(int idxReg1, int idxReg2, Register& reg) {
    // Moves value from idxReg2 to idxReg1
    reg.setCell(idxReg2, reg.getCell(idxReg1));
}

void CU::jumpEqual(int idxReg, int idxMem, Register& reg, int& programCounter) {
    if (reg.getCell(idxReg) == reg.getCell(0)) {
        programCounter = idxMem;
    }
}

void CU::jumpGreater(int idxReg, int idxMem, Register& reg, int& programCounter) {
    if (reg.getCell(idxReg) > reg.getCell(0)) {
        programCounter = idxMem;
    }
}

void CU::rotateRight(int idxReg, int steps, Register& reg) {
    int value = reg.getCell(idxReg);
    steps = steps % 32;  // Ensure the rotation step is within bounds
    value = (value >> steps) | (value << (32 - steps));
    reg.setCell(idxReg, value);
}

void CU::halt() {
    // Stops the CPU execution
    // std::cout << "HALT: Program execution stopped.\n";
}
