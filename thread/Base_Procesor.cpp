#include"Base_Procesor.h"
using seconds = std::chrono::duration<double>;

void Base_Procesor::operator()(int x, Common_Resource& common_resource)
{
	start_time = std::chrono::system_clock::now();
	std::cout << "start Procesor_" << get_n_procesor()<<std::endl;
	start(x,common_resource);
		
}

void Base_Procesor::start(int x,Common_Resource& common_resource)
{
	seconds time1 =std::chrono::seconds(10);
	while (true)
	{
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		elapsed_seconds = end - start_time;
		common_resource.mutex.lock();
		Task * t;
		if ((common_resource.resource.size() == 0)||(elapsed_seconds > time1))
			break;
		t = common_resource.get_element(get_n_procesor());
		
		common_resource.mutex.unlock();
		work(t);
	}
	std::cout << "end Procesor_" << get_n_procesor() <<": "<<get_n_task_completed() <<std::endl;
	common_resource.mutex.unlock();
}
void Base_Procesor::work(const Task* task) {
	if (task)
	{
		int buf = task->complexity;
		while (buf <= 0)
			buf = buf - get_power();
		add_n_task_completed();
	}
}
int Base_Procesor::get_power() {
	return power_0;
}
int Base_Procesor::get_n_procesor() {
	return n_procesor;
}
int Base_Procesor::get_n_task_completed() {
	return num_task_completed;
}
void Base_Procesor::add_n_task_completed() {
	num_task_completed++;
}