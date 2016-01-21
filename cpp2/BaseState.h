#pragma once
#include <unordered_map>
#include <memory>
#include "ICommand.h"

class BaseState
{
public:
	BaseState();
	~BaseState();

	virtual void Enter() = 0;
	virtual void Execute() = 0;
	virtual void Exit() = 0;

protected:
	std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;
};

