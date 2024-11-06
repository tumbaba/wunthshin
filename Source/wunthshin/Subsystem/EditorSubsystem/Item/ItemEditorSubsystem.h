// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "GenericPlatform/GenericPlatformMisc.h"

#include "wunthshin/Interfaces/DataTableQuery/DataTableQuery.h"
#include "wunthshin/Interfaces/ItemMetadataGetter/ItemMetadataGetter.h"
#include "ItemEditorSubsystem.generated.h"

class USG_WSItemMetadata;

/**
 * 
 */
UCLASS()
class UItemEditorSubsystem : public UEditorSubsystem, public IItemMetadataGetter, public IDataTableQuery
{
	GENERATED_BODY()

	// 아이템 고유 메타데이터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta=(AllowPrivateAccess = "true"))
	TMap<FName, USG_WSItemMetadata*> Metadata;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Table", meta=(AllowPrivateAccess = "true"))
	UDataTable* DataTable;
	
public:
	UItemEditorSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual USG_WSItemMetadata* GetMetadata(const FName& InAssetName) override;
	virtual bool IsEditorOnly() const override { return true; }
};