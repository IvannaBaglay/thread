#pragma once
#include"Common_Resource.h"


class Private_Resource :public Common_Resource {
private:
	std::vector<Task*> private_resources;
	std::mutex mutex;
	 Task* get_element(int n_procesor);
	 void mutex_lock();
	 void mutex_unlock();
public :
	int get_n_resourse();
	void generate_resource();
	friend class Base_Procesor;
};