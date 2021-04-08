#pragma once

class ListBasedQueue {
    private:
        
    public:
        void AddBeg(int value);
        void AddEnd(int value);
        void Push(int value);
        void Pop();
        void DelBeg();
        void DelEnd();
        void GarbageSoft();
        void GarbageHard();
        void PrintForward() const;
        void PrintBackward() const;
        void PrintQueue() const;
        void Size() const;
        void Count() const;
};