#include "Item.h"


#include "Zenova/Log.h"
#include "Zenova/Minecraft.h"
#include "Zenova/API/ItemsDelegate.h"

#include "Zenova/Minecraft/Header/Item/Item_1_14.h"
#include "Zenova/Minecraft/Header/Item/Item_1_16_1.h"
#include "Zenova/Minecraft/Header/Item/TItemRegistry.h"

namespace Zenova {

	Item::Item(std::string descriptionId, const short id)
			: mDescriptionId(std::move(descriptionId)) {

		Zenova_Info("Create Item");
		
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			mItem = TItemRegistry<Item_1_16_1>::registerItemShared<Item_1_16_1>(mDescriptionId, id);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			mItem = TItemRegistry<Item_1_14>::registerItemShared<Item_1_14>(mDescriptionId, id);
		else
			ItemsDelegate::unsupportedVersion();
	}

	Item& Item::setTexture(std::string textureName, const int textureIndex) {
		ItemsDelegate::setItemTexture({ getBedrockItem(), std::move(textureName), textureIndex });
		return *this;
	}

	Item& Item::setCreativeCategory(const CreativeItemCategory category) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setCategory(category);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setCategory(category);
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	Item& Item::addCreativeItem() {
		ItemsDelegate::addItemToCreative(getBedrockItem());
		return *this;
	}

	Item& Item::setMaxStackSize(const u8 maxStackSize) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setMaxStackSize(maxStackSize);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setMaxStackSize(maxStackSize);
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	Item& Item::setMaxItemDamage(const int maxItemDamage) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setMaxDamage(maxItemDamage);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setMaxDamage(maxItemDamage);
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	Item& Item::setHandEquipped() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setHandEquipped();
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setHandEquipped();
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	Item& Item::setUseAnimation(const UseAnimation animation) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setUseAnimation(animation);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setUseAnimation(animation);
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	Item& Item::setMaxUseDuration(const int useDuration) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setMaxUseDuration(useDuration);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setMaxUseDuration(useDuration);
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	Item& Item::setIsGlint(const bool glint) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setIsGlint(glint);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setIsGlint(glint);
		else {
			ItemsDelegate::unsupportedVersion();
		}
		return *this;
	}

	Item& Item::setShouldDespawn(const bool shouldDespawn) {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			getItem<Item_1_16_1>().setShouldDespawn(shouldDespawn);
		else if (Minecraft::version() == Minecraft::v1_14_60_5)
			getItem<Item_1_14>().setShouldDespawn(shouldDespawn);
		else
			ItemsDelegate::unsupportedVersion();
		return *this;
	}

	short Item::getMaxItemId() {
		if (Minecraft::version() == Minecraft::v1_16_1_2)
			return TItemRegistry<Item_1_16_1>::getMaxItemID();
		if (Minecraft::version() == Minecraft::v1_14_60_5)
			return TItemRegistry<Item_1_14>::getMaxItemID();
		
		ItemsDelegate::unsupportedVersion();
		return 0; // ?
	}
}
