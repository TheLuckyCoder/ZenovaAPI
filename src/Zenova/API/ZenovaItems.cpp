#include "ZenovaItems.h"

#include "Zenova/Minecraft.h"
#include "Zenova/Minecraft/Header/Item/TVanillaItems.h"
#include "Zenova/Minecraft/Header/Item/Item_1_16_1.h"
#include "Zenova/Minecraft/Header/Item/Item_1_14.h"

namespace Zenova {
	std::vector<ZenovaItems::Callback> ZenovaItems::registerItemsCallbacks;
	std::vector<ZenovaItems::Callback> ZenovaItems::initCreativeCategoriesCallbacks;
	std::vector<ZenovaItems::Callback> ZenovaItems::initCreativeItemsCallbacks;
	std::vector<ZenovaItems::Callback> ZenovaItems::initClientDataCallbacks;

	void ZenovaItems::addRegisterItemsCallback(const Callback& callback) {
		registerItemsCallbacks.emplace_back(callback);
	}

	void ZenovaItems::addInitCreativeCategoriesCallback(const Callback& callback) {
		initCreativeCategoriesCallbacks.emplace_back(callback);
	}

	void ZenovaItems::addInitCreativeItemsCallback(const Callback& callback) {
		initCreativeItemsCallbacks.emplace_back(callback);
	}

	void ZenovaItems::addInitClientDataCallback(const Callback& callback) {
		initClientDataCallbacks.emplace_back(callback);
	}

	void* ZenovaItems::getRegisterItemsFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::registerItems;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::registerItems;
		return nullptr;
	}

	void* ZenovaItems::getInitCreativeCategoriesFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::initCreativeCategories;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::initCreativeCategories;
		return nullptr;
	}

	void* ZenovaItems::getInitCreativeItemsFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::initCreativeItemsCallback;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::initCreativeItemsCallback;
		return nullptr;
	}

	void* ZenovaItems::getInitClientDataFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::initClientData;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::initClientData;
		return nullptr;
	}
	
	void ZenovaItems::handleRegisterItemsCallbacks() {
		for (auto&& callback : registerItemsCallbacks) { callback(); }
	}
	
	void ZenovaItems::handleInitCreativeCategoriesCallbacks() {
		for (auto&& callback : initCreativeCategoriesCallbacks) { callback(); }
	}
	
	void ZenovaItems::handleInitCreativeItemsCallbacks() {
		for (auto&& callback : initCreativeItemsCallbacks) { callback(); }
	}
	
	void ZenovaItems::handleInitClientDataCallbacks() {
		for (auto&& callback : initClientDataCallbacks) { callback(); }
	}
}
