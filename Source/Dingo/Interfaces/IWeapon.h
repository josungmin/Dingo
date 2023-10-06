#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Enums/EWeaponType.h"
#include "IWeapon.generated.h"

UINTERFACE(MinimalAPI)
class UIWeapon : public UInterface
{
	GENERATED_BODY()
};

class DINGO_API IIWeapon
{
	GENERATED_BODY()

public:
	virtual void SetWeaponType(EWeaponType InWeaponType) = 0;
	virtual void SetIsAttachedHand(bool InBoolean) = 0;
};
