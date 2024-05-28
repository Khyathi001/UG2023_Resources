.global swap
swap:
    movq $0,%r8
    movq %rsi,%r13
    movq $2,%rbx
    movq $0,%r9
    movq $0,%r10
    jmp CountOddsEvens
CountOddsEvens:
    cmpq %r8,%rsi
    jle Check 
    xorq %rdx,%rdx
    movq (%rdi,%r8,8),%rax
    idivq %rbx
    cmpq $0,%rdx
    je itsEven
    inc %r9
    inc %r8
    jmp CountOddsEvens
itsEven:
    inc %r10
    inc %r8
    jmp CountOddsEvens
Check:
    cmpq $0,%r9
    jne checkForEven
    jmp return
checkForEven:
    cmpq $0,%r10
    jne GoForSorting
    jmp return
GoForSorting:
    movq $0,%r8
    movq %rsi,%r13
    jmp loop
loop:
    cmpq %r8,%rsi
    jle return
    movq $0,%r9
    movq %r13,%r12
    subq %r8,%r12
    dec %r12
    jmp innerLoop
innerLoop:
    cmpq %r9,%r12
    jle buff
    movq (%rdi,%r9,8),%r14
    movq %r9,%r10
    inc %r10
    movq (%rdi,%r10,8),%r15
    cmpq %r15,%r14
    jg swap_
    inc %r9
    jmp innerLoop
swap_:
    movq %r15,(%rdi,%r9,8)
    movq %r14,(%rdi,%r10,8)
    inc %r9
    jmp innerLoop
buff:
    inc %r8
    jmp loop
return:
    movq %rdi,%rax
    ret
    