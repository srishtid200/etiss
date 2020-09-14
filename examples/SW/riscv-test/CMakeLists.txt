cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
SET(CMAKE_TOOLCHAIN_FILE
    "cmake/pulpino_tumeda/toolchain.cmake"
)
project(etiss_examples)
enable_language(C ASM)
include(cmake/PulpinoTarget.cmake)
#Copy all TVMs into build/ to prepare for configuration
file(COPY ./cmake/isa DESTINATION ../build 
    NO_SOURCE_PERMISSIONS
    )

### Create multiple Test Virtual Machines for test.
option(TEST_RV32UI "test rv32ui TVM" OFF) #OFF by default
if(TEST_RV32UI)
    SET(SUPPORT_FILE "cmake/support_file/rv32ui_um")
    SET(INSTR_FILE "cmake/isa/rv32ui")
    SET(TEST_FILE "./build/isa/rv32ui")
    SET(TEST_FILE2 "../build/isa/rv64ui")                                       #TEST_FILE2 is needed because rv32ui includes content of rv64ui
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Copy riscv_test.h into ${TEST_FILE2} in build/        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})          #Copy test_macros.h into ${TEST_FILE2} in build/
endif(TEST_RV32UI)
unset(TEST_RV32UI CACHE)

option(TEST_RV32UM "test rv32um TVM" OFF) #OFF by default
if(TEST_RV32UM)
    SET(SUPPORT_FILE "cmake/support_file/rv32ui_um")
    SET(INSTR_FILE "cmake/isa/rv32um")
    SET(TEST_FILE "./build/isa/rv32um")
    SET(TEST_FILE2 "../build/isa/rv64um")                                       #TEST_FILE2 is needed because rv32um includes content of rv64um    
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Copy riscv_test.h into ${TEST_FILE2} in build/        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})          #Copy test_macros.h into ${TEST_FILE2} in build/
endif(TEST_RV32UM)
unset(TEST_RV32UM CACHE)

option(TEST_RV32UC "test rv32uc TVM" OFF) #OFF by default 
if(TEST_RV32UC)
    SET(SUPPORT_FILE "cmake/support_file/rv32uc")
    SET(INSTR_FILE "cmake/isa/rv32uc")
    SET(TEST_FILE "./build/isa/rv32uc")
    SET(TEST_FILE2 "../build/isa/rv64uc")                                       #TEST_FILE2 is needed because rv32uc includes content of rv64uc
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})           #Copy riscv_test.h into ${TEST_FILE2} in build/        
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})          #Copy test_macros.h into ${TEST_FILE2} in build/

endif(TEST_RV32UC)
unset(TEST_RV32UC CACHE)

option(TEST_RV32UD "test rv32ud TVM" OFF) #OFF by default
if(TEST_RV32UD)
    SET(SUPPORT_FILE "cmake/support_file/rv32ud")
    SET(INSTR_FILE "cmake/isa/rv32ud")
    SET(TEST_FILE "./build/isa/rv32ud")
    SET(TEST_FILE2 "../build/isa/rv64ud")                                        #TEST_FILE2 is needed because rv32ud includes content of rv64ud
    SET(TEST_FILE3 "../build/isa/rv64uf")                                        #TEST_FILE3 is needed because rv32ud includes content of rv64uf
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})            #Copy riscv_test.h into ${TEST_FILE2} in build/       
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})           #Copy test_macros.h into ${TEST_FILE2} in build/
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE3})            #Copy riscv_test.h into ${TEST_FILE3} in build/   
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE3})           #Copy test_macros.h into ${TEST_FILE3} in build/
endif(TEST_RV32UD)
unset(TEST_RV32UD CACHE)

