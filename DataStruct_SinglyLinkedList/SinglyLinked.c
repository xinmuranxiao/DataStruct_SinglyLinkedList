#include"SinglyLinked.h"

SinglyLinkedNode* createSinglyLinkNode(int num_) {//创建链表
	if (num_ <= 0) {//判端n是否合法
		return NULL;//返回NULL
	}
	SinglyLinkedNode* first = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));//申请一个链表内存
	if (first == NULL) {//判断是否申请成功
		return -2;
	}
	scanf_s("%d", first->Data);//读取数据
	first->next = NULL;//避免空指针
	SinglyLinkedNode* tempPtr = first;//临时存储比便于迭代
	for (int i = 1; i < num_; i++) {
		tempPtr->next = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));//迭代下一个数据
		if (first == NULL) {//判断是否申请成功
			return -2;
		}
		tempPtr = tempPtr->next;//迭代到下一个
		scanf_s("%d", &tempPtr->Data);//读取数据
		tempPtr->next = NULL;//避免空指针
	}
	return first;//返回链表头
}

void listSinglyLinked(SinglyLinkedNode* ptr) {//遍历链表
	while (ptr != NULL) {//迭代ptr
		printf("%d ", ptr->Data);
		ptr = ptr->next;
	}
}

SinglyLinkedNode* selectSinglinkLinked(int num_, SinglyLinkedNode* ptr) {//查询数据
	while (ptr->Data != num_ && ptr->next != NULL) {//迭代ptr看是否存在
		ptr = ptr->next;
	}
	if (ptr->Data !=num_) {//判断是否找到
		return NULL;//未找到，返回NULL
	}
	else {
		return ptr;//找到返回指针
	}
}

int insertHeadSinglyLinked(int num_,SinglyLinkedNode* ptr) {//头结点插入链表
	SinglyLinkedNode* tempPtr = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));//申请内存
	if (tempPtr == NULL) {//判断是否申请成功
		return -2;
	}
	tempPtr->next = ptr->next;//将tempPtr的next指向下一个
	ptr->next = tempPtr;//将ptr的next指向tempPtr
	return 1;
}

int insertSinglyLinked(int num_,int pos_ ,SinglyLinkedNode* ptr) {
	ptr = selectSinglinkLinked(pos_, ptr);//查询数组地址
	if (ptr==NULL) {//是否存在
		return -3;
	}
	else {//存在
		SinglyLinkedNode* tempPtr = ptr->next;//临时存储ptr的next
		ptr->next = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));//申请内存
		if (ptr->next == NULL) {//判断是否申请成功
			return -2;
		}
		ptr->next->Data = num_;//读取数据
		ptr->next->next = tempPtr;//让ptr的下一个节点的next指向原先ptr的下一个，实现插入
		return 1;
	}
}

int appendSinglyLinked(int num_, SinglyLinkedNode* ptr) {//尾部插入
	while (ptr->next != NULL)ptr = ptr->next;//迭代ptr
	SinglyLinkedNode* tempPtr = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));//申请内存
	if (ptr->next == NULL) {//判断是否申请成功
		return -2;
	}
	tempPtr->Data = num_;//存入数据
	tempPtr->next = ptr->next;//使要插入节点指向ptr的next
	ptr->next = tempPtr;//让ptr的下一个节点的next指向原先ptr的下一个，实现插入
	return 1;
}

int getLengthSinglyLinked(SinglyLinkedNode* ptr) {//获取长度
	int length = 0;//声明获取长度
	while (ptr != NULL) {//迭代ptr
		length++;
		ptr = ptr->next;
	}
	return length;//返回链表长度
}

int deleteSinglyLinked(int num_, SinglyLinkedNode* ptr) {//删除链表节点
	SinglyLinkedNode* lastPtr = NULL;//存储节点的上一个节点
	while (ptr->Data != num_ && ptr->next != NULL) {//迭代ptr
		lastPtr = ptr;
		ptr = ptr->next;
	}
	if (ptr->Data != num_||lastPtr==NULL) {//判断是否不存在
		return -3;
	}
	else {
		lastPtr->next = ptr->next;//直接使上一个节点指向下一节点的节点
		free(ptr);//释放节点内存
		return 1;
	}
}

int freeSinglyLinked(SinglyLinkedNode* ptr) {//删除链表
	while (ptr!= NULL) {//迭代ptr
		SinglyLinkedNode* tempPtr = ptr;//存储当前ptr地址
		ptr = ptr->next;//使ptr后移
		free(tempPtr);//释放内存
	}
	return 1;
}