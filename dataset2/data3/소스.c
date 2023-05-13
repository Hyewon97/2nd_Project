#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define dataNum 233
#define userNum 3 
#define fakeNum 20 

void randomIndex(int arr[]) {
	int i, j;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 5; i++) {
		arr[i] = rand() % 45;

		for (j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
	}

}

int main() {
	int i, j = 0;
	int arr[dataNum];
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char buffer[100];
	int temp = 1;
	int rantemp = 0;
	int rantemp2 = 0;

	FILE* fp;
	char filename[] = "case1.txt";

	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("파일을 열 수 없습니다.");
		exit(1);
	}

	for (i = 0; i < dataNum; i++) {
		char buffer[100];
		fgets(buffer, 100, fp);
		arr[i] = atoi(buffer);
	}

	fclose(fp);


	for (i = 0; i < 3; i++) {
		printf("%d 번째\n",i);
		int tempindexNum1[dataNum];
		for (j = 0; j < userNum; j++) {

			rantemp = 30 + (rand() % 10 + 1);
			rantemp2 = 5 + (rand() % 2 + 1);

			printf("분석용 데이터 갯수 : %d\n", rantemp);
			randomIndex(tempindexNum1);
		}
		printf("\n");
	}
	printf("데이터 저장 완료\n");
	return 0;
}
