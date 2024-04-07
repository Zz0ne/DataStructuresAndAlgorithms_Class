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
struct INode {
  // atributos obrigatórios
  int item; // informação em cada nó

  INode *next;
  INode *prev;
};

// definir lista duplamente ligada
class IDll {
private:
  // atributos obrigatórios
  int n; // dimensão atual da lista
  INode *head;

  void checkBounds(int pos, const char *method);

public:
  IDll();

  int getLength();
  int getItem(int pos);
  int getMax();

  void insert(int value, int pos);
  void insertBegin(int value);
  void insertEnd(int value);

  void del(int pos);
  void delBegin();
  void delEnd();

  int find(int value);
  void clear();
};

// EOF