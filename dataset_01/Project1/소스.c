#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define nameLength 30 // 300
#define num1 5

// ���� ��� ����ü ����
// ���� ������ȣ(int), ���� �̸�(string), ��1(int), ��2(int), ����(int)
struct video {
	int videoNum;
	char videoName[nameLength];
	int teamNum1, teamNum2,leagueNum;
};

int main() {

	int i, j; // �ݺ��� ���� ����

	
	//����ü �迭 ����
	struct video videoArr[num1];
	

	// ����ü �迭 �ʱ�ȭ
	for (i = 0; i < num1; i++) {

		videoArr[i].videoNum = i; // �ӽ� ������ ����
		videoArr[i].videoName[nameLength] = "test";
		videoArr[i].teamNum1 = i+10;
		videoArr[i].teamNum2 = i+20;
		videoArr[i].leagueNum = i+30;


		
	}

	// ����ü �迭 �ʱ�ȭ �Ҷ��� {,,}�� ������ �ȴ�. 

	// ���� ������ txt�� ������ �ڿ� ������ ��ȯ �� ������ ó���ϸ� �ɵ�
	
	

/* ********************************************************************************************
	// ������ ���� �׽�Ʈ
	FILE* fp = fopen("test.txt", "w"); //test������ w(����) ���� ����

	for (int i = 0; i < 5; i++) {
		fputs("test\n", fp); //���ڿ� �Է�
	}
	fputs("end", fp);

	fclose(fp); //���� ������ �ݱ�

	******************************************************************************************** */

	return 0;
}