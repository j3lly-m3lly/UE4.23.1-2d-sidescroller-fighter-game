// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CW_SOW/enemy_npc1_controller.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeenemy_npc1_controller() {}
// Cross Module References
	CW_SOW_API UClass* Z_Construct_UClass_Aenemy_npc1_controller_NoRegister();
	CW_SOW_API UClass* Z_Construct_UClass_Aenemy_npc1_controller();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_CW_SOW();
// End Cross Module References
	void Aenemy_npc1_controller::StaticRegisterNativesAenemy_npc1_controller()
	{
	}
	UClass* Z_Construct_UClass_Aenemy_npc1_controller_NoRegister()
	{
		return Aenemy_npc1_controller::StaticClass();
	}
	struct Z_Construct_UClass_Aenemy_npc1_controller_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Aenemy_npc1_controller_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_CW_SOW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aenemy_npc1_controller_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "enemy_npc1_controller.h" },
		{ "ModuleRelativePath", "enemy_npc1_controller.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Aenemy_npc1_controller_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Aenemy_npc1_controller>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Aenemy_npc1_controller_Statics::ClassParams = {
		&Aenemy_npc1_controller::StaticClass,
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
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_Aenemy_npc1_controller_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_Aenemy_npc1_controller_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Aenemy_npc1_controller()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Aenemy_npc1_controller_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Aenemy_npc1_controller, 1015015849);
	template<> CW_SOW_API UClass* StaticClass<Aenemy_npc1_controller>()
	{
		return Aenemy_npc1_controller::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Aenemy_npc1_controller(Z_Construct_UClass_Aenemy_npc1_controller, &Aenemy_npc1_controller::StaticClass, TEXT("/Script/CW_SOW"), TEXT("Aenemy_npc1_controller"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Aenemy_npc1_controller);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
