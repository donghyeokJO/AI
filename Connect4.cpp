#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define depth 7                                                                     //�޸���ƽ �Լ��� ����Ͽ� ���� ���� ������ �� 7�� �ձ��� ���ٺ� ���̴�. 
#define c_num 7                                                                     //�� ����� �ڽĳ���� ����

int heuristic_function(int arr[][7], int turn) {                                    //��忡 ���� �޸���ƽ ���� ã���ִ� �Լ��̴�. --���̵�� ȸ��: ��ȯ ������, �ڵ� �ۼ�: ��ȯ �ּ�: ������
	int winning_line[6][7] = { { 3, 4, 5, 7, 4, 3 },{ 4, 6, 8, 10, 8, 6, 4 },{ 5, 8, 11, 13, 11, 8, 5 },{ 5, 8, 11, 13, 11, 8, 5 },{ 4, 6, 8, 10, 8, 6, 4 },{ 3, 4, 5, 7, 4, 3 } };
	//������ �� ĭ ���� �̱� �� �ִ� ����� ���� �迭�� �����Ͽ� ����ġ�� ���� �޸���ƽ �� ��꿡 ����Ѵ�. 

	int i, j;                                                       //for���� ���� ������
	int value = 0;                                                   //value�� �ʱ�ȭ


	const int m2 = 10;                                                              //7�� ���� ���ٺ� ���� ���¿��� �ڽ��� ���� 2�� �̾��� �ִ� ����� �޸���ƽ ����ġ.
	const int m3 = 20;                                                              //7�� ���� ���ٺ� ���� ���¿��� �ڽ��� ���� 3�� �̾��� �ִ� ����� �޸���ƽ ����ġ.
	const int m4 = 100;                                                             //7�� ���� ���ٺ� ���� ���¿��� �ڽ��� ���� 4�� �̾��� �ִ� ����� �޸���ƽ ����ġ.
	const int y2 = 10;                                                              //7�� ���� ���ٺ� ���� ���¿��� ����� ���� 2�� �̾��� �ִ� ����� �޸���ƽ ����ġ.
	const int y3 = 20;                                                              //7�� ���� ���ٺ� ���� ���¿��� ����� ���� 3�� �̾��� �ִ� ����� �޸���ƽ ����ġ.
	const int y4 = 100;                                                             //7�� ���� ���ٺ� ���� ���¿��� ����� ���� 4�� �̾��� �ִ� ����� �޸���ƽ ����ġ.

	for (i = 0; i < 6; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� �ڽ��� ���� 2�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j < 6; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i][j + 1]) * m2;
				j += 2;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� �ڽ��� ���� 3�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2]) * m3;
				j += 3;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� �ڽ��� ���� 4�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2] + winning_line[i][j + 3]) * m4;
			}
		}
	}


	for (j = 0; j < 7; j++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� �ڽ��� ���� 2�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (i = 0; i < 5; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j]) * m2;
				i += 2;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� �ڽ��� ���� 3�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (i = 0; i < 3; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j]) * m3;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� �ڽ��� ���� 4�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (i = 0; i < 2; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j] + winning_line[i + 3][j]) * m4;
			}
		}
	}


	for (i = 0; i <= 4; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(�»�->����) �������� �ڽ��� ���� 2�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j + 1]) * m2;
				i += 2;
				j += 2;
			}
		}
	}

	for (i = 0; i <= 3; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(�»�->����) �������� �ڽ��� ���� 3�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2]) * m3;
			}
		}
	}

	for (i = 0; i <= 2; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(�»�->����) �������� �ڽ��� ���� 4�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2] + winning_line[i + 3][j + 3]) * m4;
			}
		}
	}


	for (i = 5; i >= 1; i--) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(����->���) �������� �ڽ��� ���� 2�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i - 1][j + 1]) * m2;
				i -= 2;
				j += 2;
			}
		}
	}

	for (i = 5; i >= 2; i--) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(����>���) �������� �ڽ��� ���� 3�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2]) * m3;
			}
		}
	}

	for (i = 5; i >= 3; i--) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(����->���) �������� �ڽ��� ���� 4�� �̾��� �ִ� ��쿡 value���� ����ġ �ο�.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == arr[i - 3][j + 3] && arr[i][j] == turn) {
				value += (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2] + winning_line[i - 3][j + 3]) * m4;
			}
		}
	}

	turn = 3 - turn;                                                               //��밡 �̱�� ��쿡 ���� ����ġ�� ������ �ֱ� ���� turn�� �ڽſ��� ���� �ٲپ� �ش�. 

	for (i = 0; i < 6; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� ����� ���� 2�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j < 6; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i][j + 1]) * y2;
				j += 2;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� ����� ���� 3�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2]) * y3;
				j += 3;
			}
		}
	}

	for (i = 0; i < 6; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� ����� ���� 4�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i][j + 1] + winning_line[i][j + 2] + winning_line[i][j + 3]) * y4;
			}
		}
	}


	for (j = 0; j < 7; j++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� ����� ���� 2�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (i = 0; i < 5; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j]) * y2;
				i += 2;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                          //7�� ���� ���ٺ� ���� ���¿��� ���� �������� ����� ���� 3�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (i = 0; i < 3; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j]) * y3;
			}
		}
	}

	for (j = 0; j < 7; j++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� ���� �������� ����� ���� 4�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (i = 0; i < 2; i++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j] + winning_line[i + 2][j] + winning_line[i + 3][j]) * y4;
			}
		}
	}


	for (i = 0; i <= 4; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(�»�->����) �������� ����� ���� 2�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j + 1]) * y2;
				i += 2;
				j += 2;
			}
		}
	}
	
	for (i = 0; i <= 3; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(�»�->����) �������� ����� ���� 3�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2]) * y3;
			}
		}
	}

	for (i = 0; i <= 2; i++) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(�»�->����) �������� ����� ���� 4�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i + 1][j + 1] + winning_line[i + 2][j + 2] + winning_line[i + 3][j + 3]) * y4;
			}
		}
	}


	for (i = 5; i >= 1; i--) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(����->���) �������� ����� ���� 2�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j <= 5; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i - 1][j + 1]) * y2;
				i -= 2;
				j += 2;
			}
		}
	}

	for (i = 5; i >= 2; i--) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(����->���) �������� ����� ���� 3�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j <= 4; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2]) * y3;
			}
		}
	}

	for (i = 5; i >= 3; i--) {                                                         //7�� ���� ���ٺ� ���� ���¿��� �밢��(����->���) �������� ����� ���� 4�� �̾��� �ִ� ��쿡 value������ ����ġ ���ش�.
		for (j = 0; j <= 3; j++) {
			if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == arr[i - 3][j + 3] && arr[i][j] == turn) {
				value -= (winning_line[i][j] + winning_line[i - 1][j + 1] + winning_line[i - 2][j + 2] + winning_line[i - 3][j + 3]) * y4;
			}
		}
	}

	return value; //����� value�� ��ȯ���ش�. 
}

