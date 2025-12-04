#define _CRT_SECURE_NO_WARNINGS

#include "pattern.h"		//패턴 모형을 모아둔 헤더 호출

#include <stdio.h>
#include <stdlib.h>			//system()을 사용하기 위해 호출
#include <conio.h>			//_kbhit() 와 _getch() 사용을 위해 호출
#include <windows.h>		//Sleep() 사용을 위해 호출

int random(int N)		//N개의 무작위 수를 만드는 랜덤 함수
{
	int r;
	r = rand() % N + 1;
	return r;	//무작위 수 반환
}

//화면을 지우고 생성하고를 반복하여 움직이는 모션을 구현
void cut(int n)		//n값 동안 화면을 멈추고, 화면 지우기를 수행하는 함수
{
	Sleep(n);		//화면을 해당 시간(1000 = 1초) 만큼 멈춤
	system("cls");		//화면을 지우는 함수
}

void ready_motion()		//플레이하기 전 준비 모션 함수
{
	//Sleep() 을 통해 화면을 해당 시간(1000 = 1초)만큼 멈춤
	//system("cls") 를 통해 화면을 지움
	system("cls");
	Sleep(500);
	
	printf("             ㅣ             ");
	cut(500);
	printf("             ][             ");
	cut(250);
	printf("             ] [             ");
	cut(750);
	printf("            -] [-            ");
	cut(100);
	printf("          - -] [- -          ");
	cut(100);
	printf("        - - -] [- - -        ");
	cut(100);
	printf("      - - - -] [- - - -      ");
	cut(100);
	printf("    - - - - -] [- - - - -    ");
	cut(100);
	printf("  - - - - - -] [- - - - - -  ");
	cut(100);
	printf("- - - - - - -] [- - - - - - -");
}

void starting()		//시작 카운트와 노트 시작 전 랜덤 시간 공백으로 시작
{
	system("cls");
	printf("- - - - - - -] [- - - - - - -\n# ready");
	cut(2000);
	printf("- - - - - - -] [- - - - - - -\n# 3");		
	cut(1000);
	printf("- - - - - - -] [- - - - - - -\n# 2");
	cut(1000);
	printf("- - - - - - -] [- - - - - - -\n# 1");
	cut(1000);
	p0();
	
	cut(random(2000) + 1000);		//노트 시작 전, 최소 1초에서 최대 3초 무작위 딜레이
}

int check()			//노트가 다 끝난 후, 반응속도를 측정할 함수
{
	int rythm = 0;		//반응 속도값을 받을 변수

	while (1)		//키 입력을 감지 할 때까지 반복할 문
	{
		//_kbhit() 를 사용하여 키 입력 감지
		if (_kbhit() == 1)		//_kbhit() : 키가 눌렸으면 1 반환
		{
			int typing = _getch();   //_getch()로 입력 문자 읽기

			if (typing == 13)		//ASCII코드에서 엔터는 = 13,  엔터가 입력되면 반복문 중지
			{      
				printf("\n과연 결과는?\n");
				break;
			}
		}

		//0.01초 동안 대기
		Sleep(10);

		//키가 감지되지 않았으면 반응 속도 값 증가
		rythm = rythm + 1;
	}
	

	if (rythm == 0)			//반응속도값이 0일 경우, 즉 측정 전에 엔터 키 입력이 있었을 경우
	{
		printf("\n# 이런.. 너무 빨리 눌렀습니다! #\n");
	}
	else if (rythm > 0 && rythm <= 15)		//0에서 15 사이 Perfect
	{
		printf("\n# Perfect! #\n");
	}
	else if (rythm > 15 && rythm <= 20)		//15에서 20 사이 Good
	{
		printf("\n# Good! #\n");
	}
	else if (rythm > 20 && rythm <= 30)		//20에서 30 사이 Not Bad
	{
		printf("\n# Not Bad! #");
	}
	else			//31 이상 Oops
	{
		printf("\n# Oops! #\n");
	}
	
	printf("\n당신의 반응 값 : %d\n", rythm);		//반응속도값 출력
}



int main()			//메인 함수
{
	int play = 1;		//게임 반복의 중지를 정할 변수
	int play_note;		//플레이할 모드 선택
	int select = 0;		

	srand(time(NULL));		//무작위 수를 사용하기 위해 난수 생성 시드 초기화

	while (play)		//게임 시작 반복문
	{
		system("cls");		//이전의 화면을 지워, 화면 원상 복귀
		printf("##### 박자 맞추기 게임에 오신 것을 환영합니다! #####\n\n");
		printf("선택 / 1. 연습 모드,  2. 박자 선택,  3. 랜덤 모드\n:");
		
		scanf("%d", &play_note);		//모드 선택



		switch (play_note)		//선택한 모드
		{
		case 1:			//1번 연습모드 선택
			testing_note();		//연습모드 노트 출력
			check();			//반응속도 측정 및 출력
			break;
		case 2:			//2번 박자 선택
			printf("Note (1, 2, 3)\n:");
			scanf("%d", &select);	//노트 선택
			if (select == 1)		//note1 선택
			{
				note1();		//note1 노트 출력
				check();		//반응속도 측정 및 출력
			}
			else if (select == 2)		//note2 선탣
			{
				note2();		//note2 노트 출력
				check();		//반응속도 측정 및 출력
			}
			else if (select == 3)		//note3 선택
			{
				note3();		//note3 노트 출력
				check();		//반응속도 측정 및 출력
			}
			else				//선택이 잘못되었을 경우
			{
				printf("# 잘못된 선택입니다");
			}
			break;
		case 3:			//3번 랜덤 모드 선택
			random_note();		//무작위 노트 출력
			check();			//반응속도 측정 및 출력
			break;
		default:		//선택이 잘못되었을 경우
			printf("# 잘못된 입력입니다");
			break;
		}



		printf("\n\n0: 종료하기  /  1: 계속하기\n:");
		scanf("%d", &play);		//반복문의 중지 여부 선택
	}

	//반복문 종료, 게임 종료
	system("cls");		//종료 화면을 위해, 화면 지우기
	printf("##### 게임이 종료되었습니다! #####\n\n");

	return 0;
}