#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// command arguments�� ����� �μ� ������ �����Ѵ�.

int main(int argc, char* argv[])	// ����� �μ�
{

	int ch;
	FILE* fr;	// TODO: file pointer to write
	// ������ ó���� �� �ʿ��� �������� ������ ���� ������
	// ��ġ ���� ��ü�� ���� �������� �� ó�� ���� ��������.

	/*
	typedef struct _iobuf	// struct, �������� ����
	{
		char*	_ptr;
		int _cnt;
		char*	_base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char*	_tmpfname;
	} FILE;
	*/
	// ������ ó���� �� �ʿ��� �������� �����͵��� ������ 
	// �����̶�� �ڷ����� �ִ� �� ó�� ����� �� �ְ� ����

	// const char* out_filename = "output.txt";	// TODO: Use this

	unsigned long count = 0;	// ��������� ī��Ʈ�Ϸ��� ������ ����

	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}	// ����� �μ��� ���� �����̸� ����
	// ����� �μ��� ��������� �̷��� ����϶�� ��(�����̸� �Է��ض�)
	// �̷������� ����� �μ��� ������ �˷��ִ� ���� C���α׷��ֿ��� �Ϲ����� ���

	/*	���� �̸��� �Է��� ����� ���Դٸ� ������ ����
		fopen�Լ��� ���� �����͸� return����(�� FILE�� ���� �ǹ�) */
	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading.
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}	/* NULL �����Ͱ� ��ȯ�Ǵ� ���� ���� ������ 
		�ϵ尡 ��á�ų� �б����� ������ ������ ������ �� �� �����. */
	
	/*
		fopen mode strings for text files	// ���� "r"�̹Ƿ� ���ڿ��̴�.
		- r: reading
		- w: creating-and-writing or oven-writing
		- a: appending or creating-and-writing	// ���� �����̰ų� ���� ������ ���� ����
		- r+: both reading and writing
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/

	// TODO: open file to write with "w" mode string

	/*	file stream���� ���� �����͸� �о���� ����
		����(������)�� �ѱ��ھ� �޾ƿ��� �ִ�.
		EOF�� �ƴ� �� ���� ���� */
	while ((ch = fgetc(fr)) != EOF)	// getc(fr)	// fgetc, getc ��� ���� ����(fgetc �� ���� ���)
	{
		//putc(ch, stdout);	// smae as putchar(ch);
		fputc(ch, stdout);	// fputc�� ����ϴ� ���� �� �� �������̶�� ��
		// �ٸ� stream�� stderr�� ���� ���� �ִ�. 
		// redirection�� �� �� stdout, stderr ������ ����

		// TODO: use fputs() to write a file stream!

		count++;	// ���ڼ� ����
	}

	// file stream�� �� ����ߴٸ� �ݵ�� �ݾ�����Ѵ�.
	fclose(fr);	// buffer�� �����ִ� �����͸� ó��
	// TODO:

	printf("FILE %s has %lu characters\n", argv[1], count);

	return 0;
}
