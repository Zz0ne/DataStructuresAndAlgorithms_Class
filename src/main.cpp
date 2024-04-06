/*
** file: main-idll.cpp
**
** Integer Double Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2023-24
**
** Aluno: 2201022 - Nuno Rodrigues
*/

// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais!

#include "idll.h"
#include <iostream>
#include <istream>
#include <string>
using namespace std;

bool isComment(string str) { return str.begin().base()[0] == '#'; }

int main() {
  string command;

  while (getline(cin, command)) {

    // Remove linhas em branco
    cin >> ws;

    // Ignora comentarios
    if (isComment(command))
      continue;

    cout << command << endl;
  }

  return 0;
}

// EOF
