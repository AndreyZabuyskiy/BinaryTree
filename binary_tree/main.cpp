#include "BinaryTree.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BinaryTree<int, string> tree;
	tree.Insert(10, "Десять");
	tree.Insert(8, "Восемь");
	tree.Insert(4, "Четыре");
	tree.Insert(2, "Два");
	tree.Insert(6, "Шесть");
	tree.Insert(14, "Четырнадцать");
	tree.Insert(12, "Двенадцать");
	tree.Insert(16, "Шестнадцать");
	tree.Show();

	return 0;
}