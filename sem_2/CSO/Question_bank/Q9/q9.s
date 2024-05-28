.global First
First:
    movq $0,%r8
    movq %rsi,%r13
    movq %rsi,%r11
    inc %r11
    jmp loop
loop:
    cmpq %r8,%r13
    je end
    cmpq $0,(%rdi,%r8,8)
    jg positive
    movq $0,(%rdi,%r8,8)
    inc %r8
    jmp loop
positive:
    cmpq %r11,(%rdi,%r8,8)
    jl lessThanN
    movq $0,(%rdi,%r8,8)
    inc %r8
    jmp loop
lessThanN:
    movq (%rdi,%r8,8),%r12
    movq $1,(%rdx,%r12,8)
    inc %r8
    jmp loop
end:
    movq $1,%r8
    jmp checkForZero
checkForZero:
    cmpq %r8,%r11
    je over
    cmpq $0,(%rdx,%r8,8)
    je firstZero
    inc %r8
    jmp checkForZero
firstZero:
    movq %r8,%rax
    ret
over:
    movq %r11,%rax
    ret
