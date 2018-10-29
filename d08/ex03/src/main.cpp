#include "Up.hpp"
#include "Down.hpp"
#include "Open.hpp"
#include "Close.hpp"
#include "Next.hpp"
#include "Prev.hpp"
#include "Show.hpp"
#include "Get.hpp"
#include "IOpenCloseInstruction.hpp"

#define BUFF_SIZE 30000

void	interpretator(std::string & program) {
	
	Up up;
	Down down;
	Next next;
	Prev prev;
	Show show;
	Open open;
	Close close;
	Get   get;

	std::vector<char> quartes(BUFF_SIZE);

	std::vector<AInstruction *> instructions;
	instructions.push_back(&up);
	instructions.push_back(&down);
	instructions.push_back(&next);
	instructions.push_back(&prev);
	instructions.push_back(&show);
	instructions.push_back(&open);
	instructions.push_back(&close);
	instructions.push_back(&get);

	std::deque<AInstruction *> commandsQueue;
	std::vector<char>::iterator quart = quartes.begin();

	for(std::string::iterator it = program.begin(); it != program.end(); ++it) {
		for(std::vector<AInstruction *>::iterator jt = instructions.begin(); jt != instructions.end(); jt++) {
			if ((*jt)->isThisInstr(*it))
				commandsQueue.push_back(*jt);
		}
    }

    int breackets = 0;
    std::deque<AInstruction *>::iterator putForException;
    try {
	    for (std::deque<AInstruction *>::iterator jt = commandsQueue.begin(); jt != commandsQueue.end(); jt++){
	    	if (!(*jt)->isBreacket())
	    		(*jt)->execute(quart);
	    	else {
	    		if ((*jt)->isThisInstr('['))
	    			putForException = commandsQueue.end();
	    		if ((*jt)->isThisInstr(']'))
	    			putForException = commandsQueue.begin();
	   			dynamic_cast<IOpenCloseInstruction *>(*jt)->execute(quart, breackets, jt, putForException);

	    	}

	    }
    } catch(std::out_of_range const & e) {
    	std::cout << e.what() << std::endl;
    } catch(std::exception const & e) {
    	std::cout << e.what() << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    std::ifstream ifs(argv[1]);
    std::string program((std::istreambuf_iterator<char>(ifs)),
                 std::istreambuf_iterator<char>());
    interpretator(program);
    ifs.close();
    return (0);
}
