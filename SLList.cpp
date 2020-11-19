#include "SLList.h"
#include <time.h>
 SLList* SLList::beginList(int data)
{
	 return new SLList(data);
}

 SLList::SLList(const int data)
 {
	 m_data = data;
 }

 SLList::~SLList()
 {
	 delete m_nextEle;
 }

 int SLList::getData() const
 {
	 if (this != nullptr)
	 {
		 return m_data;
	 }
	 else
	 {
		 return -1;
	 }
 }

 void SLList::setData(int data)
 {
	 m_data = data;
 }

 SLList* SLList::next()
 {
	 if (hasNext())
		 return m_nextEle;
	 return nullptr;
 }

 bool SLList::hasNext()
 {
	 if (m_nextEle)
	 {
		 return true;
	 }
	 return false;
 }

 SLList* SLList::addElement(int data)
 {
	 if (hasNext())
	 {
		 return nullptr;
	 }
	 m_nextEle = new SLList(data);
	 return m_nextEle;
 }

 void SLList::removeNext()
 {
	 if (hasNext())
	 {
		 auto delet_elem = m_nextEle;
		 if (m_nextEle->hasNext())
		 {
			 m_nextEle = m_nextEle->m_nextEle;
		 }
		 else
		 {
			 m_nextEle = nullptr;
		 }
		 delet_elem->m_nextEle = nullptr;
		 delete delet_elem;
	 } 
 }

 SLList* SLList::genSLList()
 {
	 srand(static_cast<unsigned int>(time(0)));
	 SLList* list = beginList(rand() * ((5 - 0 + 0.999) / RAND_MAX) + 0);
	 {
		 SLList* elem = list;
		 for (int i = 0; i < 9; ++i)
		 {
			 int random = rand() * ((5 - 0 + 0.999) / RAND_MAX) + 0;
			 elem->addElement(random);
			 elem = elem->next();
		 }
	 }
	 return list;	
 }
 void DeleteDuplicate(SLList* list)
 {
	 if (list == nullptr)
		 return;
	 SLList* current = list;
	 SLList* runner = list;
	 while (current!=nullptr)
	 {
		 while (runner->hasNext())
		 {
			 if (runner->next()->getData() == current->getData())
			 {
				 runner->removeNext();
				 continue;
			 }
			 runner = runner->next();
		 }
		 current = current->next();
		 runner = current;
	 }
	 delete current;
	 runner = nullptr;
	 delete runner;
 }
 int SearchElem(int index, SLList* list)
 {
	 int count_elem = 0;
	 SLList* elem = list;
	 for (; elem != (SLList*)nullptr; elem = elem->next())
	 {
		 count_elem += 1;
	 }
	 delete elem;
	 if (index > count_elem)
	 {
		 return -1;
	 }
	 int index_elem = count_elem - index;
	 while (index_elem>0)
	 {
		 list = list->next();
		 index_elem -= 1;
	 }
	 return list->getData();
	 
 }
 void PrintSLList(SLList* list)
 {
	 SLList* elem = list;
	 int i = 1;
	 for (; elem!= (SLList*)nullptr; elem = elem->next())
	 {
		 printf("%3d ", elem->getData());
	 }
	 delete elem;
 }