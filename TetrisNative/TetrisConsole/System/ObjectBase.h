#pragma once
#include <vector>
#include <string>
#include "Vector2.h"

class ObjectBase {
public:
	static const std::string EmptyCellStr;
public:
	ObjectBase();
	ObjectBase(const std::vector<std::vector<std::string>>& shape);

	const std::vector<std::vector<std::string>>& GetShape() const { return mShape; }

public:
	Vector2 Position;

private:
	std::vector<std::vector<std::string>> mShape;
};