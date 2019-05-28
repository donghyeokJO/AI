#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define depth 7                                                                     //휴리스틱 함수를 사용하여 다음 수를 결정할 때 7수 앞까지 내다볼 것이다. 
#define c_num 7                                                                     //각 노드의 자식노드의 개수

int heuristic_function(int arr[][7], int turn) {                                    //노드에 대한 휴리스틱 값을 찾아주는 함수이다. --아이디어 회의: 고도환 조동혁, 코드 작성: 고도환 주석: 조동혁
	int winning_line[6][7] = { { 3, 4, 5, 7, 4, 3 },{ 4, 6, 8, 10, 8, 6, 4 },{ 5, 8, 11, 13, 11, 8, 5 },{ 5, 8, 11, 13, 11, 8, 5 },{ 4, 6, 8, 10, 8, 6, 4 },{ 3, 4, 5, 7, 4, 3 } };
	//보드의 각 칸 별로 이길 수 있는 경우의 수를 배열에 저장하여 가중치와 곱해 휴리스틱 값 계산에 사용한다. 

	int i, j;                                                       //for문에 사용될 변수들
	int value = 0;                                                   //value값 초기화


	const int m2 = 10;                                                              //7수 앞을 내다본 보드 상태에서 자신의 돌이 2개 이어져 있는 경우의 휴리스틱 가중치.
	const int m3 = 20;                                                              //7수 앞을 내다본 보드 상태에서 자신의 돌이 3개 이어져 있는 경우의 휴리스틱 가중치.
	const int m4 = 100;                                                             //7수 앞을 내다본 보드 상태에서 자신의 돌이 4개 이어져 있는 경우의 휴리스틱 가중치.
	const int y2 = 10;                                                              //7수 앞을 내다본 보드 상태에서 상대의 돌이 2개 이어져 있는 경우의 휴리스틱 가중치.
	const int y3 = 20;                                                              //7수 앞을 내다본 보드 상태에서 상대의 돌이 3개 이어져 있는 경우의 휴리스틱 가중치.
	const int y4 = 100;                                                             //7수 앞을 내다본 보드 상태에서 상대의 돌이 4개 이어져 있는 경우의 휴리스틱 가중치.

	for (i = 0; i < 6; i++) {                                                         //7수 앞을 내다본 보드 상태에서 가로 방향으로 자신의 돌이 2개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j < 6; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i][j + 1]) * m2;
				j += 2;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7수 앞을 내다본 보드 상태에서 가로 방향으로 자신의 돌이 3개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2]) * m3;
				j += 3;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7수 앞을 내다본 보드 상태에서 가로 방향으로 자신의 돌이 4개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2] + winning_line[i][j + 3]) * m4;
			}
		}
	}


	for (j = 0; j < 7; j++) {                                                         //7수 앞을 내다본 보드 상태에서 세로 방향으로 자신의 돌이 2개 이어져 있는 경우에 value값에 가중치 부여.
		for (i = 0; i < 5; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j]) * m2;
				i += 2;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                         //7수 앞을 내다본 보드 상태에서 세로 방향으로 자신의 돌이 3개 이어져 있는 경우에 value값에 가중치 부여.
		for (i = 0; i < 3; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j]) * m3;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                         //7수 앞을 내다본 보드 상태에서 세로 방향으로 자신의 돌이 4개 이어져 있는 경우에 value값에 가중치 부여.
		for (i = 0; i < 2; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j] + winning_line[i + 3][j]) * m4;
			}
		}
	}


	for (i = 0; i <= 4; i++) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌상->우하) 방향으로 자신의 돌이 2개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j + 1]) * m2;
				i += 2;
				j += 2;
			}
		}
	}

	for (i = 0; i <= 3; i++) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌상->우하) 방향으로 자신의 돌이 3개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2]) * m3;
			}
		}
	}

	for (i = 0; i <= 2; i++) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌상->우하) 방향으로 자신의 돌이 4개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2] + winning_line[i + 3][j + 3]) * m4;
			}
		}
	}


	for (i = 5; i >= 1; i--) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌하->우상) 방향으로 자신의 돌이 2개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i - 1][j + 1]) * m2;
				i -= 2;
				j += 2;
			}
		}
	}

	for (i = 5; i >= 2; i--) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌하>우상) 방향으로 자신의 돌이 3개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2]) * m3;
			}
		}
	}

	for (i = 5; i >= 3; i--) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌하->우상) 방향으로 자신의 돌이 4개 이어져 있는 경우에 value값에 가중치 부여.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == arr[i - 3][j + 3] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2] + winning_line[i - 3][j + 3]) * m4;
			}
		}
	}

	turn = 3 - turn;                                                               //상대가 이기는 경우에 대해 가중치를 제거해 주기 위해 turn을 자신에서 상대로 바꾸어 준다. 

	for (i = 0; i < 6; i++) {                                                         //7수 앞을 내다본 보드 상태에서 가로 방향으로 상대의 돌이 2개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j < 6; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i][j + 1]) * y2;
				j += 2;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7수 앞을 내다본 보드 상태에서 가로 방향으로 상대의 돌이 3개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2]) * y3;
				j += 3;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7수 앞을 내다본 보드 상태에서 가로 방향으로 상대의 돌이 4개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2] + winning_line[i][j + 3]) * y4;
			}
		}
	}


	for (j = 0; j < 7; j++) {                                                         //7수 앞을 내다본 보드 상태에서 세로 방향으로 상대의 돌이 2개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (i = 0; i < 5; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j]) * y2;
				i += 2;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                          //7수 앞을 내다본 보드 상태에서 세로 방향으로 상대의 돌이 3개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (i = 0; i < 3; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j]) * y3;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                         //7수 앞을 내다본 보드 상태에서 세로 방향으로 상대의 돌이 4개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (i = 0; i < 2; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j] + winning_line[i + 3][j]) * y4;
			}
		}
	}


	for (i = 0; i <= 4; i++) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌상->우하) 방향으로 상대의 돌이 2개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j + 1]) * y2;
				i += 2;
				j += 2;
			}
		}
	}
	
	for (i = 0; i <= 3; i++) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌상->우하) 방향으로 상대의 돌이 3개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2]) * y3;
			}
		}
	}

	for (i = 0; i <= 2; i++) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌상->우하) 방향으로 상대의 돌이 4개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2] + winning_line[i + 3][j + 3]) * y4;
			}
		}
	}


	for (i = 5; i >= 1; i--) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌하->우상) 방향으로 상대의 돌이 2개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i - 1][j + 1]) * y2;
				i -= 2;
				j += 2;
			}
		}
	}

	for (i = 5; i >= 2; i--) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌하->우상) 방향으로 상대의 돌이 3개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2]) * y3;
			}
		}
	}

	for (i = 5; i >= 3; i--) {                                                         //7수 앞을 내다본 보드 상태에서 대각선(좌하->우상) 방향으로 상대의 돌이 4개 이어져 있는 경우에 value값에서 가중치 빼준다.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == arr[i - 3][j + 3] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2] + winning_line[i - 3][j + 3]) * y4;
			}
		}
	}

	return value; //계산한 value값 반환해준다. 
}

