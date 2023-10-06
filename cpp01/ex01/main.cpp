#include "Zombie.hpp"
#include <stdlib.h>
#include <unistd.h>


int main()
{
	std::string name = "Gilbert";
    int nbr = 10;
	std::cout << "Creating an Horde of " << nbr << " zombies named " << name << std::endl;
	Zombie *Horde = zombieHorde(nbr, name);
	if (!Horde)
		return (1);
	std::cout << "\033[1;34m Horde's status\033[m" << std::endl;
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
	/* ===================================================== */
	/* 				Initialisation of the horde				 */
	/* ===================================================== */
	int	i = 0;

	while (i < nbr)
	{
		Horde[i].announce();
		i++;
	}
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
	std::cout << "\033[1;34m Horde destruction\033[m" << std::endl;
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
	delete [] Horde;
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
}