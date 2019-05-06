#include"Common_Resource.h"


void Common_Resource::generate_resource() {
	std::cout << "generate_resourse\n";
	int end= Task::n_task_all;
	for (int i = Task::n_task_all; i < Task::n_task_all+500000; i++)
		resource.push_back(new Task (i));
	std::cout << "generate_resourse "<<resource.size()<<std::endl;
}
Task* Common_Resource::get_element(const int n_procesor) {
	Task* t= *(resource.begin());
	for (int i = 0; i < N_PROCESOR / 2; i++)
		if (t->n_procesor[i] == n_procesor)
		{
			resource.erase(resource.begin());
			return t;
		}
	return NULL;
}

Common_Resource::Common_Resource() {
	generate_resource();
}

