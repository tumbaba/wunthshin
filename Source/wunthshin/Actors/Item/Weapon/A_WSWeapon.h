// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "wunthshin/Actors/Item/A_WSItem.h"
#include "A_WSWeapon.generated.h"

class UAnimMontage;
class UC_WSWeapon;

UENUM()
enum class EWeaponType : uint8
{
	Melee,
	Range
};

USTRUCT()
struct WUNTHSHIN_API FWeaponTableRow : public FItemTableRow
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType;
	
	UPROPERTY(EditAnywhere)
	int32 Damage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* DefaultAttackMontage;
	
};

/**
 * 
 */
UCLASS()
class WUNTHSHIN_API AA_WSWeapon : public AA_WSItem
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta=(AllowPrivateAccess = "true"))
	UC_WSWeapon* WeaponComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation", meta=(AllowPrivateAccess = "true"))
	UAnimMontage* DefaultAttackMontage;
	
public:
	// Item 데이터 테이블은 Weapon 데이터 테이블과 다른 테이블을 씀
	using TRowTableType = FWeaponTableRow;
	
	// 자식 클래스가 Weapon Component를 override할 수 있도록 ObjectInitializer 생성자로
	AA_WSWeapon(const FObjectInitializer& ObjectInitializer);

	virtual void SetData(const FDataTableRowHandle& InRowHandle) override;

	// 기본 공격 모션 몽타주 getter
	UFUNCTION(BlueprintCallable)
	UAnimMontage* GetDefaultAttackMontage() const { return DefaultAttackMontage; }
	
	
};