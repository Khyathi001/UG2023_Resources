.global lineDirection
lineDirection:
    movq $0,%r12        # sum
    movq $0,%r8         # iterator
    # mx = r14,cur = r15, p = r8 n - p - 1 = r13
    jmp loop
loop:
    cmpq %r8,%rdi
    je end
    call ElementIsZero
    movq %rdi,%r13
    dec %r13
    subq %r8,%r13
    call ElementIsNotZero
    call pGn
    call pLn
    addq %r15,%r12
    subq %r15,%r14
    movq %r14,(%rdx,%r8,8)
    inc %r8
    jmp loop
ElementIsZero:
    cmpq $0,(%rsi,%r8,8)
    jne return
    movq %r8,%r15
    ret
ElementIsNotZero:
    cmpq $0,(%rsi,%r8,8)
    je return
    movq %r13,%r15
    ret
pGn:
    cmpq %r13,%r8
    jle return
    movq %r8,%r14
    ret
pLn:
    cmpq %r13,%r8
    jg return
    movq %r13,%r14
    ret
return:
    ret
end:
    movq $0,%r8
    jmp loop1
loop1:
    cmpq %r8,%rdi
    jle end1
    movq $0,%r9
    movq %rdi,%r13
    subq %r8,%r13
    dec %r13
    jmp innerLoop
innerLoop:
    cmpq %r9,%r13
    jle incr8
    movq (%rdx,%r9,8),%r14
    movq %r9,%r10
    inc %r10
    movq (%rdx,%r10,8),%r15
    cmpq %r15,%r14
    jl swap
    inc %r9
    jmp innerLoop
swap:
    movq %r15,(%rdx,%r9,8)
    movq %r14,(%rdx,%r10,8)
    inc %r9
    jmp innerLoop
incr8:
    inc %r8
    jmp loop1
end1:
    movq $0,%r8
    jmp Final
Final:
    cmpq %r8,%rdi
    je endFinal
    addq (%rdx,%r8,8),%r12
    movq %r12,(%rcx,%r8,8)
    inc %r8
    jmp Final
endFinal:
    movq %rcx,%rax
    ret
