#pragma once
#include <functional>
#include <vector>

namespace Common {
	template<typename T>
	class Delegate {
	public:
		void Add(std::function<void(T)> func) {
			mDelegates.push_back(func);
		}

		void Remove(std::function<void(T)> func) {
			mDelegates.erase(std::remove(mDelegates.begin(), mDelegates.end(), func), mDelegates.end());
		}

		void Invoke(T arg) {
			for (auto& delegate : mDelegates) {
				delegate(arg);
			}
		}

		void Clear() {
			mDelegates.clear();
		}

	private:
		std::vector<std::function<void(T)>> mDelegates;
	};
}
