#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;
/*
 * InfInt - Arbitrary-Precision Integer Arithmetic Library
 * Copyright (C) 2013 Sercan Tutar
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *
 * USAGE:
 *   It is pretty straight forward to use the library. Just create an instance of
 *   InfInt class and start using it.
 *
 *   Useful methods:
 *      intSqrt:        integer square root operation
 *      digitAt:        returns digit at index
 *      numberOfDigits: returns number of digits
 *      size:           returns size in bytes
 *      toString:       converts it to a string
 *
 *   There are also conversion methods which allow conversion to primitive types:
 *   toInt, toLong, toLongLong, toUnsignedInt, toUnsignedLong, toUnsignedLongLong.
 *
 *   You may define INFINT_USE_EXCEPTIONS and library methods will start raising
 *   InfIntException in case of error instead of writing error messages using
 *   std::cerr.
 *
 *   See ReadMe.txt for more info.
 *
 *
 * No overflows, happy programmers!
 *
 */

#ifndef INFINT_H_
#define INFINT_H_

//#include "Profiler.h"

#ifdef _WIN32
#define LONG_LONG_MIN LLONG_MIN
#define LONG_LONG_MAX LLONG_MAX
#define ULONG_LONG_MIN ULLONG_MIN
#define ULONG_LONG_MAX ULLONG_MAX
#endif

//#define INFINT_USE_EXCEPTIONS
//#define INFINT_USE_SHORT_BASE

#ifdef INFINT_USE_EXCEPTIONS
#include <exception>
#endif

//inline bool check_pos(int n)
//{
//    return n >= 0;
//}
//inline bool check_neg(int n)
//{
//    return n <= 0;
//}

