#include <stdio.h>
extern void random_encrypt(char* text);

void test_random_encrypt()
{
	char text[53] = "Jaki� przyk�adowy tekst\nkt�ry jest w kilku linijkach";
	random_encrypt(text);
	printf("%s", text);
}