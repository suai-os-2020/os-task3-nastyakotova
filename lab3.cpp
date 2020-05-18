#include "lab3.h"
#include "windows.h"
//
// lab3 code should be located here!
//


unsigned int lab3_thread_graph_id() {
    return 7;
}

const char *lab3_unsynchronized_threads() {
    return "dfgi";
}

const char *lab3_sequential_threads() {
    return "bcdg";
}

HANDLE lock;
HANDLE semaphore_a, semaphore_b, semaphore_c, semaphore_d, semaphore_e, semaphore_f, semaphore_g,
    semaphore_i, semaphore_k, semaphore_m, semaphore_n, semaphore_b_c, semaphore_c_c, semaphore_d_c, semaphore_g_c;

DWORD WINAPI thread_a(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'a' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_a, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_b(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_a, INFINITE);
    ReleaseSemaphore(semaphore_g_c, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semaphore_g_c, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'b' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semaphore_b_c, 1, NULL);
    }
    WaitForSingleObject(semaphore_g_c, INFINITE);
    ReleaseSemaphore(semaphore_b, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_c(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_a, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semaphore_b_c, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'c' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semaphore_c_c, 1, NULL);
    }
    ReleaseSemaphore(semaphore_c, 3, NULL);
    WaitForSingleObject(semaphore_b, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'c' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_c, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_d(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_a, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semaphore_c_c, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'd' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semaphore_d_c, 1, NULL);
    }
    ReleaseSemaphore(semaphore_d, 3, NULL);
    WaitForSingleObject(semaphore_b, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'd' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_d, 3, NULL);
    WaitForSingleObject(semaphore_e, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'd' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_d, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_e(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_b, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'e' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_e, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_f(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_e, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'f' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_f, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_g(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_a, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semaphore_d_c, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semaphore_g_c, 1, NULL);
    }
    ReleaseSemaphore(semaphore_g, 3, NULL);
    WaitForSingleObject(semaphore_b, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_g, 3, NULL);
    WaitForSingleObject(semaphore_e, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_g, 3, NULL);
    WaitForSingleObject(semaphore_f, INFINITE);
    WaitForSingleObject(semaphore_i, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_g, 2, NULL);
    return TRUE;
}
DWORD WINAPI thread_i(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_e, INFINITE);
    WaitForSingleObject(semaphore_c, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'i' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_i, 3, NULL);
    WaitForSingleObject(semaphore_f, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'i' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_i, 2, NULL);
    return TRUE;
}
DWORD WINAPI thread_k(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_f, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    WaitForSingleObject(semaphore_i, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'k' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_k, 2, NULL);
    return TRUE;
}
DWORD WINAPI thread_m(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_f, INFINITE);
    WaitForSingleObject(semaphore_d, INFINITE);
    WaitForSingleObject(semaphore_i, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'm' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semaphore_m, 1, NULL);
    WaitForSingleObject(semaphore_i, INFINITE);
    WaitForSingleObject(semaphore_k, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'm' << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    return TRUE;
}
DWORD WINAPI thread_n(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(semaphore_k, INFINITE);
    WaitForSingleObject(semaphore_i, INFINITE);
    WaitForSingleObject(semaphore_g, INFINITE);
    WaitForSingleObject(semaphore_m, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'n' << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    return TRUE;
}
int lab3_init() {

    DWORD ThreadID;	HANDLE aThread[11];
    lock = CreateMutex(NULL, FALSE, NULL);
    if (lock == NULL) {
        std::cerr << "CreateMutex error: " << GetLastError() << '\n';
        return 1;
    }
    semaphore_a = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_a == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_b = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_b == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_c = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_c == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_d = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_d == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_e = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_e == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_f = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_f == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_g = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_g == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_i = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_i == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_k = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_k == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_m = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_m == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_n = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_n == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_b_c = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_b_c == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_c_c = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_c_c == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_d_c = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_d_c == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    semaphore_g_c = CreateSemaphore(NULL, 0, 11, NULL);
    if (semaphore_g_c == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    aThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_a, NULL, 0, &ThreadID);
    if (aThread[0] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_b, NULL, 0, &ThreadID);
    if (aThread[1] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_c, NULL, 0, &ThreadID);
    if (aThread[2] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_d, NULL, 0, &ThreadID);
    if (aThread[3] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_e, NULL, 0, &ThreadID);
    if (aThread[4] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[5] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_f, NULL, 0, &ThreadID);
    if (aThread[5] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_g, NULL, 0, &ThreadID);
    if (aThread[6] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[7] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_i, NULL, 0, &ThreadID);
    if (aThread[7] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_k, NULL, 0, &ThreadID);
    if (aThread[8] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_m, NULL, 0, &ThreadID);
    if (aThread[9] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[10] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_n, NULL, 0, &ThreadID);
    if (aThread[10] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    WaitForMultipleObjects(11, aThread, TRUE, INFINITE);
    CloseHandle(lock);
    for (int i = 0; i < 11; i++)
        CloseHandle(aThread[i]);
    CloseHandle(semaphore_a);
    CloseHandle(semaphore_b);
    CloseHandle(semaphore_c);
    CloseHandle(semaphore_d);
    CloseHandle(semaphore_e);
    CloseHandle(semaphore_f);
    CloseHandle(semaphore_g);
    CloseHandle(semaphore_i);
    CloseHandle(semaphore_k);
    CloseHandle(semaphore_m);
    CloseHandle(semaphore_n);
    return 0;
}
