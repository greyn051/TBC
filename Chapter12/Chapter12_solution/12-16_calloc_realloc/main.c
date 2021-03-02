#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 10;

	int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * n);
	ptr = (int*)calloc(n, sizeof(int));	// contiguous allocation
	// ���ӵ� n���� int �޸� �޾ƶ�(parameter�� count, size 2��)
	if (!ptr)
		exit(1);

	// calloc()�� ���� �ʱ�ȭ�� ���ش�.
	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]);
	printf("\n");

	/*
		realloc() KNK p. 422
		- doesn't initialize the bytes added
		- returns NULL if can't enlarge the memory block
		- If first argument is NULL, it behaves like malloc()
		- if second argument is 0, it frees the memory block.

		������ �����Ҵ����� �޸𸮸� �޾Ҵµ�
		���� �ʿ�� �ϴ� �޸��� ����� �޶����� 
		�ٽ� �Ҵ��� �ް� ���� �� ����ϴ� �Լ�
		re-allocation(���Ҵ�)
	*/

	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;	// n�� 10���� 20���� �ٲ�

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));	// �þ �������� ���Ҵ� ��û
	// �տ� ptr�� �̹� �����Ҵ����� ������ �ִ� �޸� ���� ���� ������

	//ptr = (int*)realloc(ptr, n * sizeof(int));
	// �ǹ����� �̷��� ���� �޸𸮰� �þ�� �� ó�� �ᵵ �ȴ�.

	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);

	if (!ptr2)
		exit(1);
	else
		ptr = NULL;	// ���� ������ ������� �ʵ��� ������(ptr2 ���ÿ�)

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr2[i]);		// copies data
	printf("\n");
	// ���� �߰��� �� ���� �ʱ�ȭ ���� �ʴ´�.(������ �� ���)

	free(ptr2);

	return 0;
}

