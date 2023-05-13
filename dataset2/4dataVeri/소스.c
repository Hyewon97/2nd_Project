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
//		arr[i] = rand() % 99;  // 0 부터 99 
//
//		for (j = 0; j < i; j++) {  // 중복 제거
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
//	int arr[dataNum] = { 0 }; // 랜덤 값 전달받을 함수
//	int arr2[100];
//	int i,j ;
//
//	for (i = 0; i < 100; i++) {
//		arr2[i] = 200 + i;
//	}
//
//
//	//for (j = 0; j < 5; j++) {
//	//	modify_array(arr); // for문을 돌면서 랜덤 인덱스 함수가 실행
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
//		arr[i] = rand() % 99;  // 0 부터 99 
//
//		for (j = 0; j < i; j++) {  // 중복 제거
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
//		arr[i] = rand() % 99;  // 0 부터 99 
//
//		for (j = 0; j < i; j++) {  // 중복 제거
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
//	int arr[dataNum] = { 0 }; // 랜덤 값 전달받을 함수
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
        arr[i] = rand() % 99;  // 0 부터 99 

        for (j = 0; j < i; j++) {  // 중복 제거
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
    int arr[dataNum] = { 0 }; // 랜덤 값 전달받을 함수
    int i;

    srand((unsigned int)time(NULL)); // 시드 값 초기화

    for (i = 0; i < 5; i++) {
        modify_array(arr);
    }

    return 0;
}
