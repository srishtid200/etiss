#define RVTEST_RV32U
#define TESTNUM x28

#define RVTEST_CODE_BEGIN		\
	.text;				\
	.global TEST_FUNC_NAME;		\
	.global TEST_FUNC_RET;		\
TEST_FUNC_NAME:				\
	lui	a0,%hi(.test_name);	\
	addi	a0,a0,%lo(.test_name);	\
	lui	a2,0x80000000>>12;	\
.prname_next:				\
	lb	a1,0(a0);		\
	beq	a1,zero,.prname_done;	\
	sb	a1,0(a2);		\
	addi	a0,a0,1;		\
	jal	zero,.prname_next;	\
.test_name:				\
	.ascii TEST_FUNC_TXT;		\
	.byte 0x00;			\
	.balign 4, 0;			\
.prname_done:				\
	addi	a1,zero,' ';		\
	sb	a1,0(a2);		\
	sb	a1,0(a2);       \
    jal	zero,.output;	\
.output:                      \
    lui a0, 0x80000000 >> 12; \
    addi a1, zero, 'D';       \
    addi a2, zero, 'O';       \
    addi a3, zero, 'N';       \
    addi a4, zero, 'E';       \
    addi a5, zero, '\n';      \
    sb a1, 0(a0);             \
    sb a2, 0(a0);             \
    sb a3, 0(a0);             \
    sb a4, 0(a0);             \
    sb a5, 0(a0);             \
    ebreak;
#define RVTEST_CODE_END
#define RVTEST_DATA_BEGIN .balign 4;
#define RVTEST_DATA_END
