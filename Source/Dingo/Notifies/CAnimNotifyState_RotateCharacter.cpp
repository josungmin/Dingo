#include "Notifies/CAnimNotifyState_RotateCharacter.h"
#include "Interfaces/ICombat.h"

// Debug
#include "Utilities/CLog.h"

void UCAnimNotifyState_RotateCharacter::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);

	IICombat* Combat = Cast<IICombat>(MeshComp->GetOwner());

	if (!Combat)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("Combat Is NULL"));
		return;
	}

	FRotator NewRotator = FMath::RInterpTo(MeshComp->GetOwner()->GetActorRotation(), Combat->GetDesiredRotation(), FrameDeltaTime, InterpSpeed);

	MeshComp->GetOwner()->SetActorRotation(NewRotator);
}
