.global NoOfOnes
NoOfOnes:
    movq %rdi,%rax
    movq $0,%r10
    movq $2,%rbx
    jmp loop
loop:
    cmpq $0,%rax
    je end
    xorq %rdx,%rdx
    idivq %rbx
    cmpq $1,%rdx
    je incrementCount
    jmp loop
incrementCount:
    inc %r10
    jmp loop
end:
    movq %r10,%rax
    ret
