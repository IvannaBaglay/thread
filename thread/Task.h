#pragma once
#include<iostream>
#define N_PROCESOR 6
class Task {
public:
	int * n_procesor;//номери процесорів, що можуть виконувати дану задачу
	int complexity; //складність задачі 
	int n_task;//номер задачі
	static int n_task_all;//кількість всіх задач
	Task(int n); 
	~Task();

	static int upper;
	static int lower;
	static int probability;
protected:

	int getRandom(int &seed, int m);
	const int a = 47;
	const int c = 19;
	static int seed_for_complexity;
	static int seed_for_n_procesor;

	
private:
	
};
