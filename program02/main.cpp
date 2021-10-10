// Ptr should be used in variable name
// pointers should be initialized to nullptr
// & address operator obtains the memory address of its operand
/*
int y{5};
int* yPtr{nullptr};
yPtr = &y;

*/

#include "main.h"


// Make 5 functions that will be used in main()
void calculateDiscount(double listPrice, double discountPercentage, double* discountedPrice) {
	/*
	Function One - void calculateDiscount(). Obtain the following data from your user in 
	main(): listPrice and discountPercentage. Call calculateDiscount() to calculate the 
	discounted price. Pass the discounted price back to main() via a reference parameter.
	*/

	*discountedPrice = listPrice - (listPrice * (discountPercentage / 100));

}

void determineLarger(int intOne, int intTwo, int* largerValue) {
	/*
	Function Two - void determineLarger(). Obtain the following data from your user 
	in main(): intOne and intTwo. Call determineLarger() to determine the larger of 
	the two numbers. Pass the larger of the two back to main() via a pointer parameter.
	*/
	*largerValue = (intOne > intTwo) ? intOne : intTwo;
}

bool compareArrays(const string array1[], const string array2[]) {
	/*
	Function Three - bool compareArrays(). Obtain the following data from your user in
	main(): Populate two built-in arrays of strings. Call compareArrays() to determine
	if the arrays contain the exact same data. Send the bool result back to main() via
	a return value.
	*/
	int count = 0;
	bool equal = true;
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (array1[i] != array2[i]) {
			equal = false;
		}
	}
	return equal;
}


void sortArrays(string array1[], array<string, ARRAY_SIZE> &array2) {
	/*
	Function Four - void sortArrays(). Call sortArrays() with a built-in array of 
	strings and a Class Template array object of strings. Sort both.
	*/

	bool swapped = true;

	for (int maxElement = ARRAY_SIZE - 1; maxElement > 0 && swapped; maxElement--) {
		swapped = false;
		for (int i = 0; i < maxElement; i++) {
			if (array1[i].compare(array1[i + 1]) > 0) {
				// swap(&array1[i], &array1[i + 1]);
				string* ptr1 = &array1[i];
				string* ptr2 = &array1[i + 1];
				string temp = *ptr1;
				*ptr1 = *ptr2;
				*ptr2 = temp;
				swapped = true;
			}
		}
	}

	sort(array2.begin(), array2.end());
}

void demoPtrTechniques(int* ptr1, const int* ptr2, int* const ptr3, const int* const ptr4) {

    *ptr1 = 15;
    int newx{20};
    ptr1 = &newx;
    cout << "ptr1 " << *ptr1 << endl;

    int newy{150};
    ptr2 = &newy;

        cout << "ptr2 " << *ptr2 << endl;

    *ptr3 = 100;
}


