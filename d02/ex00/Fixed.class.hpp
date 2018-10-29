#include <iostream>

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const & number);

		Fixed & operator=(Fixed const & number);

		~Fixed(void);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int _value;
		static int const _frBits;;
};

#endif