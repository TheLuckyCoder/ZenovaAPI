#include "Item.h"

#include "Zenova/Log.h"
#include "Zenova/Minecraft.h"

#include "Zenova/Minecraft/Header/Item/Item_1_14.h"
#include "Zenova/Minecraft/Header/Item/TItemRegistry.h"

namespace Zenova {

	Item::Item(const std::string& descriptionId, const bool addToCreativeInventory, const short id) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			mItem = TItemRegistry::registerItem<Item_1_14>(descriptionId, id);
		}
		else {
			unsupportedVersion();
		}

		if (addToCreativeInventory)
			addCreativeItem(*this);
	}

	Item& Item::setTexture(const std::string& textureName, const int textureIndex) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setIcon(textureName, textureIndex);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setCreativeCategory(const CreativeItemCategory category) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setCategory(category);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setMaxStackSize(const byte maxStackSize) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setMaxStackSize(maxStackSize);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setMaxItemDamage(const int maxItemDamage) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setMaxDamage(maxItemDamage);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setHandEquipped() {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setHandEquipped();
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setUseAnimation(const UseAnimation animation) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setUseAnimation(animation);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setMaxUseDuration(const int useDuration) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setMaxUseDuration(useDuration);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setIsGlint(const bool glint) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setIsGlint(glint);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setShouldDespawn(const bool shouldDespawn) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setShouldDespawn(shouldDespawn);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Bedrock::IItem* Item::getMinecraftItem() const {
		return mItem.get();
	}

	void Item::addCreativeItem(Item &item, const short dataIndex) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			Item_1_14::addCreativeItem(&item.getItem<Item_1_14>(), dataIndex);
		}
		else {
			unsupportedVersion();
		}
	}

	short Item::getMaxItemId() {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			return TItemRegistry::getMaxItemID();
		}
		
		unsupportedVersion();
		return 0; // ?
	}

	void Item::unsupportedVersion() {
		Zenova_Error("Unsupported MC Version");
		Zenova::Platform::DebugPause();
	}
}
