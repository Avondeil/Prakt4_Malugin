

#include <iostream>
#include <conio.h>
#include <stdio.h>
struct Triangle
{
	double a, b, c;

	double square() const
	{
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s * c));
	}

	double perimeter() const
	{
		return a + b + c;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	FILE *file;
	Triangle triangles[4] =
	{
		{3,4,5}, {6,8,10}, {12,16,20}, {24,32,40}
	};

	if ((fopen_s(&file,"triangles.txt", "w")) != 0)
	{
		printf("Файл невозможно открыть или создать\n");
	}
	else {
		for (int i = 0; i<4; i++)
		{
			fprintf(file, "Треугольник номер %d\n", i + 1);
			fprintf(file, "a = %2lf\n", triangles[i].a);
			fprintf(file, "b = %2lf\n", triangles[i].b);
			fprintf(file, "c = %2lf\n", triangles[i].c);
			fprintf(file, "s = %2lf\n", triangles[i].square());
			fprintf(file, "p = %2lf\n\n", triangles[i].perimeter());

		}
		fclose(file);
		printf("Файл закрыт, треугольники записаны.");
		return 0;
	}


}