typedef struct tree {                                                               //search_tree����ü ����. ������ ������ ���� �� ����� �ڽ� ���� ����. --�ڵ� ���� ��ȯ , �ּ� ������
	int value;                                                                     //����� �޸���ƽ ��
	int sequence[depth];                                                            //�ش� ������ ���� �θ� ������ ���
	struct tree *parent;                                                            //�θ� ���
	struct tree *child[c_num];                                                         //7���� �ڽ� ���
}search_tree;

void node_initialize(search_tree *head) {                                                // ��� �ʱ�ȭ -- �ڵ� ���� ��ȯ, �ּ� ������
	head->parent = NULL;                                                            //�θ� ��带 NULL�� �ʱ�ȭ
	head->value = -2;                                                               //value���� ���ǹ��� ������ �ʱ�ȭ
	for (int i = 0; i < c_num; i++)                                                      //7���� �ڽ� ��� NULL�� �ʱ�ȭ
		head->child[i] = NULL;

	for (int i = 0; i < depth; i++)                                                      //��� �� ���ǹ��� ������ �ʱ�ȭ
		head->sequence[i] = -1;
}

void insert_node(search_tree *head, int child_num) {                                       //search_tree�� ��� ���� --�ڵ� ���� ��ȯ, �ּ� ������
	search_tree *temp = head;                                                         //���ο� search tree���� head ��������.
	search_tree *new_node = (search_tree *)malloc(sizeof(search_tree));                           //������ ���ο� ��� �������. 
	node_initialize(new_node);                                                         // node_initialize�Լ� ����Ͽ� ���� ���� ��� �ʱ�ȭ ����. 

	for (int i = 0; i < depth; i++)                                                      //���ο� ����� sequence�� head�� sequence �־���. 
		new_node->sequence[i] = head->sequence[i];

	new_node->value = -1;                                                            //���ο� ����� value�� ���ǹ��� ������ �ʱ�ȭ
	temp->child[child_num] = new_node;                                                   //head�� �����ߴ� temp����� child_num��° �ڽ� ��忡 new_node�־���. 
	new_node->parent = temp;                                                         // ���ο� ����� �θ� ��带 temp���� ��������. 
}

