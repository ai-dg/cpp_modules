#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int _fixedPoint;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(Fixed const & src);
        Fixed& operator=(Fixed const& rhs);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif