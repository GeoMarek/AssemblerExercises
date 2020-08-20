#include <stdio.h>
#include <memory.h>

extern float number_pi(int n);
extern int is_inside(int x, int y, int z, int r, int h);
extern char* join_words(char* sep, char** list, int n, char* buf);
extern int count_set_bits(int num);
extern int multiply_by_ten(int num);
extern int decimal_count(int num);
extern int binary_to_decimal(char* binary);
extern void copy_even_from_array(int* input, int* output, int size);
extern int minus2_to_binary(unsigned int num);
extern unsigned int compress(char* original, char* source);

void test_1()
{
	/* approximate number pi */
	printf("Enter number of elements\n\t");
	int n = 0;
	scanf_s("%i", &n);
	printf("Value of Pi number is:\n");
	float pi = number_pi(n);
	printf("\t%f\n", pi);
}

void test_2() 
{
	/* is point inside a cylinder */
	printf("x=5 y=0 z=5 r=5 h=6 => ");
	int ret = is_inside(5, 0, 5, 5, 6);
	printf("Result is: %i\n", ret);

	printf("x=0 y=5 z=7 r=5 h=6 => ");
	ret = is_inside(0, 5, 7, 5, 6);
	printf("Result is: %i\n", ret);

	printf("x=2 y=1 z=3 r=7 h=11 => ");
	ret = is_inside(2, 1, 3, 7, 11);
	printf("Result is: %i\n", ret);
}

void test_3() 
{
	/* join words */
	int n = 0;
	int chars = 0;
	printf("Enter number of words:");
	scanf_s("%i", &n);
	char** list;
	list = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter word nr %d: \n", i + 1);
		list[i] = (char*)malloc(80);
		memset(list[i], 0, 80);
		chars += scanf_s("%s", list[i], 80);
	}
	char sep[] = ", ";
	char* buf = (char*)malloc(sizeof(char) * chars + 10 * n * 2);
	memset(buf, 0, sizeof(char) * chars + 10 * n * 2);
	char* c = join_words(sep, list, n, buf);
	printf(c);
}

void test_4() {
	/* count set bits in number */
	for (int i = 0; i < 20; ++i) 
	{
		printf("num: %i\t bits: %i\n", i, count_set_bits(i));
	}
}

void test_5() 
{
	/* multiply by ten without mul/imul */
	for (int i = 0; i < 20; ++i) 
	{
		printf("num: %i\t ret: %i\n", i, multiply_by_ten(i));
	}
}

void test_6() 
{
	/* sum of decimal digits */
	for (int i = 3; i < 20; ++i) 
	{
		printf("num: %i\t ret: %i\n", i * 7, decimal_count(i * 7));
	}
}
	
void test_7() 
{
	/* convert binary to decimal */
	char* text = "001101010011";
	int num = binary_to_decimal(text);
	printf("%s is %i in decimal", text, num);
}

void test_8() 
{
	/* copy even elements from array */
	int size = 5;
	int input[] = { 1,3,52,71,97 };
	int* output = (int*)malloc(sizeof(int) * size);
	copy_even_from_array(input, output, size);
	for (int i = 0; i < size; ++i) 
	{
		printf("%i, ", output[i]);
	}
}
	
void test_9() 
{
	/* minus binary to U2 */
	// 25 = 11001 = (-2)^4 + (-2)^3 + (-2)^0 = 9
	unsigned int minus_binary = 25;
	int binary = minus2_to_binary(minus_binary);
	printf("%i", binary);
}

void test_10() 
{
	/* compress ASCII array */
	char input[] = "aaaaaxbbbcccccdddd";
	char* output = (char*)calloc(80);
	unsigned int result = compress(input, output);
	printf("%i\n", result);
	printf("%s", output);
}

void presentation_1() 
{
	int count = 0;
	printf("\nRuning test number: %i\n", ++count); test_1(); 
	printf("\nRuning test number: %i\n", ++count); test_2(); 
	printf("\nRuning test number: %i\n", ++count); test_3(); 
	printf("\nRuning test number: %i\n", ++count); test_4(); 
	printf("\nRuning test number: %i\n", ++count); test_5(); 
	printf("\nRuning test number: %i\n", ++count); test_6(); 
	printf("\nRuning test number: %i\n", ++count); test_7(); 
	printf("\nRuning test number: %i\n", ++count); test_8(); 
	printf("\nRuning test number: %i\n", ++count); test_9(); 
	printf("\nRuning test number: %i\n", ++count); test_10();
}