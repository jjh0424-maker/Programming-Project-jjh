#include "notes.h"

#include <stdio.h>
#include <stdlib.h>			//system()을 사용하기 위해 호출
#include <conio.h>			//_kbhit() 와 _getch() 사용을 위해 호출
#include <windows.h>		//Sleep() 사용을 위해 호출


void testing_note()			//연습 모드
{
	system("cls");
	printf("# 연습 모드 선택!\n");
	Sleep(1000);

	ready_motion();		//준비 모션
	starting();			//카운트
	//시작

	//패턴 배치
	p1();
	cut(500);	//0.5초 동안 멈추고 다음 화면을 위해, 화면 지우기
	p2();
	cut(500);
	p3();
	cut(500);
	p4();
	cut(500);
	p5();
	cut(500);
	p6();
	cut(500);
	p7();
	cut(500);
	p0();
}

void note1()			//노트 1
{
	system("cls");
	printf("# 노트 1 선택!\n");
	Sleep(1000);

	ready_motion();		//준비 모션
	starting();			//카운트
	//시작

	//패턴 배치
	p1();
	cut(500);	//0.5초 동안 멈추고 다음 화면을 위해, 화면 지우기
	p0();
	cut(500);
	p3();
	cut(500);
	p0();
	cut(500);
	p5();
	cut(500);
	p0();
	cut(500);
	p7();
	cut(500);
	p0();		//노트 마지막
}

void note2()			//노트 2
{
	system("cls");
	printf("# 노트 2 선택!\n");
	Sleep(1000);

	ready_motion();		//준비 모션
	starting();			//카운트
	//시작

	//패턴 배치
	p1();
	cut(350);	//0.35초 동안 멈추고 다음 화면을 위해, 화면 지우기
	p0();
	cut(350);
	p3();
	cut(350);
	p4();
	cut(350);
	p0();
	cut(350);
	p6();
	cut(350);
	p7();
	cut(350);
	p0();		//노트 마지막
}

void note3()			//노트3
{
	system("cls");
	printf("# 노트 3 선택!\n");
	Sleep(1000);

	ready_motion();		//준비 모션
	starting();			//카운트
	//시작

	//패턴 배치
	p1();
	cut(200);	//0.2초 동안 멈추고 다음 화면을 위해, 화면 지우기
	p0();
	cut(200);
	p0();
	cut(200);
	p0();
	cut(200);
	p5();
	cut(200);
	p6();
	cut(200);
	p7();
	cut(200);
	p0();	//노트 마지막
}

//패턴이 바뀌는 속도와 나타나는 것을 무작위로 함
void random_note()			//랜덤 모드
{
	system("cls");
	printf("# 랜덤 모드 선택!");
	Sleep(1000);

	ready_motion();		//준비 모션
	starting();			//카운트

	//시작
	int random_speed = 200 + random(300);	//최소 0.2초에서 0.5초의 무작위 박자

	p1();	//처음 패턴은 보일 수 있게 고정
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	if (random(2) == 1)		//1/2 확률로 1이 나오면 패턴을 보이게
	{
		p2();
	}
	else		//그렇지 않으면 패턴을 안 보이게
	{
		p0();
	}
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	if (random(2) == 1)		//1/2 확률로 1이 나오면 패턴을 보이게
	{
		p3();
	}
	else		//그렇지 않으면 패턴을 안 보이게
	{
		p0();
	}
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	if (random(2) == 1)		//1/2 확률로 1이 나오면 패턴을 보이게
	{
		p4();
	}
	else		//그렇지 않으면 패턴을 안 보이게
	{ 
		p0();
	}
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	if (random(2) == 1)		//1/2 확률로 1이 나오면 패턴을 보이게
	{
		p5();
	}
	else		//그렇지 않으면 패턴을 안 보이게
	{
		p0();
	}
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	if (random(2) == 1)		//1/2 확률로 1이 나오면 패턴을 보이게
	{
		p6();
	}
	else		//그렇지 않으면 패턴을 안 보이게
	{
		p0();
	}
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	p7();	//마지막 패턴은 보일 수 있게 고정 (모두 패턴이 나오지 않을 때를 대비해)
	cut(random_speed);	//무작위 시간 멈춤, 다음 화면을 위해 화면 지우기

	p0();	//노트 마지막
}