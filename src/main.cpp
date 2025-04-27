#include "CPU.hpp"

int main()

{
    CPU cpu;

    // Program: MOV A, 5; MOV B, 10; ADD A, B; HLT
    std::vector<uint8_t> program = {
        0x01, 5,
        0x02, 10,
        0x03,
        0xFF};

    // Load a simple program into memory
    cpu.loadProgram(program);

    /*
    // Load a simple program into memory manually
    cpu.memory[0] = 0x01; // MOV A, 5
    cpu.memory[1] = 5;
    cpu.memory[2] = 0x02; // MOV B, 10
    cpu.memory[3] = 10;
    cpu.memory[4] = 0x03; // ADD A, B
    cpu.memory[5] = 0xFF; // HLT*/

    cpu.run();

    return 0;
}