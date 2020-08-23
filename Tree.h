#pragma once
#pragma warning(disable:4996)
#include "GroupContainer.h"
#include "Mem.h"
#include "TreeAbstract.h"
#include "List2.h"

class Tree : public AbstractTree
{
private:
	class Data
	{

	private:
		void *value;
		size_t valueSize;
	public:
		Data() {}
		Data(void *elem, size_t sz) : valueSize(sz) {
			this->value = new char[sz];
			memcpy(value, elem, sz);
			valueSize = sz;
		}
		~Data() {
			valueSize = 0;
			delete value;
		}

		void *getElem() const {
			return value;
		}
		size_t getSize() const {
			return this->valueSize ;
		}

		bool operator==(const Data& right) {
			return memcmp(this->value, right.value, this->valueSize) == 0;
		}
		bool operator!=(const Data &right) {
			return !(*this == right);
		}

	};
	class TreeNode
	{
		friend class Tree;
	private:
		Data *element;
		size_t size;
		TreeNode *parent;
		List2 *child;
	public:
		TreeNode(size_t sz , Data *value, MemoryManager &mem, TreeNode* parent) : size(sz), element(value), parent(parent) {
			child = new List2 (mem);
		}
		~TreeNode()
		{
			size = 0;
			element = NULL;
			parent = NULL;
		}
	

		void setParent(TreeNode *parent) {
			this->parent = parent;
		}

		void *getElement(size_t &sz) const {
			sz = element->getSize();
			return element->getElem();
		}
	};
	TreeNode *root;
	void removeRecursive(TreeNode *node);
	size_t numberOfElements;

public:
	class Iterator_46 : public AbstractTree::Iterator
	{
	private:
		TreeNode *currNode;
	public:
		Iterator_46(TreeNode *node) : currNode(node){}
		//Iterator_46(TreeNode *root) : currNode(root){}
		Iterator_46() : currNode(NULL) {}
		//Iterator_46(const Iterator &it) :currNode(it.currNode){}

		TreeNode *getCurrentNode(void)
		{
			return this->currNode;
		}

		// ���������� ���� ��������� �� �������, �� ������� ��������� �������� � ������ ������.
		// ������ ���������� ������ ������
		virtual void* getElement(size_t &size);

		// ���������� true, ���� ���� ��������� �������, ����� false.
		virtual bool hasNext();

		// ������� � ���������� ��������.
		virtual void goToNext();

		// �������� �� ��������� ����������
		virtual bool equals(Container::Iterator *right);

		// ������� � ������������ �������. ���������� false ���� ������� ������� - ������ ��� end().
		virtual bool goToParent();

		// ������� � �������� ������� � child_index. ���������� false ���� �������� ������� � ����� ������� ���.
		virtual bool goToChild(int child_index);


	};

	Tree(Mem &mem) :AbstractTree(mem)
	{
		root = NULL;
		numberOfElements = 0;
	}

	~Tree(){}

	// ������� ���������� ��������, ������ ���������� ��������� � ����������.
	virtual int size();

	// ������� ���������� ��������, ������ ������������ ����������� ���������� � ������.
	virtual size_t max_bytes();

	// ������� ���������� ��������� �� ��������, ����������� �� ������ ���������
	// � ���������� �������. ���� ������� �� ������, ������������ ������ ���������.
	virtual Container::Iterator* find(void *elem, size_t size);

	// �������� ���������, ���������������� ������� ���� ����������.
	virtual Container::Iterator* newIterator();

	// ������� ���������� ��������� �� ��������, ����������� �� ������ �������
	// ����������. ���� ��������� ������, ������������ ������� ���������.
	virtual Container::Iterator* begin();

	// ������� ���������� ��������� �� ��������, ����������� ������� �� ���������
	// ��������� ����������. ���� ��������� ������, ������������ ������� ���������.
	virtual Container::Iterator* end();

	// �������� ���� ��������� �� ����������.
	virtual void clear();

	// ���� ��������� ���� ���������� true, ����� false
	virtual bool empty();

	// ���������� �������� ��� �������� ������� � child_index �������, �� �������
	// ��������� ��������. � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
	virtual int insert(AbstractTree::Iterator *iter, int child_index, void *elem, size_t size);

	// �������� �������, �� ������� ��������� ��������. ���� leaf_only==1 � ������� �� �������� ������, ���������� false
	// !!! ����������: ����� remove ������� ������� ������ �� ����� �� ���������
	virtual bool remove(AbstractTree::Iterator *iter, int leaf_only);
};