#ifdef INFINT_USE_SHORT_BASE // uses 10^4 (short) as the base
typedef short ELEM_TYPE;
typedef int PRODUCT_TYPE;
static const ELEM_TYPE BASE = 10000;
static const ELEM_TYPE UPPER_BOUND = 9999;
static const ELEM_TYPE DIGIT_COUNT = 4;
static const int powersOfTen[] = { 1, 10, 100, 1000};
#else // uses 10^9 (int) as the base
typedef int ELEM_TYPE;
typedef long long PRODUCT_TYPE;
static const ELEM_TYPE BASE = 1000000000;
static const ELEM_TYPE UPPER_BOUND = 999999999;
static const ELEM_TYPE DIGIT_COUNT = 9;
static const int powersOfTen[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
#endif

#ifdef INFINT_USE_EXCEPTIONS
class InfIntException: public std::exception
{
public:
    InfIntException(const std::string& txt) throw ();
    ~InfIntException() throw ();
    const char* what() const throw ();
private:
    std::string txt;
};

InfIntException::InfIntException(const std::string& txt) throw () :
std::exception(), txt(txt)
{
}

InfIntException::~InfIntException() throw ()
{
}

const char* InfIntException::what() const throw ()
{
    return txt.c_str();
}
#endif

class InfInt
{
    friend std::ostream& operator<<(std::ostream &s, const InfInt &n);
    friend std::istream& operator>>(std::istream &s, InfInt &val);

public:
    /* some constants */
    static const InfInt zero;
    static const InfInt one;
    static const InfInt two;

    /* constructors */
    InfInt();
    InfInt(const char* c);
    InfInt(const std::string& s);
    InfInt(int l);
    InfInt(long l);
    InfInt(long long l);
    InfInt(unsigned int l);
    InfInt(unsigned long l);
    InfInt(unsigned long long l);

    /* assignment operators */
    const InfInt& operator=(const char* c);
    const InfInt& operator=(const std::string& s);
    const InfInt& operator=(int l);
    const InfInt& operator=(long l);
    const InfInt& operator=(long long l);
    const InfInt& operator=(unsigned int l);
    const InfInt& operator=(unsigned long l);
    const InfInt& operator=(unsigned long long l);

    /* unary increment/decrement operators */
    const InfInt& operator++();
    const InfInt& operator--();
    InfInt operator++(int);
    InfInt operator--(int);

    /* operational assignments */
    const InfInt& operator+=(const InfInt& rhs);
    const InfInt& operator-=(const InfInt& rhs);
    const InfInt& operator*=(const InfInt& rhs);
    const InfInt& operator/=(const InfInt& rhs); // throw
    const InfInt& operator%=(const InfInt& rhs); // throw
    const InfInt& operator*=(ELEM_TYPE rhs);

    /* operations */
    InfInt operator-() const;
    InfInt operator+(const InfInt& rhs) const;
    InfInt operator-(const InfInt& rhs) const;
    InfInt operator*(const InfInt& rhs) const;
    InfInt operator/(const InfInt& rhs) const; // throw
    InfInt operator%(const InfInt& rhs) const; // throw
    InfInt operator*(ELEM_TYPE rhs) const;

    /* relational operations */
    bool operator==(const InfInt& rhs) const;
    bool operator!=(const InfInt& rhs) const;
    bool operator<(const InfInt& rhs) const;
    bool operator<=(const InfInt& rhs) const;
    bool operator>(const InfInt& rhs) const;
    bool operator>=(const InfInt& rhs) const;

    /* integer square root */
    InfInt intSqrt() const; // throw

    /* digit operations */
    char digitAt(size_t i) const; // throw
    size_t numberOfDigits() const;

    /* size in bytes */
    size_t size() const;

    /* string conversion */
    std::string toString() const;

    /* conversion to primitive types */
    int toInt() const; // throw
    long toLong() const; // throw
    long long toLongLong() const; // throw
    unsigned int toUnsignedInt() const; // throw
    unsigned long toUnsignedLong() const; // throw
    unsigned long long toUnsignedLongLong() const; // throw

private:
    static ELEM_TYPE dInR(const InfInt& R, const InfInt& D);
    static void multiplyByDigit(ELEM_TYPE factor, std::vector<ELEM_TYPE>& val);

    void correct(bool justCheckLeadingZeros = false, bool hasValidSign = false);
    void fromString(const std::string& s);
    void optimizeSqrtSearchBounds(InfInt& lo, InfInt& hi) const;
    void truncateToBase();
    bool equalizeSigns();
    void removeLeadingZeros();

    std::vector<ELEM_TYPE> val; // number with base FACTOR
    bool pos; // true if number is positive
};

const InfInt InfInt::zero = 0;
const InfInt InfInt::one = 1;
const InfInt InfInt::two = 2;

inline InfInt::InfInt() : pos(true)
{
    val.push_back((ELEM_TYPE) 0);
}

inline InfInt::InfInt(const char* c)
{
    fromString(c);
}

inline InfInt::InfInt(const std::string& s)
{
    fromString(s);
}

inline InfInt::InfInt(int l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
        div_t dt = div(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
}

inline InfInt::InfInt(long l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
        ldiv_t dt = ldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
}

inline InfInt::InfInt(long long l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
#ifndef _WIN32
        lldiv_t dt = lldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
#else
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
#endif
    } while (l > 0);
}

inline InfInt::InfInt(unsigned int l) : pos(true)
{
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline InfInt::InfInt(unsigned long l) : pos(true)
{
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline InfInt::InfInt(unsigned long long l) : pos(true)
{
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline const InfInt& InfInt::operator=(const char* c)
{
    fromString(c);
    return *this;
}

inline const InfInt& InfInt::operator=(const std::string& s)
{
    fromString(s);
    return *this;
}

inline const InfInt& InfInt::operator=(int l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
        div_t dt = div(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(long l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
        ldiv_t dt = ldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(long long l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
#ifndef _WIN32
        lldiv_t dt = lldiv(l, BASE);
        val.push_back((ELEM_TYPE) dt.rem);
        l = dt.quot;
#else
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
#endif
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned int l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned long l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned long long l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((ELEM_TYPE) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator++()
{
    val[0] += (pos ? 1 : -1);
    this->correct(false, true);
    return *this;
}

inline const InfInt& InfInt::operator--()
{
    val[0] -= (pos ? 1 : -1);
    this->correct(false, true);
    return *this;
}

inline InfInt InfInt::operator++(int)
{
    InfInt result = *this;
    val[0] += (pos ? 1 : -1);
    this->correct(false, true);
    return result;
}

inline InfInt InfInt::operator--(int)
{
    InfInt result = *this;
    val[0] -= (pos ? 1 : -1);
    this->correct(false, true);
    return result;
}

inline const InfInt& InfInt::operator+=(const InfInt& rhs)
{
    if (rhs.val.size() > val.size())
    {
        val.resize(rhs.val.size(), 0);
    }
    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = (pos ? val[i] : -val[i]) + (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    correct();
    return *this;
}

inline const InfInt& InfInt::operator-=(const InfInt& rhs)
{
    if (rhs.val.size() > val.size())
    {
        val.resize(rhs.val.size(), 0);
    }
    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = (pos ? val[i] : -val[i]) - (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    correct();
    return *this;
}

inline const InfInt& InfInt::operator*=(const InfInt& rhs)
{
    // TODO: optimize (do not use operator*)
    *this = *this * rhs;
    return *this;
}

inline const InfInt& InfInt::operator/=(const InfInt& rhs)
{
    if (rhs == zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("division by zero");
#else
        std::cerr << "Division by zero!" << std::endl;
        return *this;
#endif
    }
    InfInt R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    bool oldpos = pos;
    val.clear();
    val.resize(N.val.size(), 0);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        R.val.insert(R.val.begin(), (ELEM_TYPE) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        ELEM_TYPE cnt = dInR(R, D);
        R -= D * cnt;
        val[i] += cnt;
    }
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : (oldpos == rhs.pos);
    return *this;
}

inline const InfInt& InfInt::operator%=(const InfInt& rhs)
{
    if (rhs == zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("division by zero");
#else
        std::cerr << "Division by zero!" << std::endl;
        return zero;
#endif
    }
    InfInt D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    bool oldpos = pos;
    val.clear();
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        val.insert(val.begin(), (ELEM_TYPE) 0);
        val[0] = N.val[i];
        correct(true);
        *this -= D * dInR(*this, D);
    }
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : oldpos;
    return *this;
}

inline const InfInt& InfInt::operator*=(ELEM_TYPE rhs)
{
    ELEM_TYPE factor = rhs < 0 ? -rhs : rhs;
    bool oldpos = pos;
    multiplyByDigit(factor, val);
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : (oldpos == (rhs >= 0));
    return *this;
}

inline InfInt InfInt::operator-() const
{//PROFILED_SCOPE
    InfInt result = *this;
    result.pos = !pos;
    return result;
}

inline InfInt InfInt::operator+(const InfInt& rhs) const
{//PROFILED_SCOPE
    InfInt result;
    result.val.resize(val.size() > rhs.val.size() ? val.size() : rhs.val.size(), 0);
    for (size_t i = 0; i < val.size() || i < rhs.val.size(); ++i)
    {
        result.val[i] = (i < val.size() ? (pos ? val[i] : -val[i]) : 0) + (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    result.correct();
    return result;
}

inline InfInt InfInt::operator-(const InfInt& rhs) const
{//PROFILED_SCOPE
    InfInt result;
    result.val.resize(val.size() > rhs.val.size() ? val.size() : rhs.val.size(), 0);
    for (size_t i = 0; i < val.size() || i < rhs.val.size(); ++i)
    {
        result.val[i] = (i < val.size() ? (pos ? val[i] : -val[i]) : 0) - (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    result.correct();
    return result;
}

inline InfInt InfInt::operator*(const InfInt& rhs) const
{//PROFILED_SCOPE
    InfInt result;
    result.val.resize(val.size() + rhs.val.size(), 0);
    PRODUCT_TYPE carry = 0;
    size_t digit = 0;
    for (;; ++digit)
    {//PROFILED_SCOPE
        //result.val[digit] = (ELEM_TYPE) (carry % BASE);
        //carry /= BASE;

        PRODUCT_TYPE oldcarry = carry;
        carry /= BASE;
        result.val[digit] = (ELEM_TYPE) (oldcarry - carry * BASE);

        bool found = false;
        for (size_t i = digit < rhs.val.size() ? 0 : digit - rhs.val.size() + 1; i < val.size() && i <= digit; ++i)
        {//PROFILED_SCOPE
            PRODUCT_TYPE pval = result.val[digit] + val[i] * (PRODUCT_TYPE) rhs.val[digit - i];
            if (pval >= BASE || pval <= -BASE)
            {//PROFILED_SCOPE
                //carry += pval / BASE;
                //pval %= BASE;

                PRODUCT_TYPE quot = pval / BASE;
                carry += quot;
                pval -= quot * BASE;
            }
            result.val[digit] = (ELEM_TYPE) pval;
            found = true;
        }
        if (!found)
        {//PROFILED_SCOPE
            break;
        }
    }
    for (; carry > 0; ++digit)
    {//PROFILED_SCOPE
        result.val[digit] = (ELEM_TYPE) (carry % BASE);
        carry /= BASE;
    }
    result.correct();
    result.pos = (result.val.size() == 1 && result.val[0] == 0) ? true : (pos == rhs.pos);
    return result;
}

inline InfInt InfInt::operator/(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (rhs == zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("division by zero");
#else
        std::cerr << "Division by zero!" << std::endl;
        return zero;
#endif
    }
    InfInt Q, R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    Q.val.resize(N.val.size(), 0);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {//PROFILED_SCOPE
        R.val.insert(R.val.begin(), (ELEM_TYPE) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        ELEM_TYPE cnt = dInR(R, D);
        R -= D * cnt;
        Q.val[i] += cnt;
    }
    Q.correct();
    Q.pos = (Q.val.size() == 1 && Q.val[0] == 0) ? true : (pos == rhs.pos);
    return Q;
}

inline InfInt InfInt::operator%(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (rhs == zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("division by zero");
#else
        std::cerr << "Division by zero!" << std::endl;
        return zero;
#endif
    }
    InfInt R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        R.val.insert(R.val.begin(), (ELEM_TYPE) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        R -= D * dInR(R, D);
    }
    R.correct();
    R.pos = (R.val.size() == 1 && R.val[0] == 0) ? true : pos;
    return R;
}

inline InfInt InfInt::operator*(ELEM_TYPE rhs) const
{//PROFILED_SCOPE
    InfInt result = *this;
    ELEM_TYPE factor = rhs < 0 ? -rhs : rhs;
    multiplyByDigit(factor, result.val);
    result.correct();
    result.pos = (result.val.size() == 1 && result.val[0] == 0) ? true : (pos == (rhs >= 0));
    return result;
}

inline bool InfInt::operator==(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos != rhs.pos || val.size() != rhs.val.size())
    {
        return false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] != rhs.val[i])
        {
            return false;
        }
    }
    return true;
}

inline bool InfInt::operator!=(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos != rhs.pos || val.size() != rhs.val.size())
    {
        return true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] != rhs.val[i])
        {
            return true;
        }
    }
    return false;
}

inline bool InfInt::operator<(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos && !rhs.pos)
    {
        return false;
    }
    if (!pos && rhs.pos)
    {
        return true;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? false : true;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? true : false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? true : false;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? false : true;
        }
    }
    return false;
}

inline bool InfInt::operator<=(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos && !rhs.pos)
    {
        return false;
    }
    if (!pos && rhs.pos)
    {
        return true;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? false : true;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? true : false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? true : false;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? false : true;
        }
    }
    return true;
}

inline bool InfInt::operator>(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos && !rhs.pos)
    {
        return true;
    }
    if (!pos && rhs.pos)
    {
        return false;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? true : false;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? false : true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? false : true;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? true : false;
        }
    }
    return false;
}

inline bool InfInt::operator>=(const InfInt& rhs) const
{//PROFILED_SCOPE
    if (pos && !rhs.pos)
    {
        return true;
    }
    if (!pos && rhs.pos)
    {
        return false;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? true : false;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? false : true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? false : true;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? true : false;
        }
    }
    return true;
}

inline void InfInt::optimizeSqrtSearchBounds(InfInt& lo, InfInt& hi) const
{//PROFILED_SCOPE
    InfInt hdn = one;
    for (int i = (int) this->numberOfDigits() / 2; i >= 2; --i)
    {
        hdn *= 10;
    }
    if (lo < hdn)
    {
        lo = hdn;
    }
    hdn *= 100;
    if (hi > hdn)
    {
        hi = hdn;
    }
}

inline InfInt InfInt::intSqrt() const
{//PROFILED_SCOPE
    if (*this <= zero)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("intSqrt called for non-positive integer");
#else
        std::cerr << "intSqrt called for non-positive integer: " << *this << std::endl;
        return zero;
#endif
    }
    InfInt hi = *this / two + one, lo = zero, mid, mid2;
    optimizeSqrtSearchBounds(lo, hi);
    do
    {
        mid = (hi + lo) / two; // 8 factor
        mid2 = mid * mid; // 1 factor
        if (mid2 == *this)
        {
            lo = mid;
            break;
        }
        else if (mid2 < *this)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    } while (lo < hi - one && mid2 != *this);
    return lo;
}

inline char InfInt::digitAt(size_t i) const
{//PROFILED_SCOPE
    if (numberOfDigits() <= i)
    {
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("invalid digit index");
#else
        std::cerr << "Invalid digit index: " << i << std::endl;
        return -1;
#endif
    }
    return (val[i / DIGIT_COUNT] / powersOfTen[i % DIGIT_COUNT]) % 10;
}

inline size_t InfInt::numberOfDigits() const
{//PROFILED_SCOPE
    return (val.size() - 1) * DIGIT_COUNT
#ifdef INFINT_USE_SHORT_BASE
    + (val.back() > 999 ? 4 : (val.back() > 99 ? 3 : (val.back() > 9 ? 2 : 1)));
#else
    + (val.back() > 99999999 ? 9 : (val.back() > 9999999 ? 8 : (val.back() > 999999 ? 7 : (val.back() > 99999 ? 6 :
                                                                                           (val.back() > 9999 ? 5 : (val.back() > 999 ? 4 : (val.back() > 99 ? 3 : (val.back() > 9 ? 2 : 1))))))));
#endif
}

inline std::string InfInt::toString() const
{//PROFILED_SCOPE
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

inline size_t InfInt::size() const
{//PROFILED_SCOPE
    return val.size() * sizeof(ELEM_TYPE) + sizeof(bool);
}

inline int InfInt::toInt() const
{//PROFILED_SCOPE
    if (*this > INT_MAX || *this < INT_MIN)
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("out of bounds");
#else
    std::cerr << "Out of INT bounds: " << *this << std::endl;
#endif
    int result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return pos ? result : -result;
}

inline long InfInt::toLong() const
{//PROFILED_SCOPE
    if (*this > LONG_MAX || *this < LONG_MIN)
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("out of bounds");
#else
    std::cerr << "Out of LONG bounds: " << *this << std::endl;
#endif
    long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return pos ? result : -result;
}

inline long long InfInt::toLongLong() const
{//PROFILED_SCOPE
    if (*this > LONG_LONG_MAX || *this < LONG_LONG_MIN)
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("out of bounds");
#else
    std::cerr << "Out of LLONG bounds: " << *this << std::endl;
#endif
    long long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return pos ? result : -result;
}

inline unsigned int InfInt::toUnsignedInt() const
{//PROFILED_SCOPE
    if (!pos || *this > UINT_MAX)
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("out of bounds");
#else
    std::cerr << "Out of UINT bounds: " << *this << std::endl;
#endif
    unsigned int result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return result;
}

inline unsigned long InfInt::toUnsignedLong() const
{//PROFILED_SCOPE
    if (!pos || *this > ULONG_MAX)
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("out of bounds");
#else
    std::cerr << "Out of ULONG bounds: " << *this << std::endl;
#endif
    unsigned long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return result;
}

inline unsigned long long InfInt::toUnsignedLongLong() const
{//PROFILED_SCOPE
    if (!pos || *this > ULONG_LONG_MAX)
#ifdef INFINT_USE_EXCEPTIONS
        throw InfIntException("out of bounds");
#else
    std::cerr << "Out of ULLONG bounds: " << *this << std::endl;
#endif
    unsigned long long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return result;
}

inline void InfInt::truncateToBase()
{//PROFILED_SCOPE
    for (size_t i = 0; i < val.size(); ++i) // truncate each
    {
        if (val[i] >= BASE || val[i] <= -BASE)
        {//PROFILED_SCOPE
            div_t dt = div(val[i], BASE);
            val[i] = dt.rem;
            if (i + 1 >= val.size())
            {//PROFILED_SCOPE
                val.push_back(dt.quot);
            }
            else
            {//PROFILED_SCOPE
                val[i + 1] += dt.quot;
            }
        }
    }
}

inline bool InfInt::equalizeSigns()
{//PROFILED_SCOPE
    bool isPositive = true;
    int i = (int) ((val.size())) - 1;
    for (; i >= 0; --i)
    {
        if (val[i] != 0)
        {
            isPositive = val[i--] > 0;
            break;
        }
    }

    if (isPositive)
    {
        for (; i >= 0; --i)
        {
            if (val[i] < 0)
            {
                int k = 0, index = i + 1;
                for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index); // count adjacent zeros on left
                //if ((size_t)(index) < val.size() && val[index] > 0)
                { // number on the left is positive
                    val[index] -= 1;
                    val[i] += BASE;
                    for (; k > 0; --k)
                    {
                        val[i + k] = UPPER_BOUND;
                    }
                }
            }
        }
    }
    else
    {
        for (; i >= 0; --i)
        {
            if (val[i] > 0)
            {
                int k = 0, index = i + 1;
                for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index); // count adjacent zeros on right
                //if ((size_t)(index) < val.size() && val[index] < 0)
                { // number on the left is negative
                    val[index] += 1;
                    val[i] -= BASE;
                    for (; k > 0; --k)
                    {
                        val[i + k] = -UPPER_BOUND;
                    }
                }
            }
        }
    }

    return isPositive;
}

