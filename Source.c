#include <stdio.h>
#define SIZE 2
#define nums 4

struct Student
{
	char firstName[51];
	char lastName[51];
	char studentId[10];
};

struct SenecaStudent
{
	struct Student student;
	float grades[nums];
	//getGrades;;			// Believing that the professor was confused between C and C++
							// Unlike C++, in C, struct cannot contain a function as a member
							// getGrades() should not be included in SenecaStudent, so it is removed
};

// it is actually void setSenecaStudent(struct Student *) in the paper, 
// but as looked at the definition of it, the argument, Student is technically impossible
void setSenecaStudent(struct SenecaStudent *);
void setStudentId(char *);
// What he wanted to do is to set this as a member function in SenecaStudent (senStudent.getGrade())
// That's why there is no argument for this function in the sheet
// Because it is not possible, need to have SenecaStudent as an argument
// In fact, if you see the definition of getAverageGrade, it will make sense
float getGrades(const struct SenecaStudent);
void setGrades(float ar[], int);
float getAverageGrade(struct SenecaStudent[], int);

int main(void)
{
	struct SenecaStudent students[SIZE] = {
		{ {"Susan", "Wong", "123456789"}, {78.0f, 67.0f, 82.0f, 81.0f} },
		{ { { '\0' }, { '\0' }, { '\0' } }, 0.f }
	};
	float avgGrade;

	setSenecaStudent(&students[1]);

	avgGrade = getAverageGrade(students, SIZE);

	printf("The average grade for the %d Seneca Students is: %.2f\n", SIZE, avgGrade);

	return 0;
}

void setSenecaStudent(struct SenecaStudent* senecaStudent)
{
	printf("Enter First Name: ");
	scanf(" %40[^\n]", senecaStudent->student.firstName);

	printf("Enter Last Name: ");
	scanf(" %40[^\n]", senecaStudent->student.lastName);

	setStudentId(senecaStudent->student.studentId);
	// Because of it, change Student to SenecaStudent
	setGrades(senecaStudent->grades, nums);
}

void setStudentId(char* id)
{
	printf("Enter the student id: ");
	scanf(" %9[^\n]", id);
}

void setGrades(float ar[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Enter a grade: ");
		scanf("%f", &ar[i]);
	}
}

// Because of taking SenecaStudent as an argument list, life has been much easier
float getGrades(const struct SenecaStudent senecaStudent)
{
	float result = 0.f;
	int i;

	for (i = 0; i < nums; i++)
	{
		result += senecaStudent.grades[i];
	}
	return result;
}

float getAverageGrade(struct SenecaStudent students[], int size)
{
	float result = 0.f;

	// He made blanks for these calling functions
	// That means he expects a variable in it
	result += getGrades(students[0]);
	
	result += getGrades(students[1]);

	return result / 2;
}