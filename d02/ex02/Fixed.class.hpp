#include <iostream>
#include <cmath>

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed {
	public:
		Fixed(void);
		Fixed(int const number);
		Fixed(float const number);
		Fixed(Fixed const & number);

		
		bool operator<(Fixed const & number) const;
		bool operator>(Fixed const & number) const;
		bool operator<=(Fixed const & number) const;
		bool operator>=(Fixed const & number) const;
		bool operator==(Fixed const & number) const;
		bool operator!=(Fixed const & number) const;

		Fixed & operator=(Fixed const & number);

		Fixed  operator+(Fixed const & number) const;
		Fixed  operator-(Fixed const & number) const;
		Fixed  operator*(Fixed const & number) const;
		Fixed  operator/(Fixed const & number) const;

		Fixed  operator--(int);
		Fixed  operator++(int);
		Fixed & operator++(void);
		Fixed & operator--(void);

		~Fixed(void);

		int 	toInt(void) const;
		float 	toFloat(void) const;
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);

		static Fixed & max(Fixed & number1, Fixed & number2);
		static Fixed const & max(Fixed const & number1, Fixed const & number2);
		static Fixed & min(Fixed & number1, Fixed & number2);
		static Fixed const & min(Fixed const & number1, Fixed const & number2);

	private:
		int _value;
		static int const _frBits;
};


std::ostream & operator<<(std::ostream & o, Fixed const & number);

#endif