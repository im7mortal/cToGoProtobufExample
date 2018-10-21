#include <iostream>
#include <library.h>

int main()
{
    // Allocate 1mb just in case
    char *buffer = (char*)malloc(1000000);
    // Get message
    unsigned long n = getData(buffer);
    // Send message
    sendData(buffer);
    // Free array
    free(buffer);
    return 0;
}