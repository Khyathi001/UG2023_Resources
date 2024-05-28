.global GCD
GCD:
    movq %rdi,%r10          # a
    movq %rsi,%r11          # b
    jmp loop
loop:
    cmpq $0,%r10
    je aIsZero
    cmpq $0,%r11
    je bIsZero
    cmpq %r10,%r11
    je equal
    jg bGa
    jl aGb
bGa:
    subq %r10,%r11
    jmp loop
aGb:
    subq %r11,%r10
    jmp loop
equal:
    movq %r10,%rax
    ret
aIsZero:
    movq %r11,%rax
    ret
bIsZero:
    movq %r10,%rax
    ret
    