inline void InfInt::removeLeadingZeros()
{//PROFILED_SCOPE
    for (int i = (int) (val.size()) - 1; i > 0; --i) // remove leading 0's
    {
        if (val[i] != 0)
        {
            return;
        }
        else
        {
            val.erase(val.begin() + i);
        }
    }
}

inline void InfInt::correct(bool justCheckLeadingZeros, bool hasValidSign)
{//PROFILED_SCOPE
    if (!justCheckLeadingZeros)
    {
        truncateToBase();

        if (equalizeSigns())
        {
            pos = ((val.size() == 1 && val[0] == 0) || !hasValidSign) ? true : pos;
        }
        else
        {
            pos = hasValidSign ? !pos : false;
            for (size_t i = 0; i < val.size(); ++i)
            {
                val[i] = abs(val[i]);
            }
        }
    }

    removeLeadingZeros();
}

inline void InfInt::fromString(const std::string& s)
{//PROFILED_SCOPE
    pos = true;
    val.clear();
    // TODO use resize
    val.reserve(s.size() / DIGIT_COUNT + 1);
    int i = (int) s.size() - DIGIT_COUNT;
    for (; i >= 0; i -= DIGIT_COUNT)
    {
        val.push_back(atoi(s.substr(i, DIGIT_COUNT).c_str()));
    }
    if (i > -DIGIT_COUNT)
    {
        std::string ss = s.substr(0, i + DIGIT_COUNT);
        if (ss.size() == 1 && ss[0] == '-')
        {
            pos = false;
        }
        else
        {
            val.push_back(atoi(ss.c_str()));
        }
    }
    if (val.back() < 0)
    {
        val.back() = -val.back();
        pos = false;
    }
    correct(true);
}

