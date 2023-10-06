#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IInteractabl.h"
#include "GameFramework/Actor.h"
#include "CPickupActor.generated.h"

UCLASS()
class DINGO_API ACPickupActor : public AActor, public IIInteractabl
{
	GENERATED_BODY()
	
public:	
	ACPickupActor();

protected:
	virtual void BeginPlay() override;


public:	
	virtual void Tick(float DeltaTime) override;

public:
	// IInteractabl Class Override
	virtual void Interact(AActor* InCaller) override;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Compopnent", Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Compopnent", Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Compopnent", Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class USphereComponent> InteractCollision;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon", Meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class ACEquipableBase> Item;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapon", Meta = (AllowPrivateAccess = "true"))
		float Radius = 100.0f;
};
