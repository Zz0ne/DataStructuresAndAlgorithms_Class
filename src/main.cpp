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
#include <sstream>
#include <string>

using namespace std;

bool isComment(string str) { return str.begin().base()[0] == '#'; }

bool findCmd(string inputCmd, const char *cmd) {
  if (inputCmd.find(cmd) == string::npos) {
    return false;
  }
  return true;
}

int main() {
  string line;
  string cmd;
  int arg;

  while (getline(cin, line)) {

    // Ignora linhas vazias
    cin >> ws;

    // Ignora comentarios
    if (isComment(line))
      continue;

    stringstream cmdStream(line);
    cmdStream >> cmd;

    if (findCmd(cmd, "insert_0")) {

      while (cmdStream >> arg) {
        cout << arg << endl;
      }

    } else if (findCmd(cmd, "insert_end")) {

      while (cmdStream >> arg) {
        cout << arg << endl;
      }

    } else if (findCmd(cmd, "print_0")) {
      cout << "print_0" << endl;
    } else if (findCmd(cmd, "print_end")) {
      cout << "print_end" << endl;
    } else if (findCmd(cmd, "print")) {
      cout << "print" << endl;
    } else if (findCmd(cmd, "delete_0")) {
      cout << "delete_0" << endl;
    } else if (findCmd(cmd, "delete_end")) {
      cout << "delete_end" << endl;
    } else if (findCmd(cmd, "dim")) {
      cout << "dim" << endl;
    } else if (findCmd(cmd, "clear")) {
      cout << "clear" << endl;
    } else if (findCmd(cmd, "find")) {

      while (cmdStream >> arg) {
        cout << arg << endl;
      }

    } else if (findCmd(cmd, "find_max")) {
      cout << "find_max" << endl;
    } else if (findCmd(cmd, "delete_pos")) {

      while (cmdStream >> arg) {
        cout << arg << endl;
      }

    } else if (findCmd(cmd, "invert_range")) {

      while (cmdStream >> arg) {
        cout << arg << endl;
      }

    } else {
      cout << "Invalid command: " << line << endl;
    }
  }

  return 0;
}

// EOF
