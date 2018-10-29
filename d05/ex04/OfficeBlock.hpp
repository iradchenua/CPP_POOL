#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock  {
	public:
		OfficeBlock(void);

		OfficeBlock(OfficeBlock const & OfficeBlock);
		OfficeBlock(Intern & intern, Bureaucrat & signer, Bureaucrat & executor);
		OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);

		~OfficeBlock(void);

		OfficeBlock & operator=(const OfficeBlock & OfficeBlock);

		Form *makeForm(std::string const & name, std::string const & target);

		void	setIntern(Intern & intern);
		void	setSigner(Bureaucrat & signer);
		void	setExecutor(Bureaucrat & executor);

		void	setIntern(Intern *intern);
		void	setSigner(Bureaucrat *signer);
		void	setExecutor(Bureaucrat *executor);

		void 	doBureaucracy(std::string const & formName, std::string const & target) const;

		class NoLink: public std::exception {
			public:
				NoLink(void);

				NoLink(NoLink const & e);
				~NoLink(void) throw();

				NoLink & operator=(const NoLink & e);

				virtual const char *what() const throw();
		};
		class BadConstructor: public std::exception {
			public:
				BadConstructor(void);

				BadConstructor(BadConstructor const & e);
				~BadConstructor(void) throw();

				BadConstructor & operator=(const BadConstructor & e);

				virtual const char *what() const throw();
		};
	private:
		Intern *_intern;
		Bureaucrat *_signer;
		Bureaucrat *_executor;
};