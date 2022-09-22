int main() {
	int x = 20;
	int y = -42;
	int max = 0;

	if(x < y) {
		max = y;
	}
	else {
		max = x;
	}
}

/* 
	possible assembly code`
	
	main:
		push ebp
		mov ebp esp
		mov DWORD PTR [rbp - 4], 20
		mov DWORD PTR [rbp - 8], -42
		mov DWORD PTR [rbp - 12], 0
		cmp  DWORD PTR [rbp - 4], DWORD PTR [rbp - 8]
		jl L1
		mov eax, DWORD PTR [rbp - 8]
		jmp L2
	L1:
		mov eax, DWORD PTR [rbp - 4]
	L2:
		mov DWORD PTR [rbp - 12], eax
		mov eax, 0
		ret
*/
