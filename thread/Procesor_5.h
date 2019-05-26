#pragma once
#include "Base_Procesor.h"

class Procesor_5 :public Base_Procesor {

	std::vector<Task*> resource;
	
public:
	//void operator()(int x);
	 int get_power();
	 static int power_5;
private:
	//void start(int x, Common_Resource& common_resource);
	
	const int n_procesor = 5;
	int get_n_procesor();
	int get_n_task_completed();
	void add_n_task_completed();
	int num_task_completed = 0;
};