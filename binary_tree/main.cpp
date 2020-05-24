#include "BinaryTree.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BinaryTree<int, string> tree;
	tree.Insert(10, "������");
	tree.Insert(8, "������");
	tree.Insert(4, "������");
	tree.Insert(2, "���");
	tree.Insert(6, "�����");
	tree.Insert(14, "������������");
	tree.Insert(12, "����������");
	tree.Insert(16, "�����������");
	tree.Show();

	return 0;
}