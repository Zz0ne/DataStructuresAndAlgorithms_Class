/*
** file: maxh.cpp
**
** max Heap (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-fólio B 2023-24
**
** Aluno: 2201022 - Nuno Rodrigues
*/

// Defina:
//   Em maxh.h as classes da estrutura de dados
//   Em maxh.cpp a implementação dos métodos das classes da estrutura de dados

#include "maxh.h"
#include <cmath>
#include <cstring>

#define LEFT_CHILD(index)    (index * 2 + 1)
#define RIGHT_CHILD(index)   (index * 2 + 2)
#define PARENT(index)        ((index - 1) / 2)
#define LAST_NON_LEAF(index) ((index / 2) - 1)

// Construtor que inicializa a heap com uma capacidade máxima
IMAXH::IMAXH(int nmax)
{
    this->v  = new int[nmax];
    this->n  = 0;
    this->nv = nmax;
}

// Destrutor que libera a memória alocada para a heap
IMAXH::~IMAXH()
{
    delete[] v;
}

// Obtém o maior elemento da heap (o elemento na raiz)
int IMAXH::getMax()
{
    if (this->n == 0)
        throw EmptyHeapError();

    return this->v[0];
}

// Obtém a dimensão atual da heap (número de elementos)
int IMAXH::getDimension()
{
    return this->n;
}

// Obtém a capacidade máxima da heap
int IMAXH::getCapacity()
{
    return this->nv;
}

// Define uma nova capacidade máxima para a heap, redimensionando o array
void IMAXH::setCapacity(int nmax)
{
    int *newV = new int[nmax];
    std::memcpy(newV, this->v, this->n * sizeof(int));

    delete[] this->v;
    this->nv = nmax;
    this->v  = newV;
}

// Insere um novo elemento na heap, mantendo a propriedade de heap máxima
void IMAXH::insert(int element)
{
    if (this->n == this->nv)
        throw FullHeapError();

    // Insere o novo elemento no fim e restaura a propriedade de heap máxima
    this->v[this->n] = element;
    this->n++;
    this->_shiftUp(this->n - 1);
}

// Constrói a heap a partir de um array de elementos
void IMAXH::heapifyUp(int *arr, size_t size)
{
    // Define o novo array como heap
    std::memcpy(this->v, arr, size * sizeof(int));
    this->n = size;

    // Restaura a propriedade de heap máxima, um elemento de cada vez
    // A partir do último elemento que tem filhos
    int start = LAST_NON_LEAF(this->n);
    for (int i = start; i >= 0; i--)
        this->_shiftDown(i);
}

// Remove e retorna o maior elemento da heap, mantendo a propriedade de heap máxima
int IMAXH::deleteMax()
{
    int max = this->getMax();

    // Troca o elemento na raiz com o último
    std::swap(this->v[0], this->v[this->n - 1]);
    // Limpa o último elemento
    this->n--;

    // Restaura a propriedade de heap máxima
    this->_shiftDown(0);
    return max;
}

// Limpa todos os elementos da heap
void IMAXH::clear()
{
    if (this->n == 0)
        throw EmptyHeapError();

    // Colocando n a 0, a MAXH fica vazia
    this->n = 0;
    return;
}

// Sobrecarga do operador de inserção para imprimir a heap
std::ostream &operator<<(std::ostream &os, IMAXH const &p)
{
    if (p.n == 0)
        throw IMAXH::EmptyHeapError();

    int levelLength = 1;
    int index       = 0;

    os << "Heap=\n";
    while (index < p.n)
    {
        for (int i = 0; i < levelLength && index < p.n; ++i)
        {
            os << p.v[index++];
            if (i < levelLength - 1 && index < p.n)
                os << " ";
        }
        os << "\n";
        levelLength *= 2;
    }
    return os;
}

// Método privado que desloca um elemento para baixo na heap
// para restaurar a propriedade de heap máxima
void IMAXH::_shiftDown(int index)
{
    int largest = index;
    int left    = LEFT_CHILD(index);
    int right   = RIGHT_CHILD(index);

    // Procura o maior entre o elemento e seus filhos
    if ((left < this->n) && (this->v[largest] < this->v[left]))
        largest = left;

    if ((right < this->n) && (this->v[largest] < this->v[right]))
        largest = right;

    // Se o maior for diferente do elemento, troca o elemento com o maior
    if (largest != index)
    {
        std::swap(this->v[index], this->v[largest]);
        this->_shiftDown(largest);
    }
}

// Método privado que desloca um elemento para cima na heap
// para restaurar a propriedade de heap máxima
void IMAXH::_shiftUp(int index)
{
    int parent = PARENT(index);
    while (index > 0 && this->v[index] > this->v[parent])
    {
        std::swap(this->v[index], this->v[parent]);
        index  = parent;
        parent = PARENT(index);
    }
}

// Mensagem de erro para heap vazia
const char *IMAXH::EmptyHeapError::what() const throw()
{
    return "Heap vazio!";
}

// Mensagem de erro para heap cheia
const char *IMAXH::FullHeapError::what() const throw()
{
    return "Heap cheio!";
}
// EOF
