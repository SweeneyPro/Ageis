// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUBMARINE_API UPlayerMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMovementComponent();

	UPROPERTY(EditAnywhere, Category = Movement)
	float MovementMultiplier;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AActor* Parent;
	APlayerController* PlayerController;
	void LookAtMouse();
	void MoveHorizontally(float const input);
	void MoveVertically(float const input);
	void ForceMovement();
	void Setup();

	FVector ForceVector;
	
};
