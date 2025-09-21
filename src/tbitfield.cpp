// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

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
    return n / count_bits;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n > BitLen || n < 0) throw - 1;
    int bit_num = n % count_bits;
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
    int maxLen = std::max(BitLen, bf.BitLen);
    TBitField res(maxLen);

    // копируем биты обоих операндов в результат
    for (int i = 0; i < res.MemLen; ++i)
    {
        TELEM left = (i < MemLen) ? pMem[i] : 0;
        TELEM right = (i < bf.MemLen) ? bf.pMem[i] : 0;
        res.pMem[i] = left | right;
    }
    return res;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int maxLen = std::max(BitLen, bf.BitLen);
    TBitField res(maxLen);

    for (int i = 0; i < res.MemLen; ++i)
    {
        TELEM left = (i < MemLen) ? pMem[i] : 0;
        TELEM right = (i < bf.MemLen) ? bf.pMem[i] : 0;
        res.pMem[i] = left & right;
    }
    return res;
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
