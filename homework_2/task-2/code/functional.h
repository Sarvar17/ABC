#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - �������� �������� ��������������� ��
//------------------------------------------------------------------------------

#include <fstream>
#include "constants.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// �������������� ��
class functional : public language {
public:
    // ���, ����������� ������� ��� ��������� �����������
    char name[MAX_NAME_LEN];
    // ��� �������� �����
    int releaseYear;
    // ������������ � ��������� (TIOBE)
    double tiobeRating;
    // ���������: �����������, ������������
    enum typing { STATIC, DYNAMIC };
    typing t;
    // ��������� ��������� ����������
    bool supportLazyCalculations;

    // ���� ���������� ��������������� �� �� �����
    virtual void In(std::ifstream& ifst);

    // ��������� ���� ���������� ��������������� ��
    virtual void InRnd();

    // ����� ���������� ��������������� �� � ������������� �����
    virtual void Out(std::ofstream& ofst);

    // ���������� �������� �� ������� ���� �������� �� ����������
    // �������� � �������� (�������������� �����)
    virtual double YearDividedByNameLength();
};

#endif //__functional__