.global SortBinary
SortBinary:
    movq $0,%r8             # to maintain count of 0s
    movq $0,%r9             # to maintain count of 1s
    movq $0,%r10            # index
    jmp loop
loop:
    cmpq %r10,%rsi
    je another
    cmpq $1,(%rdi,%r10,8)
    je incOne
    cmpq $0,(%rdi,%r10,8)
    je incZero
incOne:
    inc %r10
    inc %r9
    jmp loop
incZero:
    inc %r10
    inc %r8
    jmp loop
another:
    movq $0,%r10
    jmp fillZeroes
fillZeroes:
    cmpq %r8,%r10
    je another1
    movq $0,(%rdi,%r10,8)
    inc %r10
    jmp fillZeroes
another1:
    movq $0,%r11
    jmp fillOnes
fillOnes:
    cmpq %r9,%r11
    je end
    movq $1,(%rdi,%r10,8)
    inc %r10
    inc %r11
    jmp fillOnes
end:
    movq %rdi,%rax
    ret

