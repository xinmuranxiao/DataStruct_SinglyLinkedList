#include"SinglyLinked.h"

SinglyLinkedNode* createSinglyLinkNode(int num_) {
	if (num_ <= 0) {
		return NULL;
	}
	SinglyLinkedNode* first = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
	scanf_s("%d", first->Data);
	first->next = NULL;
	SinglyLinkedNode* tempPtr = first;
	for (int i = 1; i < num_; i++) {
		tempPtr->next = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
		tempPtr = tempPtr->next;
		scanf_s("%d", &tempPtr->Data);
		tempPtr->next = NULL;
	}
	return first;
}

void listSinglyLinked(SinglyLinkedNode* ptr) {
	while (ptr != NULL) {
		printf("%d ", ptr->Data);
		ptr = ptr->next;
	}
}

SinglyLinkedNode* selectSinglinkLinked(int num_, SinglyLinkedNode* ptr) {
	while (ptr->Data != num_ && ptr->next != NULL) {
		ptr = ptr->next;
	}
	if (ptr->Data !=num_) {
		return NULL;
	}
	else {
		return ptr;
	}
}

int insertHeadSinglyLinked(int num_,SinglyLinkedNode* ptr) {
	SinglyLinkedNode* tempPtr = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
	tempPtr->next = ptr->next;
	ptr->next = tempPtr;
	return 1;
}

int insertSinglyLinked(int num_, SinglyLinkedNode* ptr) {
	ptr = selectSinglinkLinked(num_, ptr);
	if (ptr==NULL) {
		return -1;
	}
	else {
		SinglyLinkedNode* tempPtr = ptr->next;
		ptr->next = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
		scanf_s("%d",&ptr->next->Data);
		ptr->next->next = tempPtr;
		return 1;
	}
}

int appendSinglyLinked(int num_, SinglyLinkedNode* ptr) {
	while (ptr->next != NULL)ptr = ptr->next;
	SinglyLinkedNode* tempPtr = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
	tempPtr->Data = num_;
	tempPtr->next = ptr->next;
	ptr->next = tempPtr;
	return 1;
}

int getLengthSinglyLinked(SinglyLinkedNode* ptr) {
	int length = 0;
	while (ptr != NULL) {
		length++;
		ptr = ptr->next;
	}
	return length;
}

int deleteSinglyLinked(int num_, SinglyLinkedNode* ptr) {
	SinglyLinkedNode* lastPtr = NULL;
	while (ptr->Data != num_ && ptr->next != NULL) {
		lastPtr = ptr;
		ptr = ptr->next;
	}
	if (ptr->Data != num_||lastPtr==NULL) {
		return -1;
	}
	else {
		lastPtr->next = ptr->next;
		free(ptr);
		return 1;
	}
}

int freeSinglyLinked(SinglyLinkedNode* ptr) {
	while (ptr!= NULL) {
		SinglyLinkedNode* tempPtr = ptr;
		ptr = ptr->next;
		free(tempPtr);
	}
	return 1;
}