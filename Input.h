#pragma once
#include "Constants.h"
#include "ListBasedQueue.h"

class Input {
    private:
        char userInput[MAX_USER_INPUT];
        int optionalValue;
    public:
        Input() : userInput(""), optionalValue(0) { }
        bool ScanUserInput();
        void PerformProperOperationOnListBasedQueue(ListBasedQueue*);
    private: 
        bool InputIsTheSameAs(const char* string);   
        bool ScanUserValue();
};