option(TEST_RV32UA "test rv32ua TVM" OFF) #OFF by default
if(TEST_RV32UA)
    SET(SUPPORT_FILE "cmake/support_file/rv32ua")
    SET(INSTR_FILE "cmake/isa/rv32ua")
    SET(TEST_FILE "./build/isa/rv32ua")
    SET(TEST_FILE2 "../build/isa/rv64ua")                                        #TEST_FILE2 is needed because rv32ua includes content of rv64ua
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})            #Copy riscv_test.h into ${TEST_FILE2} in build/
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})           #Copy test_macros.h into ${TEST_FILE2} in build/
endif(TEST_RV32UA)
unset(TEST_RV32UA CACHE)

option(TEST_RV32SI "test rv32si TVM" OFF) #OFF by default
if(TEST_RV32SI)
    SET(SUPPORT_FILE "cmake/support_file/rv32si")
    SET(INSTR_FILE "cmake/isa/rv32si")
    SET(TEST_FILE "./build/isa/rv32si")
    SET(TEST_FILE2 "../build/isa/rv64si")                                        #TEST_FILE2 is needed because rv32si includes content of rv64si
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})            #Copy riscv_test.h into ${TEST_FILE2} in build/
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})           #Copy test_macros.h into ${TEST_FILE2} in build/
endif(TEST_RV32SI)
unset(TEST_RV32SI CACHE)

option(TEST_RV32MI "test rv32mi TVM" OFF) #OFF by default
if(TEST_RV32MI)
    SET(SUPPORT_FILE "cmake/support_file/rv32mi")
    SET(INSTR_FILE "cmake/isa/rv32mi")
    SET(TEST_FILE "./build/isa/rv32mi")
    SET(TEST_FILE2 "../build/isa/rv64mi")                                        #TEST_FILE2 is needed because rv32mi includes content of rv64mi
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})            #Copy riscv_test.h into ${TEST_FILE2} in build/    
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})           #Copy test_macros.h into ${TEST_FILE2} in build/
endif(TEST_RV32MI)
unset(TEST_RV32MI CACHE)

option(TEST_RV32UF "test rv32uf TVM" OFF) #OFF by default
if(TEST_RV32UF)
    SET(SUPPORT_FILE "cmake/support_file/rv32uf")
    SET(INSTR_FILE "cmake/isa/rv32uf")
    SET(TEST_FILE "./build/isa/rv32uf")
    SET(TEST_FILE2 "../build/isa/rv64uf")                                        #TEST_FILE2 is needed because rv32uf includes content of rv64uf
    file(COPY ${SUPPORT_FILE}/riscv_test.h DESTINATION ${TEST_FILE2})            #Copy riscv_test.h into ${TEST_FILE2} in build/
    file(COPY ${SUPPORT_FILE}/test_macros.h DESTINATION ${TEST_FILE2})           #Copy test_macros.h into ${TEST_FILE2} in build/
endif(TEST_RV32UF)
unset(TEST_RV32UF CACHE)

option(TEST_RV64UI "test rv64ui TVM" OFF) #OFF by default
if(TEST_RV64UI)
    SET(SUPPORT_FILE "cmake/support_file/rv64ui_um")
    SET(INSTR_FILE "cmake/isa/rv64ui")
    SET(TEST_FILE "./build/isa/rv64ui")
endif(TEST_RV64UI)
unset(TEST_RV64UI CACHE)

option(TEST_RV64UM "test rv64um TVM" OFF) #OFF by default
if(TEST_RV64UM)
    SET(SUPPORT_FILE "cmake/support_file/rv64ui_um")
    SET(INSTR_FILE "cmake/isa/rv64um")
    SET(TEST_FILE "./build/isa/rv64um")
endif(TEST_RV64UM)
unset(TEST_RV64UM CACHE)


### Configure instructiontests to test all instructiontests automatically 
#Generate a list of instructiontest_files to configure later
file(GLOB source_list 
    "${INSTR_FILE}/*.S"
   
)
get_filename_component(file_name "${source_list}" NAME)           #Get list name+dir of test_files
set(index 0)
FOREACH(source ${source_list})
    get_filename_component(file_name "${source}" NAME_WE)         #Add just name_files to a list  
    list(APPEND list_name ${file_name})
