#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r) {
	// do something with r
}

int main() {

	register int r;
	// register keyword�� ���̸� �����Ϸ����� ������ �� ������ register�� ��ġ �ش޶�� �ǹ�
	r = 123;
	// �Ӻ���� �о� � �̰� ����ϴ� ��찡 �ִ�.

	//printf("%p\n", &r);
	int* ptr = &r;	// register keyword ���� address of operator�� ����� �� ����.
	// ���²� �����ͳ� �ּҸ� ����� ���� �� �����ġ�� ���ַ� ����߱� ����


	return 0;
}
