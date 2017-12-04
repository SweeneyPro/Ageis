// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnSubmarine.generated.h"

UCLASS()
class SUBMARINE_API AMyPawnSubmarine : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* SubmarineMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Cam;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Root, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;

private: 

	void MoveHorizontally(float input);
	void MoveVertically(float input);

public:
	// Sets default values for this pawn's properties
	AMyPawnSubmarine();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
