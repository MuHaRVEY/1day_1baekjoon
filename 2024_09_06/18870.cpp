#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<string>
#include<vector>
#include<algorithm> //sort뿐만 아니라 unique, lower_bound 등을 사용할 수 있다고 함.
using namespace std;

int coordinate[1000000];
int N;
int main() {
	
	
	cin >> N;

	vector<int> original(N);
	vector<int>sorted(N);

	for (int i = 0; i < N; i++)
	{
		cin >> coordinate[i];
		original[i] = coordinate[i];
	}

	sorted = original; //복사
	sort(sorted.begin(), sorted.end()); //sorted 벡터를 정렬함.
	
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	//unique는 연속되는 중복요소를 제거한다.
	// 그 상태에서 나머지를 재배열 하고, 반환 값은 마지막 요소의 다음 위치이다.
	/*
		example
		sorted = {1, 2, 2, 3, 3, 4}
		sorted = {1, 2, 3, 4, ?, ?}
		반환되는 값은 "sorted.begin() + 4"

		즉 위의 코드는 erase를 통해 필요 없어진 불필요한 부분들을 제거해주고 있음.
	*/

	for (int i = 0; i < N; i++)
	{
		int compressed_answer = lower_bound(sorted.begin(), sorted.end(), original[i])-sorted.begin();
		/*
		lower_bound(first, last, value)는 정렬된 범위 [first, last) 내에서 
		value보다 크거나 같은 첫 번째 요소를 찾음.
		그 뒤에 iterator를 반환
		즉, 정렬된 sorted에서 original 배열의 i번째 값 이상의 값이 나오는 처음 위치를 찾는다.
		sorted.begin() 즉, 배열의 맨앞 시작 위치를 빼줌으로써 인덱스를 통한 순위를 얻을 수 있음.

		즉, lower_bound는 범위내에서 특정 값의 위치를 빠르게 찾을 수 있는 함수임.
		*/
		cout << compressed_answer << " ";
	}
	return 0;
}
