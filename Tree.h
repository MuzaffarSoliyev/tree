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

		// Возврашает явно указатель на элемент, на который указывает итератор в данный момент.
		// Неявно возвращает размер данных
		virtual void* getElement(size_t &size);

		// Возвращает true, если есть следующий элемент, иначе false.
		virtual bool hasNext();

		// Переход к следующему элементу.
		virtual void goToNext();

		// проверка на равенство итераторов
		virtual bool equals(Container::Iterator *right);

		// Переход к родительской вершине. Возвращает false если текущая вершина - корень или end().
		virtual bool goToParent();

		// Переход к дочерней вершине № child_index. Возвращает false если дочерней вершины с таким номером нет.
		virtual bool goToChild(int child_index);


	};

	Tree(Mem &mem) :AbstractTree(mem)
	{
		root = NULL;
		numberOfElements = 0;
	}

	~Tree(){}

	// Функция возвращает значение, равное количеству элементов в контейнере.
	virtual int size();

	// Функция возвращает значение, равное максимальной вместимости контейнера в байтах.
	virtual size_t max_bytes();

	// Функция возвращает указатель на итератор, указывающий на первый найденный
	// в контейнере элемент. Если элемент не найден, возвращается пустой указатель.
	virtual Container::Iterator* find(void *elem, size_t size);

	// Создание итератора, соответствующего данному типу контейнера.
	virtual Container::Iterator* newIterator();

	// Функция возвращает указатель на итератор, указывающий на первый элемент
	// контейнера. Если контейнер пустой, возвращается нулевой указатель.
	virtual Container::Iterator* begin();

	// Функция возвращает указатель на итератор, указывающий позицию за последним
	// элементом контейнера. Если контейнер пустой, возвращается нулевой указатель.
	virtual Container::Iterator* end();

	// Удаление всех элементов из контейнера.
	virtual void clear();

	// Если контейнер пуст возвращает true, иначе false
	virtual bool empty();

	// Добавление элемента как дочернюю вершину № child_index вершины, на которую
	// указывает итератор. В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
	virtual int insert(AbstractTree::Iterator *iter, int child_index, void *elem, size_t size);

	// Удаление вершины, на которую указывает итератор. Если leaf_only==1 и вершина не является листом, возвращает false
	// !!! Примечание: метод remove удаляет вершину вместе со всеми ее потомками
	virtual bool remove(AbstractTree::Iterator *iter, int leaf_only);
};