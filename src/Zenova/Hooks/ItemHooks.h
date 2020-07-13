#include "Zenova/API/ItemsDelegate.h"

#include "Zenova.h"

namespace Zenova {	
	static void (*_registerVanillaItems)(bool);
	inline void registerVanillaItems(const bool b1) {
		_registerVanillaItems(b1);

		Zenova_Info("Initializing Items");
		ItemsDelegate::handleRegisterItems();
		Zenova_Info("Initializing Items End");
	}

	static void (*_initVanillaCreativeCategories)();
	inline void initVanillaCreativeCategories() {
		_initVanillaCreativeCategories();

		Zenova_Info("Initializing Creative Categories");
		ItemsDelegate::handleInitCreativeCategories();
		Zenova_Info("Initializing Creative Categories End");
	}

	static void (*_initVanillaCreativeItems)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	inline void initVanillaCreativeItems(class ActorInfoRegistry* p1, class BlockDefinitionGroup* p2, const bool p3) {
		_initVanillaCreativeItems(p1, p2, p3);

		Zenova_Info("Initializing Creative Items");
		ItemsDelegate::handleInitCreativeItems();
		Zenova_Info("Initializing Creative Items End");
	}

	static void (*_initVanillaClientData)();
	inline void initVanillaClientData() {
		_initVanillaClientData();

		Zenova_Info("Initializing Client Data");
		ItemsDelegate::handleInitClientData();
		Zenova_Info("Initializing Client Data End");
	}
	
	inline void createItemHooks() {
		Zenova::Hook::Create(ItemsDelegate::getRegisterItemsFunction(), &registerVanillaItems, &_registerVanillaItems);
		Zenova::Hook::Create(ItemsDelegate::getInitCreativeCategoriesFunction(), &initVanillaCreativeCategories, &_initVanillaCreativeCategories);
		Zenova::Hook::Create(ItemsDelegate::getInitCreativeItemsFunction(), &initVanillaCreativeItems, &_initVanillaCreativeItems);
		Zenova::Hook::Create(ItemsDelegate::getInitClientDataFunction(), &initVanillaClientData, &_initVanillaClientData);
	}
}
