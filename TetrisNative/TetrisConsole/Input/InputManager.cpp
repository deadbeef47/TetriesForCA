#include "InputManager.h"
#include <conio.h>

InputManager::InputManager() :
	mOnInputDelegate()
	, mInputValue('\0')
{
}

void InputManager::UpdateInput() {
	if (_kbhit()) {
		mInputValue = _getch();
	}
}

void InputManager::NoticeInput() {
	mLatestInput = ConvertInputValueToInputType(mInputValue);
	if (mLatestInput != EInputType::None)
		mOnInputDelegate.Invoke(mLatestInput);
	mInputValue = '\0';
}

void InputManager::RegisterInputEvent(std::function<void(EInputType)> event) {
	mOnInputDelegate.Add(event);
}

EInputType InputManager::ConvertInputValueToInputType(char inputValue) const {

	EInputType inputType = EInputType::None;
	switch (inputValue) {
	case 72:inputType = EInputType::Up; break;		// Å™
	case 80: inputType = EInputType::Down; break;	// Å´
	case 75: inputType = EInputType::Left; break;	// Å©
	case 77: inputType = EInputType::Right;  break; // Å®
	case 27: inputType = EInputType::Quit; break;	// Esc
	}

	return inputType;
}
