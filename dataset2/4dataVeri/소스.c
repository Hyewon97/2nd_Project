//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define dataNum 5
//
//void modify_array(int arr[]) {
//	int i, j;
//
//	srand((unsigned int)time(NULL));
//
//	for (i = 0; i < dataNum; i++) {
//
//		arr[i] = rand() % 99;  // 0 ���� 99 
//
//		for (j = 0; j < i; j++) {  // �ߺ� ����
//			if (arr[i] == arr[j]) {
//				i--;
//				break;
//			}
//		}
//
//		printf("%d, ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//	int arr[dataNum] = { 0 }; // ���� �� ���޹��� �Լ�
//	int arr2[100];
//	int i,j ;
//
//	for (i = 0; i < 100; i++) {
//		arr2[i] = 200 + i;
//	}
//
//
//	//for (j = 0; j < 5; j++) {
//	//	modify_array(arr); // for���� ���鼭 ���� �ε��� �Լ��� ����
//	//	for (i = 0; i < dataNum; i++) {
//	//		printf("%d ", arr2[arr[i]]);
//	//	}
//	//	printf("\n\n");
//	//}
//
//	for (i=0; i < 5; i++) {
//		modify_array(arr);
//		int arr[dataNum] = { 0 };
//	}
//
//	return 0;
//}
////////////
///////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dataNum 5

//void modify_array(int arr[]) {
//	int i, j;
//
//	srand((unsigned int)time(NULL));
//
//	for (i = 0; i < dataNum; i++) {
//
//		arr[i] = rand() % 99;  // 0 ���� 99 
//
//		for (j = 0; j < i; j++) {  // �ߺ� ����
//			if (arr[i] == arr[j]) {
//				i--;
//				break;
//			}
//		}
//
//		printf("%d, ", arr[i]);
//	}
//	printf("\n");
//}

//void modify_array(int arr[]) {
//	int i, j;
//
//	for (i = 0; i < dataNum; i++) {
//		srand((unsigned int)time(NULL));
//		arr[i] = rand() % 99;  // 0 ���� 99 
//
//		for (j = 0; j < i; j++) {  // �ߺ� ����
//			if (arr[i] == arr[j]) {
//				i--;
//				break;
//			}
//		}
//
//		printf("%d, ", arr[i]);
//	}
//	printf("\n");
//}
//
//
//int main() {
//	int arr[dataNum] = { 0 }; // ���� �� ���޹��� �Լ�
//	int i;
//
//	for (i = 0; i < 5; i++) {
//		modify_array(arr);
//		int arr[dataNum] = { 0 };
//	}
//
//	return 0;
//}

void modify_array(int arr[]) {
    int i, j;

    for (i = 0; i < dataNum; i++) {
        arr[i] = rand() % 99;  // 0 ���� 99 

        for (j = 0; j < i; j++) {  // �ߺ� ����
            if (arr[i] == arr[j]) {
                i--;
                break;
            }
        }

        printf("%d, ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[dataNum] = { 0 }; // ���� �� ���޹��� �Լ�
    int i;

    srand((unsigned int)time(NULL)); // �õ� �� �ʱ�ȭ

    for (i = 0; i < 5; i++) {
        modify_array(arr);
    }

    return 0;
}
