#include <iostream>
#include <fstream>

struct Node
{
    Node* next;
    int count;
    char* word;
};

//--------------------------------

void AddElem(Node* list, char* word); // ���������� ����� � ������


//----------------------------------
int find(Node* list, char* word);

//--------------------------------------
void OutList(Node* list);