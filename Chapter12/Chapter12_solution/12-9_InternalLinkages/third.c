#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// printf() in third.c

extern int g_int;	// referencing declaration
// main()���� static���� ���ұ� ������ ���� �Ұ�

void fun_second(void) {

	g_int += 1;
	printf("g_int in fun_third() %d %p\n", g_int, &g_int);
}