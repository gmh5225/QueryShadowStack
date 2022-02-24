#include <Windows.h>
#include <stdio.h>

using pfnNtQueryInformationProcess = NTSTATUS(NTAPI *)(
    HANDLE ProcessHandle, /*PROCESSINFOCLASS*/ ULONG ProcessInformationClass,
    PVOID ProcessInformation, ULONG ProcessInformationLength,
    PULONG ReturnLength);

int QueryProcessUserShadowStack(HANDLE hProcess) {
  int ret = 0;

  do {
    auto ntdll = GetModuleHandleA("ntdll.dll");
    if (!ntdll) {
      printf("ntdll null\n");
      ret = -1;
      break;
    }

    auto pNtQueryInformationProcess =
        (pfnNtQueryInformationProcess)GetProcAddress(
            ntdll, "NtQueryInformationProcess");
    if (!pNtQueryInformationProcess) {
      printf("NtQueryInformationProcess null\n");
      ret = -2;
      break;
    }

    PROCESS_MITIGATION_USER_SHADOW_STACK_POLICY pmussp = {0};
    ULONG uReturnLength = 0;
    auto ns =
        pNtQueryInformationProcess(hProcess, ProcessUserShadowStackPolicy,
                                   &pmussp, sizeof(pmussp), &uReturnLength);
    if (ns < 0) {
      printf("not support\n");
      ret = -3;
      break;
    }

    if (pmussp.EnableUserShadowStack) {
      printf("EnableUserShadowStack\n");
      ret = 1;
    } else {
      printf("not EnableUserShadowStack\n");
      ret = 2;
    }

  } while (0);

  return ret;
}

int main() {
  int ret = QueryProcessUserShadowStack(GetCurrentProcess());
  printf("ret=%d\n", ret);
  system("pause");
  return 0;
}
