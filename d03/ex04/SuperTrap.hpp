#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

#ifndef SUPER_TRAP_HPP
#define SUPER_TRAP_HPP

class SuperTrap : public NinjaTrap, public FragTrap {
		public:
			SuperTrap(void);
			SuperTrap(SuperTrap const & super);
			SuperTrap(std::string name);

			~SuperTrap(void);
			SuperTrap & operator=(SuperTrap const & super);

			void meleeAttack(std::string const & target) const;
			void rangedAttack(std::string const & target) const;
			
		protected:
			static int const _maxEp ;
};

#endif