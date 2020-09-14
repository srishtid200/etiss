#ifndef TEST_FUNC_NAME
#  define TEST_FUNC_NAME ebreak
#  define TEST_FUNC_TXT "ebreak"
#  define TEST_FUNC_RET exit
#endif

#include "ebreak.h"
#include "test_macros.h"

RVTEST_RV64U
RVTEST_CODE_BEGIN
  
RVTEST_CODE_END

  .data
RVTEST_DATA_BEGIN

  TEST_DATA

RVTEST_DATA_END
