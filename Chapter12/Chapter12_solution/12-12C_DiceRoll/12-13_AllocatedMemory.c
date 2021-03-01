#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc(), free()

int main() {

	float x;
	char str[] = "Dancing with a Star";

	int arr[100];

	/*
		(malloc: memory allocation �޸� �Ҵ�)
		malloc() returns a void type pointer.(������ �ּ�)
		void* : generic pointer

		free() deallocates the memory
	*/

	double* ptr = NULL;

	// ���� ��(ptr)���� double�� casting
	ptr = (double*)malloc(30 * sizeof(double));	// double 30�� �����, �޸� ������ ù��° �ּҸ� return���ش�.(pointer)
	//size_t;	// malloc()�Լ� parameter Ȯ�ο�	// �� byte �޸� ��û���� size�� �����ָ� �ȴ�.

	if (ptr == NULL)	// malloc()�Լ��� �� �޸� ������ ���� �� NULL�� return��
	{

		puts("Memory allocation failed");

		/*
			exit(EXIT_FAILURE) is similar to return 1 IN main().
			exit(EXIT_SUCCESS) is similar to return 0 IN main().

			exit()�Լ��� ��� ��Ȳ������ ������ ���α׷� ���� ����
		*/

		exit(EXIT_FAILURE);
		/*
			��κ��� ��� �޸� �Ҵ��� �� �ȴٴ� �ǹ̴� 
			���� �ɰ��ؼ� ���α׷��� ������ �� ���� ����̹Ƿ�
			exit�� �̿��ؼ� ������ ����(exit �ǿܷ� ���� ���, debugging �� �� ���� ����)
			(�޸� �Ҵ� �� �Ǵ� ��� �� ����. ���� �ִٸ� �޸𸮸� �ʹ� ũ�� ��û�� ����.)
			(���α׷� ������ �־ ���ӵ� ������ �� �� ���� ���� �޸� �Ҵ� �� �ȴ�.)
			
			�� ������ �� �ʿ� ����.

			�ٸ�, ������ �� ��� ��쿡�� ��� ���ư����Ѵٸ� 
			����ó����� ������ �̿��ؼ� �ٸ� ��� ã��(�ٸ� ���� ����)
		*/
	}
	/*
		�����Ҵ� ���� �޸𸮿� �����͸� ���Ͻ����� ����
		automatic�� scope ������ ���� �Ҿ�����Ƿ�
		(�ּҸ� ���� ������� ����)
		(�ּҴ� ������ ������ �Ҿ������ ã�� �� ���� ���)

		�ʺ��� �����͸� �Ҿ���ȴµ��� 
		�����Ҵ��� �ݺ��ϴٰ� heap�� ������ ������ ����� ��찡 �ִ�.
	*/

	printf("Before free %p\n", ptr);

	free(ptr);	// no action occurs when ptr is NULL

	printf("After free %p\n", ptr);
	/*
		free���Ŀ��� ptr�� ��(�ּ�)�� ������ ������ 
		������ �ϸ� ģ���� �ּҸ� ������ ��� ������ ������
		ģ���� �̻縦 �ص� ������ ���� �ּҴ� ������ ������ ���� �ȴ�.

		�׷��Ƿ� free ���Ŀ� �����Ҵ� �޸𸮿� ���� ������ ������ 
		NULL������ �ٲٴ� ���� �����ϰ� ���ϴ�.(optional)
	*/
	ptr = NULL;	// optional

	/* Dynamic Allocated Array */
	// �����Ҵ� �޸𸮴� �迭ó�� ��� ����

	int n = 5;
	// n�� ���� runtime�� �����Ǿ �ȴ�.
	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL)	// if(!ptr)
	{
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");
		// �޸𸮸� �Ҵ� �� �ް� �ʱ�ȭ�� ���� �ʾұ� ������ ������ ���� ����ִ�.

		for (int i = 0; i < n; ++i)
			* (ptr + i) = (double)i;	// ������ ������ �̿��� �迭ó�� ���

		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");
	}
	// �����Ҵ� �޸𸮴� (malloc()�Լ��� �޾ƿ��� ����) �ʱ�ȭ�� ���� �ʴ´ٴ� ���� ���

	free(ptr);
	ptr = NULL;

	/*
		Comparision to VLA (�������̹迭�� ��)

		VLA
		- not supported by VS compilers.(gcc������ ����)(��κ��� ���α׷��� VLA���� �����Ҵ� ����)
		- automatic duration, cannot be resized	(�����Ҵ��� �ٸ� size�� �޸� �ٽ� �޾ƿ� �� ����)
		- limited by stack size (when compiler places VLA in stack segment)
	*/

	return 0;
}