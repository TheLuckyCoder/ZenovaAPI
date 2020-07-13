#include "ItemsDelegate.h"

#include "Zenova/Log.h"
#include "Zenova/Minecraft.h"
#include "Zenova/Minecraft/Header/Item/TVanillaItems.h"
#include "Zenova/Minecraft/Header/Item/TItemRegistry.h"
#include "Zenova/Minecraft/Header/Item/Item_1_16_1.h"
#include "Zenova/Minecraft/Header/Item/Item_1_14.h"

namespace Zenova {
	template <class T, typename std::enable_if<std::is_base_of<Bedrock::IItem, T>::value>::type* = nullptr>
	T& getItem(const ItemsDelegate::BedrockItemPtr& item) {
		return *reinterpret_cast<T*>(item.get());
	}
	
	void ItemsDelegate::addRegisterItemCallback(const Callback& callback) {
		registerItemCallbacks.push_back(callback);
	}

	void ItemsDelegate::addItemToCreative(const BedrockItemPtr& item) {
		creativeItems.emplace_back(item);
	}

	void ItemsDelegate::setItemTexture(ItemTexture itemTexture) {
		itemsTextures.push_back(std::move(itemTexture));
	}

	void* ItemsDelegate::getRegisterItemsFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::registerItems;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::registerItems;
		return nullptr;
	}

	void* ItemsDelegate::getInitCreativeCategoriesFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::initCreativeCategories;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::initCreativeCategories;
		return nullptr;
	}

	void* ItemsDelegate::getInitCreativeItemsFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::initCreativeItemsCallback;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::initCreativeItemsCallback;
		return nullptr;
	}

	void* ItemsDelegate::getInitClientDataFunction() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return &TVanillaItems<Item_1_16_1>::initClientData;
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return &TVanillaItems<Item_1_14>::initClientData;
		return nullptr;
	}
	
	void ItemsDelegate::handleRegisterItems() {
		for (auto&& callback : registerItemCallbacks) { callback(); }
	}
	
	void ItemsDelegate::handleInitCreativeCategories() {
		//for (auto&& callback : initCreativeCategoriesCallbacks) { callback(); }
	}
	
	void ItemsDelegate::handleInitCreativeItems() {
		if (Minecraft::version() == Minecraft::v1_16_1_2) {
			for (auto&& item : creativeItems)
				Item_1_16_1::addCreativeItem(&getItem<Item_1_16_1>(item), 0);
		}
		else if (Minecraft::version() == Minecraft::v1_14_60_5) {
			for (auto&& item : creativeItems)
				Item_1_14::addCreativeItem(&getItem<Item_1_14>(item), 0);
		}
	}
	
	void ItemsDelegate::handleInitClientData() {
		if (Minecraft::version() == Minecraft::v1_16_1_2) {
			for (auto&& texture : itemsTextures)
				getItem<Item_1_16_1>(texture.item).setIcon(texture.name, texture.dataIndex);
		}
		else if (Minecraft::version() == Minecraft::v1_14_60_5) {
			for (auto&& texture : itemsTextures)
				getItem<Item_1_14>(texture.item).setIcon(texture.name, texture.dataIndex);
		}
	}

	void ItemsDelegate::unsupportedVersion() {
		Zenova_Error("Unsupported Minecraft Version!");
		Zenova::Platform::DebugPause();
	}
}
