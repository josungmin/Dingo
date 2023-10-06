#include "Notifies/CAnimNotify_CheckContinueAttack.h"
#include "Interfaces/ICombat.h"

// Debug
#include "Utilities/CLog.h"

void UCAnimNotify_CheckContinueAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	IICombat* Combat = Cast<IICombat>(MeshComp->GetOwner());

	if (!Combat)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("Combat is NULL"));
		return;
	}

	Combat->CheckContinueAttack();
}
