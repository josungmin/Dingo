#include "Character/CAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

// Debug
#include "Utilities/CLog.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwningActor());
	MovementComponent = OwnerCharacter->GetCharacterMovement();
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!OwnerCharacter)
	{
		return;
	}

	Velocity = MovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();
	IsFalling = MovementComponent->IsFalling();

	bool bIsAcceleration = !MovementComponent->GetCurrentAcceleration().Equals(FVector::ZeroVector);
	ShouldMove = (GroundSpeed > 3.0f) & bIsAcceleration;

}

void UCAnimInstance::SetWeaponType(EWeaponType InWeaponType)
{
	WeaponType = InWeaponType;
}

void UCAnimInstance::SetIsAttachedHand(bool InBoolean)
{
	IsAttachedHand = InBoolean;
}