typedef struct tree {                                                               //search_tree구조체 정의. 다음의 가능한 수를 그 노드의 자식 노드로 본다. --코드 구현 고도환 , 주석 조동혁
	int value;                                                                     //노드의 휴리스틱 값
	int sequence[depth];                                                            //해당 노드까지 오는 부모 노드들의 경로
	struct tree *parent;                                                            //부모 노드
	struct tree *child[c_num];                                                         //7개의 자식 노드
}search_tree;

void node_initialize(search_tree *head) {                                                // 노드 초기화 -- 코드 구현 고도환, 주석 조동혁
	head->parent = NULL;                                                            //부모 노드를 NULL로 초기화
	head->value = -2;                                                               //value값을 무의미한 값으로 초기화
	for (int i = 0; i < c_num; i++)                                                      //7개의 자식 노드 NULL로 초기화
		head->child[i] = NULL;

	for (int i = 0; i < depth; i++)                                                      //경로 값 무의미한 값으로 초기화
		head->sequence[i] = -1;
}

void insert_node(search_tree *head, int child_num) {                                       //search_tree에 노드 삽입 --코드 구현 고도환, 주석 조동혁
	search_tree *temp = head;                                                         //새로운 search tree만들어서 head 저장해줌.
	search_tree *new_node = (search_tree *)malloc(sizeof(search_tree));                           //삽입할 새로운 노드 만들어줌. 
	node_initialize(new_node);                                                         // node_initialize함수 사용하여 새로 만든 노드 초기화 해줌. 

	for (int i = 0; i < depth; i++)                                                      //새로운 노드의 sequence에 head의 sequence 넣어줌. 
		new_node->sequence[i] = head->sequence[i];

	new_node->value = -1;                                                            //새로운 노드의 value값 무의미한 값으로 초기화
	temp->child[child_num] = new_node;                                                   //head를 저장했던 temp노드의 child_num번째 자식 노드에 new_node넣어줌. 
	new_node->parent = temp;                                                         // 새로운 노드의 부모 노드를 temp노드로 설정해줌. 
}

