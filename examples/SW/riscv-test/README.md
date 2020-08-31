# RISC-V Software Compilation

This file contains ctr0, linker script, Makefile (originally from plupino
project) for simple RISC-V software compilation

## Build
### Prerequisites
In order to compile riscv software, the following requirements has to be
met:

  - A RISC-V toolchain is required for cross-compiling (https://www.sifive.com/boards (scroll down to toolchain downloads)).

### RISC-V test cases

Binary code and elf file will be located at `build/`. Minimal
dependent source code in `cmake/` is linked against final executable,
such as default interrupt handlers and exception handlers.
Test cases such as rv32ui and rv32um are stored in `cmake/isa/`(that work for now). 

To compile the SW:

	$ mkdir build && cd build
  ## For RV32UI
  $ cmake -DTEST_RV32UI=ON-DRISCV_ELF_GCC_PREFIX=path/to/toolchain -DRISCV_ELF_GCC_BASENAME=riscv64-unknown-elf ..
  ## For RV32UM
  $ cmake -DTEST_RV32UM=ON-DRISCV_ELF_GCC_PREFIX=path/to/toolchain -DRISCV_ELF_GCC_BASENAME=riscv64-unknown-elf ..
	$ make

# Building on Windows

Get a RISC-V toolchain. Recommended: https://www.sifive.com/boards (scroll down to toolchain downloads)

Get GNU Make for Windows: http://gnuwin32.sourceforge.net/packages/make.htm

    mkdir build
    cd build
    cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=X:\path\to\gmake\bin\make.exe ..
    cmake --build .