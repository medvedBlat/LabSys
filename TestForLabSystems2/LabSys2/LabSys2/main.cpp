#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

//--------------------------------------
int main(int argc, char** argv)

{
    if (argc != 2) //
    {  // вывод справочной информации
        cout << "l4 from to";
        return 1; // закончить программу
    }
    ifstream from(argv[1]); // открываем входной файл
    if (!from)
    {
        cout << "Не открывается входной файл :" << argv[1] << endl;
        return 1;
    }


    Node list;
    list.next = NULL;
    list.count = 0;
    list.word = 0;

    while (!from.eof())

    {
        char r_word[100];
        from.getline(r_word, 100, ' '); // читаем до пробела
        char* ptr = r_word;
        if (find(&list, ptr) == 0)   // если такого слова еще не встречалось
            AddElem(&list, ptr);      // добавляем новое слово
    }

    OutList(&list);

    return 0;
}