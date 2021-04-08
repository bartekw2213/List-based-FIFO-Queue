#include <cstring>
#include <iostream>
#include "Input.h"

bool Input::ScanUserInput() {
    return (bool)(std::cin >> userInput);
}

bool Input::ScanUserValue() {
    return (bool)(std::cin >> optionalValue);
}

bool Input::InputIsTheSameAs(const char* string) {
    return strncmp(userInput, string, MAX_USER_INPUT) == 0;
}

void Input::PerformProperOperationOnListBasedQueue(ListBasedQueue* queue) {
    if(Input::InputIsTheSameAs("ADD_BEG")) {
        Input::ScanUserValue();
        queue->AddBeg(Input::optionalValue);
    } else if (Input::InputIsTheSameAs("ADD_END")) {
        Input::ScanUserValue();
        queue->AddEnd(Input::optionalValue);
    } else if (Input::InputIsTheSameAs("PUSH")) {
        Input::ScanUserValue();
        queue->Push(Input::optionalValue);
    } else if (Input::InputIsTheSameAs("POP"))
        queue->Pop();
    else if (Input::InputIsTheSameAs("DEL_BEG"))
        queue->DelBeg();
    else if (Input::InputIsTheSameAs("DEL_END"))
        queue->DelEnd();
    else if (Input::InputIsTheSameAs("GARBAGE_HARD"))
        queue->GarbageHard();
    else if (Input::InputIsTheSameAs("GARBAGE_SOFT"))
        queue->GarbageSoft();
    else if (Input::InputIsTheSameAs("PRINT_FORWARD"))
        queue->PrintForward();
    else if (Input::InputIsTheSameAs("PRINT_BACKWARD"))
        queue->PrintBackward();
    else if (Input::InputIsTheSameAs("PRINT_QUEUE"))
        queue->PrintQueue();
    else if (Input::InputIsTheSameAs("SIZE"))
        queue->Size();
    else if (Input::InputIsTheSameAs("COUNT"))
        queue->Count();
}