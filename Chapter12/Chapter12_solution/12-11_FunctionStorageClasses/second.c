#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// printf() in second.c

extern int g_int;	// referencing declaration

static void tool(void) {
	// �ٸ� ���Ͽ��� ���������� ��� ���� ���� static keyword �̿�
}

//static void fun_second();	// prototype�� static�ٿ��� linking error ��

void fun_second(void) {

	tool();	// fun_second�� �ܺο��� ��� ����, tool()�� ���� ������ ��� ����  

	g_int += 1;
	printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}

/*
static void fun_second(void) {

	g_int += 1;
	printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}
// �� ��쿡 linking error �߻�
*/