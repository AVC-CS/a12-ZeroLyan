#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int globalInt1 = 100;
int globalInt2 = 150;

// TODO: Declare 2 uninitialized global variables (BSS segment)
int globalInt3, globalInt4;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    cout << "Value of parentAddr: " << parentAddr << endl;
    
    // TODO: Print &parentAddr (parameter's own address - child frame)
    //cout << "Address of parentAddr: " << &parentAddr << endl;

    // TODO: Print &childVar (local var address - child frame)
    cout << "Address of childVar: " << &childVar << endl;

    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)
    cout << "Stack grows: " << (parentAddr > &childVar ? "DOWN" : "UP") << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int localVar = 50;
    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    char* heapVar1 = (char*)malloc(1024);
    char* heapVar2 = (char*)malloc(2048);

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;
    
    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&localVar);

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack

    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "Address of main(): " << (void*)main << endl;
    cout << "Address of checkStack(): " << (void*)checkStack << endl;
    cout << endl;
    

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "Value of globalInt1: " << globalInt1 << endl;
    cout << "Address of globalInt1: " << &globalInt1 << endl;
    cout << "Value of globalInt2: " << globalInt2 << endl;
    cout << "Address of globalInt2: " << &globalInt2 << endl;
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "Value of globalInt3: " << globalInt3 << endl;
    cout << "Address of globalInt3: " << &globalInt3 << endl;
    cout << "Value of globalInt4: " << globalInt4 << endl;
    cout << "Address of globalInt4: " << &globalInt4 << endl;
    cout << endl;

    

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << "Address of heapVar1: " << (void*)heapVar1 << endl;
    cout << "Address of heapVar2: " << (void*)heapVar2 << endl;
    cout << "Heap grows: " << (heapVar1 > heapVar2 ? "DOWN" : "UP") << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    if ((void*)&localVar > (void*)heapVar1) {
        cout << "The STACK is at a HIGHER address than the HEAP." << endl;
    } 
    else {
        cout << "The HEAP is at a HIGHER address than the STACK." << endl;
    }

    // Compare Heap vs Static/Global
    if ((void*)heapVar1 > (void*)&globalInt1) {
        cout << "The HEAP is at a HIGHER address than the STATIC segment." << endl;
    } 
    else {
        cout << "The STATIC segment is at a HIGHER address than the HEAP." << endl;
    }

    // TODO: Free all heap allocations
    delete(heapVar1);
    delete(heapVar2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 *      - I observed that the checkStack() function had the lowest address.
 * - Which has the highest?
 *      - I observed that the highest address belonged to the local variable 
 *        I passed into the check stack function
 * - Does stack grow down? How did you verify this?
 *      - Yes the stack grows down. Once the output was created it showed that the 
 *        addresses indeed went to smaller addresses.
 * - Does heap grow up? How did you verify this?
 *      - Yes the heap grows up. Once the output was created it showed that the 
 *        addresses were being allocated to ones that were larger.
 * - What is the gap between HEAP and STACK?
 *      - The gap between the two is immense, on the scale of being terabytes apart. 
 */
