#pragma once

#include <vector>
#include <string>

#include "../Util/SharedPtr.h"
#include "Zenova/Minecraft/Bedrock/IItem.h"

template <class Item, typename std::enable_if<std::is_base_of<Bedrock::IItem, Item>::value>::type* = nullptr>
class TItemRegistry {
public:
	template<typename T, typename... Args>
	static WeakPtr<T> registerItem(const std::string& name, const short id, Args&&... args) {
		return TItemRegistry<Item>::template registerItemShared<T>(name, id + 256, std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	static WeakPtr<T> registerItemShared(Args&&... args) {
		SharedPtr<T> itemReg = SharedPtr<T>::make(std::forward<Args>(args)...);
		TItemRegistry<Item>::registerItem(itemReg);
		return itemReg;
	}

	static void registerItem(SharedPtr<Item>);
	static void shutdown();

	static WeakPtr<Item> lookupByName(int&, int&, const std::string&);
	static WeakPtr<Item> lookupByName(int&, const std::string&);
	static WeakPtr<Item> lookupByName(const std::string& inString) {
		int itemAux;
		return lookupByName(itemAux, inString);
	}
	static WeakPtr<Item> getItem(short);
	static short getMaxItemID() {
		return *TItemRegistry::mMaxItemID;
	}

	static short* mMaxItemID;
	static std::vector<SharedPtr<Item>>* mItemRegistry;
};
