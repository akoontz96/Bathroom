/*
Andrew Koontz
CSC 389
Progressive Bathroom
*/

#include <stdio.h>

int cycle = 0;
int people = 0;
int status = 0;
int queue[30];
int queueNum = 0;
int stop = 0;
int choice = 0;
int front = 0;
int count = 0;

main ()
{
	while (stop != 1)
	{
		cycle++;
		printf("What is happening?\n");
		printf("1: Woman wants to enter.\n");
		printf("2: Man wants to enter.\n");
		printf("3: Woman left the bathroom.\n");
		printf("4: Man left the bathroom.\n");
		printf("5: Exit Program.\n");
		scanf("%d", &choice);
		
		if (choice == 1)
		{
			woman_wants_to_enter();
		}
		else if (choice == 2)
		{
			man_wants_to_enter();
		}
		else if (choice == 3)
		{
			woman_leaves();
		}
		else if (choice == 4)
		{
			man_leaves();
		}
		else
		{
			printf("Thank you for using our progressive bathroom.\n");
			printf("Have a nice day.\n");
			stop = 1;
		}
		
		printf("Cycle Number: ");
		printf("%d", cycle);
		printf("\n");
		if (status == 0)
		{
			printf("Status of Bathroom: Empty\n");
		}
		else if (status == 1)
		{
			printf("Status of Bathroom: Women\n");
		}
		else
		{
			printf("Status of Bathroom: Men\n");
		}
		printf("Number of People in the Bathroom: ");
		printf("%d", people);
		printf("\n");
		printf("People in Queue (1 = Female, 2 = Male): ");
		int i;
		for(i = 0; i < 30; i++)
		{
			printf("%d", queue[i]);
		}
		printf("\n");
	}
}

woman_wants_to_enter()
{
	if (status == 0 || status == 1 && count == 0)
	{
		status = 1;
		people++;
	}
	else
	{
		queue[queueNum] = 1;
		queueNum++;
		count++;
	}
}

man_wants_to_enter()
{
	if (status == 0 || status == 2 && count == 0)
	{
		status = 2;
		people++;
	}
	else
	{
		queue[queueNum] = 2;
		queueNum++;
		count++;
	}
}

woman_leaves()
{
	if (status == 1)
	{
		people--;
		if (people == 0 && count == 0)
		{
			status = 0;
		}
		else
		{
			if (people == 0)
			{
				while (queue[front] == 2)
				{
					people++;
					queue[front] = 0;
					front++;
					count--;
				}
				status = 2;
			}
		}
	}
	else
	{
		printf("There are no women in the bathroom.\n");
	}
}

man_leaves()
{
	if (status == 2)
	{
		people--;
		if (people == 0 && count == 0)
		{
			status = 0;
		}
		else
		{
			if (people == 0)
			{
				while(queue[front] == 1)
				{
					people++;
					queue[front] = 0;
					front++;
					count--;
				}
				status = 1;
			}
		}
	}
	else
	{
		printf("There are no men in the bathroom.\n");
	}
}