int overflow = 0;                                                                  //보드에 새로운 값을 넣는 과정에서 overflow가 일어났는지 여부를 체크하기 위한 전역 변수. 

void put(int arr[][7], int column, int &turn) {                                              // 게임 보드에 값 넣어줌. --코드 구현 고도환, 주석 조동혁
	int i;                                                                        //for문 위한 변수
	for (i = 5; i >= 0; i--) {                                                          //게임 보드의 해당 칸이 비어있을 경우 turn(ai와 사람 구별, 1일 때 사람, 2일 때 ai)
		if (arr[i][column] == 0) {
			arr[i][column] = turn;
			break;
		}
	}

	if (i == -1) {                                                                  //for문을 break에 걸리지 않고 완전히 통과 했을 때, 즉 해당 column에 빈 칸이 없을 때, overflow가 발생하므로 overflow를 1로 설정하고 함수를 종료함. 
		overflow = 1;
		return;
	}

	if (turn == 1) turn = 2;                                                         //사람과 ai의 turn을 바꿔줌 
	else if (turn == 2) turn = 1;
}

void branch(search_tree *pre, int num) {                                                //search_tree를 단말노드까지 확장해줌. --아이디어 회의: 고도환 조동혁 코드 구현:고도환(*) 조동혁 주석:조동혁
	if (num == 0) return;                                                            //단말노드까지 모두 확장한 경우 더 이상 재귀함수 호출하지 않고 종료. 

	num--;                                                                        //한 단계 낮은 depth에서 호출하기 위해 1 줄여줌. 
	for (int i = 0; i < c_num; i++) {
		insert_node(pre, i);                                                         //pre의 i번째 자식노드를 추가해줌. 
		pre->child[i]->sequence[depth - num - 1] = i;                                       //pre의 i번째 자식노드에 대해 부모 노드의 경로를 파악하기 위한 sequence를 update해줌. 
		branch(pre->child[i], num);                                                      //pre의 자식 노드에 대해 branch를 재귀적으로 호출하여, 단말 노드까지 같은 작업이 반복될 수 있도록 하고 결과적으로 search-tree를 단말노드까지 확장해줌.
	}
}

/*void print_tree(search_tree *pre, int num) {
int i, j;
if (num != 0) {
for (i = 0; i < c_num; i++) {
printf("%d ", pre->child[i]->value);
if (num == 1) {
for (j = 0; j <= depth - num; j++)
printf("%d->", pre->child[i]->sequence[j]);
printf(" ");
}
}
printf("\t\t%d\n", num);
num--;
for (i = 0; i < c_num; i++) {
print_tree(pre->child[i], num);
}
}
}*/