int overflow = 0;                                                                  //���忡 ���ο� ���� �ִ� �������� overflow�� �Ͼ���� ���θ� üũ�ϱ� ���� ���� ����. 

void put(int arr[][7], int column, int &turn) {                                              // ���� ���忡 �� �־���. --�ڵ� ���� ��ȯ, �ּ� ������
	int i;                                                                        //for�� ���� ����
	for (i = 5; i >= 0; i--) {                                                          //���� ������ �ش� ĭ�� ������� ��� turn(ai�� ��� ����, 1�� �� ���, 2�� �� ai)
		if (arr[i][column] == 0) {
			arr[i][column] = turn;
			break;
		}
	}

	if (i == -1) {                                                                  //for���� break�� �ɸ��� �ʰ� ������ ��� ���� ��, �� �ش� column�� �� ĭ�� ���� ��, overflow�� �߻��ϹǷ� overflow�� 1�� �����ϰ� �Լ��� ������. 
		overflow = 1;
		return;
	}

	if (turn == 1) turn = 2;                                                         //����� ai�� turn�� �ٲ��� 
	else if (turn == 2) turn = 1;
}

void branch(search_tree *pre, int num) {                                                //search_tree�� �ܸ������� Ȯ������. --���̵�� ȸ��: ��ȯ ������ �ڵ� ����:��ȯ(*) ������ �ּ�:������
	if (num == 0) return;                                                            //�ܸ������� ��� Ȯ���� ��� �� �̻� ����Լ� ȣ������ �ʰ� ����. 

	num--;                                                                        //�� �ܰ� ���� depth���� ȣ���ϱ� ���� 1 �ٿ���. 
	for (int i = 0; i < c_num; i++) {
		insert_node(pre, i);                                                         //pre�� i��° �ڽĳ�带 �߰�����. 
		pre->child[i]->sequence[depth - num - 1] = i;                                       //pre�� i��° �ڽĳ�忡 ���� �θ� ����� ��θ� �ľ��ϱ� ���� sequence�� update����. 
		branch(pre->child[i], num);                                                      //pre�� �ڽ� ��忡 ���� branch�� ��������� ȣ���Ͽ�, �ܸ� ������ ���� �۾��� �ݺ��� �� �ֵ��� �ϰ� ��������� search-tree�� �ܸ������� Ȯ������.
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

search_tree *fmax(search_tree *pre) {                                                   //minimax �˰��򿡼� max�κ� --���̵�� ȸ��: ��ȯ(*),������ �ڵ��ۼ�: ��ȯ,������ �ּ�: ������
	int max = pre->child[0]->value;                                                      //max���� ���� ���� �ڽĳ���� value������ �ʱ�ȭ
	int count = 0;                                                                  //overflow�� �߻��� ��� �񱳿��� �����ϱ� ���� overflow�� �߻��� ����� ���� counter.
	search_tree *temp = pre->child[0];                                                                  //��ȯ�� ��带 ���� ���� �ڽ� ���� �ʱ�ȭ

	for (int i = 0; i < c_num; i++) {                                                   //overflow�� �߻��� �ڽ� ����� ���� count����
		if (pre->child[i]->value == -10000) count++;
	}

	if (count != 7) {                                                               //�ϳ��� overflow�� �߻����� �ʴ� ��尡 �ִ� ���
		for (int i = 0; i < c_num; i++) {                                                //overflow�� �߻����� ���� ������ �ڽĳ�带 ã�� max���� temp���� �ٽ� �ʱ�ȭ����. 
			if (pre->child[i]->value != -10000) {
				max = pre->child[i]->value;
				temp = pre->child[i];
				break;
			}
		}

		for (int i = 0; i < c_num; i++) {                                                //�ٽ� �ʱ�ȭ �� max���� �������� overflow�� �߻����� �ʴ� �ڽ� ���� �� ���� ū value���� ������ �ִ� ��带 ã�� temp�� ����.
			if (max <= pre->child[i]->value && pre->child[i]->value != -10000) {
				max = pre->child[i]->value;
				temp = pre->child[i];
			}
		}
	}

	return temp;                                                                  //���� ū value���� ������ ��� ��ȯ
}

search_tree *fmin(search_tree *pre) {                                                   //minimax �˰��򿡼� min�κ� --���̵�� ȸ��: ��ȯ,������ �ڵ��ۼ�: ��ȯ(*),������ �ּ�: ������
	int min = pre->child[0]->value;                                                      //min���� ���� ���� �ڽĳ���� value������ �ʱ�ȭ
	int count = 0;                                                                  //overflow�� �߻��� ��� �񱳿��� �����ϱ� ���� overflow�� �߻��� ����� ���� counter.
	search_tree *temp = pre->child[0];                                                   //��ȯ�� ��带 ���� ���� �ڽ� ���� �ʱ�ȭ

	for (int i = 0; i < c_num; i++) {                                                   //overflow�� �߻��� �ڽ� ����� ���� count����.
		if (pre->child[i]->value == -10000) count++;
	}

	if (count != 7) {                                                               //�ϳ��� overflow�� �߻����� �ʴ� ��尡 �ִ� ���
		for (int i = 0; i < c_num; i++) {                                                //overflow�� �߻����� �ʴ� ������ �ڽĳ�带 ã�� min���� temp���� �ٽ� �ʱ�ȭ����.
			if (pre->child[i]->value != -10000) {
				min = pre->child[i]->value;
				temp = pre->child[i];
				break;
			}
		}

		for (int i = 0; i < c_num; i++) {                                                //�ٽ� �ʱ�ȭ �� min���� �������� overflow�� �߻����� �ʴ� �ڽ� ���� �� ���� ���� value���� ������ �ִ� ��带 ã�� temp�� ����.
			if (min >= pre->child[i]->value && pre->child[i]->value != -10000) {
				min = pre->child[i]->value;
				temp = pre->child[i];
			}
		}
	}

	return temp;                                                                  //���� ���� value���� ������ ��� ��ȯ
}

void find_path(search_tree *pre, int num) {                                                //minimax�˰����� fmin�Լ��� fmax�Լ��� ���� ������ �κ� --���̵�� ȸ�� ��ȯ,������ �ڵ��ۼ�: ��ȯ(*),������. �ּ�: ������
	int i;
	int temp = num;

	if (pre->child[0] == NULL)                                                         //�ڽĳ����� ������ ��� ��� ȣ�� �ߴ��ϰ� ����. 
		return;
	else {
		temp--;                                                                     //�ڽĳ����� �������� ���� ��� �� �ܰ� ���� depth�� Ȯ��.
		for (i = 0; i < c_num; i++)
			find_path(pre->child[i], temp);
	}

	if (num % 2 == 0) {                                                               //¦�� depth�� ��� min�Լ� ����Ͽ� �ڽĳ�� �� ���� ���� value�� ���� �θ� ����� value�� ����
		pre->value = fmin(pre)->value;

	}
	else if (num % 2 == 1) {                                                         //Ȧ�� depth�� ��� max�Լ� ����Ͽ� �ڽĳ�� �� ���� ū value�� ���� �θ����� value�� ����
		pre->value = fmax(pre)->value;
	}

}

void print_arr(int arr[][7]) {                                                         //���Ӻ��带 ����ϴ� �Լ�. --�ڵ� ���� ��ȯ �ּ� ������
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (arr[i][j] == 1) printf("|O");                                             //����� ��� 'O'��, AI�� ��� 'X'�� ����ϵ��� ��.
			else if (arr[i][j] == 2) printf("|X");
			else printf("| ");
		}
		printf("|\n");
	}
}

