// Copyright Benjamin Herzig


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"


AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GameplayEffectClass) const
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;

	check(GameplayEffectClass)
	FGameplayEffectContextHandle Context = TargetASC->MakeEffectContext();
	Context.AddSourceObject(this);

	const FGameplayEffectSpecHandle OutgoingSpec = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, Context);
	TargetASC->ApplyGameplayEffectSpecToSelf(*OutgoingSpec.Data.Get());
}
