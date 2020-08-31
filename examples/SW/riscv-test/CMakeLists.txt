cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
SET(CMAKE_TOOLCHAIN_FILE
    "cmake/pulpino_tumeda/toolchain.cmake"
)
project(etiss_examples)
enable_language(C ASM)
include(cmake/PulpinoTarget.cmake)

file(COPY ./cmake/isa DESTINATION ../build 
    NO_SOURCE_PERMISSIONS
    )

option(TEST_RV32UI "test rv32ui version" OFF) #OFF by default
if(TEST_RV32UI)
    SET(SUPPORT_FILE "cmake/support_file/rv32ui_um")
    SET(INSTR_FILE "cmake/isa/rv32ui")
    SET(TEST_FILE "./build/isa/rv32ui")
    SET(TEST_FILE2 "../build/isa/rv64ui")
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Handle riscv_test.h        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})
endif(TEST_RV32UI)
unset(TEST_RV32UI CACHE)

option(TEST_RV32UM "test rv32um version" OFF) #OFF by default
if(TEST_RV32UM)
    SET(SUPPORT_FILE "cmake/support_file/rv32ui_um")
    SET(INSTR_FILE "cmake/isa/rv32um")
    SET(TEST_FILE "./build/isa/rv32um")
    SET(TEST_FILE2 "../build/isa/rv64um")
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Handle riscv_test.h        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})
endif(TEST_RV32UM)
unset(TEST_RV32UM CACHE)

option(TEST_RV32UC "test rv32uc version" OFF) #OFF by default 
#doesn't work: illegal operands `li t0,SSTATUS_SPP'
if(TEST_RV32SI)
    SET(SUPPORT_FILE "cmake/support_file/rv32si")
    SET(INSTR_FILE "cmake/isa/rv32si")
    SET(TEST_FILE "./build/isa/rv32si")
    SET(TEST_FILE2 "../build/isa/rv64si")
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Handle riscv_test.h        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})

endif(TEST_RV32SI)
unset(TEST_RV32SI CACHE)

option(TEST_RV32UD "test rv32ud version" OFF) #OFF by default
#doesn't work: unrecognized opcode `fld f0,0(a0)'
if(TEST_RV32UD)
    SET(SUPPORT_FILE "cmake/support_file/rv32ud")
    SET(INSTR_FILE "cmake/isa/rv32ud")
    SET(TEST_FILE "./build/isa/rv32ud")
    SET(TEST_FILE2 "../build/isa/rv64ud")
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Handle riscv_test.h        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})
endif(TEST_RV32UD)
unset(TEST_RV32UD CACHE)

option(TEST_RV64UI "test rv64ui version" OFF) #OFF by default
#doesn't work: unrecognized opcode `addiw x14,x1,((0x000)|(-(((0x000)>>11)&1)<<11))'
if(TEST_RV64UI)
    SET(SUPPORT_FILE "cmake/support_file/rv64ui")
    SET(INSTR_FILE "cmake/isa/rv64ui_um")
    SET(TEST_FILE "./build/isa/rv64ui")
endif(TEST_RV64UI)
unset(TEST_RV64UI CACHE)

option(TEST_RV64UM "test rv64um version" OFF) #OFF by default
#doesn't work: unrecognized opcode `divuw x14,x1,x2'
if(TEST_RV64UM)
    SET(SUPPORT_FILE "cmake/support_file/rv64ui_um")
    SET(INSTR_FILE "cmake/isa/rv64um")
    SET(TEST_FILE "./build/isa/rv64um")
endif(TEST_RV64UM)
unset(TEST_RV64UM CACHE)

file(GLOB source_list 
    "${INSTR_FILE}/*.S"
   
)
get_filename_component(file_name "${source_list}" NAME)           #get list name+dir of test_files
set(index 0)
FOREACH(source ${source_list})
    get_filename_component(file_name "${source}" NAME_WE)         #add just name_files to a list  
    list(APPEND list_name ${file_name})
ENDFOREACH()
list(LENGTH list_name len_list)    
math(EXPR next_to_last "${len_list} - 2")
FOREACH(_name ${list_name})       
    if(index EQUAL 0) 
        list(GET list_name ${index} file_name)                    #get a element with index n of the list
        math(EXPR index "${index} + 1")  
        math(EXPR index_next "${index} + 1")
        list(GET list_name ${index} file_name_next)               #get a element with index n+1 of the list
        file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)                                     #copy old file
        file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")                              #Write new file with some new lines
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME Test1\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"Test1\"\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET T${index_next}_${file_name_next}\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")                                     #copy old file into new file
        set_source_files_properties(${TEST_FILE}/${file_name}.S PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")                                #Handle each test_file 
    elseif(index LESS_EQUAL ${next_to_last}) 
        list(GET list_name ${index} file_name)                    #get a element with index n of the list
        math(EXPR index "${index} + 1")  
        math(EXPR index_next "${index} + 1")
        list(GET list_name ${index} file_name_next)               #get a element with index n+1 of the list
        file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)                                     #copy old file
        file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")                              #Write new file with some new lines
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME T${index}_${file_name}\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"T${index}_${file_name}\"\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET T${index_next}_${file_name_next}\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")                                     #copy old file into new file
        set_source_files_properties(${TEST_FILE}/${file_name}.S PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")
    elseif(index GREATER ${next_to_last})                                         #Handle the last element in the list
        list(GET list_name ${index} file_name)
        math(EXPR index "${index} + 1")
        file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)
        file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME T${index}_${file_name}\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"T${index}_${file_name}\"\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET ebreak\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
        file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")
        set_source_files_properties(${TEST_FILE}/${file_name}.S PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")
    endif()    

ENDFOREACH()
file(GLOB test_list_SRC             
    "${TEST_FILE}/*.S"
   
)
file(READ ${SUPPORT_FILE}/riscv_test.h contentOfFile)                     #Handle riscv_test.h
file(WRITE ${TEST_FILE}/riscv_test.h "${contentOfFile}")        
file(READ ${SUPPORT_FILE}/test_macros.h contentOfFile)          #Handle test_macros.h
file(WRITE ${TEST_FILE}/test_macros.h "${contentOfFile}")
file(READ ${SUPPORT_FILE}/ebreak.S contentOfFile)                         #Handle ebreak.S to break program
file(WRITE ${TEST_FILE}/ebreak.S "${contentOfFile}")
file(READ ${SUPPORT_FILE}/ebreak.h contentOfFile)                         #Handle ebreak.h
file(WRITE ${TEST_FILE}/ebreak.h "${contentOfFile}")
set_source_files_properties(${TEST_FILE}/ebreak.S PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")


ADD_DEFINITIONS(-DPULPINO_NO_GPIO)
ADD_EXECUTABLE_PULPINO(riscv_example main.c ${TEST_FILE}/ebreak.S ${test_list_SRC})
