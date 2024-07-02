#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class VirtualMachine {
private:
    vector<int> registers;
    map<string, int> memory;

public:
    VirtualMachine() {
        registers.resize(5, 0); // Assuming we have 5 general-purpose registers R0-R4
    }

    void LD(int reg, int value) {
        registers[reg] = value;
    }

    void ADD(int reg, int value) {
        registers[reg] += value;
    }

    void SUB(int reg, int value) {
        registers[reg] -= value;
    }

    void MUL(int reg, int value) {
        registers[reg] *= value;
    }

    void DIV(int reg, int value) {
        if (value != 0)
            registers[reg] /= value;
        else
            cout << "Error: Division by zero!" << endl;
    }

    void ST(int reg, string addr) {
        memory[addr] = registers[reg];
    }

    void FJ(int reg, int address, const vector<string>& instructions) {
        if (registers[reg] == 0)
            executeJump(address, instructions);
    }

    void TJ(int reg, int address, const vector<string>& instructions) {
        if (registers[reg] != 0)
            executeJump(address, instructions);
    }

    void JMP(int address, const vector<string>& instructions) {
        executeJump(address - 1, instructions); // Subtract 1 to account for zero-based indexing
    }

    void LT(int reg, int value) {
        if (registers[reg] < value)
            registers[reg] = 1;
        else
            registers[reg] = 0;
    }

    void GT(int reg, int value) {
        if (registers[reg] > value)
            registers[reg] = 1;
        else
            registers[reg] = 0;
    }

    void EQ(int reg, int value) {
        if (registers[reg] == value)
            registers[reg] = 1;
        else
            registers[reg] = 0;
    }

    void LE(int reg, int value) {
        if (registers[reg] <= value)
            registers[reg] = 1;
        else
            registers[reg] = 0;
    }

    void GE(int reg, int value) {
        if (registers[reg] >= value)
            registers[reg] = 1;
        else
            registers[reg] = 0;
    }

    void NE(int reg, int value) {
        if (registers[reg] != value)
            registers[reg] = 1;
        else
            registers[reg] = 0;
    }

    void execute(const vector<string>& instructions) {
        for (size_t i = 0; i < instructions.size(); ++i) {
            istringstream iss(instructions[i]);
            string op, reg_str, value_str;
            int reg, value;
            iss >> op >> reg_str >> value_str;
            reg = stoi(reg_str.substr(1)); // Extract register number from R
            value = getValue(value_str);

            if (op == "LD")
                LD(reg, value);
            else if (op == "ADD")
                ADD(reg, value);
            else if (op == "SUB")
                SUB(reg, value);
            else if (op == "MUL")
                MUL(reg, value);
            else if (op == "DIV")
                DIV(reg, value);
            else if (op == "ST")
                ST(reg, value_str);
            else if (op == "FJ")
                FJ(reg, value, instructions);
            else if (op == "TJ")
                TJ(reg, value, instructions);
            else if (op == "JMP")
                JMP(value, instructions);
            else if (op == "LT")
                LT(reg, value);
            else if (op == "GT")
                GT(reg, value);
            else if (op == "EQ")
                EQ(reg, value);
            else if (op == "LE")
                LE(reg, value);
            else if (op == "GE")
                GE(reg, value);
            else if (op == "NE")
                NE(reg, value);
        }
    }

    void printRegisters() {
        cout << "Registers:" << endl;
        for (size_t i = 0; i < registers.size(); ++i)
            cout << "R" << i << ": " << registers[i] << endl;
    }

    void printMemory() {
        cout << "Memory:" << endl;
        for (const auto& entry : memory)
            cout << entry.first << ": " << entry.second << endl;
    }

private:
    int getValue(string val) {
        if (val[0] == 't' || val[0] == 'a' || val[0] == 'b' || val[0] == 'x') // Check if it's a temporary variable or variable a, b, or x
            return memory[val];
        else
            return stoi(val);
    }

    void executeJump(int address, const vector<string>& instructions) {
        // Execute a jump to the specified address
        // For simplicity, just go to the instruction with the given address
        // This would typically involve updating the program counter
        // But here, we'll just call execute() with a subset of instructions
        // starting from the given address
        vector<string> instructionsSubset(instructions.begin() + address, instructions.end());
        execute(instructionsSubset);
    }
};


