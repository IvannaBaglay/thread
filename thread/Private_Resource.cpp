#include"Private_Resource.h"
void Private_Resource::generate_resource() {
	//std::cout << "generate_resourse\n";
	int end = Task::n_task_all;
	for (int i = Task::n_task_all; i < Task::n_task_all; i++)
		private_resources.push_back(new Task(i));
	//std::cout << "generate_resourse " << private_resources.size() << std::endl;
}
Task* Private_Resource::get_element(const int n_procesor) {
	if (private_resources.size())
	{
		Task* t = *(private_resources.begin());
		for (int i = 0; i <3; i++)
			if (t->n_procesor[i] == n_procesor)
			{
				private_resources.erase(private_resources.begin());
				return t;
			}
	}
	return NULL;
}
int Private_Resource::get_n_resourse() {
	return private_resources.size();
}
void Private_Resource::mutex_lock()
{
	mutex.lock();
}
void Private_Resource::mutex_unlock()
{
	mutex.unlock();
}