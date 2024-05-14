
/*
** file: maxh.h
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
// Não altere o nome das classes nem dos atributos obrigatórios!

// definir int max heap em array
#include <exception>
#include <iostream>

class IMAXH
{
  private:
    // atributos obrigatórios
    int *v, // vetor com nós
        n,  // num. nós usados  (dimensão atual do vetor)
        nv; // dim max do vetor (capacidade)

    void _shiftDown(int index);
    void _shiftUp(int index);

  public:
    // construtores
    IMAXH(int nmax = 15); // cria heap vazio c/ capacidade nmax nós
    ~IMAXH();
    // outros atributos e métodos (protótipos) livres
    int getMax();
    int getDimension();
    int getCapacity();
    void setCapacity(int nmax);

    void insert(int element);
    void heapifyUp(int *arr, size_t size);
    int deleteMax();
    void clear();

    friend std::ostream &operator<<(std::ostream &os, IMAXH const &p);

    // Erros
    class EmptyHeapError : public std::exception
    {
      public:
        const char *what() const throw();
    };

    class FullHeapError : public std::exception
    {
      public:
        const char *what() const throw();
    };
};

// EOF