search_tree *fmax(search_tree *pre) {                                                   //minimax 알고리즘에서 max부분 --아이디어 회의: 고도환(*),조동혁 코드작성: 고도환,조동혁 주석: 조동혁
	int max = pre->child[0]->value;                                                      //max값을 가장 왼쪽 자식노드의 value값으로 초기화
	int count = 0;                                                                  //overflow가 발생한 경우 비교에서 제외하기 위해 overflow가 발생한 노드의 개수 counter.
	search_tree *temp = pre->child[0];                                                                  //반환할 노드를 가장 왼쪽 자식 노드로 초기화

	for (int i = 0; i < c_num; i++) {                                                   //overflow가 발생한 자식 노드의 개수 count해줌
		if (pre->child[i]->value == -10000) count++;
	}

	if (count != 7) {                                                               //하나라도 overflow가 발생하지 않는 노드가 있는 경우
		for (int i = 0; i < c_num; i++) {                                                //overflow가 발생하지 않은 최초의 자식노드를 찾아 max값과 temp값을 다시 초기화해줌. 
			if (pre->child[i]->value != -10000) {
				max = pre->child[i]->value;
				temp = pre->child[i];
				break;
			}
		}

		for (int i = 0; i < c_num; i++) {                                                //다시 초기화 한 max값을 바탕으로 overflow가 발생하지 않는 자식 노드들 중 가장 큰 value값을 가지고 있는 노드를 찾아 temp에 저장.
			if (max <= pre->child[i]->value && pre->child[i]->value != -10000) {
				max = pre->child[i]->value;
				temp = pre->child[i];
			}
		}
	}

	return temp;                                                                  //가장 큰 value값을 가지는 노드 반환
}

search_tree *fmin(search_tree *pre) {                                                   //minimax 알고리즘에서 min부분 --아이디어 회의: 고도환,조동혁 코드작성: 고도환(*),조동혁 주석: 조동혁
	int min = pre->child[0]->value;                                                      //min값을 가장 왼쪽 자식노드의 value값으로 초기화
	int count = 0;                                                                  //overflow가 발생한 경우 비교에서 제외하기 위해 overflow가 발생한 노드의 개수 counter.
	search_tree *temp = pre->child[0];                                                   //반환할 노드를 가장 왼쪽 자식 노드로 초기화

	for (int i = 0; i < c_num; i++) {                                                   //overflow가 발생한 자식 노드의 개수 count해줌.
		if (pre->child[i]->value == -10000) count++;
	}

	if (count != 7) {                                                               //하나라도 overflow가 발생하지 않는 노드가 있는 경우
		for (int i = 0; i < c_num; i++) {                                                //overflow가 발생하지 않는 최초의 자식노드를 찾아 min값과 temp값을 다시 초기화해줌.
			if (pre->child[i]->value != -10000) {
				min = pre->child[i]->value;
				temp = pre->child[i];
				break;
			}
		}

		for (int i = 0; i < c_num; i++) {                                                //다시 초기화 한 min값을 바탕으로 overflow가 발생하지 않는 자식 노드들 중 가장 작은 value값을 가지고 있는 노드를 찾아 temp에 저장.
			if (min >= pre->child[i]->value && pre->child[i]->value != -10000) {
				min = pre->child[i]->value;
				temp = pre->child[i];
			}
		}
	}

	return temp;                                                                  //가장 작은 value값을 가지는 노드 반환
}

void find_path(search_tree *pre, int num) {                                                //minimax알고리즘을 fmin함수와 fmax함수를 통해 구현한 부분 --아이디어 회의 고도환,조동혁 코드작성: 고도환(*),조동혁. 주석: 조동혁
	int i;
	int temp = num;

	if (pre->child[0] == NULL)                                                         //자식노드까지 내려온 경우 재귀 호출 중단하고 종료. 
		return;
	else {
		temp--;                                                                     //자식노드까지 도달하지 못한 경우 한 단계 낮은 depth로 확장.
		for (i = 0; i < c_num; i++)
			find_path(pre->child[i], temp);
	}

	if (num % 2 == 0) {                                                               //짝수 depth의 경우 min함수 사용하여 자식노드 중 가장 작은 value의 값을 부모 노드의 value로 저장
		pre->value = fmin(pre)->value;

	}
	else if (num % 2 == 1) {                                                         //홀수 depth의 경우 max함수 사용하여 자식노드 중 가장 큰 value의 값을 부모노드의 value로 저장
		pre->value = fmax(pre)->value;
	}

}

