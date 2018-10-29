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

		Fixed & operator=(Fixed const & number);

		~Fixed(void);

		int 	toInt(void) const;
		float 	toFloat(void) const;
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		static	int getDiv(void);
		int _value;
		static int const _frBits;
};


std::ostream & operator<<(std::ostream & o, Fixed const & number);

#endif