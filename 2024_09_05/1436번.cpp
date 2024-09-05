#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main() {
	int count = 0 ,N;
	//int current_number = 666; //틀린곳 666을 시작으로 하면 요구하는 바에 비해 한칸 먼저 출발한 격임.
	int current_number = 0;

	cin >> N;

	//string my_string;
	//종말의 수는 적어도 6이 3개 이상 들어간다.

	while (count != N)
	{
		current_number++;
		string my_str = to_string(current_number);
		/*
		if (my_str.find("666") != NULL) count++;  //틀린 곳
		find 함수는 찾지 못할 경우 string::npos라는 것을 반환함.
		*/
		if (my_str.find("666") != string::npos) count++;
	}
	cout << current_number;
	

	return 0;
}
