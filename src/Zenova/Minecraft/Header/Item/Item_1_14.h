#pragma once

#include <string>

#include "Zenova/Minecraft/Bedrock/IItem.h"

#include "../Client/TextureUVCoordinateSet.h"
#include "CooldownType.h"
#include "CreativeItemCategory.h"
#include "UseAnimation.h"

class BlockPos;
class ItemInstance;
class ItemStack;
class ItemStackBase;
class Level;
class CompoundTag;
class Color;
class Player;
class BlockSource;
class Container;
class Vec3;
class Block;
class Mob;
class Actor;
class IDataInput;
class ReadOnlyBinaryStream;
class IDataOutput;
class ItemDescriptor;
enum class BlockShape;
enum class InHandUpdateType;
enum class ItemUseMethod;
class TextureAtlasItem;
class FoodItemComponent;
class SeedItemComponent;
class CameraItemComponent;
class BlockLegacy;

typedef unsigned char byte;
typedef unsigned char FacingID;

class Item_1_14 : public Bedrock::IItem {
public:
    class Tier {
        const int mLevel;
        const int mUses;
        const float mSpeed;
        const int mDamage;
        const int mEnchantmentValue;

    public:
        Tier(int level, int uses, float speed, int damage, int enchantmentValue)
    		: mLevel(level), mUses(uses), mSpeed(speed), mDamage(damage), mEnchantmentValue(enchantmentValue) {}
        int getUses() const { return mUses; }
        float getSpeed() const { return mSpeed; }
        int getAttackDamageBonus() const { return mDamage; }
        int getLevel() const { return mLevel; }
        int getEnchantmentValue() const { return mEnchantmentValue; }
    };

private:
    char filler[438];
	
public:
    static bool* mInCreativeGroup;

