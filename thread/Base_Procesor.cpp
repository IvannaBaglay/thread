#include"Base_Procesor.h"
#include<vector>
using seconds = std::chrono::duration<double>;
seconds time2 = std::chrono::milliseconds(20);//робота
seconds time3 = std::chrono::seconds(1000);//планування
seconds time1 = std::chrono::seconds(10);
void Base_Procesor::operator()(int x, Common_Resource& common_resource)
{
	if (x == 200)
		time3 = std::chrono::milliseconds(100);
	if (x == 300)
		time3 = std::chrono::milliseconds(40);
	start_time = std::chrono::system_clock::now();
	//std::cout << "start Procesor_" << get_n_procesor()<<std::endl;
	start(x, common_resource);
		
}
void Base_Procesor::operator()(int x, Private_Resource& common_resource)
{
	if (x == 200)
		time3 = std::chrono::milliseconds(100);
	if (x == 300)
		time3 = std::chrono::milliseconds(40);
	start_time = std::chrono::system_clock::now();
	//std::cout << "start Procesor_" << get_n_procesor() << std::endl;
	start(x, common_resource);

}
void Base_Procesor::operator()(int x, 
	Common_Resource& common_resource, Private_Resource& pr_0, Private_Resource& pr_1, 
	Private_Resource& pr_2,	Private_Resource& pr_3, Private_Resource& pr_4, Private_Resource& pr_5)
{

	if (x==200)
		time3 = std::chrono::milliseconds(100);
	if (x == 300)
		time3 = std::chrono::milliseconds(40);

	start_time = std::chrono::system_clock::now();
	//std::cout << "start Procesor_" << get_n_procesor() << std::endl;
	start(x, common_resource,pr_0,pr_1,pr_2,pr_3,pr_4,pr_5);
}



void Base_Procesor::start(int x,Common_Resource& common_resource)
{
	
	//std::cout << "start\n";
	while (true)
	{
		
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		elapsed_seconds = end - start_time;
		common_resource.mutex_lock();
		//std::cout << "size " << common_resource.get_n_resourse()<<std::endl;
		Task * t;
		if (elapsed_seconds > time1)
			break;
		t = common_resource.get_element(get_n_procesor());
		
		common_resource.mutex_unlock();
		work(t);
	}
	//std::cout << "end Procesor_" << get_n_procesor() <<": "<<get_n_task_completed() <<std::endl;
	common_resource.mutex.unlock();
}
void Base_Procesor::start(int x, Private_Resource& common_resource)
{


	seconds time1 = std::chrono::seconds(10);
	//std::cout << "start2\n";
	while (true)
	{

		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		elapsed_seconds = end - start_time;
		common_resource.mutex_lock();
		//std::cout << "size " << common_resource.get_n_resourse() << std::endl;
		Task * t;
		if (elapsed_seconds > time1)
			break;
		t = common_resource.get_element(get_n_procesor());

		common_resource.mutex_unlock();
		work(t);
	}
	//std::cout << "end Procesor_" << get_n_procesor() << ": " << get_n_task_completed() << std::endl;
	common_resource.mutex.unlock();
}

void Base_Procesor::start(int x, Common_Resource& common_resource, 
	Private_Resource& pr_0, Private_Resource& pr_1, Private_Resource& pr_2,
	Private_Resource& pr_3, Private_Resource& pr_4, Private_Resource& pr_5) {
	
	planning(common_resource, pr_0, pr_1, pr_2, pr_3, pr_4, pr_5);
	//std::cout << "start2\n";
	while (true)
	{

		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		elapsed_seconds = end - start_time;
		pr_0.mutex_lock();
		//std::cout << "size " << pr_0.get_n_resourse() << std::endl;
		Task * t;
		if (elapsed_seconds > time1)
			break;
		t = pr_0.get_element(get_n_procesor());

		pr_0.mutex_unlock();
		work(t);
		if (elapsed_seconds > time2)
		{
			//std::cout << "s " << time2.count()<<std::endl;
			time2 = time2 + std::chrono::milliseconds(24);
			planning(common_resource, pr_0, pr_1, pr_2, pr_3, pr_4, pr_5);
		}
	}
	//std::cout << "end Procesor_" << get_n_procesor() << ": " << get_n_task_completed() << std::endl;
	pr_0.mutex.unlock();
}



void Base_Procesor::planning(Common_Resource& common_resource, Private_Resource& pr_0, Private_Resource& pr_1, Private_Resource& pr_2,
	Private_Resource& pr_3, Private_Resource& pr_4, Private_Resource& pr_5)
{
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	elapsed_seconds = end - start_time;

	//std::cout << "planning\n";
	while(true)
	{
		common_resource.mutex_lock();
		int *buf;
		

		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		elapsed_seconds = end - start_time;
		Task * t;
		if ((common_resource.get_n_resourse() == 0))
			break;
		t = common_resource.get_element();

		buf = t->n_procesor;
		int *min_n_procesor=buf;
		int min_n_procesor_size[3];
		
		for (int i=0;i<3;i++)
		{
			switch (min_n_procesor[i])
			{
			case(0):pr_0.mutex_lock(); min_n_procesor_size[i] = pr_0.private_resources.size(); pr_0.mutex_unlock(); break;
			case(1):pr_1.mutex_lock(); min_n_procesor_size[i] = pr_1.private_resources.size(); pr_1.mutex_unlock(); break;
			case(2):pr_2.mutex_lock(); min_n_procesor_size[i] = pr_2.private_resources.size();  pr_2.mutex_unlock(); break;
			case(3):pr_3.mutex_lock(); min_n_procesor_size[i] = pr_3.private_resources.size();  pr_3.mutex_unlock(); break;
			case(4):pr_4.mutex_lock(); min_n_procesor_size[i] = pr_4.private_resources.size(); pr_4.mutex_unlock(); break;
			case(5):pr_5.mutex_lock(); min_n_procesor_size[i] = pr_5.private_resources.size();  pr_5.mutex_unlock(); break;
			default:
				break;
			}
		}

		int min = 0;
		for (int i = 1; i < 3; i++)
		{
			if (min_n_procesor_size[i] < min_n_procesor_size[min])
				min = i;
		}

		switch (min_n_procesor[min])
		{
		case(0):pr_0.mutex_lock(); pr_0.private_resources.push_back(t); pr_0.mutex_unlock(); break;
		case(1):pr_1.mutex_lock(); pr_1.private_resources.push_back(t); pr_1.mutex_unlock(); break;
		case(2):pr_2.mutex_lock(); pr_2.private_resources.push_back(t);  pr_2.mutex_unlock(); break;
		case(3):pr_3.mutex_lock(); pr_3.private_resources.push_back(t);  pr_3.mutex_unlock(); break;
		case(4):pr_4.mutex_lock(); pr_4.private_resources.push_back(t); pr_4.mutex_unlock(); break;
		case(5):pr_5.mutex_lock(); pr_5.private_resources.push_back(t);  pr_5.mutex_unlock(); break;
		default:
			break;
		}

		if ((elapsed_seconds > time3)||(elapsed_seconds > time1))
		{
			//std::cout << "s " << time3.count() << std::endl;
			time3 =time3 + std::chrono::milliseconds(24);
			break;
		}
	
		
		common_resource.mutex_unlock();
	}
	common_resource.mutex_unlock();
	return;
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


