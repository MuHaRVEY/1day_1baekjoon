#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

// 15649번 "백트랙킹"
//  1부터 N까지 자연수 중에서 
// 중복 없이 M개를 고른 수열

/*
	1~N까지 각각 M개를 고르되 뽑힌 적 없는 수열이어야함.
*/

int N, M;
bool visited[9]; // 1~8까지의 자연수이므로 visited[1] ~ visited[8]까지 사용할 것이므로 크기 9의 배열로 일단 선언
vector<int> sequence_vector;

void backtracking(int depth) { //N을 depth라고 하고 봐도 무방할듯.
	if (depth == M) {
		for (int i = 0; i < sequence_vector.size(); i++) {
			cout << sequence_vector[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) { //visit한적 없다면 
			visited[i] = true;
			sequence_vector.push_back(i); //push_back은 vector의 마지막에 새로운 원소를 추가하는 과정. (임시 개체는 사용후 파괴됨.)
			backtracking(depth + 1);
			sequence_vector.pop_back(); //중요한 부분 pop_back()을 통해 마지막 숫자를 제거해주어야함. // 학교 수업때도 교수님이 강조하시던 내용. 다음 반복에서의 오류를 방지. 백트랙킹!
			visited[i] = false; //방문 여부도 초기화
		}
	}

}

int main() {

	cin >> N >> M;

	backtracking(0);
	return 0;
}
