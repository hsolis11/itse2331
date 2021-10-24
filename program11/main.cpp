#include "main.h"


int main(){

    switch(multiple_choice()) {

        // TODO: Division by zero
        // employ the appropriate try-throw-catch paradigm
        case 1:
            divide_zero();
            break;


        // TODO: Rethrowing exceptions
        // employ the appropriate try-throw-catch paradigm
        case 2:
            try{
                cout << "\nmain invokes function throwException\n";
                throwException();

            } catch(const exception&){
                cout << "\n\nException handled in main\n";
            }
            break;


        // TODO: Stack unwinding
        // employ the appropriate try-throw-catch paradigm
        case 3:
            try{
                cout << "function1 is called inside main" << endl;
                function1();
            } catch (const runtime_error& error){
                cout << "Exception occured: " << error.what() << endl;
                cout << "Exception handled in main" << endl;
            }
            break;


        // TODO: Using the 'new' operator to throw a bad_alloc exception type
        // employ the appropriate try-throw-catch paradigm
        case 4:
            double *ptr1[50];

            try{
                for(size_t i{0}; i < 50; ++i){
                    ptr1[i] = new double[50'000'000]{};
                    cout << "ptr1[" << i << "] points to 50,000,000 new doubles\n";
                }
            } catch (bad_alloc& memoryAllocationException) {
                cerr << "Exception occurred: " << memoryAllocationException.what() << endl;
            }
            break;


        // TODO: Using the 'new' operator to demonstrate set_new_handler
        // employ the appropriate try-throw-catch paradigm
        case 5:
            double *ptr[50];

            set_new_handler(customNewHandler);

            for (size_t i{0}; i < 50; ++i){
                ptr[i] = new double[50'000'000]{};
                cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
            }
            break;


    }


    return 0;
}
