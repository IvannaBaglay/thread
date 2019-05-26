#pragma once
#ifndef __SOURCE_HPP__
#define __SOURCE_HPP__

#include <Windows.h>
#include<iostream>
#include <cctype>
#include <fstream>
#include"Procesor_1.h"
#include"Procesor_2.h"
#include"Procesor_3.h"
#include"Procesor_4.h"
#include"Procesor_5.h"

//#include "Threads.hpp"

long int processor1, processor2, processor3, processor4, processor5, up_bound, low_bound;
double probab;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

#endif //__SOURCE_HPP__
