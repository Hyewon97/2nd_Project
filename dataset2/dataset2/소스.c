#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> // rand() �Լ� ���� ���̺귯��
#include <time.h>

// ��� ����
#define dataNum 233 // ���� �������� ����
#define userNum 30 // ���� ��
// #define fakeNum 20 // ��¥ ������ ��
#define saveNum 40
#define fakeMax 140

// �Լ� ����
void randomIndex(int arr[]) { // �Է� ���ڴ� int �迭s
	int i, j;


	for (i = 0; i < saveNum+ fakeMax; i++) {  // ��¥ �������� �ִ밹��
		arr[i] = rand() % (saveNum+fakeMax);  //0���� 44���� ���ڸ� �̿��ϱ� ����. �Լ� �ε��� ������ �ֱ� ���� ������ 0���� �����Ѵ�.

		for (j = 0; j < i; j++) {  //�ζǿ��� �ߺ��� �����Ƿ� �ߺ� ���Ÿ� ���� ����
			if (arr[i] == arr[j]) {
				i--;  //�ߺ��� �߰ߵ� ��� i��° ���ڸ� �ٽ� �̴´�.
				break;
			}
		}
	}

}

/* ������ �޾Ƽ� �� ������ŭ ������ �߻��ϵ�, �ߺ� ������ �����ϰ� �迭�� �����ؼ� �����ϴ� �Լ� */

int main() {
	// ���� ����
	int i, j = 0;
	int arr[dataNum]; // �ؽ�Ʈ ������ ������ �迭 ����
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char buffer[100];
	int temp = 1;
	int rantemp = 0; // �м��� ������ ���� ���� ���� ����
	int rantemp2 = 0; // ��¥ ������ ���� ���� ���� ����


	/////////////////////////////////////////////// case �ؽ�Ʈ ���� �о�ͼ� int �迭�� �����ϱ� 
	FILE* fp;
	char filename[] = "case1.txt"; // case ����� ���� �ҷ�����
	
	fp = fopen(filename, "r");

	// ������ ���� ��� ���α׷� ����
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.");
		exit(1);
	}

	// case ������, String Ÿ���� int Ÿ������ ��ȯ �� int �迭�� ����
	for (i = 0; i < dataNum; i++) {
		char buffer[100];
		fgets(buffer, 100, fp);  // ���Ͽ��� �� �پ� �о��
		arr[i] = atoi(buffer);   // ���ڿ��� int������ ��ȯ�Ͽ� ����

		//arr2[i] = i + 10;

	}

	fclose(fp);
	////////////////////////////////////////////////////////////////////////// �迭 ���� ��


	// ��¥ ������ ����� �Լ�
	//int fakeData[fakeNum]; // ��¥ ������ ���� �ʱ�ȭ

	//for (i = 0; i < fakeNum; i++) { // ��¥ ������ ������ŭ ���� ���� �ֱ�.. �Ƹ� ���߿� �ߺ� ���� ���� ������ �� �޾Ʒ� ó���ϴ� �κ� �ʿ�������
	//	fakeData[i] = i + 200;
	//}

	// ���� ������ ���� �Լ��� ������ ���� �Լ� �ε��� �迭�� ����
	// main������ �ε��� ��ȣ�� ���� �迭 ����
	int tempindexNum1[saveNum+fakeMax];

	/* ������ �ۼ� �� txt ���Ϸ� �������� */
	FILE* fp2 = fopen("savetest.txt", "w"); // ���� �� txt �̸� ����, ���� ��� w
	
	srand((unsigned int)time(NULL)); // �õ� �� �ʱ�ȭ

	// �м��� ������ �ֱ�
	for (j = 0; j < userNum; j++) { // ����� ����

		rantemp = saveNum +(rand() % fakeMax + 1); // �м��� ������ ������ ������  ���� (���� 1 ~ 10), ��ü ���� ���� 30 ~40���� ����
		//rantemp2 = 5 + (rand() % 2 + 1); // ��¥ ������ ������ ������ ���� (���� 1 ~ 3)

		printf("�м��� ������ ���� : %d\n", rantemp);
		randomIndex(tempindexNum1); // ���� �� �ޱ�

		// ���� �����͸� �����ϴ� �κ�


		// �м��� ������ �����ϴ� �ݺ���
		for (i = 0; i < rantemp; i++) { // ���� ���� ����

			// ����� ��ȣ
			sprintf(buffer, "%d", temp);  // int�� ���� ���ڿ��� ��ȯ
			fputs(buffer, fp2);             // ���Ͽ� ���ڿ� ����
			fputs(",", fp2);               // �ٹٲ� ���� ����

			// ���� ��ȣ
			sprintf(buffer, "%d", arr[tempindexNum1[i]]);  // ���� �ε��� ���� �޾Ƽ� ���� int�� ���� ���ڿ��� ��ȯ
			fputs(buffer, fp2);             // ���Ͽ� ���ڿ� ����
			fputs(",", fp2);               // �ٹٲ� ���� ����

			// ����.. �м��� �����ʹ� ���� 5�� ����
			sprintf(buffer, "%d", 5);  // int�� ���� ���ڿ��� ��ȯ
			fputs(buffer, fp2);             // ���Ͽ� ���ڿ� ����
			fputs("\n", fp2);              // �ٹٲ� ���� ����

		}

		// ��¥ ������ �����ϴ� �ݺ���
		/*
		for (i = 0; i < rantemp2; i++) { // 
			// ����� ��ȣ ����
			sprintf(buffer, "%d", temp);  // int�� ���� ���ڿ��� ��ȯ
			fputs(buffer, fp2);             // ���Ͽ� ���ڿ� ����
			fputs(",", fp2);               // �ٹٲ� ���� ����

			// ��¥ ������ ���� 
			// ��¥ �����ʹ� ��¥ ������ ���� �迭 ���� ��, �ؽ�Ʈ�� �� �о���� ���� ������ �����ؾ���
			sprintf(buffer, "%d", fakeData[i]);  // int�� ���� ���ڿ��� ��ȯ
			fputs(buffer, fp2);             // ���Ͽ� ���ڿ� ����
			fputs(",", fp2);               // �ٹٲ� ���� ����

			// ����. 1~3���� ���� ������ ������� ��. �ߺ� ��� ����
			sprintf(buffer, "%d", rand() % 3 + 1);  // ���� ��ȣ �ޱ� 1~3
			fputs(buffer, fp2);             // ���Ͽ� ���ڿ� ����
			fputs("\n", fp2);              // �ٹٲ� ���� ����
		}
		*/

		temp++; // ����� ��ȣ ����
	}
	


	fclose(fp2); //���� ������ �ݱ�

	printf("������ ���� �Ϸ�\n"); // ������ ���� Ȯ�ο� �޼���

	return 0;
}
