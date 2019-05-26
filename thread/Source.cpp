#include "Source.hpp"
#include"start.h"
//processing the messages sent by our window
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	static HWND proc1 = NULL, proc2 = NULL, proc3 = NULL, proc4 = NULL, proc5 = NULL;
	static HWND	lower_b = NULL, upper_b = NULL, probability = NULL, button = NULL;
	static HWND label1 = NULL, label2 = NULL, label3 = NULL, label4 = NULL, label5 = NULL;
	static HWND label6 = NULL, label7 = NULL, label8 = NULL;
	HDC hdcStatic = NULL;
	switch (msg) {
		//when the window is created
	case WM_CREATE: {
		label1 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", " Power of Processor 1:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 128, 20, 150, 20, hwnd, NULL, NULL, NULL);
		proc1 = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 150, 50, 100, 20, hwnd, NULL, NULL, NULL);
		label2 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", " Power of Processor 2:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 128, 120, 150, 20, hwnd, NULL, NULL, NULL);
		proc2 = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 150, 150, 100, 20, hwnd, NULL, NULL, NULL);
		label3 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", " Power of Processor 3:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 128, 220, 150, 20, hwnd, NULL, NULL, NULL);
		proc3 = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 150, 250, 100, 20, hwnd, NULL, NULL, NULL);
		label4 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", " Power of Processor 4:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 128, 320, 150, 20, hwnd, NULL, NULL, NULL);
		proc4 = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 150, 350, 100, 20, hwnd, NULL, NULL, NULL);
		label5 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", " Power of Processor 5:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 128, 420, 150, 20, hwnd, NULL, NULL, NULL);
		proc5 = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 150, 450, 100, 20, hwnd, NULL, NULL, NULL);
		label6 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", "Task Complexity Lower Bound:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 550, 20, 205, 20, hwnd, NULL, NULL, NULL);
		lower_b = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 50, 100, 20, hwnd, NULL, NULL, NULL);
		label7 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", "Task Complexity Upper Bound:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 550, 120, 205, 20, hwnd, NULL, NULL, NULL);
		upper_b = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 150, 100, 20, hwnd, NULL, NULL, NULL);
		label8 = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", "Probability of task appear:", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, 570, 220, 180, 20, hwnd, NULL, NULL, NULL);
		probability = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 600, 250, 100, 20, hwnd, NULL, NULL, NULL);
		button = CreateWindow(TEXT("Button"), TEXT("Start"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 630, 400, 70, 70, hwnd, HMENU(9999), (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		UpdateWindow(hwnd);
		break;
	}
					//for making a labels with a white background
	case WM_CTLCOLORSTATIC: {
		hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
	}
							//when button is pressed
	case WM_COMMAND: {
		if (LOWORD(wParam == 9999)) {
			char buffer[20];
			bool exit_flag = false, empty_field = false, error_occured = false;
			long int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, lb = 0, ub = 0;
			double prb = -1.0;
			for (int i = 0; i < 8; i++) {
				switch (i) {
				case 0: {
					GetWindowText(proc1, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Power of Processor 1\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Power of Processor 1\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							p1 = atol(buffer);
						}
					}
					break;
				}
				case 1: {
					GetWindowText(proc2, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Power of Processor 2\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Power of Processor 2\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							p2 = atol(buffer);
						}
					}
					break;
				}
				case 2: {
					GetWindowText(proc3, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Power of Processor 3\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Power of Processor 3\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							p3 = atol(buffer);
						}
					}
					break;
				}
				case 3: {
					GetWindowText(proc4, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Power of Processor 4\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Power of Processor 4\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							p4 = atol(buffer);
						}
					}
					break;
				}
				case 4: {
					GetWindowText(proc5, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Power of Processor 5\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Power of Processor 5\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							p5 = atol(buffer);
						}
					}
					break;
				}
				case 5: {
					GetWindowText(lower_b, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Task Complexity Lower Bound\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
						empty_field = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Task Complexity Lower Bound\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							lb = atol(buffer);
						}
					}
					break;
				}
				case 6: {
					GetWindowText(upper_b, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Task Complexity Upper Bound\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						for (unsigned j = 0; j < strlen(buffer); j++) {
							if (isdigit((int)buffer[j]) == 0) {
								exit_flag = true;
								break;
							}
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Task Complexity Upper Bound\" must be a number greater than 0!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
							break;
						}
						else {
							ub = atol(buffer);
							if (!empty_field) {
								if (ub < lb) {
									MessageBox(NULL, "\"Task Complexity Upper Bound\" must be equal or greater than \"Task Complexity Lower Bound\"!", "Error!",
										MB_ICONEXCLAMATION | MB_OK);
									error_occured = true;
								}
							}
						}
					}
					break;
				}
				case 7: {
					GetWindowText(probability, buffer, 20);
					if (!strlen(buffer)) {
						MessageBox(NULL, "\"Probability of task appear\" field is empty!", "Error!",
							MB_ICONEXCLAMATION | MB_OK);
						error_occured = true;
					}
					else {
						unsigned j = 0;
						while (j < strlen(buffer)) {
							switch (j) {
							case 0: {
								if (isdigit((int)buffer[j]) == 0)
									exit_flag = true;
								break;
							}
							case 1: {
								if (buffer[j] != '.')
									exit_flag = true;
								break;
							}
							default: {
								if (isdigit((int)buffer[j]) == 0)
									exit_flag = true;
							}
							}
							if (exit_flag) {
								break;
							}
							j++;
						}
						if (exit_flag) {
							MessageBox(NULL, "\"Probability of task appear\" must be a number in a range of   [0 - 1]!", "Error!",
								MB_ICONEXCLAMATION | MB_OK);
							exit_flag = !exit_flag;
							error_occured = true;
						}
						else {
							prb = atof(buffer);
							if ((prb < 0) || (prb > 1)) {
								MessageBox(NULL, "\"Probability of task appear\" must be in a range of [0 - 1]!", "Error!",
									MB_ICONEXCLAMATION | MB_OK);
								error_occured = true;
							}
						}
					}
					break;
				}
				}
			}
			if (!error_occured) {
				Base_Procesor::power_0;//для планувань 
				Procesor_1::power_1=p1;
				Procesor_2::power_2=p2;
				Procesor_3::power_3=p3;
				Procesor_4::power_4=p4;
				Procesor_5::power_5=p5;
				Base_Procesor::power_0=p1+p2+p3+p4+p5;//для планувань найсильніший
				processor1 = p1;
				processor2 = p2;
				processor3 = p3;
				processor4 = p4;
				processor5 = p5;
				Task::upper = ub;
				Task::lower = lb;
				Task::probability = prb;
				up_bound = ub;
				low_bound = lb;
				probab = prb;
				AllocConsole();

				errno_t err;
				FILE *stream;
				err = freopen_s(&stream, "CONOUT$", "w+", stdout);
				//print();
				start_program();
				//std::cout << "sssd";
			}
		}
		break;
	}
					 //when window is closed by the control panel
	case WM_CLOSE: {
		DestroyWindow(hwnd);
		break;
	}
				   //when the window is destroyed
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
					 //in any other case
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//name of our future window class
	const char ClassName[] = "Window_Class_Name";
	//window class example
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	//filling and registring our window class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = ClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	//creating main window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		ClassName,
		"Lab in Computer Systems made by Baglai && Marchenko, KV62, FAM",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 900, 600,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//processing the messages sent by our window
	while (GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
