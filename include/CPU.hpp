#pragma once 

#include <cstddef>
#include <cstdint>
#include <vector>

class CPU
{
public:
    CPU();

    /**
     * @brief Resets the CPU state.
     *
     * @details Clears the registers (A, B, PC, FLAGS) and sets all memory contents to zero.
     */
    void reset();

    /**
     * @brief Starts executing the loaded program.
     *
     * @details Continuously fetches, decodes, and executes instructions from memory,
     * starting from address 0, until a HLT instruction (0xFF) is encountered.
     */
    void run();

    /**
     * @brief Loads a program into CPU memory starting at address 0.
     *
     * @details Copies the provided program bytes into the CPU's memory.
     * If the program is larger than the available memory size,
     * an error is printed and the program is not loaded.
     *
     * @param program A vector of bytes representing the program instructions and data.
     */
    void loadProgram(const std::vector<uint8_t> &program);

private:
    // Registers
    uint8_t regA;
    uint8_t regB;
    uint8_t regPC; // Program counter
    uint8_t regFLAGS; // (optional) flags (Zero flag ...)

    // Memory
    std::vector<uint8_t> memory;

    //Internel helper
    void executeInstruction(uint8_t opcode);

    static constexpr size_t MEMORY_SIZE = 256;
};