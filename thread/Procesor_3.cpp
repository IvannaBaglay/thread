#include"Procesor_3.h"


int Procesor_3::get_power() {
	return power_3;
}
int Procesor_3::get_n_procesor() {
	return n_procesor;
}
int Procesor_3::get_n_task_completed() {
	return num_task_completed;
}
void Procesor_3::add_n_task_completed() {
	num_task_completed++;
}