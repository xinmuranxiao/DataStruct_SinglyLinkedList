#include"SinglyLinked.h"

SinglyLinkedNode* createSinglyLinkNode(int num_) {
	SinglyLinkedNode* first = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
	SinglyLinkedNode* tempPtr = first;
	for (int i = 1; i < num_; i++) {
		tempPtr->next = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
		tempPtr = tempPtr->next;
	}
	return first;
}