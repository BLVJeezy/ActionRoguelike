#include "ActionSystem/FourNationsElementalAction.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FourNationsElementalAction)

FGameplayTag UFourNationsElementalAction::GetBendingActionTag() const
{
    const TCHAR* TagName = TEXT("Action.Bending.Air");
    switch (Element)
    {
    case EFourNationsElement::Water: TagName = TEXT("Action.Bending.Water"); break;
    case EFourNationsElement::Earth: TagName = TEXT("Action.Bending.Earth"); break;
    case EFourNationsElement::Fire: TagName = TEXT("Action.Bending.Fire"); break;
    default: break;
    }
    return FGameplayTag::RequestGameplayTag(FName(TagName));
}
