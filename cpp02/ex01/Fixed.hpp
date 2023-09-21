#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed &object);
        Fixed(const int integer);
        Fixed(const float floating);
        ~Fixed(void);
        Fixed &operator=(const Fixed &object);

        int toInt(void) const;
        float toFloat() const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int        value;
        const static int bit_number = 8;
        
};

std::ostream& operator<<(std::ostream &os, const Fixed &obj);


#endif