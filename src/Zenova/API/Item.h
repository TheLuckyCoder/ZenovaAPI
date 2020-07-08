#pragma once

#include <string>

#include "Zenova/Common.h"
#include "Zenova/Minecraft/Util/SharedPtr.h"
#include "Zenova/Minecraft/Header/Item/CreativeItemCategory.h"
#include "Zenova/Minecraft/Bedrock/IItem.h"

using byte = unsigned char;

enum class CreativeItemCategory : byte;
enum class UseAnimation : byte;

namespace Zenova {
	
	class EXPORT Item {
	public:
		Item() = default;
		
		explicit Item(const std::string &descriptionId, bool addToCreativeInventory = false, short id = getMaxItemId());

		Item& setTexture(const std::string &textureName, int textureIndex = 0);
		Item& setCreativeCategory(CreativeItemCategory category);
		Item& setMaxStackSize(byte maxStackSize);
		Item& setMaxItemDamage(int maxItemDamage);
		Item& setHandEquipped();
		Item& setUseAnimation(UseAnimation animation);
		Item& setMaxUseDuration(int useDuration);
		Item& setIsGlint(bool glint);
		Item& setShouldDespawn(bool shouldDespawn);

		Bedrock::IItem* getMinecraftItem() const;

	private:
		template <class T>
		T& getItem() const {
			return *reinterpret_cast<T*>(mItem.get());
		}

	public:
		static void addCreativeItem(Item &item, short dataIndex = 0);
		
	private:
		static short getMaxItemId();
		static void unsupportedVersion();
		
		WeakPtr<Bedrock::IItem> mItem;
	};
}
