.global Palindrome
Palindrome:
    movq %rdi,%r11
    movq $0,%r12
    movq %r11,%rax
    movq $10,%rbx
    jmp loop
loop:
    cmpq $0,%rax
    je return
    imulq $10,%r12
    xorq %rdx,%rdx
    idivq %rbx
    addq %rdx,%r12
    jmp loop
return:
    cmpq %r11,%r12
    je give1
    movq $-1,%rax
    ret
give1:
    movq $1,%rax
    ret
    