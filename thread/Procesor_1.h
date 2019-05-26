#pragma once
#include "Base_Procesor.h"

class Procesor_1 :public Base_Procesor{
	std::vector<Task*> resource;
public:
	/*void operator()(int x);
	*/
	static int power_1;
	int get_power();
private:
	const int n_procesor = 1;
	int get_n_procesor();
	int num_task_completed = 0;
	int get_n_task_completed();
	void add_n_task_completed();
	//void start(int x, Common_Resource& common_resource);
	
	
};