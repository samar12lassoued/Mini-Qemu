#include "CPU.hpp"
#include <iostream>

CPU::CPU()
{
    memory.resize(MEMORY_SIZE);
    reset();
}

void CPU::reset()
{
    regA = 0;
    regB = 0;
    regPC = 0;
    regFLAGS = 0;
    std::fill(memory.begin(), memory.end(), 0);

}


void CPU::loadProgram(const std::vector<uint8_t>& program)
{
    if (program.size() > MEMORY_SIZE)
    {
        std::cerr << "Program too large to fit in memory!" << std::endl;
        return;
    }

    for (size_t i = 0; i < program.size(); ++i)
    {
        memory[i] = program[i];
    }
}

void CPU::run()
{
    bool running = true;
    while (running)
    {

        uint8_t opcode = memory[regPC++];
        switch (opcode)
        {
            case 0x01: // Example: MOV A, imm8
                regA = memory[regPC++];
                std::cout << "MOV A, " << static_cast<int>(regA) << std::endl;
                break;
            case 0x02: // MOV B, imm8
                regB = memory[regPC++];
                std::cout << "MOV B, " << static_cast<int>(regB) << std::endl;
                break;
            case 0x03: // ADD A, B
                regA += regB;
                std::cout << "ADD A + B = " << static_cast<int>(regA) << std::endl;
                break;
            case 0xFF: // HLT
                running = false;
                std::cout << "HLT (Halting CPU)" << std::endl;
                break;
            default:
                std::cerr << "Unknown opcode: " << (int)opcode << std::endl;
                std::cerr << "Unknown opcode: " << static_cast<int>(opcode) << std::endl;
                running = false;
                break;        }
    }
}


/* loadProgram  function: 
1. Takes a program as a std::vector<uint8_t>.

      * Example: a list of opcodes and data ({0x01, 5, 0x02, 10, 0x03, 0xFF}).

2. Checks if the program is too big to fit inside memory.

    If yes → prints an error and stops.

    (Prevents memory overflow!)

3. Copies each byte of the program into the CPU's memory array starting at index 0.

    memory[0] = first byte

    memory[1] = second byte

    and so on...

4. Result: The CPU memory now contains your program, ready for run() to execute it!*/