    Item_1_14(const std::string&, short);
    virtual ~Item_1_14();
    virtual void tearDown();
    virtual int getMaxUseDuration(const ItemInstance*) const;
    virtual int getMaxUseDuration(const ItemStack*) const;
    virtual bool isExperimental(const ItemDescriptor*) const;
    virtual Item_1_14& setMaxStackSize(byte);
    virtual Item_1_14& setCategory(CreativeItemCategory);
    virtual Item_1_14& setStackedByData(bool);
    virtual Item_1_14& setMaxDamage(int);
    virtual Item_1_14& setHandEquipped();
    virtual Item_1_14& setUseAnimation(UseAnimation);
    virtual Item_1_14& setMaxUseDuration(int);
    virtual Item_1_14& setRequiresWorldBuilder(bool);
    virtual Item_1_14& setExplodable(bool);
    virtual Item_1_14& setIsGlint(bool);
    virtual Item_1_14& setShouldDespawn(bool);
    virtual BlockShape getBlockShape() const;
    virtual bool canBeDepleted() const;
    virtual bool canDestroySpecial(const Block&) const;
    virtual int getLevelDataForAuxValue(int) const;
    virtual bool isStackedByData() const;
    virtual short getMaxDamage() const;
    virtual int getAttackDamage() const;
    virtual bool isHandEquipped() const;
    virtual bool isArmor() const;
    virtual bool isDye() const;
    virtual bool isFertilizer(int) const;
    virtual bool isGlint(const ItemStackBase&) const;
    virtual bool isThrowable() const;
    virtual bool isPattern() const;
    virtual bool showsDurabilityInCreative() const;
    virtual bool isWearableThroughLootTable(const std::unique_ptr<CompoundTag>&) const;
    virtual bool canDestroyInCreative() const;
    virtual bool isDestructive(int) const;
    virtual bool isLiquidClipItem(int) const;
    virtual bool requiresInteract() const;
    virtual void appendFormattedHovertext(const ItemStackBase&, Level&, std::string&, const bool) const;
    virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&) const;
    virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual int getArmorValue() const;
    virtual bool isComplex() const;
    virtual bool isValidAuxValue(int) const;
    virtual int getDamageChance(int) const;
    virtual bool uniqueAuxValues() const;
    virtual bool isMultiColorTinted(const ItemStack&) const;
    virtual Color getColor(const std::unique_ptr<CompoundTag>&, const ItemDescriptor&) const;
    virtual Color getBaseColor(const ItemStack&) const;
    virtual Color getSecondaryColor(const ItemStack&) const;
    virtual void saveAdditionalData(const ItemStackBase&, CompoundTag&) const;
    virtual void readAdditionalData(ItemStackBase&, const CompoundTag&) const;
    virtual bool isTintable() const;
    virtual ItemStack& use(ItemStack&, Player&) const;
    virtual bool dispense(BlockSource&, Container&, int, const Vec3&, unsigned char) const;
    virtual ItemUseMethod useTimeDepleted(ItemInstance&, Level*, Player*) const;
    virtual ItemUseMethod useTimeDepleted(ItemStack&, Level*, Player*) const;
    virtual void releaseUsing(ItemInstance&, Player*, int) const;
    virtual void releaseUsing(ItemStack&, Player*, int) const;
    virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
    virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
    virtual void hurtEnemy(ItemStack&, Mob*, Mob*) const;
    virtual bool mineBlock(ItemInstance&, const Block&, int, int, int, Actor*) const;
    virtual bool mineBlock(ItemStack&, const Block&, int, int, int, Actor*) const;
    virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
    virtual std::string buildEffectDescriptionName(const ItemStackBase&) const;
    virtual std::string buildCategoryDescriptionName() const;
    virtual void readUserData(ItemStackBase&, IDataInput&, ReadOnlyBinaryStream&) const;
    virtual void writeUserData(const ItemStackBase&, IDataOutput&) const;
    virtual byte getMaxStackSize(const ItemDescriptor&) const;
    virtual bool inventoryTick(ItemStack&, Level&, Actor&, int, bool) const;
    virtual void refreshedInContainer(ItemStackBase&, Level&) const;
    virtual CooldownType getCooldownType() const;
    virtual int getCooldownTime() const;
    virtual void fixupOnLoad(ItemStackBase&) const;
    virtual void fixupOnLoad(ItemStackBase&, Level&) const;
    virtual short getDamageValue(const std::unique_ptr<CompoundTag>&) const;
    virtual void setDamageValue(ItemStackBase&, short) const;
    virtual InHandUpdateType getInHandUpdateType(const Player&, const ItemInstance&, const ItemInstance&, const bool, const bool) const;
    virtual InHandUpdateType getInHandUpdateType(const Player&, const ItemStack&, const ItemStack&, const bool, const bool) const;
    virtual bool isSameItem(const ItemStackBase&, const ItemStackBase&) const;
    virtual std::string getInteractText(const Player&) const;
    virtual int getAnimationFrameFor(Mob*, bool, const ItemStack*, const bool) const;
    virtual bool isEmissive(int) const;
    virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
    virtual int getIconYOffset() const;
    virtual Item_1_14& setIcon(const std::string&, int);
    virtual Item_1_14& setIcon(const TextureUVCoordinateSet&);
    virtual Item_1_14& setIconAtlas(const std::string&, int);
    virtual bool canBeCharged() const;
    virtual void playSoundIncrementally(const ItemInstance&, Mob&) const;
    virtual void playSoundIncrementally(const ItemStack&, Mob&) const;
    virtual std::string getAuxValuesDescription() const;

    static const TextureAtlasItem& getTextureItem(const std::string&);
    static const TextureUVCoordinateSet& getIconTextureUVSet(const TextureAtlasItem&, int, int);

    static void beginCreativeGroup(const std::string&, Item_1_14*, short, const CompoundTag*);
    static void addCreativeItem(Item_1_14*, short);
    static void addCreativeItem(const Block&);
    static void endCreativeGroup() {
        *mInCreativeGroup = false;
    }
private:
    virtual bool _checkUseOnPermissions(Actor&, ItemInstance&, const FacingID&, const BlockPos&) const;
    virtual bool _checkUseOnPermissions(Actor&, ItemStack&, const FacingID&, const BlockPos&) const;
    virtual bool _calculatePlacePos(ItemInstance&, Actor&, FacingID&, BlockPos&) const;
    virtual bool _calculatePlacePos(ItemStack&, Actor&, FacingID&, BlockPos&) const;
    virtual bool _useOn(ItemInstance&, Actor&, BlockPos, FacingID, float, float, float) const;
    virtual bool _useOn(ItemStack&, Actor&, BlockPos, FacingID, float, float, float) const;
};
