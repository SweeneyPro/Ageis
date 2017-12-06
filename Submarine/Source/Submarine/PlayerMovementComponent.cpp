// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UPlayerMovementComponent::UPlayerMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Setup();
	
}


// Called every frame
void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	ForceMovement();
	//LookAtMouse();
}

void UPlayerMovementComponent::MoveHorizontally(float value)
{
	
	ForceVector = FVector(0, ((value * MovementMultiplier)*-1), ForceVector.Z);
}

void UPlayerMovementComponent::MoveVertically(float value)
{
	
	ForceVector = FVector(0, ForceVector.Y, value * MovementMultiplier);
}

void UPlayerMovementComponent::ForceMovement()
{
	
	Parent->FindComponentByClass<UCapsuleComponent>()->AddForce(ForceVector, NAME_None, true);
	//Parent->
}

void UPlayerMovementComponent::Setup()
{
	Parent = GetOwner();
	Parent->InputComponent->BindAxis("MoveH", this, &UPlayerMovementComponent::MoveHorizontally);
	Parent->InputComponent->BindAxis("MoveV", this, &UPlayerMovementComponent::MoveVertically);

	PlayerController = Cast<APlayerController>(Cast<APawn>(Parent)->GetController());
}

void UPlayerMovementComponent::LookAtMouse()
{
	
	float lookAtRot;
	FHitResult hitResult;
	PlayerController->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), false, hitResult);

	lookAtRot = UKismetMathLibrary::FindLookAtRotation(Parent->FindComponentByClass<UCapsuleComponent>()->GetComponentLocation(), FVector(Parent->FindComponentByClass<UCapsuleComponent>()->GetComponentLocation().X, hitResult.Location.Y, hitResult.Location.Z)).Pitch;

	if (hitResult.Location.Y > Parent->GetActorLocation().Y)
	{
		Parent->FindComponentByClass<UCapsuleComponent>()->SetWorldRotation(FRotator(0, 180, lookAtRot));
	}
	else
	{

		Parent->FindComponentByClass<UCapsuleComponent>()->SetWorldRotation(FRotator(0, 0, lookAtRot));
	}

	

	
	
}

