.global ModifyArray
ModifyArray:
    movq $0,%r10
    movq $1,%r12
    movq %rdi,%r11
    movq $15,%r9
    movq $5,%r8
    movq $3,%r13
    jmp loop
loop:
    cmpq %r12,%rdi
    jl end
    xorq %rdx,%rdx
    movq %r12,%rax
    idivq %r9
    cmpq $0,%rdx
    je divisibleBy15
    # ------------- #
    xorq %rdx,%rdx
    movq %r12,%rax
    idivq %r13
    cmpq $0,%rdx
    je divisibleBy3
    # ------------- #
    xorq %rdx,%rdx
    movq %r12,%rax
    idivq %r8
    cmpq $0,%rdx
    je divisibleBy5
    movq %r12,(%rsi,%r10,8)
    inc %r10
    inc %r12
    jmp loop
divisibleBy15:
    movq $-3,(%rsi,%r10,8)
    inc %r10
    inc %r12
    jmp loop
divisibleBy5:
    movq $-2,(%rsi,%r10,8)
    inc %r10
    inc %r12
    jmp loop
divisibleBy3:
    movq $-1,(%rsi,%r10,8)
    inc %r10
    inc %r12
    jmp loop
end:
    movq %rsi,%rax
    ret
