#pragma once

class ActorInfoRegistry;
class BlockDefinitionGroup;

template <class Item>
class TVanillaItems {
public:
	static void registerItems(bool);
	static void initCreativeItemsCallback(ActorInfoRegistry*, BlockDefinitionGroup*, bool);
	static void initCreativeCategories();
	static void initClientData();
};
