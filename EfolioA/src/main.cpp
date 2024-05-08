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

#include <iostream>
#include <istream>
#include <sstream>
#include <string>

#include "idll.h"

using namespace std;

void outOfBoundsWarn(string cmd)
{
    cout << "Comando " << cmd << ": Posicao invalida!\n";
}

void emptyListWarn(string cmd)
{
    cout << "Comando " << cmd << ": Lista vazia!\n";
}

bool isComment(string str)
{
    return str.begin().base()[0] == '#';
}

bool verifyCmd(string inputCmd, const char *cmd)
{
    if (inputCmd.compare(cmd) != 0)
        return false;
    return true;
}

int main()
{
    IDll list;
    string line;
    string cmd;
    int arg;

    while (getline(cin, line))
    {
        // Ignora linhas vazias
        cin >> ws;

        // Ignora comentarios
        if (isComment(line))
            continue;

        stringstream cmdStream(line);
        cmdStream >> cmd;

        if (verifyCmd(cmd, "insert_0"))
        {
            while (cmdStream >> arg)
                list.insertBegin(arg);
        }
        else if (verifyCmd(cmd, "insert_end"))
        {
            while (cmdStream >> arg)
                list.insertEnd(arg);
        }
        else if (verifyCmd(cmd, "print_0"))
        {
            if (list.getLength() == 0)
                emptyListWarn(cmd);
            else
                list.printBegin();
        }
        else if (verifyCmd(cmd, "print_end"))
        {
            if (list.getLength() == 0)
                emptyListWarn(cmd);
            else
                list.printEnd();
        }
        else if (verifyCmd(cmd, "print"))
        {
            if (list.getLength() == 0)
                emptyListWarn(cmd);
            else
                list.printList();
        }
        else if (verifyCmd(cmd, "delete_0"))
        {
            if (list.getLength() == 0)
                emptyListWarn(cmd);
            else
                list.delBegin();
        }
        else if (verifyCmd(cmd, "delete_end"))
        {
            list.delEnd();
        }
        else if (verifyCmd(cmd, "dim"))
        {
            int length = list.getLength();
            cout << "Lista tem " << length << " itens" << endl;
        }
        else if (verifyCmd(cmd, "clear"))
        {
            if (list.getLength() == 0)
                emptyListWarn(cmd);
            else
                list.clear();
        }
        else if (verifyCmd(cmd, "find"))
        {
            cmdStream >> arg;
            int pos = list.find(arg);
            if (pos >= 0)
                cout << "Item " << arg << " na posicao " << pos << endl;
            else
                cout << "Item " << arg << " nao encontrado!" << endl;
        }
        else if (verifyCmd(cmd, "find_max"))
        {
            int maxValue;
            if (!list.getMax(&maxValue))
            {
                cout << "Lista Vazia" << endl;
                continue;
            }

            int pos = list.find(maxValue);
            cout << "Max Item " << maxValue << " na posicao " << pos << endl;
        }
        else if (verifyCmd(cmd, "delete_pos"))
        {
            while (cmdStream >> arg)
                if (list.del(arg))
                    outOfBoundsWarn(cmd);
        }
        else if (verifyCmd(cmd, "invert_range"))
        {
            int beginPos, endPos;
            cmdStream >> beginPos >> endPos;

            if (list.invertRange(beginPos, endPos))
                outOfBoundsWarn(cmd);
        }
        else
        {
            cout << "Invalid command: " << line << endl;
        }
    }
    return 0;
}

// EOF
