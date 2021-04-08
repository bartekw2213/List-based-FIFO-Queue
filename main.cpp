#include <iostream>
#include <cstring>
#include "Input.h"
#include "ListBasedQueue.h"


int main() {
    ListBasedQueue queue;
    Input userInput;
    
    while(userInput.ScanUserInput()) {
        userInput.PerformProperOperationOnListBasedQueue(&queue);
    }
    
}