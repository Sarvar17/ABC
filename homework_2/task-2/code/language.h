#ifndef __language__
#define __language__

//------------------------------------------------------------------------------
// programming_language.h - �������� �������� ����������� ����� ���������������� (��),
//------------------------------------------------------------------------------

#include <iostream>

#include "procedure.h"
#include "oop.h"
#include "functional.h"

//------------------------------------------------------------------------------
// �����, ���������� ��� ��������� ��
class language {
public:
    // ���� ����������� ��
    static language* In(std::ifstream& ifdt);

    // ��������� ���� ����������� ��
    virtual language* InRnd();

    // ����� ����������� ��
    virtual void Out(std::ofstream& ofst);

    // ���������� �������� �� ������� ���� �������� �� ����������
    // �������� � �������� (�������������� �����)
    virtual double YearDividedByNameLength();
};

#endif