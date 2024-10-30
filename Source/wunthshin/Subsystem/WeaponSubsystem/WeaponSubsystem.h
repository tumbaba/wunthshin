// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "wunthshin/Interfaces/DataTableQuery/DataTableQuery.h"
#include "wunthshin/Interfaces/ItemMetadataGetter/ItemMetadataGetter.h"

#include "WeaponSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class WUNTHSHIN_API UWeaponSubsystem : public UGameInstanceSubsystem, public IItemMetadataGetter, public IDataTableQuery
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta=(AllowPrivateAccess = "true"))
	TMap<FName, USG_WSItemMetadata*> Metadata;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table", meta=(AllowPrivateAccess = "true"))
	UDataTable* DataTable;
	
public:
	UWeaponSubsystem();

	virtual void                Initialize(FSubsystemCollectionBase& Collection) override;
	virtual USG_WSItemMetadata* GetMetadata(const FName& InAssetName) override;
};

UCLASS()
class WUNTHSHIN_API UWeaponEditorSubsystem : public UEditorSubsystem, public IItemMetadataGetter, public IDataTableQuery
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta=(AllowPrivateAccess = "true"))
	TMap<FName, USG_WSItemMetadata*> Metadata;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table", meta=(AllowPrivateAccess = "true"))
	UDataTable* DataTable;
	
public:
	UWeaponEditorSubsystem();
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual USG_WSItemMetadata* GetMetadata(const FName& InAssetName) override;

};
