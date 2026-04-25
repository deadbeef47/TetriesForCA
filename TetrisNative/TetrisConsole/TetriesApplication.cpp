#include "TetriesApplication.h"
#include <iostream>


TetriesApplication::TetriesApplication() :
	GameApplication(12, 22) {
}

std::shared_ptr<ObjectBase> object;
void TetriesApplication::Initialize() {
	mInputManager.RegisterInputEvent([this](auto inpoutType) {OnInputEvent(inpoutType); });
	std::cout << "©ª¨«‚ÅˆÚ“®" << std::endl;
	object = std::make_shared<ObjectBase>(std::vector<std::vector<std::string>>{ {"[]", } });
	AddObject(object);
}

void TetriesApplication::Update() {

	static int counter = 0;
	static int cou = 0;
	if (cou >= 60) {
		//char c[] = { '|','/','-', '\\' };
		//char u = c[counter];
		//std::cout << "\033[H" << "--" << u << "--" << std::endl;
		//counter = (counter + 1) % 4;
		cou = 0;
		//std::cout << "\033[2J" << std::endl;
	}
	cou++;
}

void TetriesApplication::Release() {
}

void TetriesApplication::OnInputEvent(EInputType inputType) {
	switch (inputType) {
	case EInputType::Up: 
		object->Position.Y = std::max(0, object->Position.Y - 1);
		break;
	case EInputType::Down: 
		object->Position.Y = std::min(mScreenHeight - (int)object->GetShape().size(), object->Position.Y + 1);
		break;
	case EInputType::Left: 
		object->Position.X = std::max(0, object->Position.X - 1);
		break;
	case EInputType::Right: 
		object->Position.X = std::min(mScreenWidth - (int)object->GetShape()[0].size(), object->Position.X + 1);
		break;
	}
	RequestRefresh();
}
