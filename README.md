# QueryShadowStack
Query ShadowStack

https://stackoverflow.com/questions/56905811/what-does-the-endbr64-instruction-actually-do

https://www.spinics.net/lists/kvm/msg208593.html

https://stackoverflow.com/questions/62436160/is-it-possible-to-temporarily-suppress-intel-cet-for-a-single-ret-instruction-o

https://github.com/gwsystems/wasmception-clang/blob/e47f248a73cff7bea95f356eacaf60aa3a48c0f9/test/CodeGen/cetintrin.c


```
mov eax, 7
mov ecx, 0
cpuid
test ebx, ebx
jz not_supported

```
