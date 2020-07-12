#include "Item.h"

#include "Zenova/Log.h"
#include "Zenova/Minecraft.h"

#include "Zenova/Minecraft/Header/Item/Item_1_14.h"
#include "Zenova/Minecraft/Header/Item/Item_1_16_1.h"
#include "Zenova/Minecraft/Header/Item/TItemRegistry.h"

namespace Zenova {

	Item::Item(const std::string& descriptionId, const short id) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			mItem = TItemRegistry<Item_1_14>::registerItem<Item_1_14>(descriptionId, id);
		}
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			mItem = TItemRegistry<Item_1_16_1>::registerItem<Item_1_16_1>(descriptionId, id);
		}
		else {
			unsupportedVersion();
		}
	}

	Item& Item::setTexture(const std::string& textureName, const int textureIndex) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setIcon(textureName, textureIndex);
		}
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setIcon(textureName, textureIndex);
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setCategory(category);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::addCreativeItem(const short dataIndex) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			Item_1_14::addCreativeItem(&getItem<Item_1_14>(), dataIndex);
		}
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			Item_1_16_1::addCreativeItem(&getItem<Item_1_16_1>(), dataIndex);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setMaxStackSize(const u8 maxStackSize) {
		if (Minecraft::version() == Minecraft::v1_14_60_5) {
			getItem<Item_1_14>().setMaxStackSize(maxStackSize);
		}
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setMaxStackSize(maxStackSize);
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setMaxDamage(maxItemDamage);
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setHandEquipped();
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setUseAnimation(animation);
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setMaxUseDuration(useDuration);
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setIsGlint(glint);
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
		else if (Minecraft::version() == Minecraft::v1_16_1_2) {
			getItem<Item_1_16_1>().setShouldDespawn(shouldDespawn);
		}
		else {
			unsupportedVersion();
		}
		return *this;
	}

	Bedrock::IItem* Item::getMinecraftItem() const {
		return mItem.get();
	}

	short Item::getMaxItemId() {
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return TItemRegistry<Item_1_14>::getMaxItemID();
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return TItemRegistry<Item_1_16_1>::getMaxItemID();
		
		unsupportedVersion();
		return 0; // ?
	}

	void Item::unsupportedVersion() {
		Zenova_Error("Unsupported MC Version");
		Zenova::Platform::DebugPause();
	}
}
