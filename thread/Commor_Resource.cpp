#include"Common_Resource.h"




void Common_Resource::generate_resource() {
	//std::cout << "generate_resourse\n";
	int end= Task::n_task_all;
	for (int i = Task::n_task_all; i < Task::n_task_all+500000; i++)
		resource.push_back(new Task (i));
	//std::cout << "generate_resourse "<<resource.size()<<std::endl;
}
Task* Common_Resource::get_element(const int n_procesor) {
	if (resource.size())
	{
		Task* t = *(resource.begin());
		for (int i = 0; i < 3; i++)
			if (t->n_procesor[i] == n_procesor)
			{
				resource.erase(resource.begin());
				return t;
			}
	}
	return NULL;
}
Task* Common_Resource::get_element() {
	Task* t = *(resource.begin());	
	resource.erase(resource.begin());
	return t;
}
int Common_Resource::get_n_resourse() {
	return resource.size();
}

void Common_Resource::mutex_lock()
{
	mutex.lock();
}
void Common_Resource::mutex_unlock()
{
	mutex.unlock();
}