void print_result(int flag) {                                                         //������ ����� ����ϴ� �Լ�. flag���� 1�̸� ����� �¸�, 2�̸� AI�� �¸��̴�. --�ڵ� ���� ��ȯ �ּ� ������
	if (flag == 1)
		printf("You Win\n");
	else if (flag == 2)
		printf("Computer Win\n");
}

int check(int arr[][7]) {                                                            //������ ������ �� �ľ��ϴ� �Լ� --�ڵ� ���� ��ȯ �ּ� ������
	int i, j, k;                                                                  //for���� ����� ������
	int count = 1;                                                                  //�� ���� ���� ����Ǿ� �ִ� �� �ľ��ϴ� counter


	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 3; j++) {
			for (k = 1; k <= 3; k++)
				if (arr[i][j] == arr[i][j + k] && arr[i][j] != 0) count++;                        //���� �������� ��� ���� ���� ����Ǿ� �ִ��� �ľ���. 
			if (count == 4) {
				return arr[i][j];                                                      //4���� ����Ǿ� �ִٸ�, ������ ������ ��ȯ. 1�� ��� ��� 2�� ��� AI
			}
			count = 1;                                                               //count�� �ٽ� 1�� �ʱ�ȭ

			for (k = 1; k <= 3; k++) {
				if (i <= 2) {
					if (arr[i][j] == arr[i + k][j + k] && arr[i][j] != 0)                        //�밢�� ����(�Ʒ�)���� ��� ���� ���� ����Ǿ� �ִ��� �ľ���.
						count++;
				}
				else {
					if (arr[i][j] == arr[i - k][j + k] && arr[i][j] != 0)                        //�밢�� ����(��)���� ��� ���� ���� ����Ǿ� �ִ��� �ľ���.
						count++;
				}
			}
			if (count == 4) {
				return arr[i][j];                                                      //4���� ����Ǿ� �ִٸ�, ������ ������ ��ȯ. 1�� ��� ��� 2�� ��� AI
			}
			count = 1;                                                               //count�� �ٽ� 1�� �ʱ�ȭ
		}
	}

	for (j = 0; j <= 6; j++) {
		for (i = 0; i <= 2; i++) {
			for (k = 1; k <= 3; k++)
				if (arr[i][j] == arr[i + k][j] && arr[i][j] != 0) count++;                        //���� �������� ��� ���� ���� ����Ǿ� �ִ��� �ľ���.                     
			if (count == 4) {
				return arr[i][j];                                                      //4���� ����Ǿ� �ִٸ�, ������ ������ ��ȯ. 1�� ��� ��� 2�� ��� AI
			}
			count = 1;                                                               //count�� �ٽ� 1�� �ʱ�ȭ
		}
	}

	return 0;
}

