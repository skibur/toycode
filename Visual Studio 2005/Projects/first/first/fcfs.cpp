#include <stdio.h>
#include <stdlib.h>

void menu();

int find_length(int array[], int size)
{
	int counter = size;
	int total = 0;
    while ( counter > 0 )
	{
		counter --;
		total = total + array[counter];
	}
	return (total);
}


///////////////////////////
//
//  FUNCTION NAME: first_come
//  INPUT: two arrays and their sizes, the first array being
//  a list of execution times and the second array being a list
//  of respective arrival times. Also include the number of jobs
//  and include the total length of all the jobs which can be
//  found with the find_length function
//  OUTPUT: a list of the jobs in the order in which they arrive
//
///////////////////////////

int first_come(int array[], int size, int array2[],
    int size2, int total_pro, int total_length)
{
    int current_time = 0; // Used to keep track of time
    int time_counter = 0;
	int counter = 0;
    int print_counter = 0;
	while( total_length > 0 )
	{

       if ( counter == total_pro )
       {
          counter = 0;
       }

       if( (array[counter] > 0) && ( current_time >= array2[counter] ) )
       {
          print_counter = array[counter];
          while ( print_counter > 0 )
          {
             printf("Process %d at Time %d\n", counter, current_time);
             print_counter--;
             current_time++;
             total_length--;
          }
          array[counter] = 0;
       }
       counter++;

       if ( current_time < array2[counter] )
       {
           time_counter++;
       }

       if ( time_counter == total_pro )
       {
           printf("%d skipped\n", current_time);
           current_time++;
           time_counter = 0;
       }
	}
    return 0;
}


///////////////////////////
//
// NAME: Scheduling Simulator
// DATE: 02.28.2007 
//
//////////////////////////

int main()
{
	int exec[10] =  {2,2,2,0,0,0,0,0,0,0};	// executions required for jobs
	int arriv[10] = {0,5,0,0,0,0,0,0,0,0};  // arrival times of jobs
	int total_pro = 3;                      // total number of jobs
    int total_length = 0;                   // amount of execution required
    int exit_flag = 0;
    char entry;
    int counter;

    counter = 0;
    system("cls");

    // This function call will find total executions required

    total_length = find_length(exec, 10);

    // This function does the round robin
    //round_robin(exec, 10, arriv, 10, total_pro, total_length);

    // This function does the first come first serve
    first_come(exec, 10, arriv, 10, total_pro, total_length);

    system("pause");
	return 0;
}
