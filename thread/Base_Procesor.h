#pragma once
#include <iostream>
#include<chrono>

#include"Private_Resource.h"


static std::chrono::time_point<std::chrono::system_clock> start_time;

class Base_Procesor {
protected:
	//Private_Resource resource;
	static int power_0;
	std::chrono::duration<double> elapsed_seconds;
public:
	//std::chrono::time_point<std::chrono::system_clock> start_time;
	void operator()(int x,Common_Resource& common_resource);
	virtual int get_power();
	virtual int get_n_task_completed();
	
private:
	virtual int get_n_procesor();
	
	virtual void add_n_task_completed();
	const int n_procesor= 0;
	int num_task_completed = 0;
	void start(int x, Common_Resource& common_resource);
	void work(const Task* task);

};
