.global Operations
Operations:
    movq $1,%rax
    cmpq $1,%rdx
    je add
    cmpq $2,%rdx
    je sub
    cmpq $3,%rdx
    je div
    cmpq $4,%rdx
    je exp
    cmpq $5,%rdx
    je mod
add:
    addq %rdi,%rsi
    movq %rsi,%rax
    ret
sub:
    subq %rsi,%rdi
    movq %rdi,%rax
    ret
div:
    xorq %rdx,%rdx
    movq %rsi,%rbx
    movq %rdi,%rax
    idivq %rbx
    ret
exp:
    cmpq $0,%rsi
    je return
    imulq %rdi,%rax
    dec %rsi
    jmp exp
return:
    ret
mod:
    xorq %rdx,%rdx
    movq %rsi,%rbx
    movq %rdi,%rax
    idivq %rbx
    movq %rdx,%rax
    ret
