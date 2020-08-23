#pragma once
#include "List2Abstract.h"

// јбстрактный класс: двунаправленный список
class List2 : public AbstractList2
{
private:

	struct List2Node {

		void * value;
		size_t size;
		List2Node * prev;
		List2Node * next;

		List2Node() : value(NULL), size(0), prev(NULL), next(NULL) {}

		List2Node(void * value, size_t size) : value(value), size(size) { prev = next = NULL; }

		List2Node(void * value, size_t size, List2Node * prev, List2Node * next) : value(value), size(size), prev(prev), next(next) { }

	};

	class List2Iterator : public Container::Iterator
	{
		List2Node * currentElement;

	public:

		List2Iterator(List2Node * currentElement) : currentElement(currentElement) {}

		List2Node * getNode();

		virtual void* getElement(size_t &size);

		virtual bool hasNext();

		virtual void goToNext();

		virtual bool equals(Iterator *right);

	};

protected:
	List2Node * firstElement;

	List2Node * lastElement;

	size_t countElements;
public:

	List2(MemoryManager &mem) : AbstractList2(mem) { firstElement = lastElement = NULL; countElements = 0; }

	~List2() {   }

	virtual int push_back(void *elem, size_t elemSize);

	virtual int push_front(void *elem, size_t elemSize);

	virtual void pop_back();

	virtual void pop_front();

	virtual void* front(size_t &size);

	virtual void* back(size_t &size);

	virtual int insert(Container::Iterator *iter, void *elem, size_t elemSize);

	virtual int size();

	virtual size_t max_bytes();

	virtual Container::Iterator* find(void *elem, size_t size);

	virtual Container::Iterator* newIterator();

	virtual Container::Iterator* begin();

	virtual Container::Iterator* end();

	virtual void remove(Container::Iterator *iter);

	virtual void clear();

	virtual bool empty();

};