/*
You are given a list of petrol pumps arranged in a circular path. Each petrol pump has an amount of petrol it can provide and the
distance to the next petrol pump. Your task is to find the starting petrol pump from which a truck can complete
the circular tour without running out of petrol. If there is no possible solution, return -1.
*/
#include <stdio.h>

// A petrol pump has petrol and distance to next petrol pump
struct petrolPump
{
int petrol;
int distance;
};

// The function returns starting point if there is a possible solution,
// otherwise returns -1
int printTour(struct petrolPump arr[], int n)
{
	// Consider first petrol pump as a starting point
	int start = 0;
	int end = 1;

	int curr_petrol = arr[start].petrol - arr[start].distance;

	/* Run a loop while all petrol pumps are not visited.
	And we have reached first petrol pump again with 0 or more petrol */
	while (end != start || curr_petrol < 0)
	{
		// If current amount of petrol in truck becomes less than 0, then
		// remove the starting petrol pump from tour
		while (curr_petrol < 0 && start != end)
		{
			// Remove starting petrol pump. Change start
			curr_petrol -= arr[start].petrol - arr[start].distance;
			start = (start + 1)%n;

			// If 0 is being considered as start again, then there is no
			// possible solution
			if (start == 0)
			return -1;
		}

		// Add a petrol pump to current tour
		curr_petrol += arr[end].petrol - arr[end].distance;

		end = (end + 1)%n;
	}

	// Return starting point
	return start;
}

int main()
{
	struct petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

	int n = sizeof(arr)/sizeof(arr[0]);
	int start = printTour(arr, n);

	(start == -1)? printf("No solution"): printf("Start = %d", start);

	return 0;
}

/*
This C program solves the circular tour problem using a greedy approach. The printTour function takes an array of petrol pumps (arr)
and the number of pumps (n) as input and returns the starting point from which the truck can complete the circular tour.
The struct petrolPump represents a petrol pump with two attributes: the amount of petrol it contains and the distance to the next
petrol pump.

The algorithm starts by considering the first petrol pump as the starting point (start) and the second pump as the current point (end). It calculates the current amount of petrol in the truck (curr_petrol) by subtracting the distance to the next pump from the available petrol. It then enters a loop that continues until either the tour completes (i.e., end becomes equal to start) or the current petrol becomes negative.

If the current petrol becomes negative, it means that the starting point (start) cannot be reached from the current position (end).
In this case, the algorithm removes the starting petrol pump and increments start to the next pump. It subtracts the petrol consumed
from the current petrol and checks if start becomes 0 again. If it does, there is no possible solution, and the function returns -1.

If the current petrol remains non-negative, the algorithm adds the petrol from the next pump to the current petrol and
increments end to the next pump. This simulates moving the truck to the next petrol pump in the circular path.

Once the loop ends, the function returns the starting point (start).

In the main function, a sample input of petrol pumps is provided, and the printTour function is called.
The starting point is then printed if a solution exists; otherwise, "No solution" is printed.
*/
