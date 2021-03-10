#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	/*
		Object
		- "An object is simply a block of memory that can store a value." (KNK p. 487)
		- Object has more developed meaning in C++ and Object Oriented Programming (OOP)

		Identifiers
		- Names for variables, functions, macros, and other entitles. (KNK p. 25)
	*/

	int var_name = 3;		// creates an object called 'var_name'.

	int* pt = &var_name;	// pt is an identifier.
	*pt = 1;				// *pt is not an identifier. *pt designates an object.

	int arr[100];	// arr is an identifier. Is arr an object?(No, arr is address of first element of array)
	arr[0] = 7;		// arr[0] is an object.(Identifier�� �ƴ����� expression�� ���� �޸𸮿� ���� �����ϹǷ�)
	// Identifier�� Object�� �ٸ� �������� ���� �� �ִ�.
	

	/*
		lvalue is an expression 'referring' to an object. (K&R p.197)
		(refer�� �� �ٸ� �̸�ó�� ����Ѵٰ� ����)

		L-value : left side of an assignment
		R-value : right side, variable, constant, expressions (KNK p. 67)
	*/

	var_name = 3;	// modifiable lvalue
	// �޸��� ������ referring���ش�.(���� �̸��� �޸� ����x)
	int temp = var_name; // var_name�� �ִ� '��'�� �����ؼ� ����
	temp = 1 + 2;
	// L-value�� object��. �������� R-value�� ���� ���� ���� �������� ���̴�

	pt = &var_name;		// �����Ϳ� ������ �ּҰ��� ����
	int* ptr = arr;		// �ּҰ� ����
	*pt = 7;	// *pt is not an identifier but an modifiable lvalue expression.

	int* ptr2 = arr + 2 * var_name; // address rvalue
	*(arr + 2 * var_name) = 456;	// lvalue expression(���� ���¿� *�� �տ� �ٿ��༭ rvalue expression(modifiable) ó�� ��� ����

	const char* str = "Constant string";		// str is a modifiable lvalue.
	str = "Second string";	// "Constant string" = "Second String"	// impossible
	//str[0] = 'A'; // Error(���� const ���� error ����)
	//puts(str);

	char str2[] = "String in an array";
	/*
		Array�μ� �޸� ������ ���� �Ҵ� �ް�
		str2��� identifier�� ���ڿ��� ����Ǳ� ����� �޸� ������ ���� �ĺ��� ������ �Ѵ�.
		�׷��Ƿ� ���� �ִ� str�� �۵������ �ٸ���. �������� �˰�����.
	*/
	str2[0] = 'A';	// OK
	//puts(str2);

	/*
		Identifiers have scope.(����)	// Identifier�� Object�� �̸� ������ �ϴµ� �̸��� �������ΰ� �ƴϴ�.(�̸��� ���� ���� �ִ�.)
		Objects have storage duration.(��������� ���ӱⰣ)(�޸𸮿� �������� �������� ��ġ�ϴ���)
		Variables and functions have one of the following linkages(����):
			external linkage, internal linkage, or no linkage.
		���� ���ǿ� ����
	*/

	return 0;
}


