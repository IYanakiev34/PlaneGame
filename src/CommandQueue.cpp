#include "GameHeaders/CommandQueue.hpp"

// push an element on the queue
void CommandQueue::push(const Command& command)
{
	mQueue.push(command);
}

// pop the element from the queue
Command CommandQueue::pop()
{

	Command command = mQueue.front();
	mQueue.pop();
	return command;
}

// check if queue is empty
bool CommandQueue::isEmpty() const
{
	return mQueue.empty();
}