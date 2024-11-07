// Memory.h
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>
using namespace std;

class Memory {
private:
    vector<string>memory;
    static const int size = 256;
public:
    Memory();
    int getsize() const;
    string getCell(int address) const;
    void setCell(int address, const std::string& val);
};

#endif