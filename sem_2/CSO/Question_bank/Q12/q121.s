.global SpecialNumber
SpecialNumber:
    movq %rdi,%r11
    movq %r11,%rax
    movq $10,%rbx
    movq $0,%r13
    cmpq $0,%rdi
    je return1
    jmp loop
loop:
    cmpq $0,%rax
    je end
    xorq %rdx,%rdx
    idivq %rbx
    movq %rdx,%r8
    movq $1,%r12
    call ComputeFactorial
    addq %r12,%r13
    jmp loop
ComputeFactorial:
    cmpq $0,%r8
    je return
    imulq %r8,%r12
    dec %r8
    jmp ComputeFactorial
return:
    ret
end:
    movq %r13,%rax
    ret
return1:
    movq $1,%rax
    ret