inline ELEM_TYPE InfInt::dInR(const InfInt& R, const InfInt& D)
{//PROFILED_SCOPE
    ELEM_TYPE min = 0, max = UPPER_BOUND;
    while (max - min > 0)
    {
        ELEM_TYPE avg = max + min;
        //div_t dt = div(avg, 2);
        //avg = dt.rem ? (dt.quot + 1) : dt.quot;
        ELEM_TYPE havg = avg / 2;
        avg = (avg - havg * 2) ? (havg + 1) : havg;
        InfInt prod = D * avg;
        if (R == prod)
        {//PROFILED_SCOPE
            return avg;
        }
        else if (R > prod)
        {//PROFILED_SCOPE
            min = avg;
        }
        else
        {//PROFILED_SCOPE
            max = avg - 1;
        }
    }
    return min;
}

inline void InfInt::multiplyByDigit(ELEM_TYPE factor, std::vector<ELEM_TYPE>& val)
{//PROFILED_SCOPE
    ELEM_TYPE carry = 0;
    for (size_t i = 0; i < val.size(); ++i)
    {
        PRODUCT_TYPE pval = val[i] * (PRODUCT_TYPE) factor + carry;
        if (pval >= BASE || pval <= -BASE)
        {
            //carry = (ELEM_TYPE) (pval / BASE);
            //pval %= BASE;

            carry = (ELEM_TYPE) (pval / BASE);
            pval -= carry * BASE;
        }
        else
        {
            carry = 0;
        }
        val[i] = (ELEM_TYPE) pval;
    }
    if (carry > 0)
    {
        val.push_back(carry);
    }
}

