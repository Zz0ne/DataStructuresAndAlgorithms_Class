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

//  Private
void IDll::checkBounds(int pos, const char *method) {
  if (pos >= n || pos < 0) {
    std::cout << method << ": Out of scope" << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

// Public
IDll::IDll() {
  this->n = 0;
  this->head = new INode();
  this->head->next = NULL;
  this->head->prev = NULL;
}

int IDll::getLength() { return this->n; }

int IDll::getItem(int pos) {
  checkBounds(pos, __FUNCTION__);

  INode *curr = this->head;

  for (int i = 0; i <= pos; i++) {
    curr = curr->next;
  }

  return curr->item;
}

int IDll::getMax() {

  INode *curr = this->head;
  int max = 0;

  while (curr != NULL) {
    if (curr->item > max)
      max = curr->item;
    curr = curr->next;
  }

  return max;
}

int IDll::find(int value) {
  INode *curr = this->head;
  int pos = 0;

  while (curr != NULL) {
    if (curr->item == value)
      return pos;
    curr = curr->next;
    pos++;
  }

  return -1;
}
// EOF
