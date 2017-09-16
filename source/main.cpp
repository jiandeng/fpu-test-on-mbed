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
#define ITERATIONS  100000                         // Number of calculations.
#define CLOCK       (SystemCoreClock/1000000.0f)    // Clock freqency in MHz
Timer timer;                        // Timer..

Serial pc(USBTX, USBRX);
float operation_cycles, operation_time;
volatile float a, b,c;            // Float operands and result. Must be volatile!
//volatile int a, b,c;              // Int operands and result. Must be volatile!

int test_for(int iterations) {
    int total_time;
    volatile int i;

    pc.printf("Testing for()...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    total_time=timer.read_us();
    timer.stop();

    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);
    return total_time;
}

int test_plus(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing (+)...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=a+b;
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_sub(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing (-)...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=a-b;
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_mul(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing (*)...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=a*b;
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_div(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing (/)...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=a/b;
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_sin(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing sin()...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=sin(a);
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_sqrt(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing sqrt()...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=sqrt(a);
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_exp(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing exp()...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=exp(a);
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int test_log(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    pc.printf("Testing log()...");
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    a = 1.7;
    b = 2.2;
    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        c=log(a);
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

float data[100];
int test_std(int iterations) {
    int for_time, total_time;
    volatile float a, b, c;
    volatile int i;

    for(int n = 0; n < sizeof(data) / sizeof(data[0]); n++) {
        data[n] = 10 + n * 0.01;
    }
    pc.printf("Testing std(%d)...", sizeof(data)/sizeof(data[0]));
    /* Determine loop overhead */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
    }
    for_time=timer.read_us();
    timer.stop();

    /* Determine the total loop time */
    timer.reset();
    timer.start();
    for (i=0; i<iterations; i++) {
        a = 0;
        b = 0;
        for(int n = 0; n < sizeof(data) / sizeof(data[0]); n++) {
            a += data[n];
        }
        a /= sizeof(data) / sizeof(data[0]);
        for(int n = 0; n < sizeof(data) / sizeof(data[0]); n++) {
            c = data[n] - a;
            b += c * c;
        }
        b /= sizeof(data) / sizeof(data[0]);
        b = sqrt(b);
    }
    total_time=timer.read_us();
    timer.stop();

    total_time -= for_time;
    printf("\tTotalTime=%dus, AverageTime=%.3fus (%.3fcycles)\n", total_time, total_time/float(iterations), total_time/float(iterations)*CLOCK);

    return total_time;
}

int main() {
    test_plus(ITERATIONS*10);
    test_sub(ITERATIONS*10);
    test_mul(ITERATIONS*10);
    test_div(ITERATIONS*10);
    test_sqrt(ITERATIONS);
    test_sin(ITERATIONS);
    test_exp(ITERATIONS);
    test_log(ITERATIONS);
    test_std(ITERATIONS/10);
}
