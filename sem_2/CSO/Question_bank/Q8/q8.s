.global sortLikeWave
sortLikeWave:
    movq $0,%r8         # i
    movq %rsi,%r13      # r13 -> n
    jmp loop
loop:   
    cmpq %r8,%rsi
    jle end
    movq $0,%r9
    movq %r13,%r12
    subq %r8,%r12
    dec %r12
    jmp innerLoop
innerLoop:
    cmpq %r9,%r12
    jle buff
    movq (%rdi,%r9,8),%r14          # arr[j]
    movq %r9,%r10
    inc %r10
    movq (%rdi,%r10,8),%r15         # arr[j+1]
    cmpq %r14,%r15
    jl swap
    inc %r9
    jmp innerLoop
swap:
    movq %r14,(%rdi,%r10,8)
    movq %r15,(%rdi,%r9,8)
    inc %r9
    jmp innerLoop
buff:
    inc %r8
    jmp loop
end:
    movq $0,%r8
    movq $0,%r9
    jmp wave
wave:
    cmpq %r8,%rsi
    jle return
    movq %r8,%r9
    inc %r9
    cmpq %r9,%rsi
    jle return
    movq (%rdi,%r8,8),%r10
    movq (%rdi,%r9,8),%r11
    movq %r11,(%rdi,%r8,8)
    movq %r10,(%rdi,%r9,8)
    addq $2,%r8
    jmp wave
return:
    movq %rdi,%rax
    ret
