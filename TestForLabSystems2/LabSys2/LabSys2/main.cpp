#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

//--------------------------------------
int main(int argc, char** argv)

{
    if (argc != 2) //
    {  // ����� ���������� ����������
        cout << "l4 from to";
        return 1; // ��������� ���������
    }
    ifstream from(argv[1]); // ��������� ������� ����
    if (!from)
    {
        cout << "�� ����������� ������� ���� :" << argv[1] << endl;
        return 1;
    }


    Node list;
    list.next = NULL;
    list.count = 0;
    list.word = 0;

    while (!from.eof())

    {
        char r_word[100];
        from.getline(r_word, 100, ' '); // ������ �� �������
        char* ptr = r_word;
        if (find(&list, ptr) == 0)   // ���� ������ ����� ��� �� �����������
            AddElem(&list, ptr);      // ��������� ����� �����
    }

    OutList(&list);

    return 0;
}