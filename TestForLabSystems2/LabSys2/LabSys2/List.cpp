#include "List.h"
#include <iostream>
#include <fstream>

void AddElem(Node* list, char* word)
{
    Node* tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new Node;
    tmp = tmp->next;

    int len = strlen(word) + 1;
    tmp->word = new char[len];
    strcpy(tmp->word, word);

    tmp->next = NULL;
    tmp->count = 1;
}

int find(Node* list, char* word)

{
    int ok = 0;
    Node* tmp = list->next; // Старт с первой ноды

    while (tmp != NULL)
    {
        if (strcmp(tmp->word, word) == 0)
        {
            tmp->count++;
            ok = 1;
            break; // Выход из цикла при нахождении слова
        }
        tmp = tmp->next;
    }

    return ok;
}

void OutList(Node* list)
// вывод списка в файл 
{
    Node* tmp = list;
    std::ofstream out;			// поток для записи
    out.open("ResultPairs.txt"); 		// открываем файл для записи
    for (tmp = list->next; tmp != NULL; tmp = tmp->next)
    {
        if (out.is_open())
        {
            out << tmp->word << " " << tmp->count << std::endl;
        }
    }
    out.close();
}
