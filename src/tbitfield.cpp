// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"


TBitField::TBitField(int len)
{
    if (len <= 0) throw - 1;
    BitLen = len;
    MemLen = (BitLen + (count_bits - 1)) / count_bits;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
    pMem = nullptr;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n > BitLen || n < 0) throw - 1;
    return n >> power_bits;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n > BitLen || n < 0) throw - 1;
    int bit_num = n & (count_bits - 1);
    return (1 << bit_num);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n > BitLen || n < 0) throw - 1;
    int index = GetMemIndex(n);
    pMem[index] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n > BitLen || n < 0) throw - 1;
    int index = GetMemIndex(n);
    pMem[index] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n > BitLen || n < 0) throw - 1;
    int index = GetMemIndex(n);
    int bit = pMem[index] & GetMemMask(n);
    if (bit) return 1;
    return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField& bf)
{
    if (this == &bf)
        return *this;
    delete[] pMem;
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i)
        pMem[i] = bf.pMem[i];
    return *this;
}


int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (bf.BitLen != BitLen)
        return 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i])
            return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    if (bf == *this)
        return 0;
    return 1;
}

TBitField TBitField::operator|(const TBitField& bf)  // операция "или"
{
    int maxBitLen = std::max(BitLen, bf.BitLen);
    int minMemLen = std::min(MemLen, bf.MemLen);
    int maxMemLen = std::max(MemLen, bf.MemLen);
    TBitField result(maxBitLen);

    for (int i = 0; i < minMemLen; i++)
        result.pMem[i] = pMem[i] | bf.pMem[i];

    for (int i = minMemLen; i < maxMemLen; i++)
        result.pMem[i] = BitLen > bf.BitLen ? pMem[i] : bf.pMem[i];

    return result;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int maxBitLen = std::max(BitLen, bf.BitLen);
    int minMemLen = std::min(MemLen, bf.MemLen);
    TBitField result(maxBitLen);

    for (int i = 0; i < minMemLen; i++)
        result.pMem[i] = pMem[i] & bf.pMem[i];

    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);

    for (int i = 0; i < MemLen - 1; i++) {
        res.pMem[i] = ~pMem[i];
    }
    TELEM lastMask = (GetMemMask(BitLen) - 1);
    res.pMem[MemLen - 1] = (~pMem[MemLen - 1]) & lastMask;

    return res;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    return ostr;
}
