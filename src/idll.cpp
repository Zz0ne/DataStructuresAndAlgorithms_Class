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

// Métodos Privados

/**
 * Verifica se uma posição dada está fora dos limites da lista.
 * @param pos A posição a verificar.
 * @return Verdadeiro se estiver fora dos limites, caso contrário Falso.
 */
bool IDll::outOfBounds(int pos)
{
    if (pos >= this->n || pos < 0)
        return true;
    return false;
}

/**
 * Verifica se a lista está vazia.
 * @return Verdadeiro se a lista estiver vazia, caso contrário Falso.
 */
bool IDll::isEmpty()
{
    return this->n == 0;
}

// Métodos Públicos

/**
 * Construtor para a classe IDll, inicializa uma lista vazia.
 */
IDll::IDll()
{
    this->n    = 0;
    this->head = NULL;
    this->tail = NULL;
}

/**
 * Destruidor para a classe IDll, limpa todos os elementos.
 */
IDll::~IDll()
{
    this->clear();
}

/**
 * Obtém o número de elementos na lista.
 * @return O comprimento da lista.
 */
int IDll::getLength()
{
    return this->n;
}

/**
 * Recupera um item da lista numa posição especificada.
 * @param pos Posição do item a recuperar.
 * @param item Ponteiro para armazenar o item.
 * @return Verdadeiro se o item foi recuperado com sucesso, caso contrário Falso.
 */
bool IDll::getItem(int pos, int *item)
{
    if (this->outOfBounds(pos))
        return false;

    INode *curr = this->head;
    // Navega até a posição
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    *item = curr->item;
    return true;
}

/**
 * Recupera o valor máximo da lista.
 * @param max Ponteiro para armazenar o valor máximo.
 * @return Verdadeiro se a lista não estiver vazia e o máximo for encontrado, caso contrário Falso.
 */
bool IDll::getMax(int *max)
{
    if (this->isEmpty())
        return false;

    INode *curr = this->head;
    *max        = curr->item;

    // Percorre a lista atualizando o máximo se um valor maior for encontrado
    while (curr != NULL)
    {
        if (curr->item > *max)
            *max = curr->item;
        curr = curr->next;
    }

    return true;
}

/**
 * Insere um valor no início da lista.
 * @param value O valor a inserir.
 */
void IDll::insertBegin(int value)
{
    INode *newData = new INode;
    newData->item  = value;

    // Se a lista estiver vazia, define o novo nó como head
    if (this->isEmpty())
    {
        this->head = newData;
        this->tail = newData;
        this->n++;
        return;
    }

    // Se não estiver vazia, insere o novo nó antes da head atual
    newData->next    = this->head;
    this->head->prev = newData;

    this->head       = newData;
    newData->prev    = NULL;

    this->n++;
}

/**
 * Insere um valor no final da lista.
 * @param value O valor a inserir.
 */
void IDll::insertEnd(int value)
{
    INode *newData = new INode;
    newData->item  = value;
    newData->next  = NULL;

    // Se a lista estiver vazia, define o novo nó como head
    if (this->isEmpty())
    {
        this->head = newData;
        this->tail = newData;
        this->n++;
        return;
    }

    newData->prev    = this->tail;
    this->tail->next = newData;
    this->tail       = newData;
    this->n++;
}

/**
 * Apaga um item da lista numa posição especificada.
 * @param pos A posição do item a apagar.
 * @return Verdadeiro se o item foi apagado com sucesso, caso contrário Falso.
 */
bool IDll::del(int pos)
{
    if (this->outOfBounds(pos))
        return false;

    // Se a posição for 0, usa o método delBegin para remover o primeiro nó
    if (pos == 0)
    {
        this->delBegin();
        return true;
    }

    // Se a posição for a última, usa o método delEnd para remover o último nó
    if (pos == this->n - 1)
    {
        this->delEnd();
        return true;
    }

    // Se não for o primeiro nem o último, encontra o nó a ser removido
    INode *toDelete = this->head;
    for (int i = 0; i < pos; i++)
        toDelete = toDelete->next;

    // Remove o nó do meio conectando os nós antes e depois do mesmo
    INode *before = toDelete->prev;
    INode *after  = toDelete->next;

    before->next  = after;
    after->prev   = before;

    delete toDelete;
    toDelete = NULL;

    this->n--;

    return true;
}