void print_arr(int arr[][7]) {                                                         //게임보드를 출력하는 함수. --코드 구현 고도환 주석 조동혁
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (arr[i][j] == 1) printf("|O");                                             //사람의 경우 'O'를, AI의 경우 'X'를 출력하도록 함.
			else if (arr[i][j] == 2) printf("|X");
			else printf("| ");
		}
		printf("|\n");
	}
}

void print_result(int flag) {                                                         //게임의 결과를 출력하는 함수. flag값이 1이면 사람의 승리, 2이면 AI의 승리이다. --코드 구현 고도환 주석 조동혁
	if (flag == 1)
		printf("You Win\n");
	else if (flag == 2)
		printf("Computer Win\n");
}

int check(int arr[][7]) {                                                            //게임이 끝났는 지 파악하는 함수 --코드 구현 고도환 주석 조동혁
	int i, j, k;                                                                  //for문에 사용할 변수들
	int count = 1;                                                                  //몇 개의 돌이 연결되어 있는 지 파악하는 counter


	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 3; j++) {
			for (k = 1; k <= 3; k++)
				if (arr[i][j] == arr[i][j + k] && arr[i][j] != 0) count++;                        //가로 방향으로 몇개의 같은 돌이 연결되어 있는지 파악함. 
			if (count == 4) {
				return arr[i][j];                                                      //4개가 연결되어 있다면, 누구의 돌인지 반환. 1일 경우 사람 2일 경우 AI
			}
			count = 1;                                                               //count값 다시 1로 초기화

			for (k = 1; k <= 3; k++) {
				if (i <= 2) {
					if (arr[i][j] == arr[i + k][j + k] && arr[i][j] != 0)                        //대각선 방향(아래)으로 몇개의 같은 돌이 연결되어 있는지 파악함.
						count++;
				}
				else {
					if (arr[i][j] == arr[i - k][j + k] && arr[i][j] != 0)                        //대각선 방향(위)으로 몇개의 같은 돌이 연결되어 있는지 파악함.
						count++;
				}
			}
			if (count == 4) {
				return arr[i][j];                                                      //4개가 연결되어 있다면, 누구의 돌인지 반환. 1일 경우 사람 2일 경우 AI
			}
			count = 1;                                                               //count값 다시 1로 초기화
		}
	}

	for (j = 0; j <= 6; j++) {
		for (i = 0; i <= 2; i++) {
			for (k = 1; k <= 3; k++)
				if (arr[i][j] == arr[i + k][j] && arr[i][j] != 0) count++;                        //세로 방향으로 몇개의 같은 돌이 연결되어 있는지 파악함.                     
			if (count == 4) {
				return arr[i][j];                                                      //4개가 연결되어 있다면, 누구의 돌인지 반환. 1일 경우 사람 2일 경우 AI
			}
			count = 1;                                                               //count값 다시 1로 초기화
		}
	}

	return 0;
}

void initialize(int arr[][7]) {                                                         //게임보드 초기화해주는 함수 --코드 구현 고도환 주석 조동혁
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)
			arr[i][j] = 0;
	}
}

void set_temp_arr(int arr[][7], int temp_arr[][7]) {                                       // 앞으로의 수를 내다보는 과정에서 사용할 임시 게임보드 만들기. --코드구현 고도환 주석 조동혁
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)
			temp_arr[i][j] = arr[i][j];                                                   //임시 게임보드에 현재 게임보드의 값 그대로 가져옴. --코드구현 고도환 주석 조동혁
	}
}

void set_overflow(int arr[][7], int column) {                                             //어떤 column에서 overflow가 발생할 경우 overflow의 값을 1로 설정해줌.
	if (arr[0][column] != 0 || column > 6 || column < 0) overflow = 1;
	else overflow = 0;
}

