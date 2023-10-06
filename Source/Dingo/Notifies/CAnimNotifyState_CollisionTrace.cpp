#include "Notifies/CAnimNotifyState_CollisionTrace.h"
#include "Components/CCombatComponent.h"
#include "Equipment/Weapons/CWeaponBase.h"
#include "Components/CCollisionComponent.h"

// Debug
#include "Utilities/CLog.h"

void UCAnimNotifyState_CollisionTrace::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

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

	UCCollisionComponent* CollisionCompo = Weapon->FindComponentByClass<UCCollisionComponent>();
		
	if (!CollisionCompo)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("CollisionCompo is NULL"));
		return;
	}

	CollisionCompo->EnableCollision();
}

void UCAnimNotifyState_CollisionTrace::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

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

	UCCollisionComponent* CollisionCompo = Weapon->FindComponentByClass<UCCollisionComponent>();

	if (!CollisionCompo)
	{
		PrintLine();
		UE_LOG(Caiman, Error, TEXT("CollisionCompo is NULL"));
		return;
	}

	CollisionCompo->DisableCollision();
}
