#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>
#include <cmath>


class Fixed
{
    private:
        int _fixedPoint;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(Fixed const& src);
        Fixed& operator=(Fixed const& rhs);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(Fixed const& src) const;
        bool operator<(Fixed const& src) const;
        bool operator>=(Fixed const& src) const;
        bool operator<=(Fixed const& src) const;
        bool operator==(Fixed const& src) const;
        bool operator!=(Fixed const& src)const ;
        
        Fixed operator+(Fixed const &src) const;
        Fixed operator-(Fixed const &src) const;
        Fixed operator*(Fixed const &src) const;
        Fixed operator/(Fixed const &src) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(Fixed const &a, Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(Fixed const &a, Fixed const &b);

        Fixed abs() const;



};

std::ostream& operator<<(std::ostream& out, Fixed const& i);

#endif