#include "memory.h"
#include <iostream>
using namespace std;

Memory::Memory(): memory(vector<string>(size,"00")){};

int Memory::getsize() const{
    return size;
};
string Memory::getCell(int address) const{
    if(address >= 0 && address < size){
        return memory[address];
    }
    throw range_error("invalid address " + to_string(address));
};
void Memory::setCell(int address, const string& val){
    if(address >= 0 && address < size){
        memory[address] = val;
    }
};
