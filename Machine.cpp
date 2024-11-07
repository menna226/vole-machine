#include "machine.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Machine ::setCounterPosition(int cp){
    this->counterPosition = cp;
}

void Machine ::loadProgramFile(string filename){
    ifstream file(filename); 
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return;
    }
    this->processor = CPU();
    this->memory = Memory();
    int addressCounter = this->counterPosition;
    string instruction;
    while(file >> instruction){
        string firstPart = instruction.substr(0,2);
        string secondPart = instruction.substr(2,2);
        this->memory.setCell(addressCounter++,firstPart);
        this->memory.setCell(addressCounter++,secondPart);
    }
    file.close();
    this->loadedprogram = true;
}

bool Machine ::executeProgram(){
    if(!this->loadedprogram){
        return false;
    }
    this->processor.setPC(this->counterPosition);
    while(this->processor.runNextStep(this->memory)){
        if(this->processor.printAVlueToScreen()){
            int output = stoi(this->memory.getCell(0), nullptr, 16);
            cout << (char)output;
        }
    };
    cout << '\n';
    return true;
}

void Machine ::outputState(){
    cout << "Program Counter = " << this->processor.get_programCounter() << "\n";
    cout << "Instruction register: " << this->processor.get_instructionRegister() << "\n";
    
    cout << "Register\n";
    this->processor.displayStatus();
    
    cout << "Memory\n";
    for(int i = 0; i < memory.getsize(); i++){
        cout << "Address # " << i+1 << " : "<< this->memory.getCell(i) << "\n";
    }
}

bool Machine ::getloadedprogram(){
    return loadedprogram;
}