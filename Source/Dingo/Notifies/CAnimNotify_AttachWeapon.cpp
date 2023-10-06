#include "Notifies/CAnimNotify_AttachWeapon.h"
#include "Components/CCombatComponent.h"
#include "Equipment/Weapons/CWeaponBase.h"

// Debug
#include "Utilities/CLog.h"

void UCAnimNotify_AttachWeapon::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	UCCombatComponent* CombatCompo = MeshComp->GetOwner()->FindComponentByClass<UCCombatComponent>();

	if (!CombatCompo)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("CombatComponent is NULL"));
		return;
	}

	ACWeaponBase* Weapon = CombatCompo->GetMainWeapon();

	if (!Weapon)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("Weapon is NULL"));
		return;
	}

	if (CombatCompo->GetIsWeaponAttachToHand())
	{
		Weapon->AttachActor(Weapon->GetAttachSocketName());
		CombatCompo->SetIsWeaponAttachToHand(false);
	}
	else
	{
		Weapon->AttachActor(Weapon->GetHandSocketName());
		CombatCompo->SetIsWeaponAttachToHand(true);
	}
}
