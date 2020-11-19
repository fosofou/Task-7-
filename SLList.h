#pragma once
#include <iostream>
class SLList
{
public:
	int getData() const;
	void setData(int data);
	SLList* next();
	bool hasNext();
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
	static SLList* genSLList();
	~SLList();

private:
	SLList* m_nextEle = nullptr;
	int m_data;
	SLList(const int data);
	
	
};

void PrintSLList(SLList* list);
void DeleteDuplicate(SLList* list);
int SearchElem(int index,SLList* list);