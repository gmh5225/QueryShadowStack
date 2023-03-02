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

```C++
#include <windows.h>

BOOL is_cet_supported() {
  OSVERSIONINFOEXW osvi = { sizeof(osvi), 0, 0, 0, 0, {0}, 0, 0 };
  DWORDLONG mask = 0;
  VER_SET_CONDITION(mask, VER_MAJORVERSION, VER_GREATER_EQUAL);
  VER_SET_CONDITION(mask, VER_MINORVERSION, VER_GREATER_EQUAL);
  VER_SET_CONDITION(mask, VER_BUILDNUMBER, VER_GREATER_EQUAL);
  VER_SET_CONDITION(mask, VER_PLATFORMID, VER_EQUAL);
  osvi.dwMajorVersion = 10;
  osvi.dwMinorVersion = 0;
  osvi.dwBuildNumber = 17763;
  osvi.dwPlatformId = VER_PLATFORM_WIN32_NT;
  return VerifyVersionInfoW(&osvi, VER_MAJORVERSION | VER_MINORVERSION | VER_BUILDNUMBER | VER_PLATFORMID, mask);
}

```
