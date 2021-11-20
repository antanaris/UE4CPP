// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Tool.h"
#include "GeneralWeapon.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UE4CPP_API AGeneralWeapon : public ATool
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGeneralWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Muzzle socket
	UPROPERTY()
	UStaticMeshSocket* MuzzleSocket;

public:
	// Weapon has mesh and Muzzle Socket on it
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	bool bHasMuzzleSocket = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 MaxAmmo = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 AmmoPerClip = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Damage = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float ReloadDuration = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Range = 1500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FName MuzzleSocketName = "Muzzle";

	// State
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 CurrentAmmo = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 CurrentAmmoInClip = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool bIsReloading = false;
	
	// Actions
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void CanFire(bool& bCanFire) const;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void CanReload(bool& bCanReload) const;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Reload();

	UFUNCTION()
	void UseAmmo();

	UFUNCTION()
	void WeaponTrace();
	void WeaponTrace(FVector& HitLocation); // 🌸

};
