#pragma once
#include "GameApplication.h"

class TetriesApplication : public GameApplication
{
public:
	TetriesApplication();

private:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Release()override;

private:
	void OnInputEvent(EInputType inputType);
};

