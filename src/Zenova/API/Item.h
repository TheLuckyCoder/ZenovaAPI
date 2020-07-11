#pragma once

#include <string>

#include "Zenova/Common.h"
#include "Zenova/Minecraft/Header/Util/SharedPtr.h"
#include "Zenova/Minecraft/Header/Item/CreativeItemCategory.h"
#include "Zenova/Minecraft/Header/Item/UseAnimation.h"
#include "Zenova/Minecraft/Bedrock/IItem.h"

namespace Zenova {
	
	class EXPORT Item {
	public:
		Item() = default;
		
		explicit Item(const std::string &descriptionId, short id = getMaxItemId());

		Item& setTexture(const std::string &textureName, int textureIndex = 0);
		Item& setCreativeCategory(CreativeItemCategory category);
		Item& addCreativeItem(short dataIndex = 0);
		Item& setMaxStackSize(u8 maxStackSize);
		Item& setMaxItemDamage(int maxItemDamage);
		Item& setHandEquipped();
		Item& setUseAnimation(UseAnimation animation);
		Item& setMaxUseDuration(int useDuration);
		Item& setIsGlint(bool glint);
		Item& setShouldDespawn(bool shouldDespawn);

		Bedrock::IItem* getMinecraftItem() const;

	private:
		template <class T, typename std::enable_if<std::is_base_of<Bedrock::IItem, T>::value>::type* = nullptr>
		T& getItem() const {
			return *reinterpret_cast<T*>(mItem.get());
		}

		static short getMaxItemId();
		static void unsupportedVersion();
		
		WeakPtr<Bedrock::IItem> mItem;
	};
}
