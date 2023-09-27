#include "Zombie.hpp"

int	main()
{
	std::cout << "\033[1;34m Creating 4 Zombies with Zombie function\033[m" << std::endl;
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
	Zombie("Jeff");
	Zombie("Darude");
	Zombie("Sandstorm");
	Zombie("Rick Astley");
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
	std::cout << "\033[1;36m Creating 2 Zombies with newZombie\033[m" << std::endl;
	std::cout << "\033[1;36m----------------------------------------------\033[m" << std::endl;
	Zombie *zombie1 = newZombie("Michael");
	Zombie *zombie2 = newZombie("Michael");
	std::cout << "\033[1;36m----------------------------------------------\033[m" << std::endl;
	std::cout << "\033[1;33m Killing my dear zombies\033[m" << std::endl;
	std::cout << "\033[1;33m----------------------------------------------\033[m" << std::endl;
	delete (zombie1);
	delete (zombie2);
	std::cout << "\033[1;33m----------------------------------------------\033[m" << std::endl;
	std::cout << "\033[1;34m Creating 2 Zombies with randomChump\033[m" << std::endl;
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
	randomChump("Random Bob");
	randomChump("Random Michael");
	std::cout << "\033[1;34m----------------------------------------------\033[m" << std::endl;
}
