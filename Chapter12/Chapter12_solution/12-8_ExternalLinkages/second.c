#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// printf() in second.c

extern int g_int;	
// file scope������ �ʱ�ȭ ����(��, ó�� �������� ���� �� ���� �ʱ�ȭ���� �ʾƾ� ��)(file scope�� �� �������� �ʱ�ȭ �����ϴٴ� ��)
// ������ extern�� ���� �������� �ʱ�ȭ �� �ϴ� ���� ����.

void temp() {

	// extern int g_int;	// ���⼭ �ʱ�ȭ�� �Ұ�(block scope���� �ʱ�ȭ�� �Ұ���)(BSS data segment�� �ٷ���ϹǷ� ����ġ ����)

	g_int += 1000;
}

void fun_sec() {

	temp();

	extern int g_int;

	g_int += 7;
	printf("g_int in fun_sec() %d %p\n", g_int, &g_int);	// �������� ��� ����
}



