#include "mbed.h"
/* This program determines the time it takes to perform floating point
    and integer operations.
    To determine the time it takes, a Timer is used to measure the time
    it takes to complete a large amount of iterations. The time for a single
    operation can then be determined.

    To increase accuracy of the results, an empty for loop is timed to determine
    the loop overhead and the overhead is subtracted from the time it takes to
    complete the operation loop.

    */
#define ITERATIONS  1000000                         // Number of calculations.
#define CLOCK       (SystemCoreClock/1000000.0f)    // Clock freqency in MHz
Timer timer;                        // Timer..

Serial pc(USBTX, USBRX);
float number_of_cycles, single_operation_time;
volatile float a, b,c;            // Float operands and result. Must be volatile!
//volatile int a, b,c;              // Int operands and result. Must be volatile!

int main() {

    unsigned int i, for_time, total_time, operation_time;
    a=2.3;
    b=5.33;

    pc.printf("Operations in progress.. May take some time.\n\n");
    timer.reset();      // Reset timer
    timer.start();      // Start timer
    /* Determine loop overhead */
    for (i=0; i<ITERATIONS; i++);
    for_time=timer.read_us();
    timer.stop();

    /* Determine the total loop time */
    timer.reset();
    timer.start();

    /* The operation takes place in the body of
    this for loop. */

    for (i=0; i<ITERATIONS; i++) {
        c=a+b;
        // c=sin(a);
        // c=sqrt(a);
        // c = log(b);
        // c = exp(a);
    }
    total_time=timer.read_us();

    operation_time = total_time-for_time;   // Calculate the time it took for the number of operations

    single_operation_time=float(operation_time)/float(ITERATIONS);
    number_of_cycles = single_operation_time*CLOCK;

    pc.printf("for overhead: \t\t%dus \n", for_time);
    pc.printf("total time: \t\t%dus \n\n", total_time);
    pc.printf("%d calculations took:\t%dus \n", ITERATIONS, operation_time);
    pc.printf("single operation took: \t\t%fus\n", single_operation_time);
    pc.printf("single operation took: \t\t%.3f cycles\n", number_of_cycles);
}
