#include <iostream>
#include <Windows.h>
#pragma warning(disable: 4996)

extern "C" {
	void BREAKL() {
		std::cout << std::endl;
	}

	void OutputInt(int a) {
		std::cout << a;
	}

	void OutputStr(char* ptr) {
		setlocale(LC_ALL, "RUS");
		if (ptr == nullptr) {
			std::cout << std::endl;
			return;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
	
			
	}

	void OutputIntLn(int a) {
		std::cout << a << std::endl;
	}

	void OutputStrLn(char* ptr) {

		setlocale(LC_ALL, "RUS");
		if (ptr == nullptr) {
			std::cout << std::endl;
			return;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		std::cout << std::endl;
	}

	int ABS(int a) {
		return abs(a);
	}
	int DEG(int a, int degree) {
		return pow(a, degree);
	}
}