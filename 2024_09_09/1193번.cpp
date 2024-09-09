#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

/* 
	1193번 분수 찾기
    // 배열이 필요한가?
    // 규칙 각각의 대각선에 번호를 부여하면 홀수는 분모 증가, 짝수는 분자 증가
    // 대각선의 번호와 대각선 내의 분수 개수는 동일하게 지정할 수 있음.
*/

int main() {

	int X;
	cin >> X;

	int diagonal = 1; //대각선의 번호
	int sum = 0; // 현재까지 지나간 분수의 개수를 누적
	// 대각선 순서에 따라 해당 순서와 같은 개수의 분수가 존재하므로.

	while (sum + diagonal < X) //X번째 분수가 어느 대각선에 있는가?
	{
		sum = sum + diagonal; // 
		diagonal++;
	}

	int offset = X - sum; // 대각선 내의 번호이자, 숫자 증가 역할
	int numerator;
	int denominator;
	if (diagonal % 2 == 0) {
		// 대각선 짝수 -> 분자 증가, 분모 감소
		numerator = offset;
		denominator = diagonal - offset + 1;
	}
	else {
		numerator = diagonal - offset + 1;
		denominator = offset;
	}

	cout << numerator << "/" << denominator;
	return 0; 
}
