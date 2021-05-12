	.file	"main.c"
	.intel_syntax noprefix
# GNU C17 (Ubuntu 9.3.0-17ubuntu1~20.04) version 9.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.3.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu main.c -masm=intel
# -mtune=generic -march=x86-64 -fverbose-asm -fno-pie
# -fasynchronous-unwind-tables -fstack-protector-strong -Wformat
# -Wformat-security -fstack-clash-protection -fcf-protection
# options enabled:  -faggressive-loop-optimizations -fassume-phsa
# -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.globl	perms
	.type	perms, @function
perms:
.LFB6:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 32	#,
	mov	QWORD PTR [rbp-24], rdi	# addr, addr
# main.c:12:     int page_size = getpagesize();
	call	getpagesize	#
	mov	DWORD PTR [rbp-4], eax	# page_size, tmp90
# main.c:13:     addr -= (unsigned long)addr % page_size;
	mov	rax, QWORD PTR [rbp-24]	# addr.0_1, addr
# main.c:13:     addr -= (unsigned long)addr % page_size;
	mov	edx, DWORD PTR [rbp-4]	# tmp91, page_size
	movsx	rcx, edx	# _2, tmp91
	mov	edx, 0	# tmp92,
	div	rcx	# _2
	mov	rax, rdx	# _3, tmp92
# main.c:13:     addr -= (unsigned long)addr % page_size;
	neg	rax	# _4
	add	QWORD PTR [rbp-24], rax	# addr, _4
# main.c:15:     if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
	mov	eax, DWORD PTR [rbp-4]	# tmp94, page_size
	movsx	rcx, eax	# _5, tmp94
	mov	rax, QWORD PTR [rbp-24]	# tmp95, addr
	mov	edx, 7	#,
	mov	rsi, rcx	#, _5
	mov	rdi, rax	#, tmp95
	call	mprotect	#
# main.c:15:     if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
	cmp	eax, -1	# _6,
	jne	.L2	#,
# main.c:16:         return -1;
	mov	eax, -1	# _7,
	jmp	.L3	#
.L2:
# main.c:19:     return 0;
	mov	eax, 0	# _7,
.L3:
# main.c:20: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	perms, .-perms
	.section	.rodata
	.align 8
.LC0:
	.string	"My innocent flag checker can't run with such high security..."
	.text
	.globl	check_flag
	.type	check_flag, @function
check_flag:
.LFB7:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 48	#,
	mov	QWORD PTR [rbp-40], rdi	# flag, flag
# main.c:23: 	int len = strlen(flag);
	mov	rax, QWORD PTR [rbp-40]	# tmp119, flag
	mov	rdi, rax	#, tmp119
	call	strlen	#
# main.c:23: 	int len = strlen(flag);
	mov	DWORD PTR [rbp-20], eax	# len, _1
# main.c:24: 	if (len != 47)
	cmp	DWORD PTR [rbp-20], 47	# len,
	je	.L5	#,
# main.c:25: 		return 47;
	mov	eax, 47	# _36,
	jmp	.L6	#
.L5:
# main.c:26: 	long long *stuff = &&hello;
	mov	QWORD PTR [rbp-16], OFFSET FLAT:.L7	# stuff,
# main.c:27: 	long long *fl = flag;
	mov	rax, QWORD PTR [rbp-40]	# tmp120, flag
	mov	QWORD PTR [rbp-8], rax	# fl, tmp120
# main.c:28: 	if (perms((void*)stuff)) {
	mov	rax, QWORD PTR [rbp-16]	# tmp121, stuff
	mov	rdi, rax	#, tmp121
	call	perms	#
# main.c:28: 	if (perms((void*)stuff)) {
	test	eax, eax	# _2
	je	.L8	#,
# main.c:29: 		printf("My innocent flag checker can't run with such high security...\n");
	mov	edi, OFFSET FLAT:.LC0	#,
	call	puts	#
# main.c:30: 		return 1;
	mov	eax, 1	# _36,
	jmp	.L14	#
