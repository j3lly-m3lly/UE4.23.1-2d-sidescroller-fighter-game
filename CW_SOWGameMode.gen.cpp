// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CW_SOW/CW_SOWGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCW_SOWGameMode() {}
// Cross Module References
	CW_SOW_API UClass* Z_Construct_UClass_ACW_SOWGameMode_NoRegister();
	CW_SOW_API UClass* Z_Construct_UClass_ACW_SOWGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CW_SOW();
// End Cross Module References
	void ACW_SOWGameMode::StaticRegisterNativesACW_SOWGameMode()
	{
	}
	UClass* Z_Construct_UClass_ACW_SOWGameMode_NoRegister()
	{
		return ACW_SOWGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACW_SOWGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACW_SOWGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CW_SOW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACW_SOWGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The GameMode defines the game being played. It governs the game rules, scoring, what actors\n * are allowed to exist in this game type, and who may enter the game.\n *\n * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of CW_SOWCharacter\n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "CW_SOWGameMode.h" },
		{ "ModuleRelativePath", "CW_SOWGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "The GameMode defines the game being played. It governs the game rules, scoring, what actors\nare allowed to exist in this game type, and who may enter the game.\n\nThis game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of CW_SOWCharacter" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACW_SOWGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACW_SOWGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACW_SOWGameMode_Statics::ClassParams = {
		&ACW_SOWGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_ACW_SOWGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACW_SOWGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACW_SOWGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACW_SOWGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACW_SOWGameMode, 2979648194);
	template<> CW_SOW_API UClass* StaticClass<ACW_SOWGameMode>()
	{
		return ACW_SOWGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACW_SOWGameMode(Z_Construct_UClass_ACW_SOWGameMode, &ACW_SOWGameMode::StaticClass, TEXT("/Script/CW_SOW"), TEXT("ACW_SOWGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACW_SOWGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
