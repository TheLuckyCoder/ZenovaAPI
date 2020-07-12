#include "Zenova/API/ZenovaItems.h"

#include "Zenova.h"

namespace Zenova {	
	static void (*_registerVanillaItems)(bool);
	inline void registerVanillaItems(const bool b1) {
		_registerVanillaItems(b1);

		Zenova_Info("Initializing Items");
		ZenovaItems::handleRegisterItemsCallbacks();
		Zenova_Info("Initializing Items End");
	}

	static void (*_initVanillaCreativeCategories)();
	inline void initVanillaCreativeCategories() {
		_initVanillaCreativeCategories();

		Zenova_Info("Initializing Creative Categories");
		ZenovaItems::handleInitCreativeCategoriesCallbacks();
		Zenova_Info("Initializing Creative Categories End");
	}

	static void (*_initVanillaCreativeItemsCallback)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	inline void initVanillaCreativeItemsCallback(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, const bool b1) {
		_initVanillaCreativeItemsCallback(actorInfoRegistry, blockDefinitionGroup, b1);

		Zenova_Info("Initializing Creative Items");
		ZenovaItems::handleInitCreativeItemsCallbacks();
		Zenova_Info("Initializing Creative Items End");
	}

	static void (*_initVanillaClientData)();
	inline void initVanillaClientData() {
		_initVanillaClientData();

		Zenova_Info("Initializing Client Data");
		ZenovaItems::handleInitClientDataCallbacks();
		Zenova_Info("Initializing Client Data End");
	}
	
	inline void createItemHooks() {
		Zenova::Hook::Create(ZenovaItems::getRegisterItemsFunction(), &registerVanillaItems, &_registerVanillaItems);
		Zenova::Hook::Create(ZenovaItems::getInitCreativeCategoriesFunction(), &initVanillaCreativeCategories, &_initVanillaCreativeCategories);
		Zenova::Hook::Create(ZenovaItems::getInitCreativeItemsFunction(), &initVanillaCreativeItemsCallback, &_initVanillaCreativeItemsCallback);
		Zenova::Hook::Create(ZenovaItems::getInitClientDataFunction(), &initVanillaClientData, &_initVanillaClientData);
	}
}
