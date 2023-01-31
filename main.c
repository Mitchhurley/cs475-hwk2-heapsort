#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 12
#define MAX_INPUT_LEN 128

int main(int argc, char *argv[])
{
	Employee tester[MAX_EMPLOYEES] = {};
	char sal[MAX_INPUT_LEN] = {};
	for (int i = 0; i < MAX_EMPLOYEES; i++){
		
		printf("Please enter a name for employee #%d: \n", i);
		Employee tmp;
		fgets(tmp.name, MAX_NAME_LEN, stdin);
		strtok(tmp.name, "\n");
		printf("Please enter salary: ");
		fgets(sal, MAX_INPUT_LEN, stdin);
		tmp.salary = atoi(sal);
		printf("Name = %s, Salary = %d\n ", tmp.name,tmp.salary);
		tester[i] = tmp;
	}
	heapSort(tester, MAX_EMPLOYEES);
	return 0;
}
