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

IMAXH::IMAXH(int nmax)
{
    ;
}

IMAXH::~IMAXH()
{
    ;
}

int IMAXH::getMax()
{
    return 0;
}

int IMAXH::getDimension()
{
    return 0;
}

int IMAXH::getCapacity()
{
    return 0;
}

void IMAXH::setCapacity(int nmax)
{
    return;
}

void IMAXH::insert(int val)
{

    return;
}
void IMAXH::heapifyUp(int *arr)
{

    return;
}

void IMAXH::deleteMax()
{

    return;
}

void IMAXH::clear()
{

    return;
}

std::ostream &operator<<(std::ostream &os, IMAXH const &p)
{
    os << p.n << "," << p.n;
    return os;
}

void IMAXH::_bottomUp()
{
    return;
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
