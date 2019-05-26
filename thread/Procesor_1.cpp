
#include"Procesor_1.h"
#include"Common_Resource.h"

int Procesor_1::get_power() {
	return power_1;
}
int Procesor_1::get_n_procesor() {
	return n_procesor;
}
int Procesor_1::get_n_task_completed() {
	return num_task_completed;
}

void Procesor_1::add_n_task_completed() {
	num_task_completed++;
}
