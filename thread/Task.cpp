#include"Task.h"
#include<ctime>
Task::Task(int n) {
		
	
	while ((complexity > upper) || (complexity < lower))
	{
		complexity = (rand()%upper+ getRandom(seed_for_complexity, upper))%upper;
		if (complexity > upper)
			complexity -= upper;
		if (complexity < lower)
			complexity += lower;

	}
	//std::cout << "///////////////////////\n";
	//std::cout << "comm " << complexity<<"\n";

	n_procesor = new int[3];
	srand(time(NULL));

	n_procesor[0] = (rand() % 10 + getRandom(seed_for_n_procesor, 10)) % 6;

	n_procesor[1] = (rand()%10+getRandom(seed_for_n_procesor,10))%6;

	n_procesor[2] = (rand() % 10 + getRandom(seed_for_n_procesor, 10)) % 6;

	//n_procesor[3] = (rand() % 10 + getRandom(seed_for_n_procesor, 10)) % 6;
	//n_procesor[4] = (rand() % 10 + getRandom(seed_for_n_procesor, 10)) % 6;
	/*std::cout << "///////////////////////\n";
	std::cout << "n 0 " << n_procesor[0]<<"\n";
	std::cout << "n 1 " << n_procesor[1] << "\n";
	std::cout << "n 2 " << n_procesor[2] << "\n";
	std::cout << "n 3 " << n_procesor[3] << "\n";
	std::cout << "n 4 " << n_procesor[4] << "\n";

	std::cout << "///////////////////////\n";
	*/
	n_task = n;
}
Task::~Task() {
	delete[] n_procesor;
}

int Task::getRandom(int &seed, int m) {
	
	seed = (a*seed + c) % m;

	//std::cout << seed << std::endl;
	return seed;
}