void initialize(int arr[][7]) {                                                         //���Ӻ��� �ʱ�ȭ���ִ� �Լ� --�ڵ� ���� ��ȯ �ּ� ������
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)
			arr[i][j] = 0;
	}
}

void set_temp_arr(int arr[][7], int temp_arr[][7]) {                                       // �������� ���� ���ٺ��� �������� ����� �ӽ� ���Ӻ��� �����. --�ڵ屸�� ��ȯ �ּ� ������
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)
			temp_arr[i][j] = arr[i][j];                                                   //�ӽ� ���Ӻ��忡 ���� ���Ӻ����� �� �״�� ������. --�ڵ屸�� ��ȯ �ּ� ������
	}
}

void set_overflow(int arr[][7], int column) {                                             //� column���� overflow�� �߻��� ��� overflow�� ���� 1�� ��������.
	if (arr[0][column] != 0 || column > 6 || column < 0) overflow = 1;
	else overflow = 0;
}

void put_temp_arr(search_tree *pre, int temp_arr[][7], int *sequence, int turn) {                  //�ӽ� ���Ӻ��忡 ���� ���� �Լ� --�ڵ� ���� ��ȯ �ּ� ������
	int temp_turn = turn;

	for (int i = 0; i < depth; i++) {                                                   //���ٺ� 7��
		if (sequence[i] >= 0) {                                                          //sequence�� �����ϴ� ��쿡�� �Ʒ��� �۾��� ����.
			set_overflow(temp_arr, sequence[i]);                                          //�ش� column�� overflow�� �����ϴ��� Ȯ��                                    
			put(temp_arr, sequence[i], temp_turn);                                          //�ӽ� ���Ӻ��忡 �÷��̾��� ���ʿ� �°� ����   
			if (overflow == 1) {                                                      //���� overflow�� �߻��ߴٸ�, ����� ���� ���ǹ��� ���� �־��ְ� turn�� �ٲ���. �� ���� ������ �ִ� ���� overflow�� �߻��� ���¶�� ���� �� �� ����. 
				pre->value = -10000;
				temp_turn = 3 - temp_turn;
			}
		}
		overflow = 0;                                                               //overflow�� ���� �ٽ� �ʱ�ȭ ����.
	}
}

