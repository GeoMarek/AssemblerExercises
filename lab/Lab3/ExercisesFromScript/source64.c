#include<stdio.h>

extern __int64 suma_liczb(__int64 v1, __int64 v2, __int64 v3, __int64 v4, __int64 v5, __int64 v6, __int64 v7);
int main()
{
	__int64 sum = suma_liczb(1, 2, 3, 4, 5, 6, 7);
	printf("\nSuma liczb wynosi %I64d\n", sum);
	return 0;
}