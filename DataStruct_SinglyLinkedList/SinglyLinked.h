#pragma once
#include<stdio.h>

typedef struct SinglyLinkedNode {
	int Data;
	struct SinglyLinkedNode* next;
}SinglyLinkedNode;

SinglyLinkedNode* createSinglyLinkNode(int num_);//创建链表

void listSinglyLinked(SinglyLinkedNode* ptr);//遍历链表

SinglyLinkedNode* selectSinglinkLinked(int num_, SinglyLinkedNode* ptr);//查找节点

int insertHeadSinglyLinked(int num_, SinglyLinkedNode* ptr);//头部插入节点

int insertSinglyLinked(int num_, SinglyLinkedNode* ptr);//指定插入

int appendSinglyLinked(int num_, SinglyLinkedNode* ptr);//尾部插入节点

int deleteSinglyLinked(int num_, SinglyLinkedNode* ptr);//删除节点

int freeSinglyLinked(SinglyLinkedNode* ptr);//释放链表