#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>


class Fixed
{
    private:
        int _fixedPoint;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(Fixed const & src);
        Fixed& operator=(Fixed const& rhs);
        ~Fixed();

        float toFloat(void) const;
        int toInt(void) const;


        int getRawBits(void) const;
        void setRawBits(int const raw);

};

std::ostream& operator<<(std::ostream& out, Fixed const& i);

#endif