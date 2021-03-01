#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand()	// random number�� ������ �� �ʿ��� �Լ����� ���Ե�
#include <time.h>	// time()

int main() {

	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdlib.h.

		C���� ���� ������ ���(����� ���� �� �������� ����)
		��ǻ�ʹ� ������ ������ ����� �ɷ��� ����.
	*/

	/*
	//srand(3);	// random seed	// seed���� �ٲ�� ������ rand() ���� �ٲ�
	srand((unsigned int)time(0));	// time�� �̿��ؼ� seed���� �����ϱ� ����� �����
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
		//printf("%d\n", rand() % 6 + 1);
	}
	*/

	unsigned int next = (unsigned int)time(0);	// seed��

	for (int i = 0; i < 10; ++i) {
		next = next * 1103515245 + 1234;
		// ������ ����� � ��Ģ�� �ִ�. ���� '���� ����'(pseudo random number)�� �θ��⵵ ��
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}

	return 0;
}


