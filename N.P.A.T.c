#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
	srand(time(NULL));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

	system("title N.P.A.T");

	int cau = 0, cls = 0, temp;
	long double count, loop;
	long long com;
	int objectnum, lnum, mnum;

end:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("\nStarting value, Value to analyze, End value, Number of repetitions: ");

rre:

	if (cau == 1)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\nPlease try again & enter a valid value.");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		printf("\n\nStarting value, Value to analyze, End value, Number of repetitions: ");
	}

	scanf("%d %d %d %lf", &lnum, &objectnum, &mnum, &loop);
	temp = loop;
	system("cls");

	count = 0;
	cau = 0;

	if (lnum < 0 || objectnum < 0 || mnum < 0 || loop < 0 || lnum > objectnum || mnum < objectnum)
	{
		cau = 1;
		while (getchar() != '\n');
		goto rre;
	}

	printf("\n");

	for (int i = 0; i < loop; i++)
	{
	re:

		com = rand() % mnum + 1;

		if (com < lnum || com > mnum)
			goto re;

		if (com == objectnum)
		{
			count++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			printf("%lld ", com);
			continue;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("%lld ", com);
	}

	while (getchar() != '\n');

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n\nYour command:  ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%d(start) ~ ", lnum);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("%d", objectnum);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf(" ~% d(end)", mnum);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("    %d times ", temp);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n\nResult: %d Num came out %lf times in total. --> %lf\%\% Percentage\n\n\n\n", objectnum, count, (count / loop) * 100);

	goto end;

	return 0;
}