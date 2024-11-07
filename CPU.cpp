#include "CPU.h"
#include <iostream>

using namespace std;

bool CPU::runNextStep(Memory& mem) {
    this->PrintAValue = false;
    fetch(mem);                   // Fetch instruction
    auto instruction = decode();  // Decode instruction
    bool result = execute(reg, mem, instruction); // Execute instruction
    // displayStatus();              // Display register status
    return result;
}

bool CPU::printAVlueToScreen(){
    return this->PrintAValue;
}
void CPU::fetch(Memory& mem) {
    string firstHalf = mem.getCell(programCounter);
    string secondHalf = mem.getCell(programCounter + 1);
    instructionRegister = firstHalf + secondHalf;
    programCounter += 2;
}

vector<int> CPU::decode() {
    vector<int> instruction;
    if (instructionRegister.length() == 4) {
        instruction.push_back(stoi(instructionRegister.substr(0, 1), nullptr, 16));
        instruction.push_back(stoi(instructionRegister.substr(1, 1), nullptr, 16));
        instruction.push_back(stoi(instructionRegister.substr(2, 1), nullptr, 16));
        instruction.push_back(stoi(instructionRegister.substr(3, 1), nullptr, 16));
    }
    else {
        cout << "Invalid instruction format!\n";
    }
    return instruction;
}

bool CPU::execute(Register& reg, Memory& mem, vector<int> instruction) {
    int opCode = instruction[0];
    switch (opCode) {
    case 1: cu.load(instruction[1], ((instruction[2] * 16 )+ instruction[3]), reg, mem); break;
    case 2: cu.load(instruction[1], ((instruction[2] * 16 )+ instruction[3]), reg); break;
    case 3:
        cu.store(instruction[1], ((instruction[2] * 16 )+ instruction[3]), reg, mem);
        if (((instruction[2] * 16 )+ instruction[3]) == 0) { // Check if the destination is memory location 0
            this->PrintAValue = true;
        }
        break;
    case 4: cu.move(instruction[2], instruction[3], reg); break;
    case 5: alu.add(instruction[1], instruction[2], instruction[3], reg); break;
    case 6: alu.addFloat(instruction[1], instruction[2], instruction[3], reg); break;
    case 7: alu.bitwiseOr(instruction[1], instruction[2], instruction[3], reg); break;
    case 8: alu.bitwiseAnd(instruction[1], instruction[2], instruction[3], reg); break;
    case 9: alu.bitwiseXor(instruction[1], instruction[2], instruction[3], reg); break;
    case 10: cu.rotateRight(instruction[1], instruction[3], reg); break;
    case 11: cu.jumpEqual(instruction[1], ((instruction[2] * 16 )+ instruction[3]), reg, programCounter); break;
    case 12: cu.halt(); return false;
    case 13: cu.jumpGreater(instruction[1], ((instruction[2] * 16 )+ instruction[3]), reg, programCounter); break;
    default:
        cout << "Invalid opcode!\n";
        return false;
    }
    return true;
}

void CPU::setPC(int pc) {
    this->programCounter = pc;
}

string CPU::get_instructionRegister() {
    return instructionRegister;
}

int CPU::get_programCounter() {
    return programCounter;
}

void CPU::displayStatus() const {
    cout << "REGISTER: \n";
    reg.display();
}
