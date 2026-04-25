#include "ObjectBase.h"


const std::string ObjectBase::EmptyCellStr = "  ";

ObjectBase::ObjectBase() :mShape() {
}

ObjectBase::ObjectBase(const std::vector<std::vector<std::string>>& shape) :
	mShape(shape) {
}
