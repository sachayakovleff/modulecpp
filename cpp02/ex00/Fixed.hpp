#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed &object);
        ~Fixed(void);
        Fixed &operator=(const Fixed &object);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int        value;
        const static int bit_number = 8;
};

#endif