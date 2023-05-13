#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define nameLength 30 // 300
#define num1 5

// 영상 목록 구조체 선언
// 영상 고유번호(int), 영상 이름(string), 팀1(int), 팀2(int), 리그(int)
struct video {
	int videoNum;
	char videoName[nameLength];
	int teamNum1, teamNum2,leagueNum;
};

int main() {

	int i, j; // 반복문 변수 선언

	
	//구조체 배열 선언
	struct video videoArr[num1];
	

	// 구조체 배열 초기화
	for (i = 0; i < num1; i++) {

		videoArr[i].videoNum = i; // 임시 데이터 삽입
		videoArr[i].videoName[nameLength] = "test";
		videoArr[i].teamNum1 = i+10;
		videoArr[i].teamNum2 = i+20;
		videoArr[i].leagueNum = i+30;


		
	}

	// 구조체 배열 초기화 할때는 {,,}로 묶으면 된다. 

	// 파일 저장은 txt로 저장한 뒤에 엑셀로 변환 후 데이터 처리하면 될듯
	
	

/* ********************************************************************************************
	// 데이터 저장 테스트
	FILE* fp = fopen("test.txt", "w"); //test파일을 w(쓰기) 모드로 열기

	for (int i = 0; i < 5; i++) {
		fputs("test\n", fp); //문자열 입력
	}
	fputs("end", fp);

	fclose(fp); //파일 포인터 닫기

	******************************************************************************************** */

	return 0;
}