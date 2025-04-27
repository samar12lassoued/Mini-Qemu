# Mini-Qemu

A simple CPU emulator written in C++.
It simulates a basic CPU with memory, registers, and a minimal instruction set.

## 🔁 CPU Execution Flow

1. Fetch instruction from memory address pointed by PC.

2. Decode the instruction to understand what to do.

3. Execute the operation (e.g., move value, add registers).

4. Update PC to point to the next instruction.

5. Repeat until a HLT (halt) instruction is encountered.

## 🚀 Goals

- [x] Create a basic CPU class with registers and memory
- [x] Implement basic instruction set: MOV, ADD, SUB, HLT
- [ ] Implement simple branching (JMP instruction)
- [ ] Load program binaries into memory from file
- [ ] Add simple output (UART print or LED toggle emulation)
- [ ] Implement FLAGS register (Zero, Carry flags)
- [ ] Add a basic assembler to convert text to binary
- [ ] Optimize execution (optional: instruction caching)

1. Create a simple CPU emulator with basic instructions.

2. Load binary programs into memory.

3. Add support for simple branching (JMP).

4. Add I/O peripherals (future).

5. Optimize execution speed (future).

<div align="center"> 📈 Architecture Overview

```
┌───────────────────────────────────────────────┐
│                    MEMORY                     │
│          (Array of Bytes: RAM)                 │
│  Address 0:  Instruction 1 (e.g., MOV A, 5)    │
│  Address 1:  Data (e.g., 5)                    │
│  Address 2:  Instruction 2 (e.g., MOV B, 10)   │
│  ...                                           │
└───────────────────────────────────────────────┘
            ▲
            │ (Program Counter PC points here)
            │
┌───────────────────────────────────────────────┐
│                PROGRAM COUNTER (PC)            │
│         ➔ Address of next instruction          │
└───────────────────────────────────────────────┘
            │
            ▼
┌───────────────────────────────────────────────┐
│            FETCH (read instruction)            │
│  1. Read memory[PC]                            │
│  2. Increment PC                               │
└───────────────────────────────────────────────┘
            │
            ▼
┌───────────────────────────────────────────────┐
│            DECODE (understand instruction)     │
│  Check opcode: 0x01, 0x02, 0x03, etc.           │
│  (e.g., is it MOV? ADD? JMP?)                   │
└───────────────────────────────────────────────┘
            │
            ▼
┌───────────────────────────────────────────────┐
│            EXECUTE (do the action)              │
│  Based on instruction:                         │
│    - Move data to register                     │
│    - Add two registers                         │
│    - Jump to a new memory address               │
│    - Stop if HLT                               │
└───────────────────────────────────────────────┘
            │
            ▼
┌───────────────────────────────────────────────┐
│                REGISTERS                      │
│     ┌─────────────┬─────────────┬────────────┐ │
│     │     A       │      B      │   FLAGS    │ │
│     │ 8 bits      │ 8 bits      │ 8 bits     │ │
│     └─────────────┴─────────────┴────────────┘ │
└───────────────────────────────────────────────┘

```


## 🌟 Contribution

Contributions are welcome!
Feel free to open Issues or Pull Requests.