#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "Fraction.hpp"
#include <algorithm>
#include <iostream>


//using namespace ariel;
namespace ariel{

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction :: Fraction(int mon,int mach=1)
{
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    if(mach==0)
    {
        throw std::invalid_argument("invalid_argument");
        
    }
    if(mach<0)
    {
        mon=-mon;
        mach=-mach;
    }
    long lmon = (long) (mon);
    long lmach =(long)(mach);

    if(lmach > max_int || lmon > max_int || lmach < min_int || lmon < min_int)
    {
        throw std:: overflow_error("invalid input");
    }
    if(abs(mon)==abs(mach))
    {
        this->mon=mon/abs(mach);
        this->mach=mach/abs(mach);
    }
    else
    {
        int mini=std::min(abs(mon),abs(mach));
        
        int common=gcd(abs(mon),abs(mach));
        
        
        this->mon=mon/common;
        this->mach=mach/common;


    }

    
    
}
Fraction :: Fraction()
:mon(0),mach(1){}

    
Fraction :: ~Fraction(){}

Fraction :: Fraction (const Fraction& other)
:mon(other.mon),mach(other.mach){}

Fraction :: Fraction (float x)
{
    if(x==(int)(x*10))
    {
        mon=x;
        mach=1;
    }
    else if((float)x*10==(int)(x*10))
    {
        mon=(float)x*10;
        mach=10;
    }
    else if((float)x*100==(int)(x*100))
    {
        mon=(float)x*100;
        mach=100;
    }
    else
    {
        mon=(float)x*1000;
        mach=1000;
    }
}
Fraction& Fraction :: operator=(const Fraction& other)
{
    if(!(*this==other))
    {
        mon=other.mon;
        mach=other.mach;

    }
    
    return *this;
}
Fraction :: Fraction (Fraction &&other) noexcept
:mon(std::exchange(other.mon, 0)),
mach(std::exchange(other.mach, 1)){}

Fraction& Fraction ::  operator=(Fraction&& other) noexcept
{

    mon=other.mon;
    mach=other.mach;

    return *this;
}

int Fraction :: getNumerator() const
{
    return mon;
}
int Fraction :: getDenominator()const
{
    return mach;
}


//prefix
Fraction& Fraction :: operator++()
{
    mon+=mach;
    return (*this);
}
Fraction& Fraction :: operator--()
{
    mon-=mach;
    return (*this);
}
//postfix
Fraction Fraction ::  operator++(int)
{
    Fraction other(mon,mach);
    mon+=mach;
    return other;
}
Fraction Fraction ::  operator--(int)
{
    Fraction other(mon,mach);
    mon-=mach;
    return other;
}



bool Fraction :: operator==(const float b)
{
    return (float)mon/mach==b;
}
bool Fraction :: operator>(const float b)
{
    
    return (float)mon/mach>b;
}
bool Fraction :: operator<(const float b)
{
    return (float)mon/mach<b;
}
bool Fraction :: operator<=(const float b)
{
    return (float)mon/mach<=b;
}
bool Fraction :: operator>=(const float b)
{
    return (float)mon/mach>=b;
}


Fraction Fraction :: operator+(const Fraction& b) const
{
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    long lmon = (long) (mon*(long)b.mach+(long)b.mon*(long)mach);
    long lmach =(long) (b.mach*(long)mach);

    if(lmach > max_int || lmon > max_int || lmach < min_int || lmon < min_int)
    {
        throw std:: overflow_error("invalid input");
    }

    Fraction other(mon*b.mach+b.mon*mach,mach*b.mach);
    return other;
}
Fraction Fraction :: operator-(const Fraction& b) const {
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    long lmon = (long) (mon*(long)b.mach-(long)b.mon*(long)mach);
    long lmach =(long)(b.mach*(long)mach);

    if(lmach > max_int || lmon > max_int || lmach < min_int || lmon < min_int)
    {
        throw std:: overflow_error("invalid input");
    }
    
    Fraction other(mon*b.mach-b.mon*mach,mach*b.mach);
    return other;
}
Fraction Fraction :: operator/(const Fraction& b) const {
    if(b.mon==0)
    {
        throw std::runtime_error("invalid_argument");
    }
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    long lmon = (long) (mon*(long)b.mach);
    long lmach =(long)(b.mon*(long)mach);

    if(lmach > max_int || lmon > max_int || lmach < min_int || lmon < min_int)
    {
        throw std:: overflow_error("invalid input");
    }
    Fraction other(mon*b.mach,mach*b.mon);
    return other;
}
Fraction Fraction :: operator*(const Fraction& b) const {

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    long lmon = (long) (mon*(long)b.mon);
    long lmach =(long)(mach*(long)b.mach);

    if(lmach > max_int || lmon > max_int || lmach < min_int || lmon < min_int)
    {
        throw std:: overflow_error("invalid input");
    }
    Fraction other(mon*b.mon,mach*b.mach);
    return other;
}

Fraction Fraction :: operator+(const float b) const {
    Fraction other(b);
    return *this+other;
}
Fraction  Fraction ::operator-(const float b) const {
    Fraction other(b);
    return *this-other;
}
Fraction  Fraction ::operator/(const float b) const {
    if(b==0)
    {
        throw std::runtime_error("invalid_argument");
    }
    Fraction other(b);
    return *this/other;
}
Fraction  Fraction ::operator*(const float b) const {
    Fraction other(b);
    return *this*other;
}

// namespace ariel
// {
    bool operator==(const float a, const Fraction& b)
    {
        Fraction other(a);
        return other==b;
    }
    bool operator>(const float a, const Fraction& b)
    {
        Fraction other(a);
        return other>b;
    }
    bool operator<(const float a, const Fraction& b)
    {
        Fraction other(a);
        return other<b;
    }
    bool operator<=(const float a, const Fraction& b)
    {
        Fraction other(a);
        return other<=b;
    }
    bool operator>=(const float a, const Fraction& b)
    {
        Fraction other(a);
        return other>=b;
    }
    Fraction operator+(const float a, const Fraction& b){
        
        Fraction other(a);
        return other+b;
    }
    Fraction operator-(const float a, const Fraction& b){
        Fraction other(a);
        return other-b;
    }
    Fraction operator/(const float a, const Fraction& b){
        if(b.mon==0)
        {
            throw std::runtime_error("invalid_argument");
        }
        Fraction other(a);
        return other/b;
    }
    Fraction operator*(const float a, const Fraction& b){
        Fraction other(a);
        return other*b;
    }

