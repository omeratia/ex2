/******************
Name: Omer Attia
ID: 206667958
Assignment: ex2
*******************/

#include <stdio.h>
//check all tasks are optimated to 0 as user's input

int main() {
	int choice; //Variable to be the user's chocie for the menu 
	int gameOn = 1; //Variable to indicate if the user keep playing or the program need to be terminated
	while (gameOn){
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
			printf("Enter symbols for the eyes, nose and mouse:\n");
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
			int num4, temp4, revNum, isPrime=1;
			//num4 will ne our user's choice, temp4 will imitate the num4 to help us retrieve his digits,
			//revNum would be the reversed number
			//isPrime is our indicator for which our number is prime and his reversed version need to be checked
			printf("Enter a number:\n");
			scanf("%d",&num4);
			while (num4<=0){
				printf("Only positive number is allowed, please try again:\n");
			scanf("%d",&num4);
			}

			//special cases for 1,2,3 as the following loop condition (i<(num4/2 +1)) isn't optimized for
			//them.

			if (num4 == 1){
				printf("The circle remains incomplete.\n");
				isPrime = 0;
				break;}
			else if (num4 == 2 || num4 == 3) {
				printf("This number completes the circle of joy!\n");
				break;
			}
			
			
			//checking if our num has a divisor, which will indicate weather it is a prime number.
			// if it's not then we don't need to check his reversed version.
			for (int i = 2; i<(num4/2 + 1); i++){
				if (num4%i == 0){
					printf("The circle remains incomplete.\n");
					isPrime = 0;
					break;
				}
			}
			if (isPrime){
				//if we got here it means our number is prime, and we need to check his reversed version.
				revNum = 0;
				temp4 = num4;
				int currentDig;
				while (temp4 > 0){
					revNum *= 10;
					currentDig = temp4%10;
					revNum+= currentDig;
					temp4/=10;
				}
				//this loop goes as follow: we are getting each digit from temp which is actually our number
				//every digit is appended to our reversed number, and then the reversed number is being multiplied
				// by 10, "making room" for the next digit to come. as it goes, the number is being reversed.

				for (int i = 2; i<(revNum/2 + 1);i++){
					//same loop again to check if the reversed is a prime number
					if (revNum%i == 0){
					printf("The circle remains incomplete.\n");
					isPrime = 0;
					break;}
				}

				if (isPrime){
					printf("This number completes the circle of joy!\n");
				}
				
			};
		break;	}

		case 5: {
			int n;
			printf("Enter a number:\n");
			scanf("%d",&n);
			while (n<=0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d",&n);
			}
			//Initial detail: between 1 to 9, only 1 and 7 are happy numbers. our guidance would be to 
			//deconstruct the number until we get a number lower than 10, then we will be able to indicate easily
			//if our number is happy or otherwise. 

			printf("Between 1 and %d only these numbers bring happiness: 1 ", n); //as we know we can state 1 as a happy number

			for (int i = 2; i<=n; i++){
				int isHappy= 1; //Indicator for our following summing loop 
				int temp5 = i; 
				int sum = 0;
				while (isHappy){
					sum = 0; //resetting the sum if we got here again from previous iteration
					while (temp5!=0){
						//summming the squares of digits to indicate sum 
						int currentDig = temp5%10;
						sum += (currentDig*currentDig);
						temp5 /= 10;
					}
					//now we will check if we got under 10
					if (sum<10){
						if (sum == 7 || sum == 1){
							printf("%d ",i);//printing our original number as if it got eventually to be 1 or 7,
							//it means it is a happy number
							isHappy = 0;
						}
						else {
							isHappy = 0; //exiting the loop without printing
						}
					}
					else {
						temp5 = sum; //if we got here, it means our sum was above 10 and the loop needs to run again.
					}
				}
			}
			printf("\n");
			break;
		}

		case 6: {
			int smileNum, cheerNum, maxNum;
			printf("Enter a smile and a cheer number\n:");
			int isValid = 2;
			isValid = scanf("smile: %d, cheer: %d", &smileNum, &cheerNum);
			while (isValid != 2)
			{
				printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				scanf("%*[^\n]");



				//cleaning buffer using negated scanset
			}
			
		}

		case 7: {
			printf("Thank you for the journey through Numeria!\n");
			gameOn = 0;
		}

		default:
			break;
		}
		}

	

	
	
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
