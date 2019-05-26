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
#include"start.h"
using namespace std;



int Task::n_task_all = 0;
int Task::seed_for_complexity = rand()%100000;
int Task::seed_for_n_procesor = rand()%10;
//ââîäèòüñÿ êîðèñòóâà÷åì ÷åðåç ³íòåðôåéñ
//ïîòóæí³ñòü ïðîöåñîð³â
int Base_Procesor::power_0 = 0;
int Procesor_1::power_1 = 25;
int Procesor_2::power_2 = 10;
int Procesor_3::power_3 = 30;
int Procesor_4::power_4= 40;
int Procesor_5::power_5 = 50;

//ïàðàìåòðè çàäà÷
int Task::upper = 100;
int Task::lower = 20;
int Task::probability = 0;



int start_program()
{
	system("pause");
	srand(time(NULL));
	printf("START");
	double sum_power = 0;
	double sum_power_all = 0;

/*	std::cout <<  <<Base_Procesor::power_0<<std::endl;
	std::cout << Procesor_1::power_1 << std::endl;
	std::cout << Procesor_2::power_2 << std::endl;
	std::cout << Procesor_3::power_3 << std::endl;
	std::cout << Procesor_4::power_4 << std::endl;
	std::cout << Procesor_5::power_5 << std::endl;

	std::cout << Task::upper << std::endl;
	std::cout << Task::lower << std::endl;
	std::cout << Task::probability << std::endl;*/



	Common_Resource common_resource;
	Common_Resource common_resource1;
	common_resource1.generate_resource();
	Common_Resource common_resource2;
	common_resource2.generate_resource();
	Private_Resource private_resource0;
	Private_Resource private_resource1;
	Private_Resource private_resource2;
	Private_Resource private_resource3;
	Private_Resource private_resource4;
	Private_Resource private_resource5;
	common_resource.generate_resource();
	private_resource0.generate_resource();
	private_resource1.generate_resource();
	private_resource2.generate_resource();
	private_resource3.generate_resource();
	private_resource4.generate_resource();
	private_resource5.generate_resource();
	chrono::time_point<chrono::system_clock> start, end;
	cout << "Wait..." << endl;
	
	start = std::chrono::system_clock::now();
	// This thread is launched by using  
	// function pointer as callable 
	//thread th1(foo, 3);

	// This thread is launched by using 
	// function object as callable 


//	thread th2(Base_Procesor(), 100, std::ref(common_resource));

	std::cout << "\nFIFO\n";
	cout << "Wait..." << endl;
	thread th3(Procesor_1(), 100, std::ref(common_resource));
	thread th4(Procesor_2(), 100, std::ref(common_resource));
	thread th5(Procesor_3(), 100, std::ref(common_resource));
	thread th6(Procesor_4(), 100, std::ref(common_resource));
	thread th7(Procesor_5() ,100, std::ref(common_resource));
	
	// Wait for thread t2 to finish 

	//th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();
	th7.join();
	

	sum_power_all = (Procesor_1::power_1 + Procesor_2::power_2 + Procesor_3::power_3 + Procesor_4::power_4
		+ Procesor_5::power_5) * 1000;

	std::cout << " task completed " <<500000 - common_resource.get_n_resourse() << std::endl;
	cout << "KPD 1 " << (500000 - common_resource.get_n_resourse()) / sum_power_all << endl;
	cout << "KPD 2 " << (500000 - common_resource.get_n_resourse()) / sum_power_all << endl;
	////////////////////////////////////////////////////////////////////////////////////////
	//окремий процесор-планувальник
	
	std::cout << "\nONLY PLANNING\n";
	cout << "Wait..." << endl;
	thread th22(Base_Procesor(), 100, 
		std::ref(common_resource1), std::ref(private_resource0),std::ref(private_resource1), std::ref(private_resource2),
		std::ref(private_resource3), std::ref(private_resource4), std::ref(private_resource5)
	);
//thread th23(Procesor_1(), 100, std::ref(private_resource1));
	thread th24(Procesor_2(), 100, std::ref(private_resource2));
	thread th25(Procesor_3(), 100, std::ref(private_resource3));
	thread th26(Procesor_4(), 100, std::ref(private_resource4));
	thread th27(Procesor_5(), 100, std::ref(private_resource5));


	th22.join();
	//th23.join();
	th24.join();
	th25.join();
	th26.join();
	th27.join();



	std::cout << " task completed " << 500000 - common_resource1.get_n_resourse() << std::endl;
	
	sum_power = (Procesor_2::power_2 + Procesor_3::power_3 + Procesor_4::power_4
		+ Procesor_5::power_5) * 1000;

	cout << "KPD 1 " << (500000 - common_resource1.get_n_resourse()) / sum_power_all << endl;
	cout << "KPD 2 " << (500000 - common_resource1.get_n_resourse()) / sum_power << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////
	//найсильніший планувальник
	std::cout << "\nWORKING + PLANNING\n";
	cout << "Wait..." << endl;
	Base_Procesor::power_0 = Procesor_1::power_1;
	if (Base_Procesor::power_0 < Procesor_2::power_2)
		Base_Procesor::power_0 = Procesor_2::power_2;
	if (Base_Procesor::power_0 < Procesor_3::power_3)
		Base_Procesor::power_0 = Procesor_3::power_3;
	if (Base_Procesor::power_0 < Procesor_4::power_4)
		Base_Procesor::power_0 = Procesor_4::power_4;
	if (Base_Procesor::power_0 < Procesor_5::power_5)
		Base_Procesor::power_0 = Procesor_5::power_5;


	thread th432(Base_Procesor(), 300,
		std::ref(common_resource2), std::ref(private_resource0), std::ref(private_resource1), std::ref(private_resource2),
		std::ref(private_resource3), std::ref(private_resource4), std::ref(private_resource5)
	);
	thread th433(Procesor_1(), 300, std::ref(private_resource1));
	thread th434(Procesor_2(), 300, std::ref(private_resource2));
	thread th435(Procesor_3(), 300, std::ref(private_resource3));
	thread th436(Procesor_4(),300, std::ref(private_resource4));
	//thread th37(Procesor_5(), 200, std::ref(private_resource5));

	//std::cout << "POWER BASE" << Base_Procesor::power_0;

	th432.join();
	th433.join();
	th434.join();
	th435.join();
	th436.join();
	//th37.join();
	std::cout << " task completed " << 500000 - common_resource2.get_n_resourse() << std::endl;
	sum_power = (Procesor_1::power_1 + Procesor_3::power_3 + Procesor_4::power_4
		+ (Base_Procesor::power_0)*0.7) * 1000;

	cout << "KPD 1 " << (500000 - common_resource2.get_n_resourse()) / sum_power_all << endl;
	cout << "KPD 2 " << (500000 - common_resource2.get_n_resourse()) / sum_power << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////
	//найсильніший планувальник
	std::cout << "\nWORKING + PLANNING + Optimal time \n";
	cout << "Wait..." << endl;
	Base_Procesor::power_0 = Procesor_1::power_1;
	if (Base_Procesor::power_0<Procesor_2::power_2)
		Base_Procesor::power_0 = Procesor_2::power_2;
	if (Base_Procesor::power_0 < Procesor_3::power_3)
		Base_Procesor::power_0 = Procesor_3::power_3;
	if (Base_Procesor::power_0 < Procesor_4::power_4)
		Base_Procesor::power_0 = Procesor_4::power_4;
	if (Base_Procesor::power_0 < Procesor_5::power_5)
		Base_Procesor::power_0 = Procesor_5::power_5;


	thread th32(Base_Procesor(), 200,
		std::ref(common_resource2), std::ref(private_resource0), std::ref(private_resource1), std::ref(private_resource2),
		std::ref(private_resource3), std::ref(private_resource4), std::ref(private_resource5)
	);
	thread th33(Procesor_1(), 200, std::ref(private_resource1));
	thread th34(Procesor_2(), 200, std::ref(private_resource2));
	thread th35(Procesor_3(), 200, std::ref(private_resource3));
	thread th36(Procesor_4(), 200, std::ref(private_resource4));
	//thread th37(Procesor_5(), 200, std::ref(private_resource5));

	//std::cout << "POWER BASE" << Base_Procesor::power_0;

	th32.join();
	th33.join();
	th34.join();
	th35.join();
	th36.join();
	//th37.join();
	

	std::cout << " task completed " << 500000 - common_resource2.get_n_resourse() << std::endl;

	sum_power = (Procesor_1::power_1 + Procesor_3::power_3 + Procesor_4::power_4
		+ (Base_Procesor::power_0)*0.9) * 1000;

	cout << "KPD 1 " << (500000 - common_resource2.get_n_resourse()) / sum_power_all << endl;
	cout << "KPD 2 " << (500000 - common_resource2.get_n_resourse()) / sum_power << endl;

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << "all time: " << elapsed_seconds.count() << "s\n";

	system("pause");
	return 0;
}