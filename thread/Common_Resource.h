#pragma once
#include "Task.h"



#include <vector>
#include <iostream>
#include<mutex>
class Common_Resource {

private:

	std::mutex mutex;
	std::vector<Task*> resource;
	virtual Task* get_element(int n_procesor);
	Task* get_element();
	virtual void mutex_lock();
	virtual void mutex_unlock();

	
public:
	virtual void generate_resource();
	virtual int get_n_resourse();
	friend class Base_Procesor;
	friend class Procesor_1;
	friend class Procesor_2;
	friend class Procesor_3;
	friend class Procesor_4;
	friend class Procesor_5;
	friend class Procesor_add;
};