    bool operator==(const Fraction& a, const Fraction& b)
    {
        return (float)a.mon/a.mach==(float)b.mon/b.mach;
    }
    bool operator<(const Fraction& a, const Fraction& b)
    {
        return (float)a.mon/a.mach<(float)b.mon/b.mach;
    }
    bool operator>(const Fraction& a, const Fraction& b)
    {
        return (float)a.mon/a.mach>(float)b.mon/b.mach;
    }
    bool operator<=(const Fraction& a, const Fraction& b)
    {
        return (float)a.mon/a.mach<=(float)b.mon/b.mach;
    }
    bool operator>=(const Fraction& a, const Fraction& b)
    {
        return (float)a.mon/a.mach>=(float)b.mon/b.mach;
    }
    std::ostream& operator<< (std::ostream& output, const Fraction& other)
    {
        return output<<other.mon<<'/'<<other.mach;
    }
    

    std::istream& operator>> (std::istream& input ,  Fraction& other)
    {

        int mon=-30;
        int mach=-30;
        
        if(input>>mon>>mach)
        {
            
            if(mach==0)
            {
                throw std:: runtime_error("input 0");
            }
            Fraction f(mon,mach);
            other=f;
        }
        
        else
        {
            throw std:: runtime_error(" problem");
        }
         
        
        return input;
    }
    

    
} 


