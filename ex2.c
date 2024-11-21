/******************
Name: Omer Attia
ID: 206667958
Assignment: ex2
*******************/

#include <stdio.h>
//check all tasks are optimated to 0 as user's input

int main() {
	int choice; //Variable to be the user's chocie for the menu 
	int gameOn = 1;

	printf("Choose an option:\n\n");
	printf("\t1. Happy Face\n\n");
	printf("\t2. Balanced Number\n\n");
	printf("\t3. Generous Number\n\n");
	printf("\t4. Circle Of Joy\n\n");
	printf("\t5. Happy Numbers\n\n");
	printf("\t6. Festival Of Laughter\n\n");
	printf("\t7. Exit\n");

	scanf("%d",&choice);
	while (choice < 1 || choice > 7){
		printf("This option is not available, please try again.\n");
		scanf("%d",&choice); 
		//assuming the user will only enter numbers, this while loop while make sure a valid number in our range
		//is being chosen 
	};

	switch (choice)
	{
	case 1:{
		// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
		char eye,nose,mouth; //chars for the face
		int num1; // integer for the user's choice
		printf("Enter symbols for the eyes, nose and mouth:\n");
		scanf(" %c %c %c",&eye,&nose,&mouth);
		printf("Enter face size:\n");
		scanf("%d",&num1);
		while(num1<0 || !(num1%2))//loop to ensure the number is positive and that it is odd (so the remain won't
		//be false(0))
		{
			printf("The face's size must be an odd and positive number, please try again:\n");
			scanf("%d",&num1);
		};
		//Building the face:
		//Eyes:
		printf("%c",eye);
		for (int i = 0; i<num1;i++){
			printf(" ");//Spaces between the eyes as the number of our user's choice
		};
		printf("%c\n",eye);
		//Nose:
		//The number of spaces before and after the nose is (num1 / 2)
		for (int i=0;i<(num1/2);i++){
			printf(" ");
		}
		printf("%c",nose);
		for (int i=0;i<(num1/2);i++){
			printf(" ");
		}
		printf("\n");
		//Mouth:
		printf("\\");
		for (int i = 0; i<num1 ; i++){
			printf(" ");
		};
		printf("/");
		break;
	}
	case 2: {
		// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
		// and the sum of all digits to the right of the middle digit(s) are equal


		int num2, digCount =0 , temp1; //num2 will be our user's choice, digCount will be the counter
		//of the num's digits and temp1 will help us uncover the digits number
		printf("Enter a number:\n");
		scanf("%d",&num2);
		while (num2<0){
			printf("Only positive number is allowed, please try again:\n");
			scanf("%d",&num2);
		}
		temp1 = num2; // this temp will help us discover the number of digits in our number, without messing
		//the number value
		while (temp1 > 0){
			//running a loop that "collects digits" from our num. every iteration we substract the number by
			//10 and then appending our digits count, until the number is eliminated. 
			temp1 /= 10;
			digCount += 1;
		}
		int oddDigCount = digCount%2; //this will tell us if the number of digits is odd or equal

		//summing the right end of our number
		int rightSum = 0;
		int currentDig = 0; //each digit that will be retrived from the iterations of the following for loop 
		for (int i = 0; i <(digCount/2); i++){
			currentDig = num2%10;//getting the digit
			rightSum += currentDig; //appending the our sum
			num2/=10;//elininating the current digit before moving on
		};
		if (oddDigCount){
			num2/=10;
			//An important check in the program. if the number of digits is odd, it means we have a middle digit
			//which need to be discluded from our summing loops. for example: 12721, we must remove the 7 
			//before entering our next loop so it won't be summed as well 
		};
		//summing the left end of our number
		int leftSum = 0 ;
		for (int i = 0; i <(digCount/2); i++){
			currentDig = num2%10;
			leftSum += currentDig;
			num2/=10;
			//same as the previous loop
		};
		//checking equivalances of our sums
		if (rightSum == leftSum){
			printf("This number is balanced and brings harmony!\n");
		}
		else {
			printf("This number isn't balanced and destroys harmony.\n");
		}
		break;
	}
	case 3: {
		// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
		int num3,sum=0;
		printf("Enter a number:\n");
		scanf("%d",&num3);
		while (num3<=0){
			printf("Only positive number is allowed, please try again:\n");
			scanf("%d",&num3);
		};
		//Now running a loop from 1 to the half of the user's num plus 1. every number which we find as proper divisor
		//would be appended to our sum. we are iterating until the half of the num because for every positive number 
		//there aren't proper divisors bigger than the half of the number
		for (int i=1; i<(num3/2 + 1); i++){
			if (!(num3%i)){
				sum+=i;
			};
		}
		if (sum > num3)
			printf("This number is generous!\n");
		else
			printf("This number does not share.\n");
		;

		break;
	}
	case 4: {
		int num4, temp4, revNum;
		//num4 will ne our user's choice, temp4 will imitate the num4 to help us retrieve his digits,
		//revNum would be the reversed number
		printf("Enter a number:\n");
		scanf("%d",&num4);
		while (num4<=0){
			printf("Only positive number is allowed, please try again:\n");
		scanf("%d",&num4);
		}
		
		//checking if our num is prime, if it's not then we don't need to check his reversed version
		for (int i = 2; i<(num4/2 + 1); i++){
			if (num4%i == 0){
				printf("The circle remains incomplete.\n");
				break;
			}
			}
		printf("hey prime");
		

	break;
	
		}
		


	
	default:
		break;
	}

	
	
    

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}
