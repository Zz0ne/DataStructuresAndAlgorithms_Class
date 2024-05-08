
/*
** file: main-maxh.cpp
**
** max Heap (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-fólio B 2023-24
**
** Aluno: 2201022 - Nuno Rodrigues
*/

// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais!

#include "maxh.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

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
    IMAXH maxheap; // exemplo
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

        try
        {
            if (verifyCmd(cmd, "insert"))
            {
                while (cmdStream >> arg)
                    maxheap.insert(arg);
            }
            else if (verifyCmd(cmd, "print_max"))
            {
                cout << "Max=" << maxheap.getMax() << endl;
            }
            else if (verifyCmd(cmd, "print"))
            {
                cout << "Heap=\n" << maxheap << endl;
            }
            else if (verifyCmd(cmd, "dim"))
            {
                cout << "Heap tem " << maxheap.getDimension() << "itens" << endl;
            }
            else if (verifyCmd(cmd, "dim_max"))
            {
                cout << "Heap tem capacidade" << maxheap.getCapacity() << "itens" << endl;
            }
            else if (verifyCmd(cmd, "clear"))
            {
                maxheap.clear();
            }
            else if (verifyCmd(cmd, "delete"))
            {
                maxheap.deleteMax();
            }
            else if (verifyCmd(cmd, "heapify_up"))
            {
                int *arr = new int[maxheap.getDimension()];

                for (int i = 0; cmdStream >> arg; i++)
                    arr[i] = arg;
                maxheap.heapifyUp(arr);

                delete[] arr;
            }
            else if (verifyCmd(cmd, "redim_max"))
            {
                int newCapacity;
                cmdStream >> newCapacity;
                maxheap.setCapacity(newCapacity);
            }
            else
            {
                cout << "Comando desconhecido" << endl;
            }
        }
        catch (IMAXH::EmptyHeapError &e)
        {
            cout << "Comando: " + cmd + " " << e.what() << endl;
        }
        catch (IMAXH::FullHeapError &e)
        {
            cout << "Comando: " + cmd + " " << e.what() << endl;
        }
    }
    return 0;
}

// EOF
