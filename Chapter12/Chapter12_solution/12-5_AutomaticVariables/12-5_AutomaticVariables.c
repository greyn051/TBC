#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Automatic storage class
	- Automatic storage duration, block scope, no linkage
	- Any variable declared in a block or function header
*/

void func(int k);

int main()	// Note: main() is a function.
{
	auto int a;	// keyword auto : a storage-class specifier(���� ���x, C++������ auto keyword�� ���� �ٸ� ���� ������)
	a = 1024;
	//printf("%d\n", a);		// what happens if uninitialized?
	//auto int b = a * 3;		// what happens if uninitialized?
	/*
		�ڵ������� ����ϰ� ���Ǳ� ������ �ʱ�ȭ�� ������Ѵ�.
		�����Ϸ��� �ڵ������� �ʱ�ȭ ������ ����
		(�ڵ������� ���������� ���� �Ź� �����Ϸ��� 0���� �ʱ�ȭ���ָ� ȿ���� ���� �����Ƿ�)
	*/

	int i = 1;
	int j = 2;

	printf("i %lld\n", (long long)&i);

	{
		// ������ �ٲ�� �Ȱ��� identifier ����
		int i = 3;	// name hiding(�� ū �������� ������ �� identifier�� hiding�ȴ�.)
		printf("i %lld\n", (long long)&i);
		// C���� identifier�� ���� ��� ���� �� �� ������ �ִ� ���� ����

		// j is visible here
		printf("j = %d\n", j);	// �� ū ������ �ִ� j �״�� ���

		int ii = 123;
	}
	// ii is not visible here

	printf("i %lld\n", (long long)&i);	// which i?

	for (int m = 1; m < 2; m++)
		printf("m %lld\n", (long long)&m);		// no block?	
	// block�� ��� m�� �ٷ� �������� ��� ����

	func(5);	// cannot see any of the variabled defined so far.

	for (int m = 3; m < 4; m++) {
		printf("m %lld\n", (long long)&m);		// block?
	}
	// block�� ���� �� ���� m ��� ����

	return 0;
}

void func(int k) {

	int i = k * 2;
	// do something with i and k
	printf("i %lld\n", (long long)&i);
}
/*
	�� function�� ȣ��Ǹ� stack frame�� ��ü�� �ٲ�� �����Ƿ� 
	���� ���� ��� ������ �� �� ����.
	(main �Լ� �ȿ� �ִ� i, j�� ������ �� ����)
*/
