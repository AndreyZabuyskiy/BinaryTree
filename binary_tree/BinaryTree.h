#pragma once
#include <iostream>
using namespace std;

template<typename TKey, typename TValye>
class BinaryTree
{
public:
	BinaryTree() : root(nullptr) {}

	void Insert(TKey key, TValye value)
	{
		root != nullptr ? Add(key, value, root) : AddRoot(key, value);
	}
	void Show()
	{
		if (root != nullptr)
			Print(root);
		else
			cout << "Дерево пусто" << endl;
	}
	void RemoveIt(TKey key)
	{
		if (root != nullptr) 
			FindItemToDeleted(root, key);
	}
	void Remove()
	{
		if (root != nullptr)
			Delete(root);
	}
	bool IsExist(TKey key)
	{
		if (root != nullptr)
			return FindNode(key, root);

		return false;
	}

private:
	template<typename TKey, typename TValye>
	struct Node
	{
		TValye data;
		TKey key;
		Node* perant;
		Node* left;
		Node* right;

		Node(TKey key = TKey(), TValye data = TValye(), Node* prev = nullptr, Node* left = nullptr, Node* right = nullptr)
		{
			this->key = key;
			this->data = data;
			this->perant = prev;
			this->left = left;
			this->right = right;
		}
	};

	Node<TKey, TValye>* root;

	void AddRoot(TKey key, TValye value)
	{
		root = new Node<TKey, TValye>(key, value);
	}
	void Add(TKey key, TValye value, Node<TKey, TValye>* current)
	{
		if (current->key > key)
		{
			if (current->left == nullptr)
				current->left = new Node<TKey, TValye>(key, value, current);
			else
				Add(key, value, current->left);
		}
		else
		{
			if (current->right == nullptr)
				current->right = new Node<TKey, TValye>(key, value, current);
			else
				Add(key, value, current->right);
		}
	}

	void Print(Node<TKey, TValye>* current)
	{
		if (current->left != nullptr) Print(current->left);

		cout << current->data << endl;

		if (current->right != nullptr) Print(current->right);
	}

	void FindItemToDeleted(TKey key, Node<TKey, TValye>* current)
	{
		if (current->key < key)
		{
			if (current->right != nullptr)
				FindItemToDeleted(key, current->right);
		}
		else if (current->key > key)
		{
			if (current->left != nullptr) 
				FindItemToDeleted(key, current->left);
		}
		else
		{
			DeleteFoundItem(key, current);
		}
	}
	void DeleteFoundItem(TKey key, Node<TKey, TValye>* current)
	{
		if (current->right != nullptr)
			ChangeDirectionOfRightBranch(key, current);
		else if (current->left != nullptr)
			ChangeDirectionOfLeftBranch(key, current);
		else
			ChangeDirectionOutBranch(key, current);

		delete current;
	}

	void ChangeDirectionOfRightBranch(TKey key, Node<TKey, TValye>* current)
	{
		if (current->perant != nullptr)
		{
			current->right->perant = current->perant;

			if (current->perant->right == current)
				current->perant->right = current->right;
			else
				current->perant->left = current->right;
		}
		else root = current->right;

		ToEndLeftBranch(current->right)->left = current->left;
		current->left->perant = ToEndLeftBranch(current->right);
	}
	void ChangeDirectionOfLeftBranch(TKey key, Node<TKey, TValye>* current)
	{
		if (current->perant != nullptr)
		{
			current->left->perant = current->perant;

			if (current->perant->right == current)
				current->perant->right = current->left;
			else
				current->perant->left = current->left;
		}
		else root = current->left;
	}
	void ChangeDirectionOutBranch(TKey key, Node<TKey, TValye>* current)
	{
		if (current->perant != nullptr)
		{
			if (current->perant->right == current)
				current->perant->right = nullptr;
			else
				current->perant->left = nullptr;
		}
		else root = nullptr;
	}

	Node<TValye, TKey>* ToEndLeftBranch(Node<TKey, TValye>* current)
	{
		while (current->left != nullptr)
			current = current->left;

		return current;
	}

	void Delete(Node<TKey, TValye>*& current)
	{
		if (current->left != nullptr) Delete(current->left);
		if (current->right != nullptr) Delete(current->right);

		delete current;
		current = nullptr;
	}

	bool FindNode(TKey key, Node<TKey, TValye>* current)
	{
		if (current->key < key)
		{
			if (current->right != nullptr)
				return FindNode(key, current->right);
		}
		else if (current->key > key)
		{
			if(current->left != nullptr)
				return FindNode(key, current->left);
		}
		else
		{
			return true;
		}

		return false;
	}
};