/**
 * Apaga o primeiro item da lista.
 * @return Verdadeiro se o item foi apagado com sucesso, caso contrário Falso.
 */
bool IDll::delBegin()
{
    if (this->isEmpty())
        return false;

    INode *toDelete = this->head;
    this->head      = toDelete->next;

    delete toDelete;
    toDelete = NULL;

    this->n--;

    if (!this->isEmpty())
        this->head->prev = NULL;

    return true;
}

/**
 * Apaga o último item da lista.
 * @return Verdadeiro se o item foi apagado com sucesso, caso contrário Falso.
 */
bool IDll::delEnd()
{
    if (this->isEmpty())
        return false;

    INode *toDelete = this->tail;
    // Se, na lista, existir apenas 1 elemento remove-o
    if (this->n == 1)
    {
        this->head = NULL;
        this->tail = NULL;
    }
    else
    {
        this->tail       = toDelete->prev;
        this->tail->next = NULL;
    }

    delete toDelete;
    this->n--;
    return true;
}

/**
 * Limpa todos os elementos da lista.
 */
void IDll::clear()
{
    if (this->isEmpty())
        return;

    INode *toDelete = this->head;

    // Percorre e apaga cada elemento da lista
    while (toDelete != NULL)
    {
        INode *prev = toDelete;
        toDelete    = toDelete->next;
        delete prev;
    }
    this->head = NULL;
    this->tail = NULL;
    this->n    = 0;
}

/**
 * Procura um valor na lista e retorna a posição do primeiro encontro.
 * @param value O valor a procurar.
 * @return A posição do valor na lista, ou -1 se não for encontrado.
 */
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

/**
 * Imprime todos os itens da lista.
 */
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

/**
 * Imprime o último item da lista.
 */
void IDll::printEnd()
{
    std::cout << "Lista(end)= " << this->tail->item << std::endl;
}

/**
 * Imprime o primeiro item da lista.
 */
void IDll::printBegin()
{
    std::cout << "Lista(0)= " << this->head->item << std::endl;
}

/**
 * Inverte uma sub-secção da lista delimitada por posições de início e fim.
 * @param start Posição inicial da sub-secção a inverter.
 * @param end Posição final da sub-secção a inverter.
 * @return Verdadeiro se a sub-secção foi invertida com sucesso, caso contrário Falso.
 */
bool IDll::invertRange(int start, int end)
{
    if (this->outOfBounds(start) || this->outOfBounds(end))
        return false;

    // Localiza os nós inicial e final da sub-secção
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

    // Reinicia a partir do início da sub-seção
    curr          = rangeStart;
    IDll *tmpList = new IDll();

    // Copia os items para lista temporária de forma invertida
    for (int i = start; i <= end; i++)
    {
        tmpList->insertBegin(curr->item);
        curr = curr->next;
    }

    INode *lastNodeTmp = tmpList->tail;

    // se rangeStart for o primeiro elemento da lista
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

    // Se rangeEnd não for o último elemento da lista
    if (rangeEnd->next != NULL)
    {
        lastNodeTmp->next    = rangeEnd->next;
        rangeEnd->next->prev = lastNodeTmp;
    }
    else
        lastNodeTmp->next = NULL;

    // Limpar nós não invertidos
    curr = rangeStart;

    while (curr != rangeEnd)
    {
        INode *prev = curr;
        curr        = curr->next;
        delete prev;
    }
    tmpList->head = NULL;
    tmpList->tail = NULL;
    delete tmpList;

    return true;
}
// EOF
