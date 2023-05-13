#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tree.h"

Node* root;  // 전역 변수 root 선언

Node* createNode(int val)
{
	//1. sizodf(Node) malloc
	Node* pNode = (Node*)malloc(sizeof(Node));
	//2. 초기화 : N->value = val, left, right (NULL)
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	//3. 만든 Node 객체(변수) 포인터 변환
	return pNode;
}

Node* connectChild(Node* parent, Node* left, Node* right)
{
	if (parent == NULL) return NULL;

	parent->left = left;
	parent->right = right;
}

Node* makeTree()
{
	Node* pRoot = NULL;
	Node* tLeft = NULL;
	Node* tRight = NULL;


	pRoot = createNode(100);
	tLeft = createNode(200);
	tRight = createNode(300);

	connectChild(pRoot, tLeft, tRight);

	connectChild(tRight, createNode(400), createNode(500));

	return pRoot;
}

void printTree(Node* root)
{
	if (root == NULL) return;  // 노드가 NULL이면 반환
	printf("Node: %d", root->value);  // 현재 노드의 값을 출력
	printTree(root->left);   // 왼쪽 서브트리 전위 순회
	printTree(root->right);  // 오른쪽 서브트리 전위 순회
}
// 4.추가 함수1 : 이진 트리에서 특정 값을 가진 노드의 포인터를 반환하는 함수
Node* findNode(Node* root, int value)
{
	if (root == NULL) {  // 트리가 빈 트리이면 NULL 반환
		return NULL;
	}
	if (root->value == value) {  // 노드 값이 찾는 값과 일치하면 해당 노드 반환
		return root;
	}
	Node* leftResult = findNode(root->left, value);  // 왼쪽 서브트리에서 찾기
	if (leftResult != NULL) {  // 왼쪽 서브트리에서 찾았으면 해당 노드 반환
		return leftResult;
	}
	return findNode(root->right, value);  // 오른쪽 서브트리에서 찾기
}
// 5.추가 함수2 작성 : 노드를 트리에 삽입하는 코드 작성 (선택적)
Node* insertLeftNode(Node* where, Node* new_node) {
	// where가 NULL이면 삽입할 수 없으므로 NULL 반환
	if (where == NULL) {
		return NULL;
	}

	// 원래 노드의 왼쪽 자식을 저장해둠
	Node* original_left = where->left;
	// 새로운 노드를 where의 왼쪽 자식으로 설정
	where->left = new_node;
	// 새로운 노드의 왼쪽 자식을 기존의 where의 왼쪽 자식으로 설정
	new_node->left = original_left;

	// where 노드를 반환
	return where;
}

Node* insertRightNode(Node* where, Node* new_node) {
	// where가 NULL이면 삽입할 수 없으므로 NULL 반환
	if (where == NULL) {
		return NULL;
	}

	// 원래 노드의 오른쪽 자식을 저장해둠
	Node* original_right = where->right;
	// 새로운 노드를 where의 오른쪽 자식으로 설정
	where->right = new_node;
	// 새로운 노드의 오른쪽 자식을 기존의 where의 오른쪽 자식으로 설정
	new_node->right = original_right;

	return where; // where 노드를 반환
}
