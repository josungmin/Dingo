#include "Notifies/CAnimNotify_ResetCombat.h"
#include "Interfaces/ICombat.h"

// Debug
#include "Utilities/CLog.h"

void UCAnimNotify_ResetCombat::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	IICombat* Combat = Cast<IICombat>(MeshComp->GetOwner());

	if (!Combat)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("Combat Is NULL"));
		return;
	}

	Combat->ResetCombat();
}
