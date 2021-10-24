//------------------------------------------------------------------------------
// container.cpp - �������� ������� ��������� ����������
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// ������������� ����������
void container::Init() {
    this->len = 0;
}

//------------------------------------------------------------------------------
// ������� ���������� �� ��������� (������������ ������)
void container::Clear() {
    for (int i = 0; i < this->len; i++) {
        delete this->cont[i];
    }
    this->len = 0;
}

//------------------------------------------------------------------------------
// ���� ����������� ���������� �� ���������� ������
void container::In(std::ifstream& ifst) {
    language lang;
    while (!ifst.eof()) {
        if ((this->cont[this->len] = lang.In(ifst)) != 0) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// ��������� ���� ����������� ����������
void container::InRnd(int size) {
    language lang;
    while (this->len < size) {
        if ((this->cont[this->len] = lang.InRnd()) != nullptr) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// ����� ����������� ���������� � ��������� �����
void container::Out(std::ofstream& ofst) {
    ofst << "Container contains " << this->len << " elements.\n";
    for (int i = 0; i < this->len; i++) {
        ofst << i << ": ";
        this->cont[i].Out(ofst);
    }
}

// ���������� ���������� ������� Straight Selection
void container::sort() {
    int i = 0, j, k;
    language* temp;
    while (i < this->len) {
        k = i;
        for (j = i + 1; j < this->len; j++) {
            if (this->cont[j].YearDividedByNameLength() > this->cont[k].YearDividedByNameLength()) {
                k = j;
            }
        }
        temp = this->cont[i];
        this->cont[i] = this->cont[k];
        this->cont[k] = temp;
        i++;
    }
}