.global SpecialNumber
SpecialNumber:
    movq $10,%rbx
    movq %rdi,%rax
    movq %rdx,%r14
    movq %rdx,%r9
    dec %r9
    movq %rdx,%r11
    jmp loop
loop:
    cmpq $-1,%r9
    je end
    xorq %rdx,%rdx
    idivq %rbx
    movq %rdx,(%rsi,%r9,8)
    dec %r9
    jmp loop
end:
    movq $0,%r9
    movq $0,%r13
    jmp ComputeFactorial
ComputeFactorial:
    cmpq %r14,%r9
    je Yayyy
    movq $1,%r10
    movq (%rsi,%r9,8),%r8
    cmpq $0,%r8
    je Add1
    call Factorial
    addq %r10, %r13
    inc %r9
    jmp ComputeFactorial
Factorial:
    cmpq $0,%r8
    je return
    imulq %r8,%r10
    dec %r8
    jmp Factorial
return:
    ret
Yayyy:
    movq %r13,%rax
    ret
Add1:
    inc %r13
    inc %r9
    jmp ComputeFactorial
