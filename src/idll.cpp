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
bool IDll::checkBounds(int pos) {
  if (pos >= n || pos < 0) {
    return false;
  }
  return true;
}

// Public
IDll::IDll() {
  this->n = 0;
  this->head = NULL;
}

int IDll::getLength() { return this->n; }

bool IDll::getItem(int pos, int *item) {
  if (checkBounds(pos)) {
    return false;
  }

  INode *curr = this->head;

  for (int i = 0; i <= pos; i++) {
    curr = curr->next;
  }

  *item = curr->item;
  return true;
}

bool IDll::getMax(int *max) {

  if (this->n == 0) {
    return false;
  }

  INode *curr = this->head;
  *max = curr->item;

  while (curr != NULL) {
    if (curr->item > *max)
      *max = curr->item;
    curr = curr->next;
  }

  return true;
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

bool IDll::del(int pos) {
  if (this->checkBounds(pos)) {
    return false;
  }

  if (pos == 0) {
    this->delBegin();
    return true;
  }

  if (pos == this->n) {
    this->delEnd();
    return true;
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

  return true;
}

bool IDll::delBegin() {
  if (this->n == 0) {
    return false;
  }

  INode *toDelete = this->head;
  this->head = toDelete->next;

  delete toDelete;
  toDelete = NULL;

  this->n--;

  if (n) {
    this->head->prev = NULL;
  }

  return true;
}

bool IDll::delEnd() {
  if (this->n == 0) {
    return false;
  }

  // Se a lista tiver apenas 1 elemento
  if (this->n == 1) {
    delete this->head;
    this->head = NULL;
    return true;
  }

  INode *toDelete = this->head;

  while (toDelete->next != NULL) {
    toDelete = toDelete->next;
  }

  INode *newLast = toDelete->prev;
  newLast->next = NULL;
  delete toDelete;

  this->n--;
  return true;
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

void IDll::printList() {
  INode *curr = this->head;

  std::cout << "Lista:";

  while (curr != NULL) {
    std::cout << " " << curr->item;
  }

  std::cout << std::endl;
}

bool IDll::printItem(int pos) {
  int item;
  if (this->getItem(pos, &item)) {
    std::cout << "Lista(" << pos << "): " << item << std::endl;
    return true;
  }
  return false;
}
// EOF
