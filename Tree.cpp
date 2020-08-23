#include "Tree.h"

void* Tree::Iterator_46::getElement(size_t &size){
	return currNode->getElement(size);
}

// Возвращает true, если есть следующий элемент, иначе false.
bool Tree::Iterator_46::hasNext(){
	if (currNode->child->size()>0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

// Переход к следующему элементу.

void Tree::Iterator_46::goToNext(){
	/*size_t s;
	if (hasNext())
	{
		currNode = currNode->child->front(s);
	}*/
}


// проверка на равенство итераторов
bool Tree::Iterator_46::equals(Container::Iterator* right)
{
	Tree::Iterator_46 *it = dynamic_cast<Tree::Iterator_46*>(right);
	if (this->currNode == it->currNode)
		return true;
}


// Переход к родительской вершине. Возвращает false если текущая вершина - корень или end().
bool Tree::Iterator_46::goToParent(){
	if (currNode == currNode->parent)
		return false;

	while (currNode != currNode->parent)
		currNode = currNode->parent;
	return true;
}

// Переход к дочерней вершине № child_index. Возвращает false если дочерней вершины с таким номером нет.
bool Tree::Iterator_46::goToChild(int child_index){
	return false;
}

// Функция возвращает значение, равное количеству элементов в контейнере.
int Tree::size(){
	return numberOfElements;
}

// Функция возвращает значение, равное максимальной вместимости контейнера в байтах.
size_t Tree::max_bytes(){
	return _memory.size();
}

// Функция возвращает указатель на итератор, указывающий на первый найденный
// в контейнере элемент. Если элемент не найден, возвращается пустой указатель.
Container::Iterator* Tree::find(void *elem, size_t size){
	
	return NULL;
}

// Создание итератора, соответствующего данному типу контейнера.
Container::Iterator* Tree::newIterator()
{
	return (AbstractTree::Iterator*)this->begin();
}

// Функция возвращает указатель на итератор, указывающий на первый элемент
// контейнера. Если контейнер пустой, возвращается нулевой указатель.
Container::Iterator* Tree::begin(){
	
	return new Tree::Iterator_46(root);
}
// Функция возвращает указатель на итератор, указывающий позицию за последним
// элементом контейнера. Если контейнер пустой, возвращается нулевой указатель.
Container::Iterator* Tree::end(){
	return new Tree::Iterator_46 (root);
}
// Удаление всех элементов из контейнера.
void Tree::clear(){

}

// Если контейнер пуст возвращает true, иначе false
bool Tree::empty(){
	if (numberOfElements == 0)
		return true;
	else
		return false;
}
// Добавление элемента как дочернюю вершину № child_index вершины, на которую
// указывает итератор. В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int Tree::insert(AbstractTree::Iterator *iter, int child_index, void *elem, size_t size){
	return 0; 
}
// Удаление вершины, на которую указывает итератор. Если leaf_only==1 и вершина не является листом, возвращает false
// !!! Примечание: метод remove удаляет вершину вместе со всеми ее потомками
bool Tree::remove(AbstractTree::Iterator* iter, int leaf_only){
	return false;
}