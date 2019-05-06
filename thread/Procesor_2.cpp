#include"Procesor_2.h"

int Procesor_2::get_power() {
	return power_2;
}
int Procesor_2::get_n_procesor() {
	return n_procesor;
}
int Procesor_2::get_n_task_completed() {
	return num_task_completed;
}
void Procesor_2::add_n_task_completed() {
	num_task_completed++;
}