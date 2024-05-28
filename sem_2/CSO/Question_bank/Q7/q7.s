.global MaxB
MaxB:
    movq $0,%r8
    movq %rcx,%r12 # r12 -> ans
    jmp loop
loop:
    cmpq %r8,%rdx
    jl end
    movq %rdx,%r14
    subq %r8,%r14
    movq $0,%rax
    movq $0,%r9
    call sumFromFront
    movq %rax,%rbx
    movq $0,%rax
    movq %rsi,%r9
    dec %r9
    movq %r8,%r14
    call sumFromBack
    addq %rax,%rbx
    cmpq %r12,%rbx
    jg updateMax
    inc %r8
    jmp loop
sumFromFront:
    cmpq $0,%r14
    je return
    addq (%rdi,%r9,8),%rax
    inc %r9
    dec %r14
    jmp sumFromFront
sumFromBack:
    cmpq $0,%r14
    je return
    addq (%rdi,%r9,8),%rax
    dec %r9
    dec %r14
    jmp sumFromBack
return:
    ret
updateMax:
    movq %rbx,%r12
    inc %r8
    jmp loop
end:
    movq %r12,%rax
    ret
