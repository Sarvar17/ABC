//------------------------------------------------------------------------------
// main.cpp - �������� ������� �������,
// �������������� ������� ������������
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime>   // ��� ������� time()
#include <cstring>

#include "container.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {

    std::cout << "Start\n";
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of figures = "
                << size
                << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // ��������� ���� � �������� ��������������
        srand(static_cast<unsigned int>(time(0)));
        // ���������� ���������� ����������� ��������� �����
        InRnd(c, size);
    }

    // ����� ����������� ���������� � ����
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    // The 2nd part of task
    sort(c);
    std::ofstream ofst2(argv[4]);
    ofst2 << "Sorted container:\n";
    Out(c, ofst2);

    Clear(c);
    std::cout << "Stop\n";
    return 0;
}