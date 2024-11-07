#include "ALU.h"
#include <sstream>  
#include <cmath>
using namespace std;

// string ALU::hexToDec(const string& hex) {
//     int decimalValue = stoi(hex, nullptr, 16);
//     return to_string(decimalValue);
// }

// string ALU::decToHex(const string& dec) {
//     int decimalValue = stoi(dec);
//     stringstream ss;
//     ss << std::hex << decimalValue;  // Use std::hex for hexadecimal formatting
//     return ss.str();
// }

// bool ALU::isValid(const string& instruction) {
//     // Validate if the instruction matches the Vole machine's instruction set format
//     return instruction.length() == 4;  // Example validation
// }

void ALU::add(int idx1, int idx2, int idx3, Register& reg) {
    // Adds values from idx2 and idx3 and stores result in idx1
    int result = reg.getCell(idx2) + reg.getCell(idx3);
    reg.setCell(idx1, result);
}

void ALU::addFloat(int R, int S, int T, Register& reg) {
    // if (R < reg.size && S < reg.size && T < reg.size) {
        // Extract sign, exponent, and mantissa for registers S and T
        int signS = (reg.getCell(S) >> 7) & 1;
        int exponentS = (reg.getCell(S) >> 4) & 0b111;
        int mantissaS = reg.getCell(S) & 0b1111;

        int signT = (reg.getCell(T) >> 7) & 1;
        int exponentT = (reg.getCell(T) >> 4) & 0b111;
        int mantissaT = reg.getCell(T) & 0b1111;

        // Convert S and T to floating-point values
        float valS = pow(-1, signS) * (mantissaS / 16.0) * pow(2, exponentS - 4);
        float valT = pow(-1, signT) * (mantissaT / 16.0) * pow(2, exponentT - 4);

        // Perform floating-point addition
        float result = valS + valT;

        // Convert result back to custom floating-point format
        int signResult = result < 0 ? 1 : 0;
        result = fabs(result);

        int exponentResult = static_cast<int>(floor(log2(result))) + 4;
        int mantissaResult = static_cast<int>((result / pow(2, exponentResult - 4)) * 16) & 0b1111;

        // Combine into a single integer in custom format and set the result in register R
        reg.setCell(R, (signResult << 7) | (exponentResult << 4) | mantissaResult);
    // }
}

void ALU::bitwiseOr(int idx1, int idx2, int idx3, Register& reg) {
    int result = reg.getCell(idx2) | reg.getCell(idx3);
    reg.setCell(idx1, result);
}

void ALU::bitwiseAnd(int idx1, int idx2, int idx3, Register& reg) {
    int result = reg.getCell(idx2) & reg.getCell(idx3);
    reg.setCell(idx1, result);
}

void ALU::bitwiseXor(int idx1, int idx2, int idx3, Register& reg) {
    int result = reg.getCell(idx2) ^ reg.getCell(idx3);
    reg.setCell(idx1, result);
}

