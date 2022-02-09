#include <iostream>
#include <unistd.h>
void Count_odd_or_even(int arr[] , int size)
{
	int sum_of_odd = 0;
	int sum_of_even = 0;
	if(fork() == 0)
	{
		for(int i = 0 ; i < size ; ++i)
		{
			if(arr[i] % 2 != 0)
			{
				sum_of_odd += arr[i];
			}	
		}
		std::cout << "Count of odd numbers: " << sum_of_odd;
	}
	else
	{
		for(int i = 0 ; i < size ; ++i)
		{
			if(arr[i] % 2 == 0)
			{
				sum_of_even += arr[i];
			}
		}
		std::cout << " | Count of even numbers: " << sum_of_even << std::endl;	
	}
}

int main()
{
	int size;
	std::cin >> size;
	const int size_of_array = size;
	int arr[size_of_array];
	for(int i = 0 ; i < size_of_array ; ++i)
	{
		arr[i] = rand() % 100;
	}
	Count_odd_or_even(arr , size_of_array);
}
