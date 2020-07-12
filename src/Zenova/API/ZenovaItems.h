#pragma once

#include <functional>

#include "Zenova/Common.h"

namespace Zenova {
	void createItemHooks();
	
	class EXPORT ZenovaItems {
		friend void createItemHooks();
		
	public:
		using Callback = std::function<void()>;
		
		ZenovaItems() = delete;
		ZenovaItems(const ZenovaItems&) = delete;
		ZenovaItems(ZenovaItems&&) = delete;
		~ZenovaItems() = delete;

		ZenovaItems& operator=(const ZenovaItems&) = delete;
		ZenovaItems& operator=(ZenovaItems&&) noexcept = delete;

	private:
		static std::vector<Callback> registerItemsCallbacks;
		static std::vector<Callback> initCreativeCategoriesCallbacks;
		static std::vector<Callback> initCreativeItemsCallbacks;
		static std::vector<Callback> initClientDataCallbacks;

	public:
		static void addRegisterItemsCallback(const Callback& callback);
		static void addInitCreativeCategoriesCallback(const Callback& callback);
		static void addInitCreativeItemsCallback(const Callback& callback);
		static void addInitClientDataCallback(const Callback& callback);

	private:
		static void* getRegisterItemsFunction();
		static void* getInitCreativeCategoriesFunction();
		static void* getInitCreativeItemsFunction();
		static void* getInitClientDataFunction();

	public:
		static void handleRegisterItemsCallbacks();
		static void handleInitCreativeCategoriesCallbacks();
		static void handleInitCreativeItemsCallbacks();
		static void handleInitClientDataCallbacks();
	};
}