void put_temp_arr(search_tree *pre, int temp_arr[][7], int *sequence, int turn) {                  //임시 게임보드에 말을 놓는 함수 --코드 구현 고도환 주석 조동혁
	int temp_turn = turn;

	for (int i = 0; i < depth; i++) {                                                   //내다볼 7수
		if (sequence[i] >= 0) {                                                          //sequence가 존재하는 경우에만 아래의 작업을 수행.
			set_overflow(temp_arr, sequence[i]);                                          //해당 column에 overflow가 존재하는지 확인                                    
			put(temp_arr, sequence[i], temp_turn);                                          //임시 게임보드에 플레이어의 차례에 맞게 착수   
			if (overflow == 1) {                                                      //만약 overflow가 발생했다면, 노드의 값에 무의미한 값을 넣어주고 turn을 바꿔줌. 이 값을 가지고 있는 노드는 overflow가 발생한 상태라는 것을 알 수 있음. 
				pre->value = -10000;
				temp_turn = 3 - temp_turn;
			}
		}
		overflow = 0;                                                               //overflow의 값을 다시 초기화 해줌.
	}
}

void set_value(search_tree *pre, int arr[][7], int temp_arr[][7], int num, int turn) {               //해당 노드의 heuristic value를 결정해주는 함수 --아이디어 회의 고도환 조동혁 코드 구현 고도환 주석 조동혁
	int i, j;                                                                     //for문에 사용할 변수
	if (num != 0) {                                                                  //단말노드까지 내려온 경우 재귀 호출을 종료
		for (i = 0; i < c_num; i++) {                                                   //pre의 자식노드들에 대해 만일 단말 노드라면, set_temp_arr함수와 put_temp_arr함수를 사용해 임시 게임보드를 만들고 돌을 놓아 휴리스틱 함수를 사용하여 노드의 value값을 결정함.
			if (num == 1) {
				set_temp_arr(arr, temp_arr);
				put_temp_arr(pre->child[i], temp_arr, pre->child[i]->sequence, turn);
				if (pre->child[i]->value != -10000)
					pre->child[i]->value = heuristic_function(temp_arr, turn);
				//print_arr(temp_arr);
				//printf("%d\n", pre->child[i]->value);
			}
		}
		num--;
		for (i = 0; i < c_num; i++) {                                                   //pre의 자식 노드들에 대해 재귀적으로 함수를 호출하여 단말노드까지 확장될 수 있도록 함.
			set_value(pre->child[i], arr, temp_arr, num, turn);
		}
	}
}

int next_check(int arr[][7], int temp_arr[][7], int turn) {                     //hueristic함수를 보완하기 위해 rule-base방식을 도입함. 상대의 돌이 3개 연결되어 있으면 바로 막고, 자신의 돌이 3개 연결되어 있으면 휴리스틱 값과 상관 없이 돌을 그곳에 둘 수 있도록 함. --코드 구현 고도환 주석 조동혁
	set_temp_arr(arr, temp_arr);                                                      //한 수 앞을 내다보기 위한 임시 게임보드를 만듦.
	for (int i = 0; i < c_num; i++) {                                                   //한 수를 두었을 때, 게임이 끝나면 해당 column을 반환.
		put(temp_arr, i, turn);
		if (check(temp_arr) != 0) return i;
	}
	return -1;                                                                     //그렇지 않으면 -1을 반환
}

