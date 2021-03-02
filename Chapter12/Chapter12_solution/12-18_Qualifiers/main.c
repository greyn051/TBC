#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// memcpy
#include "constants.h"

//const double gravity = 9.8;
//const double PI = 3.141592;

int main() {

	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
	*/

	// C99 ideompotent	// ������ �ᵵ �ȴٴ� ��
	const const const int n = 6;	// const int n = 6;

	// type define
	typedef const int zip;	// const int�� zip�̶�� type���� ���� ����
	const zip q = 8;	// const const int zip
	// �̷� ��� ����ؼ� ideompotent

	//const int i;	// Not initialized!
	//i = 12;	// Error
	//printf("%d\n", i);	// Error

	const int j = 123;
	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f;	// Error
	pf1 = &f2;		// Allowed
	// pf1�̶�� ������ ���� ��ü�� �ٸ� ���� ���� �� �ִ�

	float* const pf2 = &f1;
	*pf2 = 6.0f;	// Allowed
	//pf2 = &f2;	// Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f;	// Error
	//pf3 = &pf2;	// Error

	/*
		Global constants

		����
		const double gravity = 9.8;
		const double PI = 3.141592;

		constant�� header file�� �־ ���ϰ� ��� ����
		#include "constants.h"
	*/

	double area_circle = PI * 2.0f * 2.0f;

	/*
		volatile
		- Do not optimize	(�����Ϸ��� ����ȭ ���� ����) (�ӽð��� ������ ������ �ӵ� ������ cashing)
		- (ex: hardward clock)

		�ֹ߼�, �Ҿ����� �ǹ�
		�����Ϸ��� �𸣴� ��Ȳ���� ���� �ٲ� �� �ִٰ� ǥ��
		(�����Ϸ��� �� �� ���� ������ ���� �ٲ� �� �ִٴ� �ǹ�)
	*/

	volatile int vi = 1;	// volatile location
	volatile int* pvi = &vi;	// points to a volatile location

	int i1 = vi;

	// ...

	int i2 = vi;

	/*
		restrict (__restrict in VS)
		- sole initial means of accessing a data object
		- compiler can't check this restriction
	*/

	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	
	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)exit(1);
	/*
		�����Ҵ� �޾� �� �޸𸮸� �ٸ� ����(�ٸ� ������ ��)�� �̿��ؼ� �������� �ʰڴ�.
		restar�� ���ؼ��� �����ϰڴ�. ��� �ǹ�
	*/

	// array�� ���ؼ� ���� �ٲٴ� �Ͱ� pointer�� ���ؼ� ���� �ٲٴ� ���� ����
	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;	// �� 2���� ��ġ�� 8�� �� ���� ���ϴ� �Ͱ� ����
	// ������ array�� pointer�� ���� �ٸ��� ������ �� ���� ���ϴ� ����ȭ �Ұ�

	restar[0] += 3;
	restar[0] += 5;
	//restar[0] += 8;	// Equalivalent
	// ���ʹ� �޸� �����Ϸ��� �� ���� 8�� ���ϴ� ����ȭ�� ���� ���� �ִ�.
	// (__restrict�� ����ȭ�� �����ִ� ����)
	/*
		������ �����Ϸ��� ������ restrict�� �������� �ִ���
		(���� restar���� restrict����) Ȯ���� �� ����.
		compiler can't check this restriction
	*/

	free(restar);

	return 0;
}
