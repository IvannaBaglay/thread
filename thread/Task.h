#pragma once
#include<iostream>
#define N_PROCESOR 6
class Task {
public:
	int * n_procesor;//������ ���������, �� ������ ���������� ���� ������
	int complexity; //��������� ������ 
	int n_task;//����� ������
	static int n_task_all;//������� ��� �����
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
