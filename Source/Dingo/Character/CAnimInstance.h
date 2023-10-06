#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Enums/EWeaponType.h"
#include "Interfaces/IWeapon.h"
#include "CAnimInstance.generated.h"

UCLASS()
class DINGO_API UCAnimInstance : public UAnimInstance, public IIWeapon
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
		FVector Velocity;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
		float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
		uint32 ShouldMove : 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
		uint32 IsFalling : 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Initialization", Meta = (AllowPrivateAccess = "true"))
		EWeaponType WeaponType;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Initialization", Meta = (AllowPrivateAccess = "true"))
		uint32 IsAttachedHand : 1;

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void SetWeaponType(EWeaponType InWeaponType) override;
	virtual void SetIsAttachedHand(bool InBoolean) override;

private:
	class ACharacter* OwnerCharacter;
	class UCharacterMovementComponent* MovementComponent;
};
