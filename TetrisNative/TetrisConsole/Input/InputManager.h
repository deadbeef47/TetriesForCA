#pragma once

#include <Common/Delegate.h>

enum class EInputType {
	None,
	Up,
	Down,
	Left,
	Right,
	Quit,
};

class InputManager {

public:

	InputManager();

	void UpdateInput();

	void NoticeInput();

	void RegisterInputEvent(std::function<void(EInputType)> event);

	EInputType GetLatestInput() const { return mLatestInput; }

private:
	EInputType ConvertInputValueToInputType(char inputValue) const;

private:
	Common::Delegate<EInputType> mOnInputDelegate;
	EInputType mLatestInput;

	char mInputValue;

};
