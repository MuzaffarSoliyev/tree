#include "List2.h"

int List2::push_back(void * elem, size_t elemSize)
{
	if (!elem || !elemSize) return 1;

	List2Node * temp = new List2Node();
	temp->value = _memory.allocMem(elemSize);
	temp->size = elemSize;
	memcpy(temp->value, elem, elemSize);

	temp->prev = lastElement;
	if (lastElement) lastElement->next = temp;

	if (firstElement == NULL)  firstElement = temp;
	lastElement = temp;
	countElements++;
	return 0;
}

int List2::push_front(void * elem, size_t elemSize)
{
	if (!elem || !elemSize) return 1;

	List2Node * temp = new List2Node();
	temp->value = _memory.allocMem(elemSize);
	temp->size = elemSize;
	memcpy(temp->value, elem, elemSize);

	temp->next = firstElement;
	if(firstElement) firstElement->prev = temp;

	if (lastElement == NULL)  lastElement = temp;
	firstElement = temp;
	countElements++;
	return 0;
}

void List2::pop_back()
{
	if (empty()) return;
	List2Node * temp = lastElement;
	_memory.freeMem(temp->value);
	lastElement = (countElements == 0) ? NULL : lastElement->prev;
	countElements--;
	delete temp;
}

void List2::pop_front()
{
	if (empty()) return;
	List2Node * temp = firstElement;
	_memory.freeMem(temp->value);
	firstElement = (countElements == 0) ? NULL : firstElement->next;
	countElements--;
	delete temp;
}

void * List2::front(size_t & size)
{
	size = this->firstElement->size;
	return this->firstElement->value;
}

void * List2::back(size_t & size)
{
	size = this->lastElement->size;
	return this->lastElement->value;
}

int List2::insert(Iterator * iter, void * elem, size_t elemSize)
{
	if (empty() || iter == NULL) return 1;
	List2Node * temp = ((List2Iterator*)iter)->getNode();

	List2Node * newElement = new List2Node();
	newElement->value = _memory.allocMem(elemSize);
	newElement->size = elemSize;
	memcpy(newElement->value, elem, elemSize);

	newElement->next = temp;
	newElement->prev = temp->prev;

	if (temp == firstElement) firstElement = newElement;
	if (temp == lastElement) lastElement = newElement;

	if (temp->prev) temp->prev->next = newElement;
	temp->prev = newElement;
	countElements++;
	return 0;
}

int List2::size()
{
	return countElements;
}

size_t List2::max_bytes()
{
	return _memory.size();
}

Container::Iterator * List2::find(void * elem, size_t size)
{
	List2Iterator * iter = (List2Iterator*)begin();

	while (iter != NULL)
	{
		if (memcmp(iter->getNode()->value, elem, size) == 0)
		{
			return iter;
		}
		if (iter->hasNext()) iter->goToNext();
		else break;
	}

	return NULL;
}

Container::Iterator * List2::newIterator()
{
	return begin();
}

Container::Iterator * List2::begin()
{
	return new List2Iterator(firstElement);
}

Container::Iterator * List2::end()
{
	return new List2Iterator(lastElement);
}

void List2::remove(Iterator * iter)
{
	if (empty()) return;
	List2Node * temp = ((List2Iterator*)iter)->getNode();

	_memory.freeMem(temp->value);
	if (temp->next != NULL) temp->next->prev = temp->prev;
	if (temp->prev != NULL) temp->prev->next = temp->next;
	if (iter->hasNext()) iter->goToNext();
	countElements--;

	if (firstElement == temp) firstElement = temp->next;
	if (lastElement == temp) lastElement = temp->prev;

	delete temp;
}

void List2::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

bool List2::empty()
{
	return countElements == 0;
}

List2::List2Node * List2::List2Iterator::getNode()
{
	return currentElement;
}

void * List2::List2Iterator::getElement(size_t & size)
{
	size = currentElement->size;
	return currentElement->value;
}

bool List2::List2Iterator::hasNext()
{
	return currentElement->next != NULL;
}

void List2::List2Iterator::goToNext()
{
	currentElement = currentElement->next;
}

bool List2::List2Iterator::equals(Iterator * right)
{
	return this == right;
}