/**************************************************************/
/******************** NON-MEMBER OPERATORS ********************/
/**************************************************************/

inline std::istream& operator>>(std::istream &s, InfInt &n)
{//PROFILED_SCOPE
    std::string str;
    s >> str;
    n.fromString(str);
    return s;
}

inline std::ostream& operator<<(std::ostream &s, const InfInt &n)
{//PROFILED_SCOPE
    if (!n.pos)
    {
        s << '-';
    }
    bool first = true;
    for (int i = (int) n.val.size() - 1; i >= 0; --i)
    {
        if (first)
        {
            s << n.val[i];
            first = false;
        }
        else
        {
            s << std::setfill('0') << std::setw(DIGIT_COUNT) << n.val[i];
        }
    }
    return s;
}

#endif


int GCD(int a,int b){
    return a==0?b:GCD(b%a,a);
}

string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

struct myitem{
    int h;
    int w;
    myitem(int a, int b){
        h=a;
        w=b;
        if(h>w){
            int t=h;
            h=w;
            w=t;
        }
    }
};

bool mycompare (myitem a, myitem b){
    if(a.h==b.h)return a.w<b.w;
    return a.h<b.h;
}

//int representative[20005];
int findrep(int a, int * representative){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a], representative);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y, int * representative){
    int xp,yp;
    xp=findrep(x,representative);
    yp=findrep(y, representative);
    representative[yp]=xp;
}