int main() {                                                                     //main함수 --코드 구현 고도환 주석 조동혁
	int arr[6][7], temp_arr[6][7];                                                      //게임보드와 임시게임보드 선언
	int column, turn, next_column = 1;                                                   //input으로 받을 column과 사람과 ai차례를 구분해줄 turn선언 및, 다음에 둘 column변수인 next_column변수 선언 및 초기화
	int order;                                                                     //선공을 누가하는지 파악하는 변수. 1이면 사람이 선공, 2이면 AI가 선공
	int i, j;                                                                     //for문에서 사용할 변수

	search_tree *head = (search_tree *)malloc(sizeof(search_tree));                              //search_tree선언   
	node_initialize(head);                                                            //haed를 초기화 해줌
	branch(head, depth);                                                            //head를 7단계까지 펼쳐줌.

	printf("1. Play First\n");
	printf("2. Play Second\n");
	scanf("%d", &order);                                                            //누가 선공할 것인지 결정

	initialize(arr);

	if (order == 1) {                                                               //사람이 선공인 경우
		int flag1 = 0;                                                               //첫 번쨰 시도임을 나타내주는 변수(4번째 항에 두는 것 방지)
		int flag2 = 0;                                                               //rule-base방법을 사용할 떄를 알려줌. 1일때 rule-based방법 사용함
		turn = 1;                                                                  //turn결정. 1일 때 사람 2일 때 AI
		while (1) {
			if (flag1 == 0) printf("Cannot put on 4th column at first\n");                        //첫 번째 시도일 때 4번 째 column에 두지 못하도록 함.
			print_arr(arr);                                                            //게임보드 출력
			if (flag1 == 0)
				flag1 = 1;                                                            //다음 부터는 경고문 뜨지 않도록 flag1값 1로 바꿔줌
			else if (flag1 == 1) {
				if (flag2 == 0)
					printf("휴리스틱 방식으로 7수 앞까지 확인하여 %d번째 Column에 착수\nScore : %d\n", next_column + 1, head->value);
				//rule-based방법을 사용하지 않을 경우 heuristic함수를 사용해 찾은 column이 출력되도록함
				else if (flag2 == 1) {
					printf("Rule Based 방식에 의하여 %d번째 column에 착수\n", next_column + 1);            //rule-based방법을 사용하는 경우 해당 column이 출력되도록하고 flag2값 다시 0으로 바꿔줌.
					flag2 = 0;
				}
			}

			if (check(arr) != 0) {                                                      //게임이 끝나면 결과를 출력하고 프로그램 실행을 종료함
				print_result(check(arr));
				break;
			}
			overflow = 0;                                                            //overflow값 0으로 초기화

			do {                                                                  //더 이상 넣을 수 없는 column에 돌을 놓을 수 없도록 함
				printf("Select Column: ");
				scanf("%d", &column);
				printf("\n");
				column--;
				set_overflow(arr, column);
			} while (overflow != 0);

			put(arr, column, turn);                                                      //해당 column에 착수
			overflow = 0;                                                            //overflow값 다시 0으로 설정
			print_arr(arr);                                                            //현재 상태의 게임보드 출력      
			if (check(arr) != 0) {                                                      //게임이 끝나면 결과를 출력하고 프로그램 실행을 종료함
				print_result(check(arr));
				break;
			}

			set_value(head, arr, temp_arr, depth, turn);                                    //AI차례이므로 휴리스틱 값 계산
			find_path(head, depth);                                                      //AI가 착수할 column결정할 수 있도록 루트 노드의 value값 업데이트 해줌.
			for (i = 0; i < c_num; i++) {                                                //minimax알고리즘에 의거하여 자식 노드 중 착수할 column결정
				if (head->value == head->child[i]->value)
					next_column = i;
			}

			if (next_check(arr, temp_arr, turn) != -1) {                                 //rule-based를 사용해야 하는 상황이라면 다음에 착수할 column을 rule-based방식으로 결정하고 flag2 1로 설정.(나의 돌이 3개 연속으로 있는 경우)
				next_column = next_check(arr, temp_arr, turn);
				flag2 = 1;
			}
			else if (next_check(arr, temp_arr, 3 - turn) != -1) {                         //rule-based를 사용해야 하는 상황이라면 다음에 착수할 column을 rule-based방식으로 결정하고 flag2 1로 설정.(상대 돌이 3개 연속으로 있는 경우)
				next_column = next_check(arr, temp_arr, 3 - turn);
				flag2 = 1;
			}

			put(arr, next_column, turn);                                                //결정된 column에 착수
			overflow = 0;                                                            //overflow값 다시 0으로 설정
			printf("\n");

			system("cls");                                                            //가독성 위해 cmd창 클리어
		}
	}
	else {
		turn = 2;                                                                  //AI가 선공인 경우
		int flag1 = 0;                                                               //첫 번째 시도인 경우를 나타냄. 0일 경우 첫 번째 시도임.
		int flag2 = 0;                                                               //rule-based방법을 사용하는 경우를 나타냄. 1일 경우 rule-based방법 사용
		while (1) {
			print_arr(arr);                                                            //게임보드 출력
			if (check(arr) != 0) {
				print_result(check(arr));                                 //게임이 끝나면 프로그램 종료
				break;
			}
			printf("\n");

			set_value(head, arr, temp_arr, depth, turn);                                    //휴리스틱 값 계산 
			find_path(head, depth);                                                      //다음에 착수할 column을 결정할 수 있도록 루트 노드의 value 업데이트 해줌
			for (i = 0; i < c_num; i++) {                                                //minimax알고리즘에 의거하여 착수할 column결정
				if (head->value == head->child[i]->value)
					next_column = i;
			}

			if (next_check(arr, temp_arr, turn) != -1) {                                 //rule-based를 사용해야 하는 상황이라면 다음에 착수할 column을 rule-based방식으로 결정하고 flag2 1로 설정.(나의 돌이 3개 연속으로 있는 경우)
				next_column = next_check(arr, temp_arr, turn);
				flag2 = 1;
			}
			else if (next_check(arr, temp_arr, 3 - turn) != -1) {                         //rule-based를 사용해야 하는 상황이라면 다음에 착수할 column을 rule-based방식으로 결정하고 flag2 1로 설정.(상대의 돌이 3개 연속으로 있는 경우)
				next_column = next_check(arr, temp_arr, 3 - turn);
				flag2 = 1;
			}

			if (flag1 == 1) {                                                         //첫 번째 시도가 아닌 경우
				put(arr, next_column, turn);                                             //해당 column에 착수
				print_arr(arr);                                                         //현재 상태의 게임 보드 출력
				if (flag2 == 0)                                                         //rule-based방법을 사용하지 않는 경우 휴리스틱 함수를 사용하여 결정된 column출력
					printf("휴리스틱 방식으로 7수 앞까지 확인하여 %d번째 Column에 착수\nScore : %d\n", next_column + 1, head->value);
				else if (flag2 == 1) {                                                   //rule-based방법을 사용하는 경우 해당 column출력
					printf("Rule Based 방식에 의하여 %d번째 Column에 착수\n", next_column + 1);
					flag2 = 0;
				}
			}
			else if (flag1 == 0) {                                                      //첫 번째 차례인 경우 4번째 column출력할 수 없으므로 일반적으로 4번째 column을 제외하면 가장 높은 휴리스틱 값을 갖는 3번째 columnㄹ출력하고 flag1값 1로 바꿔줌
				flag1 = 1;
				put(arr, 2, turn);                                                      //해당 column에 착수                                                
				print_arr(arr);                                                         //게임보드 출력
				printf("휴리스틱 방식으로 7수 앞까지 확인하여 4번째 Column 다음으로 높은 3번째 Column에 착수\nScore : %d\n", head->child[2]->value);
			}

			overflow = 0;                                                            //overflow   0으로 설정
			if (check(arr) != 0) {
				print_result(check(arr));                                 //게임이 끝나면 프로그램 종료
				break;
			}

			do {                                                                  //(사람의 차례)overflow가 발생하여 더 이상 돌을 놓을 수 없는 column에는 돌을 놓을 수 없도록 하고 다른 column에 두도록 함.
				printf("Select Column: ");
				scanf("%d", &column);
				printf("\n");
				column--;
				set_overflow(arr, column);
			} while (overflow != 0);

			put(arr, column, turn);                                                      //해당 column에 착수
			overflow = 0;                                                            //overflow값을 다시 0으로 설정해둠.(다음 턴에 사용하기 위함)
			print_arr(arr);                                                            //현재 게임보드 출력
			if (check(arr) != 0) {
				print_result(check(arr));                                 //게임이 끝나면 프로그램 종료
				break;
			}

			system("cls");                                                            //가독성을 위해 cmd창 클리어 해줌
		}
	}


	return 0;                                                                     //정상적으로 종료
}