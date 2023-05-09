#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace ariel{
class Fraction
{
private:
    int mon;
    int mach;
public:
    Fraction(int mon,int mach);
    Fraction();    
    ~Fraction();
    Fraction (const Fraction& other);
    Fraction (float flo);
    Fraction& operator=(const Fraction& other);
    Fraction (Fraction &&other) noexcept;
    Fraction & operator=(Fraction&& other) noexcept;

    int getNumerator() const;
    int getDenominator() const;
    
   
    //prefix
    Fraction& operator++();
    Fraction& operator--();
    //postfix
    Fraction operator++(int);
    Fraction operator--(int);

    bool operator==(float other);
    bool operator>(float other);
    bool operator<(float other);
    bool operator<=(float other);
    bool operator>=(float other);

    friend bool operator==(float first, const Fraction& other);
    friend bool operator>(float first, const Fraction& other);
    friend bool operator<(float first, const Fraction& other);
    friend bool operator<=(float first, const Fraction& other);
    friend bool operator>=(float first, const Fraction& other);

    friend bool operator==(const Fraction& first, const Fraction& other);
    friend bool operator>(const Fraction& first, const Fraction& other);
    friend bool operator<(const Fraction& first, const Fraction& other);
    friend bool operator>=(const Fraction& first, const Fraction& other);
    friend bool operator<=(const Fraction& first, const Fraction& other);

    Fraction operator+(const Fraction& other) const ;
    Fraction operator-(const Fraction& other) const ;
    Fraction operator/(const Fraction& other) const ;
    Fraction operator*(const Fraction& other) const;
    friend Fraction operator+(float first, const Fraction& other);
    friend Fraction operator-(float first, const Fraction& other);
    friend Fraction operator/(float first, const Fraction& other);
    friend Fraction operator*(float first, const Fraction& other);
    Fraction operator+(float other) const ;
    Fraction operator-(float other) const ;
    Fraction operator/(float other) const ;
    Fraction operator*(float other) const ;

    friend std::ostream& operator<< (std::ostream& output, const Fraction& other);
    friend std::istream& operator>> (std::istream& input , Fraction& other);

};

   
    
}


