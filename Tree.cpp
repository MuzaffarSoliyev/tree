#include "Tree.h"

void* Tree::Iterator_46::getElement(size_t &size){
	return currNode->getElement(size);
}

// ���������� true, ���� ���� ��������� �������, ����� false.
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

// ������� � ���������� ��������.

void Tree::Iterator_46::goToNext(){
	/*size_t s;
	if (hasNext())
	{
		currNode = currNode->child->front(s);
	}*/
}


// �������� �� ��������� ����������
bool Tree::Iterator_46::equals(Container::Iterator* right)
{
	Tree::Iterator_46 *it = dynamic_cast<Tree::Iterator_46*>(right);
	if (this->currNode == it->currNode)
		return true;
}


// ������� � ������������ �������. ���������� false ���� ������� ������� - ������ ��� end().
bool Tree::Iterator_46::goToParent(){
	if (currNode == currNode->parent)
		return false;

	while (currNode != currNode->parent)
		currNode = currNode->parent;
	return true;
}

// ������� � �������� ������� � child_index. ���������� false ���� �������� ������� � ����� ������� ���.
bool Tree::Iterator_46::goToChild(int child_index){
	return false;
}

// ������� ���������� ��������, ������ ���������� ��������� � ����������.
int Tree::size(){
	return numberOfElements;
}

// ������� ���������� ��������, ������ ������������ ����������� ���������� � ������.
size_t Tree::max_bytes(){
	return _memory.size();
}

// ������� ���������� ��������� �� ��������, ����������� �� ������ ���������
// � ���������� �������. ���� ������� �� ������, ������������ ������ ���������.
Container::Iterator* Tree::find(void *elem, size_t size){
	
	return NULL;
}

// �������� ���������, ���������������� ������� ���� ����������.
Container::Iterator* Tree::newIterator()
{
	return (AbstractTree::Iterator*)this->begin();
}

// ������� ���������� ��������� �� ��������, ����������� �� ������ �������
// ����������. ���� ��������� ������, ������������ ������� ���������.
Container::Iterator* Tree::begin(){
	
	return new Tree::Iterator_46(root);
}
// ������� ���������� ��������� �� ��������, ����������� ������� �� ���������
// ��������� ����������. ���� ��������� ������, ������������ ������� ���������.
Container::Iterator* Tree::end(){
	return new Tree::Iterator_46 (root);
}
// �������� ���� ��������� �� ����������.
void Tree::clear(){

}

// ���� ��������� ���� ���������� true, ����� false
bool Tree::empty(){
	if (numberOfElements == 0)
		return true;
	else
		return false;
}
// ���������� �������� ��� �������� ������� � child_index �������, �� �������
// ��������� ��������. � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
int Tree::insert(AbstractTree::Iterator *iter, int child_index, void *elem, size_t size){
	return 0; 
}
// �������� �������, �� ������� ��������� ��������. ���� leaf_only==1 � ������� �� �������� ������, ���������� false
// !!! ����������: ����� remove ������� ������� ������ �� ����� �� ���������
bool Tree::remove(AbstractTree::Iterator* iter, int leaf_only){
	return false;
}