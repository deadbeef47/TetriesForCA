#include "GameApplication.h"
#include <chrono>
#include <iostream>

GameApplication::GameApplication(int screenWidth, int screenHeight) :
	mScreenWidth(screenWidth), mScreenHeight(screenHeight)
{
	ClearScreenBuffer();
}

void GameApplication::Run() {

	Initialize();

	while (!mIsQuit) {
		Update();

		Wait();
	}

	Release();
}

void GameApplication::Wait() {
	const auto frame = 1.0 / 60.0; // 60 FPS
	auto start = clock();
	double elapsedSec = 0;
	while (elapsedSec < frame && !mIsQuit) {
		elapsedSec = (double)(clock() - start) / CLOCKS_PER_SEC;
		mInputManager.UpdateInput();

		if (mIsQuit == false && mInputManager.GetLatestInput() == EInputType::Quit)
			mIsQuit = true;
	}
	mInputManager.NoticeInput();
}


void GameApplication::AddObject(const std::shared_ptr<ObjectBase>& object) {
	mObjects.push_back(object);
}

void GameApplication::RequestRefresh() {

	ClearScreenBuffer();

	std::string output = "";
	for (auto& object : mObjects) {
		const auto& position = object->Position;
		const auto& shape = object->GetShape();
		for (int i = 0; i < shape.size(); i++) {
			for (int j = 0; j < shape[i].size(); j++) {
				if (shape[i][j] == ObjectBase::EmptyCellStr)
					continue;
				mScreenBuffer[position.Y + i][position.X + j] = shape[i][j];
			}
		}
	}

	for (auto cc : mScreenBuffer) {
		for (auto rc : cc)
			output += rc;
		output += "\n";
	}

	std::cout << "\033[H" << output << std::endl;
}

void GameApplication::ClearScreenBuffer() {
	mScreenBuffer.clear();
	std::vector<std::string> row(mScreenWidth, ObjectBase::EmptyCellStr);
	for (int i = 0; i < mScreenHeight; i++)
		mScreenBuffer.push_back(row);
}
