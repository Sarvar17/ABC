//------------------------------------------------------------------------------
// functional.cpp - �������� ������� ��������� ��� ����������� ��
//------------------------------------------------------------------------------

#include "functional.h"
#include "constants.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// ���� ���������� �� �� ������
void functional::In(std::ifstream& ifst) {
    ifst >> this->name >> this->tiobeRating >> this->releaseYear;
    bool isDynamicTyping, supportLazyCalculations;
    ifst >> isDynamicTyping >> supportLazyCalculations;
    this->t = isDynamicTyping ? functional::typing::DYNAMIC : functional::typing::STATIC;
    this->supportLazyCalculations = supportLazyCalculations;
}

// ��������� ���� ���������� ������������ ��
void functional::InRnd() {
    for (size_t i = 0; i < MAX_NAME_LEN; ++i) {
        this->name[i] = char('a' + Random());
    }
    this->name[MAX_NAME_LEN - 1] = '\0';
    this->tiobeRating = Random() + Random() / 100.0;
    this->releaseYear = MIN_YEAR + Random();
    this->t = Random() % 2 ? functional::typing::DYNAMIC : functional::typing::STATIC;
    this->supportLazyCalculations = Random() % 2;
}

//------------------------------------------------------------------------------
// ����� ���������� ������������ �� � ������������� �����
void functional::Out(std::ofstream& ofst) {
    ofst << "It is Functional language: name = "
        << this->name << " (" << this->tiobeRating << "% | " << this->releaseYear <<
        "), typing = " <<
        (this->t ? "DYNAMIC" : "STATIC") <<
        ", lazy calculations = " << (this->supportLazyCalculations ? "true" : "false") <<
        ". year / name.size() = " << this->YearDividedByNameLength() << "\n";
}

//------------------------------------------------------------------------------
// ���������� �������� �� ������� ���� �������� �� ����������
// �������� � �������� (�������������� �����)
double functional::YearDividedByNameLength() {
    return this->releaseYear / double(strlen(this->name));
}