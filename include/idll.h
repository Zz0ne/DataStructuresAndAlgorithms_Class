/*
** file: idll.h
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
// Não altere o nome das classes nem dos atributos obrigatórios!

// definir nó
struct INode
{
    // atributos obrigatórios
    int item; // informação em cada nó

    INode *next;
    INode *prev;
};

// definir lista duplamente ligada
class IDll
{
  private:
    // atributos obrigatórios
    int n; // dimensão atual da lista
    INode *head;

    bool checkBounds(int pos);

  public:
    IDll();
    ~IDll();

    int getLength();
    bool getItem(int pos, int *item);
    bool getMax(int *max);

    void insertBegin(int value);
    void insertEnd(int value);

    bool del(int pos);
    bool delBegin();
    bool delEnd();

    void clear();
    int find(int value);

    void printList();
    void printBegin();
    void printEnd();
    bool invertRange(int begin, int end);
};

// EOF
