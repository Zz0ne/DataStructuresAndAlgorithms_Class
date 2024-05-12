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

#define LEFT_CHILD(index)  (index * 2 + 1)
#define RIGHT_CHILD(index) (index * 2 + 2)
#define PARENT(index)      ((index - 1) / 2)

IMAXH::IMAXH(int nmax)
{
    this->v  = new int[nmax]{0};
    this->n  = 0;
    this->nv = nmax;
}

IMAXH::~IMAXH()
{
    delete[] v;
}

int IMAXH::getMax()
{
    if (this->n == 0)
        throw EmptyHeapError();

    return this->v[0];
}

int IMAXH::getDimension()
{
    return this->n;
}

int IMAXH::getCapacity()
{
    return this->nv;
}

void IMAXH::setCapacity(int nmax)
{
    return;
}

void IMAXH::insert(int element)
{
    if (this->n == this->nv)
        throw FullHeapError();

    this->v[this->n] = element;
    this->n++;
    this->_bottomUp(this->n - 1);
}

void IMAXH::heapifyUp(int *arr)
{

    return;
}

int IMAXH::deleteMax()
{
    int max = this->getMax();

    std::swap(this->v[0], this->v[this->n - 1]);
    this->n--;

    this->_topDown(0);
    return max;
}

void IMAXH::clear()
{
    this->n = 0;
    return;
}

std::ostream &operator<<(std::ostream &os, IMAXH const &p)
{
    os << p.n << "," << p.n;
    return os;
}

void IMAXH::_topDown(int index)
{
    int left  = LEFT_CHILD(index);
    int right = RIGHT_CHILD(index);

    while (((left < this->n) && (this->v[index] < this->v[left])) ||
           ((right < this->n) && (this->v[index] < this->v[right])))
    {
        int largest = this->v[left] > this->v[right] ? left : right;
        std::swap(this->v[index], this->v[largest]);

        index = largest;
        left  = LEFT_CHILD(index);
        right = RIGHT_CHILD(index);
    }
}

void IMAXH::_bottomUp(int index)
{
    int parent = PARENT(index);
    while (index > 0 && this->v[index] > this->v[parent])
    {
        std::swap(this->v[index], this->v[parent]);
        index  = parent;
        parent = PARENT(index);
    }
}

const char *IMAXH::EmptyHeapError::what() const throw()
{
    return "Heap vazio!";
}

const char *IMAXH::FullHeapError::what() const throw()
{
    return "Heap cheio!";
}
// EOF
