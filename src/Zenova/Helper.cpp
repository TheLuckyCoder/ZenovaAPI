#define _CRT_SECURE_NO_WARNINGS
#include "Zenova.h"

#include <iostream> //std::cout (Zenova::MessageRedirection)
#include <algorithm> //std::find_if
#include <fstream>
#include <cstdio>
#include <chrono>
#include <cstdlib>

#include "Zenova/Globals.h"
#include "Zenova/StorageResolver.h"
#include "Zenova/JsonHelper.h"
#include "Zenova/PackManager.h"
#include "Zenova/Profile/Manager.h"
#include "Zenova/MessageRedirection.h"
#include "Utils/Utils.h"

#include "initcpp.h"
#include "ResourceHeaders.h"

namespace Zenova {
	std::string gFolder = "";

#ifdef ZENOVA_API
	static void(*_getVanillaPacks)(VanillaInPackagePacks*, std::vector<IInPackagePacks::MetaData>&, PackType);
	void getVanillaPacks(VanillaInPackagePacks* self, std::vector<IInPackagePacks::MetaData>& packs, PackType packType) {
		_getVanillaPacks(self, packs, packType);

		if(packType == PackType::Resources) {
			for(auto& pack : PackManager::instance.resource_packs) {
				packs.emplace_back(pack.first, true, PackCategory::Custom);
			}
		}
		else if(packType == PackType::Behavior) {
			for(auto& pack : PackManager::instance.behavior_packs) {
				packs.emplace_back(pack.first, true, PackCategory::Custom);
			}
		}
	}

	struct LambdaPack1 {
		ResourcePackRepository& repo;
		ResourcePackStack& tempStack;
	};

	void addPackFromPackId(LambdaPack1& self, const PackIdVersion& packType) {
		Zenova::Hook::Call<void, Zenova::CallConvention::CDecl>(Zenova::Hook::SlideAddress(0x1ABF450), &self, packType);
	}

	static void(*_VanillaGameModuleClient$initializeResourceStack)(VanillaGameModuleClient*, ResourcePackRepository&, ResourcePackStack&);
	void VanillaGameModuleClient$initializeResourceStack(VanillaGameModuleClient* self, ResourcePackRepository& repo, ResourcePackStack& tempStack) {
		//Zenova::Platform::DebugPause();
		_VanillaGameModuleClient$initializeResourceStack(self, repo, tempStack);

		for(auto& pack : Zenova::PackManager::instance.resource_packs) {
			LambdaPack1 lp { repo, tempStack };
			addPackFromPackId(lp,
				{ mce::UUID::fromString(pack.second), SemVersion(0, 0, 1), PackType::Resources });
		}
	}

	std::string GetDataFolder() {
		std::vector<std::string> folder = {
			std::getenv("ZENOVA_DATA"),
			::Util::GetAppDirectoryA() + "\\Data",
		};

		for(auto& str : folder) {
			if(!str.empty() && Util::IsDirectory(str + "/versions")) {
				return str;
			}
		}

		return "";
	}

	u32 __stdcall Start(void* dllHandle) {
		gFolder = GetDataFolder();
		Hook::BaseAddress = Platform::GetModuleBaseAddress("Minecraft.Windows.exe");
		bool canRun = (Platform::Init(dllHandle) && !gFolder.empty() && Hook::BaseAddress);
		if(canRun) {
			MessageRedirection console;

			Zenova::Platform::DebugPause();
			InitBedrockPointers();
			Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1AC2FC0)), getVanillaPacks, (void**)&_getVanillaPacks);
			Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1ABF550)), VanillaGameModuleClient$initializeResourceStack, (void**)&_VanillaGameModuleClient$initializeResourceStack);

			Zenova_Info("Zenova Started");
			Zenova_Info("ZenovaData Location: " + gFolder);
			Zenova_Info("Minecraft's BaseAddress: " + ::Util::HexString(Hook::BaseAddress));

			StorageResolver storage(L"minecraftWorlds/", L"D:/MinecraftBedrock/Worlds");
			Manager manager;

			while(canRun) {
				//Works in the console window :P
				//if(GetAsyncKeyState(VK_ESCAPE)) { 
				//	canRun = false;
				//}

				manager.Update();
			}

			Zenova_Info("Zenova Stopped");
		}

		Platform::Destroy();
		return 0;
	}
#endif // ZENOVA_API
}