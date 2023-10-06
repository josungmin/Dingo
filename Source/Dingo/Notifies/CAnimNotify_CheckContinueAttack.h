#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CAnimNotify_CheckContinueAttack.generated.h"

/**
 * 
 */
UCLASS()
class DINGO_API UCAnimNotify_CheckContinueAttack : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
