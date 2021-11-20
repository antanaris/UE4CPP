// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Tool.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class UE4CPP_API AWeapon : public ATool
{
	GENERATED_BODY()

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
	float Range = 250.f;

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
