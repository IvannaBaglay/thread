// CPP program to demonstrate multithreading
// using three different callables. 
#include <iostream> 
#include <thread> 
#include"Base_Procesor.h"
#include"Procesor_1.h"
#include"Procesor_2.h"
#include"Procesor_3.h"
#include"Procesor_4.h"
#include"Procesor_5.h"
#include<ctime>
#include<chrono>
#include<random>
using namespace std;



int Task::n_task_all = 0;
int Task::seed_for_complexity = rand()%1000;
int Task::seed_for_n_procesor = rand()%10;
//вводиться користувачем через інтерфейс
//потужність процесорів
int Base_Procesor::power_0 = 70;
int Procesor_1::power_1 = 25;
int Procesor_2::power_2 = 10;
int Procesor_3::power_3 = 30;
int Procesor_4::power_4= 40;
int Procesor_5::power_5 = 50;

//параметри задач
int Task::upper = 100;
int Task::lower = 20;
int Task::probability = 0;



int main()
{
	Common_Resource common_resource;
	chrono::time_point<chrono::system_clock> start, end;
	cout << "Wait..." << endl;
	
	start = std::chrono::system_clock::now();
	// This thread is launched by using  
	// function pointer as callable 
	//thread th1(foo, 3);

	// This thread is launched by using 
	// function object as callable 
	thread th2(Base_Procesor(), 100, std::ref(common_resource));
	thread th3(Procesor_1(), 100, std::ref(common_resource));
	thread th4(Procesor_2(), 100, std::ref(common_resource));
	thread th5(Procesor_3(), 100, std::ref(common_resource));
	thread th6(Procesor_4(), 100, std::ref(common_resource));
	thread th7(Procesor_5(), 100, std::ref(common_resource));

	// Wait for thread t2 to finish 
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();
	th7.join();



	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	system("pause");
	return 0;
}