#include"Procesor_4.h"


int Procesor_4::get_power() {
	return power_4;
}
int Procesor_4::get_n_procesor() {
	return n_procesor;
}
int Procesor_4::get_n_task_completed() {
	return num_task_completed;
}
void Procesor_4::add_n_task_completed() {
	num_task_completed++;
}