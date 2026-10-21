#pragma once

#include "CoreMinimal.h"
#include "ActionSystem/RogueAction_ProjectileAttack.h"
#include "FourNationsElementalAction.generated.h"

// An extensible bending identity for existing multiplayer-capable projectile actions.
UENUM(BlueprintType)
enum class EFourNationsElement : uint8
{
    Air UMETA(DisplayName="Air"),
    Water UMETA(DisplayName="Water"),
    Earth UMETA(DisplayName="Earth"),
    Fire UMETA(DisplayName="Fire")
};

/**
 * Elemental projectile action. Retains Action Roguelike's existing targeting,
 * animation, cooldown, spawning, damage and networking behavior.
 *
 * Create four Blueprint children and configure their inherited ProjectileClass,
 * AttackAnim, CastingEffect, CastingSound and cooldown per bending style.
 */
UCLASS(Blueprintable)
class ACTIONROGUELIKE_API UFourNationsElementalAction : public URogueAction_ProjectileAttack
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="Four Nations|Bending")
    EFourNationsElement GetElement() const { return Element; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Four Nations|Bending")
    EFourNationsElement Element = EFourNationsElement::Air;
};
