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
#include <climits>
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
  this->head = NULL;
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
  if (this->n == 0) {
    std::cout << "Empty list" << std::endl;
    return INT_MIN;
  }

  INode *curr = this->head;
  int max = curr->item;

  while (curr != NULL) {
    if (curr->item > max)
      max = curr->item;
    curr = curr->next;
  }

  return max;
}

void IDll::insertBegin(int value) {
  INode *newData = new INode;
  newData->item = value;

  if (this->head == NULL) {
    this->head = newData;
    return;
  }

  newData->next = this->head;
  this->head->prev = newData;

  this->head = newData;
  newData->prev = NULL;

  this->n++;
}

void IDll::insertEnd(int value) {
  INode *newData = new INode;
  newData->item = value;
  newData->next = NULL;

  if (this->head == NULL) {
    this->head = newData;
    return;
  }

  INode *curr = this->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = newData;
  newData->prev = curr;
  this->n++;
}

void IDll::del(int pos) {
  this->checkBounds(pos, __FUNCTION__);

  if (pos == 0) {
    this->delBegin();
    return;
  } else if (pos == this->n) {
    this->delEnd();
    return;
  }

  INode *toDelete = this->head;
  for (int i = 0; i < pos; i++) {
    toDelete = toDelete->next;
  }

  INode *before = toDelete->prev;
  INode *after = toDelete->next;

  before->next = after;
  after->prev = before;

  delete toDelete;
  toDelete = NULL;

  this->n--;
}

void IDll::delBegin() {
  if (this->n == 0) {
    std::cout << "List is empty" << std::endl;
    return;
  }

  INode *toDelete = this->head;
  this->head = toDelete->next;

  delete toDelete;
  toDelete = NULL;

  this->n--;
}

void IDll::delEnd() {
  if (this->n == 0) {
    std::cout << "List is empty" << std::endl;
    return;
  }

  INode *toDelete = this->head;

  while (toDelete->next != NULL) {
    toDelete = toDelete->next;
  }

  INode *newLast = toDelete->prev;
  newLast->next = NULL;

  delete toDelete;
  toDelete = NULL;

  this->n--;
}

void IDll::clear() {
  INode *toDelete = this->head;

  while (toDelete != NULL) {
    toDelete = toDelete->next;
    delete toDelete->prev;
  }

  this->head = NULL;
  this->n = 0;
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
