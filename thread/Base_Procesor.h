#pragma once
#include <iostream>
#include<chrono>

#include"Private_Resource.h"


static std::chrono::time_point<std::chrono::system_clock> start_time;

class Base_Procesor {
protected:

	//Private_Resource resource;
	
	std::chrono::duration<double> elapsed_seconds;
	void start(int x, Common_Resource& common_resource);
	void start(int x, Common_Resource& common_resource, Private_Resource& pr_0, Private_Resource& pr_1, Private_Resource& pr_2,
		Private_Resource& pr_3, Private_Resource& pr_4, Private_Resource& pr_5);
	void planning(Common_Resource& common_resource, Private_Resource& pr_0, Private_Resource& pr_1, Private_Resource& pr_2,
		Private_Resource& pr_3, Private_Resource& pr_4, Private_Resource& pr_5);
	void start(int x, Private_Resource& common_resource);
public:
	static int power_0;
	//std::chrono::time_point<std::chrono::system_clock> start_time;
	void operator()(int x,Common_Resource& common_resource);
	void operator()(int x, Private_Resource& common_resource);
	void operator()(int x, Common_Resource& common_resource, Private_Resource& pr_0, Private_Resource& pr_1, Private_Resource& pr_2,
		 Private_Resource& pr_3, Private_Resource& pr_4, Private_Resource& pr_5);
	virtual int get_power();
	virtual int get_n_task_completed();
	virtual int get_n_procesor();
	virtual void add_n_task_completed();
private:
	
	int switch_f(int min);
	
	const int n_procesor= 0;
	int num_task_completed = 0;

	//void start2(int x, Common_Resource& common_resource);
	std::vector<Task*> resource;
	void work(const Task* task);
	//void planning(int x, Common_Resource& common_resource);
};