/*---------credit for the graph class and methods below: geeksforgeeks---------*/
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

/*---------credit for the graph class and methods above: geeksforgeeks---------*/

/*------the template below calculates phi for 1 to N, and stores them in phi credit: codeforces grandmaster savinov----- */

/*const int N = 5000000;
int lp[N + 1];
unsigned long long phi[N + 1];
//int cumulativescore[N+1];
vector<int> pr;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] =  (i - 1);
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}*/

/*------the template above calculates phi for 1 to N, and stores them in phi credit: codeforces grandmaster savinov----- */

//int visited[20005];
//int appears[20005];
//vector < vector <int> >edges;

/*------ the below template does BFS inside with some modifications------- */

/*int BFS(vector<int>allnode, int N){
    queue<int>bfsqueue;
    int maxside=0;
    vector<int>depth(20005,-1);
    for(int i=0;i<N;++i){
        int nownode=allnode[i];
        int mx1=0;
        int mx2=0;
        //cout<<"outer for loop "<<i<<"\n";
        if(visited[nownode]==0){
            bfsqueue.push(nownode);
            depth[nownode]=0;
            visited[nownode]=1;
            while(!bfsqueue.empty()){
                int a=bfsqueue.front();
                //cout<<"queue front "<<a<<"\n";
                int da=depth[a];
                if(da%2==0)mx1++;
                else{mx2++;}
                bfsqueue.pop();
                int l=edges[a].size();
                for(int k=0;k<l;++k){
                    int tonode=edges[a][k];
                    if(visited[tonode]==0){
                    bfsqueue.push(tonode);
                    depth[tonode]=1+da;
                    visited[tonode]=1;
                    }
                }
                //cout<<l<<"\n";
            }
        }
        //cout<<nownode<<" "<<mx1<<" "<<mx2<<"\n";
        maxside+=max(mx1,mx2);

    }
    return maxside;
}
*/
/*------ the above template does BFS inside with some modifications------- */

