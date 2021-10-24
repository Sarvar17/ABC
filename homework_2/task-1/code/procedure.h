#ifndef __procedure__
#define __procedure__

//------------------------------------------------------------------------------
// procedure.h - �������� �������� ��������������� ��
//------------------------------------------------------------------------------

#include <fstream>
#include "constants.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// ����������� ��
class procedure : public language {
public:
    // ���, ����������� ������� ��� ��������� �����������
    char name[MAX_NAME_LEN];
    // ��� �������� �����
    int releaseYear;
    // ������������ � ��������� (TIOBE)
    double tiobeRating;
    // ���� ��������� ����������� ����� ������
    bool supportAbstractTypes;

    // ���� ���������� ������������ �� �� �����
    virtual void In(std::ifstream& ifst);

    // ��������� ���� ���������� ������������ ��
    virtual procedure* InRnd();

    // ����� ���������� ������������ �� � ������������� �����
    virtual void Out(std::ofstream& ofst);

    // ���������� �������� �� ������� ���� �������� �� ����������
    // �������� � �������� (�������������� �����)
    virtual double YearDividedByNameLength();
};

#endif //__procedure__