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
        ~Fixed();
        Fixed &operator=(const Fixed &object);

        int toInt(void) const;
        float toFloat() const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        bool          operator>(Fixed const &obj ) const ;
        bool          operator>=(Fixed const &obj ) const ;
        bool          operator<(Fixed const &obj ) const ;
        bool          operator<=(Fixed const &obj ) const ;
        bool          operator==(Fixed const &obj ) const ;
        bool          operator!=(Fixed const &obj ) const ;
        Fixed         operator+(Fixed const &obj ) const ;
        Fixed         operator-(Fixed const &obj ) const ;
        Fixed         operator*(Fixed const &obj ) const ;
        Fixed         operator/(Fixed const &obj ) const ;

        Fixed &operator++()  ;
        Fixed operator++(int)  ;
        Fixed &operator--()  ;
        Fixed operator--(int) ;
    private:
        int        value;
        const static int bit_number = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &obj);

#endif