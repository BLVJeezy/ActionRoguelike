# Four Nations — Milestone 01: Elemental Combat Foundation

This fork remains an **Unreal Engine 5** project. Do not deploy its native game files to Vercel: Vercel does not execute Unreal Engine gameplay.

## What this change implements

- Adds `EFourNationsElement` (Air, Water, Earth, Fire) as a Blueprint-visible C++ enum.
- Adds `UFourNationsElementalAction`, a Blueprintable child of the existing `URogueAction_ProjectileAttack`.
- **Preserves** the original projectile targeting, animation timing, VFX/audio hooks, cooldown, pooled spawning and existing multiplayer authority behavior through inheritance.
- Adds an element identifier accessible from Blueprint for HUD and future element-specific behavior.

## Unreal Editor setup

1. Open the existing ActionRoguelike project using its matching UE version and compile the C++ module.
2. Create Blueprint children of `FourNationsElementalAction`:
   - `BP_Bend_AirBlast`: Element=Air
   - `BP_Bend_WaterWhip`: Element=Water
   - `BP_Bend_EarthShard`: Element=Earth
   - `BP_Bend_FireBlast`: Element=Fire
3. Set each child's inherited `ProjectileClass`, `AttackAnim`, `CastingEffect`, `CastingSound`, `ActivationTag` and `CooldownTime` using compatible existing or newly created assets.
4. Register the actions on the player's existing `RogueActionComponent` through its current action-granting setup. Avoid replacing the existing character controller.
5. Test all four actions in single-player and in a server/client PIE session.

## Boundaries and next milestones

This first commit provides an **actual C++ integration point**, not finished elemental visuals or abilities. No new projectile meshes, animation assets, world map, terrain manipulation or playable builds are included. The WaterWhip name is a placeholder for a projectile-style attack, not a simulated rope.

Next: add per-element projectile effects and damage behavior, then movement skills, nation-specific environments, PvP balancing and packaged Windows builds.

## Acceptance tests

- C++ compiles in the Unreal Editor (not verified by GitHub-only tooling).
- Four Blueprint child classes can be created and expose the element selector.
- Each configured action fires with the existing camera aim, cooldown and spawn logic.
- Original Action Roguelike actions remain functional.
- Server and client both observe projectiles during a multiplayer PIE test.

## Attribution and assets

Retain the upstream repository's attribution and follow its asset licenses. Epic Paragon assets are restricted to Unreal Engine use. Use original or properly licensed art for Four Nations.
