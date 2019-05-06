#pragma once
#include "Task.h"



#include <vector>
#include <iostream>
#include<mutex>
class Common_Resource {

private:

	std::mutex mutex;
	std::vector<Task*> resource;
	Task* get_element(int n_procesor);
	
public:
	void generate_resource();
	Common_Resource();
	friend class Base_Procesor;
	friend class Procesor_1;
	friend class Procesor_2;
	friend class Procesor_3;
	friend class Procesor_4;
	friend class Procesor_5;
};