int main() {
	double listPrice = 19.99;
	double discountPercentage = 10;
	double* discountedPrice = nullptr;
	discountedPrice = &listPrice;

	cout << "Function One" << endl;
	cout << "List price: " << listPrice << "\ndiscount percentage: " << discountPercentage << "%" << endl;
	calculateDiscount(listPrice, discountPercentage, discountedPrice);
	cout << "Discounted price: " << * discountedPrice << endl;

	cout << endl;


	cout << "Function Two" << endl;
	int intOne = 100;
	int intTwo = 500;
	int largerValue = -1;
	int* largerValuePtr = &largerValue;
	// largerValue = &intOne;

	determineLarger(intOne, intTwo, largerValuePtr);
	cout << "Compare values and determine the larger one: " << intOne << ", " << intTwo << endl;
	cout << *largerValuePtr << " is larger" << endl;

	cout << endl;

	cout << "Function Three" << endl;
	string arrayOne[ARRAY_SIZE]{ "aaaa", "bbbb", "cccc", "dddd", "eeee" };
	string arrayTwo[ARRAY_SIZE]{ "aaaa", "bbbb", "cccc", "dddd", "eeee" };
	cout << "Determine if array [";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (i == ARRAY_SIZE - 1) {
			cout << arrayOne[i];
		}
		else {
			cout << arrayOne[i] << ", ";
		}
	}
	cout << "] equals [";


	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (i == ARRAY_SIZE - 1) {
			cout << arrayTwo[i];
		}
		else {
			cout << arrayTwo[i] << ", ";
		}
	}
	cout << "]" << endl;

	if (compareArrays(arrayOne, arrayTwo)) {
		cout << "Arrays are equal" << endl;
	}
	else {
		cout << "Arrays are not equal" << endl;
	}

	cout << endl;


	cout << "Function Four" << endl;
	string arrayThree[ARRAY_SIZE]{ "ee", "ddy", "aaaa", "ccck", "baaa" };
	array<string, ARRAY_SIZE> arrayFour{ "eeee", "dddd", "aaaa", "cccc", "bbbb" };
	array<string, ARRAY_SIZE> *arrayFourPtr = &arrayFour;

	cout << "Built in array Before: [";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (i == ARRAY_SIZE - 1) {
			cout << arrayThree[i] << "]" << endl;
		}
		else {
			cout << arrayThree[i] << ", ";
		}
	}

	cout << "Array template Before: [";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (i == ARRAY_SIZE - 1) {
			cout << arrayFour[i] << "]" << endl;
		}
		else {
			cout << arrayFour[i] << ", ";
		}
	}

	cout << "Sorting arrays" << endl;
	sortArrays(arrayThree, *arrayFourPtr);


	cout << "Built in array After: [";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (i == ARRAY_SIZE - 1) {
			cout << arrayThree[i] << "]" << endl;
		}
		else {
			cout << arrayThree[i] << ", ";
		}

	}

	cout << "Array template After: [";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (i == ARRAY_SIZE - 1) {
			cout << arrayFour[i] << "]" << endl;
		}
		else {
			cout << arrayFour[i] << ", ";
		}
	}

	cout << endl;


	cout << "Function Five" << endl;
	// nonconstant pointer to nonconstant data
	int nonconst1 = 0;
	int* nonconst1Ptr = &nonconst1;
    cout << "nonconstant pointer to nonconstant data: " << *nonconst1Ptr << endl; 

	// nonconstant pointer to constant data
	const int nonconst2 {1};
    const int* nonconst2Ptr = &nonconst2;
    cout << "nonconstant pointer to constant data: " << *nonconst2Ptr << endl;

	// constant pointer to nonconstant data
	int x{11};
	int* const constptr{ &x };
    cout << "constant pointer to nonconstant data: " << *constptr << endl;

	// constant pointer to constant data
	int y{5};
	const int* const constptr2{ &y };
    cout << "constant pointer to constant data: " << *constptr2 << endl;

    cout << endl;
    cout << "modifying pointers" << endl;
    cout << endl;

	demoPtrTechniques(nonconst1Ptr, nonconst2Ptr, constptr, constptr2);

    cout << "nonconstant pointer to nonconstant data: " << *nonconst1Ptr << endl; 

    cout << "nonconstant pointer to constant data: " << *nonconst2Ptr << endl;

    cout << "constant pointer to nonconstant data: " << *constptr << endl;

    cout << "constant pointer to constant data: " << *constptr2 << endl;

	return 0;
}

/*


void demoPtrTechniqures(int* ptr1, const int* ptr2, const int* ptr3, const int* ptr4) {
	
	Function Five - void demoPtrTechniques(). Demonstrate the four ways to pass a
	pointer to a function.
	pass-by-value
	pass-by-reference with reference arguments, passing in & to the function and function parameter *
	pass-by-reference with pointer arguments
	arrayName is implicitly convertible to &arrayName[0], when passing the array the & is not needed, just pass the name
	int sumElements(const int values[])
	int sumElements(const int* values)
	
	a nonconstant pointer to nonconstant data
	a nonconstant pointer to constant data
	a constant pointer to nonconstant data
	a constant pointer to constant data
	

}

*/