#pragma once

#include <functional>

#include "Zenova/Common.h"
#include "Zenova/API/Item.h"

namespace Zenova {

	class EXPORT ItemsDelegate {
		friend class Item;
		
		friend void createItemHooks();
		friend void registerVanillaItems(bool);
		friend void initVanillaCreativeCategories();
		friend void initVanillaCreativeItems(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
		friend void initVanillaClientData();

	public:
		using Callback = std::function<void()>;
		using BedrockItemPtr = WeakPtr<Bedrock::IItem>;
		
		ItemsDelegate() = delete;
		ItemsDelegate(const ItemsDelegate&) = delete;
		ItemsDelegate(ItemsDelegate&&) = delete;
		~ItemsDelegate() = delete;

		ItemsDelegate& operator=(const ItemsDelegate&) = delete;
		ItemsDelegate& operator=(ItemsDelegate&&) noexcept = delete;

	private:
		struct ItemTexture {
			BedrockItemPtr item;
			std::string name;
			int dataIndex = 0;
		};
		
		inline static std::vector<Callback> registerItemCallbacks;
		//static std::vector<Callback> initCreativeCategoriesCallbacks;
		inline static std::vector<BedrockItemPtr> creativeItems;
		inline static std::vector<ItemTexture> itemsTextures;

	public:
		static void addRegisterItemCallback(const Callback& callback);

	private:
		static void addItemToCreative(const BedrockItemPtr& item);
		static void setItemTexture(ItemTexture itemTexture);

		static void* getRegisterItemsFunction();
		static void* getInitCreativeCategoriesFunction();
		static void* getInitCreativeItemsFunction();
		static void* getInitClientDataFunction();

		static void handleRegisterItems();
		static void handleInitCreativeCategories();
		static void handleInitCreativeItems();
		static void handleInitClientData();

		static void unsupportedVersion();
	};
}
