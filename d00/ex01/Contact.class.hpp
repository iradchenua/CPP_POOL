#include <string>

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# define F_NUM 12

class Contact {
	public: 
		static std::string fieldsName[F_NUM];
		std::string fields[F_NUM];
		void	addContact(void);
		static int getCNb(void);
		static void	setCNb(int cNb);
		void	showContact(void);
	private:
		static int 	_cNb;
};

#endif