ENDFOREACH()
list(LENGTH list_name len_list)    
math(EXPR next_to_last "${len_list} - 2")
#If there is only one instructiontest_file
if(${len_list} EQUAL 1)
    list(GET list_name ${index} file_name)
    file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)                                           #Copy old_file
    file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")                              #Write into new_file some new lines
    file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME Test1\n")
    file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"Test1\"\n")
    file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET ebreak\n")
    file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
    file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")                                     #Copy old_file into new_file
#If there are more than one instructiontest_file
else() 
    FOREACH(_name ${list_name})   
        #Handle the first instructiontest_file in the list    
        if(index EQUAL 0) 
            list(GET list_name ${index} file_name)                                                  #get a element with index n of the list
            math(EXPR index "${index} + 1")
            math(EXPR index_next "${index} + 1")
            list(GET list_name ${index} file_name_next)                                             #get a element with index n+1 of the list  
            file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)                                   #Copy old_file
            #Write into new_file some new lines
            file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")                      
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME Test1\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"Test1\"\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET T${index_next}_${file_name_next}\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")                             #Append old_file into new_file
        #Handle other instructiontest_files in the list    
        elseif(index LESS_EQUAL ${next_to_last}) 
            list(GET list_name ${index} file_name)                                                  #get a element with index n of the list
            math(EXPR index "${index} + 1")  
            math(EXPR index_next "${index} + 1")
            list(GET list_name ${index} file_name_next)                                             #get a element with index n+1 of the list
            file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)                                   #Copy old_file
            #Write into new_file with some new lines
            file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")                      
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME T${index}_${file_name}\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"T${index}_${file_name}\"\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET T${index_next}_${file_name_next}\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")                             #Append old_file into new_file
        #Handle the last instructiontest_file in the list
        elseif(index GREATER ${next_to_last})                                                       
            list(GET list_name ${index} file_name)
            math(EXPR index "${index} + 1")
            file(READ ${INSTR_FILE}/${file_name}.S contentOfFile)                                   #Copy old_file
            #Write into new_file with some new lines
            file(WRITE ${TEST_FILE}/${file_name}.S "#ifndef TEST_FUNC_NAME\n")                      
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_NAME T${index}_${file_name}\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_TXT \"T${index}_${file_name}\"\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#define TEST_FUNC_RET ebreak\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "#endif\n")
            file(APPEND ${TEST_FILE}/${file_name}.S "${contentOfFile}")                             #Append old_file into new_file
        endif()    
    ENDFOREACH()
endif()


file(READ ${SUPPORT_FILE}/riscv_test.h contentOfFile)                     #Copy riscv_test.h into ${TEST_FILE} in build/
file(WRITE ${TEST_FILE}/riscv_test.h "${contentOfFile}")        
file(READ ${SUPPORT_FILE}/test_macros.h contentOfFile)                    #Copy test_macros.h into ${TEST_FILE} in build/
file(WRITE ${TEST_FILE}/test_macros.h "${contentOfFile}")
file(READ ${SUPPORT_FILE}/ebreak.S contentOfFile)                         #Copy ebreak.S into ${TEST_FILE} in build/
file(WRITE ${TEST_FILE}/ebreak.S "${contentOfFile}")
file(READ ${SUPPORT_FILE}/ebreak.h contentOfFile)                         #Copy ebreak.h into ${TEST_FILE} in build/
file(WRITE ${TEST_FILE}/ebreak.h "${contentOfFile}")

#Generate a list of instructiontest_files in build/
file(GLOB instructiontest_files             
    "${TEST_FILE}/*.S"
   
)

set_source_files_properties(${instructiontest_files} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")          
ADD_DEFINITIONS(-DPULPINO_NO_GPIO)
ADD_EXECUTABLE_PULPINO(riscv_example main.c ${instructiontest_files})
