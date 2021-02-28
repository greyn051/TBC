#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count() {

	int ct = 0;	// stack�� �����
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

void static_count() {

	static int ct = 0;	// initialized only once!
	// stack�� ����x, �����ͳ� BSS���� ���� ����(���α׷� ���ۺ��� ������ �����Ǵ� ��(static))
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

/*
* TODO: return &ct;
* �����͸� ��ȯ�ϴ� ��쵵 �� �ִ�.
* ex) �ϵ���� ���� api ���, ���� ���� ��

int* count() {

	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;	
	// �̷� ��� �ſ� �� ����, ���������� �����͸� ��ȯ�ϴµ� ���������� �Լ��� ������ ������� ����
}

int* static_count() {

	static int ct = 0;	// initialized only once!
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
	// �޸𸮿� ������ �ּҸ� ������ �ֱ� ������ �ᵵ �ȴ�.(���ٴ� ���� �ƴ�, �̷��ٿ� ���� �������� �������)
}

*/

//int func(static int i) {	// Warning (Error in GCC)
//
//}
/*
	�Լ��� parameter�� static �ִ� ���, 
	vs���� i�� bad storage���´ٴ� warning�� �߰�
	gcc�� �������ϸ� error�� ���� ������ �Ұ�

	paremeter�� ������ �Լ��� ������ �� �� �޸��� ������ �޴µ�
	static���� ���� �����Ƿ�
*/

void counter_caller() {
	
	count();
}

void static_counter_caller() {

	static_count();
}

int main() {

	count();
	count();
	counter_caller();	// stack �ȿ��� count() ȣ��

	static_count();
	static_count();
	static_counter_caller();

	return 0;
}


