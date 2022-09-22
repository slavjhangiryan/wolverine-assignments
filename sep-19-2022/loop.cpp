#include <iostream>

void printRecursive(int n) {
    if(n < 0) {
        return;
    }

    printRecursive(n - 1);
    std::cout << n << std::endl;
}

int main() {
    int num = 7;
    printRecursive(num);
}

/* 
    possible assembly code`

    printRecursive(int):
        push ebp
        mov ebp, esp
        mov DWORD PTR [rbp - 4], edi
        mov eax, DWORD PTR [rbp - 4]
        cmp eax, -1
        jg L1
        ret
    L1:
        sub eax, 1
        mov edi, eax
        call printRecursive(int)
        print(n)
        pop ebp

    main:
        push ebp
        mov ebp esp
        mov DWORD PTR [rbp - 4], 7
        mov edi, eax
        call printRecursive
        pop ebp
        mov eax, 0
        ret    
*/
