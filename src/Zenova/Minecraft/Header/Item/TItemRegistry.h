#pragma once

#include <vector>
#include <string>

#include "Zenova/Common.h"
#include "../../Util/SharedPtr.h"
#include "Item_1_14.h"

class EXPORT TItemRegistry {
public:
	template<typename T, typename... Args>
	static WeakPtr<T> registerItem(const std::string& name, const short id, Args&&... args) {
		return TItemRegistry::template registerItemShared<T>(name, id + 256, std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	static WeakPtr<T> registerItemShared(Args&&... args) {
		SharedPtr<T> itemReg = SharedPtr<T>::make(std::forward<Args>(args)...);
		TItemRegistry::registerItem(itemReg);
		return itemReg;
	}

	static void registerItem(SharedPtr<Item_1_14>);
	static void shutdown();

	static WeakPtr<Item_1_14> lookupByName(int&, int&, const std::string&);
	static WeakPtr<Item_1_14> lookupByName(int&, const std::string&);
	static WeakPtr<Item_1_14> lookupByName(const std::string& inString) {
		int itemAux;
		return lookupByName(itemAux, inString);
	}
	static WeakPtr<Item_1_14> getItem(short);
	static short getMaxItemID() {
		return *TItemRegistry::mMaxItemID;
	}

	static short* mMaxItemID;
	static std::vector<SharedPtr<Item_1_14>>* mItemRegistry;
};
