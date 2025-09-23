// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static TSet FAKE_SET(1);

TSet::TSet(int mp) : BitField(mp)
{
    MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
    MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
    MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    return BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    return BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if (MaxPower != s.MaxPower) return 0;
    return BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    if(BitField == s.BitField) return 0;
    return 1;
}

TSet TSet::operator+(const TSet &s) // объединение
{
    return BitField | s.BitField;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet temp(*this);
    temp.BitField.SetBit(Elem);
    return temp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet temp(*this);
    temp.BitField.ClrBit(Elem);
    return temp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    return BitField & s.BitField;;
}

TSet TSet::operator~(void) // дополнение
{
    return ~BitField;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    return ostr;
}
