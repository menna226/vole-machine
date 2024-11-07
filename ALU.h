// ALU.h
#ifndef ALU_H
#define ALU_H

#include "Register.h"
#include <string>

using namespace std;

class ALU {
public:
    // Converts hexadecimal string to decimal
    string hexToDec(const string& hex);

    // Converts decimal string to hexadecimal
    string decToHex(const string& dec);

    // Checks if a given string is a valid instruction
    bool isValid(const string& instruction);

    // Adds values from two registers and stores in a third register
    void add(int idx1, int idx2, int idx3, Register& reg);

    void addFloat(int R, int S, int T, Register& reg);

   void bitwiseOr(int idx1, int idx2, int idx3, Register& reg);

   void bitwiseAnd(int idx1, int idx2, int idx3, Register& reg);

   void bitwiseXor(int idx1, int idx2, int idx3, Register& reg);
};

#endif