/*------the template below are used in bitmasking------*/

int setbit(int N,int pos){
    return N=N|(1<<pos);
}
int resetbit(int N,int pos){
    return N=N&(~(1<<pos));
}
int checkbit(int N,int pos){
    return N&(1<<pos);
}
int countsets(int N){
int a=0;
    for(int i=1;i<=N;i<<=1){
        if(N&i)a++;
    }
    return a;
}

/*------the template above are used in bitmasking------*/

/*int marriage[20][20];
int dp[20][70000];

int N;
int getmaxindex(int man, int mask){
    if(man==N)return 0;
    if(dp[man][mask]!=-1)return dp[man][mask];
    int mx=0;
    for(int i=0;i<N;++i){
        if(checkbit(mask,i)==0){
            int newmask=setbit(mask,i);
            mx=max(mx,marriage[man][i]+getmaxindex(man+1,newmask));
            //mask=resetbit(mask,i);
        }
    }
    return dp[man][mask]=mx;
}
*/

InfInt dp[505][54];

int main(){
    for(int i=0;i<505;++i){
        for(int j=0;j<50;++j){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<505;++i){
        dp[i][1]=(i<=9?1:0);
    }
    for(int i=2;i<54;++i){
        for(int j=0;j<505;++j){
            for(int k=0;k<=9;++k){
                if((j-k)>=0){
                    dp[j][i]+=dp[j-k][i-1];
                }
            }
        }
    }
    int s,d;
    scanf("%d %d",&d,&s);
    int n=s/2;
    if(s%2){
        cout<<"0\n";
    }
    else{
        InfInt ans=dp[n][d]*dp[n][d];
        cout<<ans<<"\n";
    }

    return 0;

}
