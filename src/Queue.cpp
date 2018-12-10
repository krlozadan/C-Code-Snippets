#include <iostream>
#include <vector>

// Queue class
template <class T>
class Queue
{
private:
    std::vector<T> queue;
public:
    void enqueue(T item)
    {
        queue.insert(queue.begin(), item);
    }
    
    T dequeue()
    {
        T dequeuedItem = queue[queue.size() - 1];
        queue.pop_back();
        return dequeuedItem;
    }
    
    T peek()
    {
        if (queue.size() > 0)
        {
            T dequeuedItem = queue[queue.size() - 1];
            return dequeuedItem;
        }
        else
        {
            return nullptr;
        }
    }
    
    int length()
    {
        return (int) queue.size();
    }
    
    bool isEmpty()
    {
        return queue.size() == 0;
    }
};

// Priority Queue
template <class T>
class PriorityQueue
{
private:
    Queue<T> lowPriorityQueue;
    Queue<T> highPriorityQueue;
public:
    void enqueue(T item, bool isHighPriority = false)
    {
        isHighPriority ? highPriorityQueue.enqueue(item) : lowPriorityQueue.enqueue(item);
    }
    
    T dequeue()
    {
        if (!highPriorityQueue.isEmpty())
            return highPriorityQueue.dequeue();
        else
            return lowPriorityQueue.dequeue();
    }
    
    T peek()
    {
        if (!highPriorityQueue.isEmpty())
            return highPriorityQueue.peek();
        else
            return lowPriorityQueue.peek();
    }
    
    int length()
    {
        return highPriorityQueue.length() + lowPriorityQueue.length();
    }
    
    bool isEmpty()
    {
        return highPriorityQueue.isEmpty() && lowPriorityQueue.isEmpty();
    }
};
