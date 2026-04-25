#pragma once
#include "Input/InputManager.h"
#include "System/ObjectBase.h"
#include <string>
#include <memory>

class GameApplication
{
public:
	GameApplication(int screenWidth, int screenHeight);

	void Run();

private:

	void Wait();

protected:

	virtual void Initialize() {}
	virtual void Update() {}
	virtual void Release() {}

protected:
	void AddObject(const std::shared_ptr<ObjectBase>& object);
	void RequestRefresh();
	void ClearScreenBuffer();

protected:
	InputManager mInputManager;
	int mScreenWidth, mScreenHeight;
	std::vector<std::vector<std::string>> mScreenBuffer;
	std::vector<std::shared_ptr<ObjectBase>> mObjects;
	bool mIsQuit = false;
};