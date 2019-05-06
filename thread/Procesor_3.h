#pragma once
#include "Base_Procesor.h"

class Procesor_3 :public Base_Procesor {

public:
	//void operator()(int x);
	 int get_power();
private:
	//void start(int x, Common_Resource& common_resource);
	static int power_3;
	const int n_procesor = 3;
	int get_n_procesor();
	int num_task_completed = 0;
	int get_n_task_completed();
	void add_n_task_completed();
};