.L8:
	#init stuff
	mov	rax, QWORD PTR [rbp-16]	# stuff
	mov rbx, QWORD PTR [rbp-8] #flag
	#first
	mov rdx, QWORD PTR [rbx]
	xor QWORD PTR [rax], rdx
.L7:
	#second 
	mov rdx, QWORD PTR [rbx+8]
	xor QWORD PTR [rax+8], rdx
	#third 
	mov rdx, QWORD PTR [rbx+16]
	xor QWORD PTR [rax+16], rdx
	#fourth 
	mov rdx, QWORD PTR [rbx+24]
	xor QWORD PTR [rax+24], rdx
	#fifth 
	mov rdx, QWORD PTR [rbx+32]
	xor QWORD PTR [rax+32], rdx
	#sixth 
	mov rdx, QWORD PTR [rbx+40]
	xor QWORD PTR [rax+40], rdx
# main.c:39: 	return 0;
	mov	eax, 0	# _36,
.L6:
# main.c:40: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE7:
	.size	check_flag, .-check_flag
	.section	.rodata
.LC1:
	.string	"I need a flag to check!"
.LC2:
	.string	"Checking your flag..."
.LC3:
	.string	"Flag correct!"
	.align 8
.LC4:
	.string	"Did you even read the assembly?"
	.align 8
.LC5:
	.string	"How did you survive that with an incorrect flag???"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 32	#,
	mov	DWORD PTR [rbp-20], edi	# argc, argc
	mov	QWORD PTR [rbp-32], rsi	# argv, argv
# main.c:43: 	if (perms((void*)main)) {
	mov	edi, OFFSET FLAT:main	#,
	call	perms	#
# main.c:43: 	if (perms((void*)main)) {
	test	eax, eax	# _1
	je	.L10	#,
# main.c:44: 		printf("My innocent flag checker can't run with such high security...\n");
	mov	edi, OFFSET FLAT:.LC0	#,
	call	puts	#
# main.c:45: 		return 1;
	mov	eax, 1	# _4,
	jmp	.L11	#
.L10:
# main.c:47: 	if (argc < 2) {
	cmp	DWORD PTR [rbp-20], 1	# argc,
	jg	.L12	#,
# main.c:48: 		printf("I need a flag to check!\n");
	mov	edi, OFFSET FLAT:.LC1	#,
	call	puts	#
# main.c:49: 		return 1;
	mov	eax, 1	# _4,
	jmp	.L11	#
.L12:
# main.c:51: 	printf("Checking your flag...\n");
	mov	edi, OFFSET FLAT:.LC2	#,
	call	puts	#
# main.c:52: 	int t = check_flag(argv[1]);
	mov	rax, QWORD PTR [rbp-32]	# tmp87, argv
	add	rax, 8	# _2,
# main.c:52: 	int t = check_flag(argv[1]);
	mov	rax, QWORD PTR [rax]	# _3, *_2
	mov	rdi, rax	#, _3
	call	check_flag	#
	mov	DWORD PTR [rbp-4], eax	# t, tmp88
# main.c:53: 	if (!t)
	cmp	DWORD PTR [rbp-4], 0	# t,
	jne	.L13	#,
# main.c:54: 		printf("Flag correct!\n");
	mov	edi, OFFSET FLAT:.LC3	#,
	call	puts	#
	jmp	.L14	#
.L13:
# main.c:55: 	else if (t == 47)
	cmp	DWORD PTR [rbp-4], 47	# t,
	jne	.L15	#,
# main.c:56: 		printf("Did you even read the assembly?\n");
	mov	edi, OFFSET FLAT:.LC4	#,
	call	puts	#
	jmp	.L14	#
.L15:
# main.c:58: 		printf("How did you survive that with an incorrect flag???\n");
	mov	edi, OFFSET FLAT:.LC5	#,
	call	puts	#
.L14:
# main.c:59: 	return 0;
	mov	eax, 0	# _4,
.L11:
# main.c:60: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
