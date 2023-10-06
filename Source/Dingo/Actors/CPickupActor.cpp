#include "Actors/CPickupActor.h"
#include "Components/SphereComponent.h"
#include "Equipment/Weapons/CWeaponBase.h"
#include "Utilities/CLog.h"

ACPickupActor::ACPickupActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	// StaticMesh Section
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(GetRootComponent());

	// Sphere Collision Section
	InteractCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	InteractCollision->SetupAttachment(StaticMesh);

	InteractCollision->SetSphereRadius(Radius);
	InteractCollision->SetGenerateOverlapEvents(true);
	InteractCollision->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1); // Custom Object Chanel :  Interactable
}

void ACPickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPickupActor::Interact(AActor* InCaller)
{
	// TODO : 임시코드
	ACWeaponBase* NewWeapon = ACWeaponBase::Spawn(GetWorld(), Item, InCaller);
	NewWeapon->OnEquiped();
}