void set_value(search_tree *pre, int arr[][7], int temp_arr[][7], int num, int turn) {               //�ش� ����� heuristic value�� �������ִ� �Լ� --���̵�� ȸ�� ��ȯ ������ �ڵ� ���� ��ȯ �ּ� ������
	int i, j;                                                                     //for���� ����� ����
	if (num != 0) {                                                                  //�ܸ������� ������ ��� ��� ȣ���� ����
		for (i = 0; i < c_num; i++) {                                                   //pre�� �ڽĳ��鿡 ���� ���� �ܸ� �����, set_temp_arr�Լ��� put_temp_arr�Լ��� ����� �ӽ� ���Ӻ��带 ����� ���� ���� �޸���ƽ �Լ��� ����Ͽ� ����� value���� ������.
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
		for (i = 0; i < c_num; i++) {                                                   //pre�� �ڽ� ���鿡 ���� ��������� �Լ��� ȣ���Ͽ� �ܸ������� Ȯ��� �� �ֵ��� ��.
			set_value(pre->child[i], arr, temp_arr, num, turn);
		}
	}
}

int next_check(int arr[][7], int temp_arr[][7], int turn) {                     //hueristic�Լ��� �����ϱ� ���� rule-base����� ������. ����� ���� 3�� ����Ǿ� ������ �ٷ� ����, �ڽ��� ���� 3�� ����Ǿ� ������ �޸���ƽ ���� ��� ���� ���� �װ��� �� �� �ֵ��� ��. --�ڵ� ���� ��ȯ �ּ� ������
	set_temp_arr(arr, temp_arr);                                                      //�� �� ���� ���ٺ��� ���� �ӽ� ���Ӻ��带 ����.
	for (int i = 0; i < c_num; i++) {                                                   //�� ���� �ξ��� ��, ������ ������ �ش� column�� ��ȯ.
		put(temp_arr, i, turn);
		if (check(temp_arr) != 0) return i;
	}
	return -1;                                                                     //�׷��� ������ -1�� ��ȯ
}

int main() {                                                                     //main�Լ� --�ڵ� ���� ��ȯ �ּ� ������
	int arr[6][7], temp_arr[6][7];                                                      //���Ӻ���� �ӽð��Ӻ��� ����
	int column, turn, next_column = 1;                                                   //input���� ���� column�� ����� ai���ʸ� �������� turn���� ��, ������ �� column������ next_column���� ���� �� �ʱ�ȭ
	int order;                                                                     //������ �����ϴ��� �ľ��ϴ� ����. 1�̸� ����� ����, 2�̸� AI�� ����
	int i, j;                                                                     //for������ ����� ����

	search_tree *head = (search_tree *)malloc(sizeof(search_tree));                              //search_tree����   
	node_initialize(head);                                                            //haed�� �ʱ�ȭ ����
	branch(head, depth);                                                            //head�� 7�ܰ���� ������.

	printf("1. Play First\n");
	printf("2. Play Second\n");
	scanf("%d", &order);                                                            //���� ������ ������ ����

	initialize(arr);

	if (order == 1) {                                                               //����� ������ ���
		int flag1 = 0;                                                               //ù ���� �õ����� ��Ÿ���ִ� ����(4��° �׿� �δ� �� ����)
		int flag2 = 0;                                                               //rule-base����� ����� ���� �˷���. 1�϶� rule-based��� �����
		turn = 1;                                                                  //turn����. 1�� �� ��� 2�� �� AI
		while (1) {
			if (flag1 == 0) printf("Cannot put on 4th column at first\n");                        //ù ��° �õ��� �� 4�� ° column�� ���� ���ϵ��� ��.
			print_arr(arr);                                                            //���Ӻ��� ���
			if (flag1 == 0)
				flag1 = 1;                                                            //���� ���ʹ� ��� ���� �ʵ��� flag1�� 1�� �ٲ���
			else if (flag1 == 1) {
				if (flag2 == 0)
					printf("�޸���ƽ ������� 7�� �ձ��� Ȯ���Ͽ� %d��° Column�� ����\nScore : %d\n", next_column + 1, head->value);
				//rule-based����� ������� ���� ��� heuristic�Լ��� ����� ã�� column�� ��µǵ�����
				else if (flag2 == 1) {
					printf("Rule Based ��Ŀ� ���Ͽ� %d��° column�� ����\n", next_column + 1);            //rule-based����� ����ϴ� ��� �ش� column�� ��µǵ����ϰ� flag2�� �ٽ� 0���� �ٲ���.
					flag2 = 0;
				}
			}

			if (check(arr) != 0) {                                                      //������ ������ ����� ����ϰ� ���α׷� ������ ������
				print_result(check(arr));
				break;
			}
			overflow = 0;                                                            //overflow�� 0���� �ʱ�ȭ

			do {                                                                  //�� �̻� ���� �� ���� column�� ���� ���� �� ������ ��
				printf("Select Column: ");
				scanf("%d", &column);
				printf("\n");
				column--;
				set_overflow(arr, column);
			} while (overflow != 0);

			put(arr, column, turn);                                                      //�ش� column�� ����
			overflow = 0;                                                            //overflow�� �ٽ� 0���� ����
			print_arr(arr);                                                            //���� ������ ���Ӻ��� ���      
			if (check(arr) != 0) {                                                      //������ ������ ����� ����ϰ� ���α׷� ������ ������
				print_result(check(arr));
				break;
			}

			set_value(head, arr, temp_arr, depth, turn);                                    //AI�����̹Ƿ� �޸���ƽ �� ���
			find_path(head, depth);                                                      //AI�� ������ column������ �� �ֵ��� ��Ʈ ����� value�� ������Ʈ ����.
			for (i = 0; i < c_num; i++) {                                                //minimax�˰��� �ǰ��Ͽ� �ڽ� ��� �� ������ column����
				if (head->value == head->child[i]->value)
					next_column = i;
			}

			if (next_check(arr, temp_arr, turn) != -1) {                                 //rule-based�� ����ؾ� �ϴ� ��Ȳ�̶�� ������ ������ column�� rule-based������� �����ϰ� flag2 1�� ����.(���� ���� 3�� �������� �ִ� ���)
				next_column = next_check(arr, temp_arr, turn);
				flag2 = 1;
			}
			else if (next_check(arr, temp_arr, 3 - turn) != -1) {                         //rule-based�� ����ؾ� �ϴ� ��Ȳ�̶�� ������ ������ column�� rule-based������� �����ϰ� flag2 1�� ����.(��� ���� 3�� �������� �ִ� ���)
				next_column = next_check(arr, temp_arr, 3 - turn);
				flag2 = 1;
			}

			put(arr, next_column, turn);                                                //������ column�� ����
			overflow = 0;                                                            //overflow�� �ٽ� 0���� ����
			printf("\n");

			system("cls");                                                            //������ ���� cmdâ Ŭ����
		}
	}
	else {
		turn = 2;                                                                  //AI�� ������ ���
		int flag1 = 0;                                                               //ù ��° �õ��� ��츦 ��Ÿ��. 0�� ��� ù ��° �õ���.
		int flag2 = 0;                                                               //rule-based����� ����ϴ� ��츦 ��Ÿ��. 1�� ��� rule-based��� ���
		while (1) {
			print_arr(arr);                                                            //���Ӻ��� ���
			if (check(arr) != 0) {
				print_result(check(arr));                                 //������ ������ ���α׷� ����
				break;
			}
			printf("\n");

			set_value(head, arr, temp_arr, depth, turn);                                    //�޸���ƽ �� ��� 
			find_path(head, depth);                                                      //������ ������ column�� ������ �� �ֵ��� ��Ʈ ����� value ������Ʈ ����
			for (i = 0; i < c_num; i++) {                                                //minimax�˰��� �ǰ��Ͽ� ������ column����
				if (head->value == head->child[i]->value)
					next_column = i;
			}

			if (next_check(arr, temp_arr, turn) != -1) {                                 //rule-based�� ����ؾ� �ϴ� ��Ȳ�̶�� ������ ������ column�� rule-based������� �����ϰ� flag2 1�� ����.(���� ���� 3�� �������� �ִ� ���)
				next_column = next_check(arr, temp_arr, turn);
				flag2 = 1;
			}
			else if (next_check(arr, temp_arr, 3 - turn) != -1) {                         //rule-based�� ����ؾ� �ϴ� ��Ȳ�̶�� ������ ������ column�� rule-based������� �����ϰ� flag2 1�� ����.(����� ���� 3�� �������� �ִ� ���)
				next_column = next_check(arr, temp_arr, 3 - turn);
				flag2 = 1;
			}

			if (flag1 == 1) {                                                         //ù ��° �õ��� �ƴ� ���
				put(arr, next_column, turn);                                             //�ش� column�� ����
				print_arr(arr);                                                         //���� ������ ���� ���� ���
				if (flag2 == 0)                                                         //rule-based����� ������� �ʴ� ��� �޸���ƽ �Լ��� ����Ͽ� ������ column���
					printf("�޸���ƽ ������� 7�� �ձ��� Ȯ���Ͽ� %d��° Column�� ����\nScore : %d\n", next_column + 1, head->value);
				else if (flag2 == 1) {                                                   //rule-based����� ����ϴ� ��� �ش� column���
					printf("Rule Based ��Ŀ� ���Ͽ� %d��° Column�� ����\n", next_column + 1);
					flag2 = 0;
				}
			}
			else if (flag1 == 0) {                                                      //ù ��° ������ ��� 4��° column����� �� �����Ƿ� �Ϲ������� 4��° column�� �����ϸ� ���� ���� �޸���ƽ ���� ���� 3��° column������ϰ� flag1�� 1�� �ٲ���
				flag1 = 1;
				put(arr, 2, turn);                                                      //�ش� column�� ����                                                
				print_arr(arr);                                                         //���Ӻ��� ���
				printf("�޸���ƽ ������� 7�� �ձ��� Ȯ���Ͽ� 4��° Column �������� ���� 3��° Column�� ����\nScore : %d\n", head->child[2]->value);
			}

			overflow = 0;                                                            //overflow   0���� ����
			if (check(arr) != 0) {
				print_result(check(arr));                                 //������ ������ ���α׷� ����
				break;
			}

			do {                                                                  //(����� ����)overflow�� �߻��Ͽ� �� �̻� ���� ���� �� ���� column���� ���� ���� �� ������ �ϰ� �ٸ� column�� �ε��� ��.
				printf("Select Column: ");
				scanf("%d", &column);
				printf("\n");
				column--;
				set_overflow(arr, column);
			} while (overflow != 0);

			put(arr, column, turn);                                                      //�ش� column�� ����
			overflow = 0;                                                            //overflow���� �ٽ� 0���� �����ص�.(���� �Ͽ� ����ϱ� ����)
			print_arr(arr);                                                            //���� ���Ӻ��� ���
			if (check(arr) != 0) {
				print_result(check(arr));                                 //������ ������ ���α׷� ����
				break;
			}

			system("cls");                                                            //�������� ���� cmdâ Ŭ���� ����
		}
	}


	return 0;                                                                     //���������� ����
}