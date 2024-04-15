/*
** file: idll.cpp
**
** Integer Double Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2023-24
**
** Aluno: 2201022 - Nuno Rodrigues
*/

// Defina:
//   Em idll.h as classes da estrutura de dados
//   Em idll.cpp a implementação dos métodos das classes da estrutura de dados

#include "idll.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>

#define DEBUG_PRINT(x) std::cout << "reached " << x << std::endl

//  Private
bool IDll::outOfBounds(int pos)
{
    if (pos >= this->n || pos < 0)
        return true;
    return false;
}

// Public
IDll::IDll()
{
    this->n    = 0;
    this->head = NULL;
}

IDll::~IDll()
{
    this->clear();
}

int IDll::getLength()
{
    return this->n;
}

bool IDll::getItem(int pos, int *item)
{
    if (this->outOfBounds(pos))
        return false;

    INode *curr = this->head;

    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }

    *item = curr->item;
    return true;
}

bool IDll::getMax(int *max)
{

    if (this->n == 0)
        return false;

    INode *curr = this->head;
    *max        = curr->item;

    while (curr != NULL)
    {
        if (curr->item > *max)
            *max = curr->item;
        curr = curr->next;
    }

    return true;
}

void IDll::insertBegin(int value)
{
    INode *newData = new INode;
    newData->item  = value;

    if (this->head == NULL)
    {
        this->head = newData;
        this->n++;
        return;
    }

    newData->next    = this->head;
    this->head->prev = newData;

    this->head       = newData;
    newData->prev    = NULL;

    this->n++;
}

void IDll::insertEnd(int value)
{
    INode *newData = new INode;
    newData->item  = value;
    newData->next  = NULL;

    if (this->head == NULL)
    {
        this->head = newData;
        this->n++;
        return;
    }

    INode *curr = this->head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next    = newData;
    newData->prev = curr;
    this->n++;
}

bool IDll::del(int pos)
{
    if (this->outOfBounds(pos))
        return false;

    if (pos == 0)
    {
        this->delBegin();
        return true;
    }

    if (pos == this->n - 1)
    {
        this->delEnd();
        return true;
    }

    INode *toDelete = this->head;
    for (int i = 0; i < pos; i++)
    {
        toDelete = toDelete->next;
    }

    INode *before = toDelete->prev;
    INode *after  = toDelete->next;

    before->next  = after;
    after->prev   = before;

    delete toDelete;
    toDelete = NULL;

    this->n--;

    return true;
}

bool IDll::delBegin()
{
    if (this->n == 0)
        return false;

    INode *toDelete = this->head;
    this->head      = toDelete->next;

    delete toDelete;
    toDelete = NULL;

    this->n--;

    if (n)
    {
        this->head->prev = NULL;
    }

    return true;
}

bool IDll::delEnd()
{
    if (this->n == 0)
        return false;

    // Se a lista tiver apenas 1 elemento
    if (this->n == 1)
    {
        delete this->head;
        this->head = NULL;
        return true;
    }

    INode *toDelete = this->head;

    while (toDelete->next != NULL)
        toDelete = toDelete->next;

    INode *newLast = toDelete->prev;
    newLast->next  = NULL;
    delete toDelete;

    this->n--;
    return true;
}

void IDll::clear()
{
    if (this->n == 0)
        return;

    INode *toDelete = this->head;

    while (toDelete != NULL)
    {
        INode *prev = toDelete;
        toDelete    = toDelete->next;
        delete prev;
    }
    this->head = NULL;
    this->n    = 0;
}

int IDll::find(int value)
{
    INode *curr = this->head;
    int pos     = 0;

    while (curr != NULL)
    {
        if (curr->item == value)
            return pos;
        curr = curr->next;
        pos++;
    }

    return -1;
}

void IDll::printList()
{
    INode *curr = this->head;

    std::cout << "Lista=";

    while (curr != NULL)
    {
        std::cout << " " << curr->item;
        curr = curr->next;
    }

    std::cout << std::endl;
}

void IDll::printEnd()
{
    int item;
    this->getItem(this->n - 1, &item);
    std::cout << "Lista(end)= " << item << std::endl;
}

void IDll::printBegin()
{
    std::cout << "Lista(0)= " << this->head->item << std::endl;
}

bool IDll::invertRange(int start, int end)
{
    if (this->outOfBounds(start) || this->outOfBounds(end))
        return false;

    // Descobrir as posições dos nós
    INode *rangeStart = NULL, *rangeEnd = NULL, *curr = this->head;
    for (int i = 0; i <= end; ++i)
    {
        if (i == start)
            rangeStart = curr;
        if (i == end)
            rangeEnd = curr;
        if (i < end)
            curr = curr->next;
    }

    IDll *tmpList = new IDll();
    curr          = rangeStart;

    // Copiar os items para lista temporária
    for (int i = start; i <= end; i++)
    {
        tmpList->insertBegin(curr->item);
        curr = curr->next;
    }

    INode *lastNodeTmp = tmpList->head;

    for (int i = start; i < end; i++)
        lastNodeTmp = lastNodeTmp->next;

    if (rangeStart->prev == NULL)
    {
        this->head       = tmpList->head;
        this->head->prev = NULL;
    }
    else
    {
        rangeStart->prev->next = tmpList->head;
        tmpList->head->prev    = rangeStart->prev;
    }

    if (rangeEnd->next != NULL)
    {
        lastNodeTmp->next    = rangeEnd->next;
        rangeEnd->next->prev = lastNodeTmp;
    }
    else
    {
        lastNodeTmp->next = NULL;
    }

    // Limpar nós não invertidos
    curr = rangeStart;

    while (curr != rangeEnd)
    {
        INode *prev = curr;
        curr        = curr->next;
        delete prev;
    }
    tmpList->head = nullptr;
    delete tmpList;

    return true;
}
// EOF
