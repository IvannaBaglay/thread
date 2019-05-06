#include"Task.h"
Task::Task(int n) {

	complexity = getRandom(seed_for_complexity ,10000);
	n_procesor = new int[N_PROCESOR/2];


	n_procesor[0] = getRandom(seed_for_n_procesor,6);
	n_procesor[1] = getRandom(seed_for_n_procesor, 5);
	n_procesor[2] = getRandom(seed_for_n_procesor, 4);
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