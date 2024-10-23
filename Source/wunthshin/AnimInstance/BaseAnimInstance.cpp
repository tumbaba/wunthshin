// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"



void UBaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	APawn* Pawn = TryGetPawnOwner();
	if (GIsEditor && FApp::IsGame() && !Pawn)
	{
		checkf(false, TEXT("UBaisicCharacterAnimInstance를 사용하려면 소유권자가 Pawn이여야 합니다."));
		return;
	}
	else if (!Pawn) { return; }
	MovementComponent = Pawn->GetMovementComponent();
	check(MovementComponent);
	

	

	//CharateromponentRef = GetMove
	
	CharaterComponentRef = Cast<AA_WSCharacter>(Pawn);
	CharaterComponentRef->OnFastRun.AddDynamic(this, &ThisClass::CanFastRun);
	CharaterComponentRef->OffFastRun.AddDynamic(this, &ThisClass::OffFastRun);
	CharaterComponentRef->OnWalk.AddDynamic(this, &ThisClass::OnWalkMove);
	CharaterComponentRef->OffWalk.AddDynamic(this, &ThisClass::OffWalkMove);
	CharaterComponentRef->Glide.AddDynamic(this, &ThisClass::CanGlide);
	
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	

	if (!MovementComponent) { return; }

	RunSpeed = UKismetMathLibrary::VSizeXY(MovementComponent->Velocity);
	RunSpeed = RunSpeed * 1.7f;

	bShoudRun = !FMath::IsNearlyZero(RunSpeed);
	//bShoudWalk = !FMath::IsNearlyZero(WalkSpeed);


	bIsCrouch = MovementComponent->IsCrouching();
	bIsFalling = MovementComponent->IsFalling();
}




void UBaseAnimInstance::CanFastRun()
{
	if (!bShoudFastRun&& !bShoudWalk)
	{
		bShoudFastRun = true;
	}
}

void UBaseAnimInstance::OffFastRun()
{
	if (bShoudFastRun)
	{
		bShoudFastRun = false;
	}
}

void UBaseAnimInstance::OnWalkMove()
{
	if (!bShoudWalk&& !bShoudFastRun)
	{
		bShoudWalk = true;
	}
	else if (bShoudWalk)
	{
		bShoudWalk = false;
	}
}

void UBaseAnimInstance::OffWalkMove()
{
	if (bShoudWalk)
	{
		bShoudWalk = false;
	}
}

void UBaseAnimInstance::CanGlide()
{
	if (bIsGlide)
	{
		bIsGlide = !bIsGlide;
	}
	else
	{
		bIsGlide = !bIsGlide;
	}
}
bool UBaseAnimInstance::GetGanClide()
{
	return bIsGlide;
}
bool UBaseAnimInstance::GetIsCrouch()
{
	return bIsCrouch;
}
bool UBaseAnimInstance::GetbCanFastRun()
{
	return bShoudFastRun;
}
bool UBaseAnimInstance::GetbFastRun()
{
	return bShoudFastRun;
}

bool UBaseAnimInstance::GetbWalk()
{
	return bShoudWalk;
}



//void UBaseAnimInstance::SetRootMotionMode()
//{
//	ACharacter* Character = Cast<ACharacter>(TryGetPawnOwner());
//	if (Character)
//	{
//		UCharacterMovementComponent* MovementConponent = Character->GetCharacterMovement();
//		{
//			if (MovementComponent)
//			{
//				MovementComponent->bRootMotionMode
//			}
//		}
//	}
//}


