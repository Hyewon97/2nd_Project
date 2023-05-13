#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> // rand() 함수 포함 라이브러리
#include <time.h>

// 상수 선언
#define dataNum 233 // 데이터의 갯수
#define userNum 30 // 유저 수
#define fakeNum 20 // 가짜 데이터 수

// 함수 선언
void randomIndex(int arr[]) { // 입력 인자는 int 배열s
	int i, j;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 40; i++) { 
		arr[i] = rand() % 45;  //0부터 44까지 숫자를 이용하기 위함. 함수 인덱스 값으로 넣기 위해 범위를 0부터 시작한다.

		for (j = 0; j < i; j++) {  //로또에서 중복은 없으므로 중복 제거를 위한 포문
			if (arr[i] == arr[j]) {
				i--;  //중복이 발견될 경우 i번째 숫자를 다시 뽑는다.
				break;
			}
		}
	}

}

/* 갯수를 받아서 그 갯수만큼 난수를 발생하되, 중복 없도록 설정하고 배열에 저장해서 리턴하는 함수 */

int main() {
	// 번수 선언
	int i, j = 0;
	int arr[dataNum]; // 텍스트 데이터 저장할 배열 생성
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char buffer[100];
	int temp = 1;
	int rantemp = 0; // 분석용 데이터 난수 갯수 설정 변수
	int rantemp2 = 0; // 가짜 데이터 난수 갯수 설정 변수


	/////////////////////////////////////////////// case 텍스트 파일 읽어와서 int 배열에 저장하기 
	FILE* fp;
	char filename[] = "case1.txt"; // case 저장된 파일 불러오기
	
	fp = fopen(filename, "r");

	// 파일이 없는 경우 프로그램 종료
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.");
		exit(1);
	}

	// case 데이터, String 타입을 int 타입으로 변환 후 int 배열에 저장
	for (i = 0; i < dataNum; i++) {
		char buffer[100];
		fgets(buffer, 100, fp);  // 파일에서 한 줄씩 읽어옴
		arr[i] = atoi(buffer);   // 문자열을 int형으로 변환하여 저장

		//arr2[i] = i + 10;

	}

	fclose(fp);
	////////////////////////////////////////////////////////////////////////// 배열 저장 끝


	// 가짜 데이터 만드는 함수
	int fakeData[fakeNum]; // 가짜 데이터 변수 초기화

	for (i = 0; i < fakeNum; i++) { // 가짜 데이터 변수만큼 임의 숫자 넣기.. 아마 나중에 중복 없는 랜덤 값으로 값 받아러 처리하는 부분 필요할지도
		fakeData[i] = i + 200;
	}

	// 영상 갯수를 랜덤 함수에 던져서 랜덤 함수 인덱스 배열을 만듦
	// main문에서 인덱스 번호를 받을 배열 생성
	int tempindexNum1[40];

	/* 데이터 작성 후 txt 파일로 내보내기 */
	FILE* fp2 = fopen("savetest.txt", "w"); // 저장 될 txt 이름 설정, 쓰기 모드 w
	
	// 분석용 데이터 넣기
	//for (j = 0; j < userNum; j++) { // 사용자 숫자
	for (j = 0; j < 2; j++) { // 사용자 숫자

		rantemp = 10;// +(rand() % 10 + 1); // 분석용 데이터 갯수를 난수로  설정 (범위 1 ~ 10), 전체 갯수 범위 30 ~40개로 설정
		rantemp2 = 5 + (rand() % 2 + 1); // 가짜 데이터 갯수를 난수로 설정 (범위 1 ~ 3)

		printf("분석용 데이터 갯수 : %d\n", rantemp);
		randomIndex(tempindexNum1); // 랜덤 값 받기

		// 분석용 데이터 저장하는 반복문
		for (i = 0; i < rantemp; i++) { // 영상 저장 갯수

			// 사용자 번호
			sprintf(buffer, "%d", temp);  // int형 값을 문자열로 변환
			fputs(buffer, fp2);             // 파일에 문자열 쓰기
			fputs(",", fp2);               // 줄바꿈 문자 쓰기

			// 영상 번호
			sprintf(buffer, "%d", arr[tempindexNum1[i]]);  // 랜덤 인덱스 값을 받아서 저장 int형 값을 문자열로 변환
			fputs(buffer, fp2);             // 파일에 문자열 쓰기
			fputs(",", fp2);               // 줄바꿈 문자 쓰기

			// 평점.. 분석용 데이터는 평점 5로 고정
			sprintf(buffer, "%d", 5);  // int형 값을 문자열로 변환
			fputs(buffer, fp2);             // 파일에 문자열 쓰기
			fputs("\n", fp2);              // 줄바꿈 문자 쓰기

		}

		// 가짜 데이터 저장하는 반복문
		for (i = 0; i < rantemp2; i++) { // 
			// 사용자 번호 저장
			sprintf(buffer, "%d", temp);  // int형 값을 문자열로 변환
			fputs(buffer, fp2);             // 파일에 문자열 쓰기
			fputs(",", fp2);               // 줄바꿈 문자 쓰기

			// 가짜 데이터 저장 
			// 가짜 데이터는 가짜 데이터 넣을 배열 생성 후, 텍스트로 값 읽어오고 랜덤 값으로 수정해야함
			sprintf(buffer, "%d", fakeData[i]);  // int형 값을 문자열로 변환
			fputs(buffer, fp2);             // 파일에 문자열 쓰기
			fputs(",", fp2);               // 줄바꿈 문자 쓰기

			// 평점. 1~3까지 랜덤 값으로 던져줘야 함. 중복 상관 없음
			sprintf(buffer, "%d", rand() % 3 + 1);  // 랜덤 번호 받기 1~3
			fputs(buffer, fp2);             // 파일에 문자열 쓰기
			fputs("\n", fp2);              // 줄바꿈 문자 쓰기
		}

		temp++; // 사용자 번호 증가
	}
	


	fclose(fp2); //파일 포인터 닫기

	printf("데이터 저장 완료\n"); // 데이터 전달 확인용 메세지


	// 케이스 별 영상 번호 담은 배열 저장
	// 텍스트 파일에서 프로그램에서 값 읽어서 int 배열에 넘겨주는 방법

	return 0;
}
