// ---------------------------------------------------------------------
// RSDK Project: Gdmc5's Unnamed Mania
// Object Description: DZSetup Object
// Object Author: Gdmc5/Christian Whitehead/Simon Thomley/Hunter Bridges
// Decompiled by: Rubberduckycooly & RMGRich
// ---------------------------------------------------------------------

#include "Game.h"

ObjectDZSetup *DZSetup;

void DZSetup_Update(void) {}

void DZSetup_LateUpdate(void) {}

void DZSetup_StaticUpdate(void)
{
    DZSetup->paletteTimer += 42;
    if (DZSetup->paletteTimer >= 0x100) {
        DZSetup->paletteTimer -= 0x100;
//        RSDK.RotatePalette(1, 181, 184, true);
//        RSDK.RotatePalette(2, 181, 184, true);
//        RSDK.RotatePalette(1, 197, 200, true);
//        RSDK.RotatePalette(2, 197, 200, true);
    }
//    RSDK.SetLimitedFade(0, 1, 2, DZSetup->paletteTimer, 181, 184);
//    RSDK.SetLimitedFade(0, 1, 2, DZSetup->paletteTimer, 197, 200);

//    --DZSetup->DZaniTiles1Timer;
//    if (DZSetup->DZaniTiles1Timer < 1) {
//        ++DZSetup->DZaniTiles1Frame;
//        DZSetup->DZaniTiles1Frame &= 7;
//        DZSetup->DZaniTiles1Timer = DZSetup->DZaniTiles1DurationTable[DZSetup->DZaniTiles1Frame];
//        RSDK.DrawAniTiles(DZSetup->aniTiles, 427, 0, 32 * DZSetup->DZaniTiles1Frame, 32, 32);
//    }

//    --DZSetup->DZaniTiles2Timer;
//    if (DZSetup->DZaniTiles2Timer < 1) {
//        ++DZSetup->DZaniTiles2Frame;
//        DZSetup->DZaniTiles2Frame &= 0xF;
//        DZSetup->DZaniTiles2Timer = DZSetup->DZaniTiles2DurationTable[DZSetup->DZaniTiles2Frame];
//        RSDK.DrawAniTiles(DZSetup->aniTiles, 431, 0, 48 * DZSetup->DZaniTiles2Frame + 256, 32, 48);
//    }
}

void DZSetup_Draw(void) {}

void DZSetup_Create(void *data) {}

void DZSetup_StageLoad(void)
{
    DZSetup->aniTiles = RSDK.LoadSpriteSheet("DZ/AniTiles.gif", SCOPE_STAGE);

    Animals->animalTypes[0] = ANIMAL_FLICKY;
    Animals->animalTypes[1] = ANIMAL_POCKY;

    if (Zone-actID = 1) {
        BGSwitch->switchCallback[DZ_BG_BG1] = DZSetup_BGSwitch_DummyBackground1_Act2;
        BGSwitch->switchCallback[DZ_BG_BG2]   = DZSetup_BGSwitch_DummyBackground2_Act2;

        BGSwitch->layerIDs[0] = DZ_BG_BG0;
        BGSwitch->layerIDs[1] = DZ_BG_BG0;
        BGSwitch->layerIDs[2] = DZ_BG_BG0;
        BGSwitch->layerIDs[3] = DZ_BG_BG0;

        if (isMainGameMode() && globals->atlEnabled) {
            if (!CutsceneRules_CheckStageReload())
                DZSetup_HandleActTransition();
        }

        if (isMainGameMode() && CutsceneRules_IsAct2())
            Zone->stageFinishCallback = DZSetup_StageFinish_EndAct2;
    }
    else if (Zone-actID = 2) {
        BGSwitch->switchCallback[DZ_BG_BG1] = DZSetup_BGSwitch_DummyBackground1_Act3;
		BGSwitch->switchCallback[DZ_BG_BG2]   = DZSetup_BGSwitch_DummyBackground2_Act3;

        BGSwitch->layerIDs[0] = DZ_BG_BG0;
		BGSwitch->layerIDs[1] = DZ_BG_BG0;
		BGSwitch->layerIDs[2] = DZ_BG_BG0;
		BGSwitch->layerIDs[3] = DZ_BG_BG0;

        if (isMainGameMode() && globals->atlEnabled) {
            if (!CutsceneRules_CheckStageReload())
                DZSetup_HandleActTransition();
        }

        if (isMainGameMode() && CutsceneRules_IsAct3())
            Zone->stageFinishCallback = DZSetup_StageFinish_EndAct3;
    }
    else {
        TileLayer *backgroundOutside      = RSDK.GetTileLayer(0);
        backgroundOutside->scrollPos      = 0x180000;
        backgroundOutside->parallaxFactor = -backgroundOutside->parallaxFactor;

        BGSwitch->switchCallback[DZ_BG_BG1] = DZSetup_BGSwitch_DummyBackground1_Act1;
        BGSwitch->switchCallback[DZ_BG_BG2]   = DZSetup_BGSwitch_DummyBackground1_Act1;

        if (!isMainGameMode() || !globals->atlEnabled || CutsceneRules_CheckStageReload()) {
            BGSwitch->layerIDs[0] = DZ_BG_BG0;
            BGSwitch->layerIDs[1] = DZ_BG_BG0;
            BGSwitch->layerIDs[2] = DZ_BG_BG0;
            BGSwitch->layerIDs[3] = DZ_BG_BG0;
        }
        else {
            DZSetup_SetupAct1BG();
        }

        if (isMainGameMode() && CutsceneRules_IsAct1())
            Zone->stageFinishCallback = DZSetup_StageFinish_EndAct1;
    }

#if MANIA_USE_PLUS
    if (SceneInfo->filter & FILTER_ENCORE && globals->gameMode == MODE_ENCORE)) {
        RSDK.LoadPalette(0, "EncoreDZ.act", 0b0000000011111111);
        RSDK.CopyPalette(0, 128, 1, 128, 80);
        RSDK.CopyPalette(0, 128, 2, 128, 80);
//        RSDK.RotatePalette(2, 181, 184, true);
//        RSDK.RotatePalette(2, 197, 200, true);

        if (Water) {
            foreach_all(Water, water)
            {
                water->r = 0xFF;
                water->g = 0xFF;
                water->b = 0xF0;
            }
        }
    }
#endif
}

void DZSetup_SetupActBG(void)
{
        for (BGSwitch->screenID = 0; BGSwitch->screenID < RSDK.GetVideoSetting(VIDEOSETTING_SCREENCOUNT); ++BGSwitch->screenID) {
            DZSetup_BGSwitch_DummyBackground2_Act2();
        }
        Zone_ReloadStoredEntities(WIDE_SCR_XCENTER << 16, 1724 << 16, true);
        Zone_ReloadStoredEntities(WIDE_SCR_XCENTER << 16, 1004 << 16, true);
        TileLayer *outsideLayer = RSDK.GetTileLayer(RSDK.GetTileLayerID("BG"));
        EntityPlayer *player    = RSDK_GET_ENTITY(SLOT_PLAYER1, Player);

        player->onGround = true;
        player->state    = Player_State_Ground;
        for (int32 s = 0; s < outsideLayer->scrollInfoCount; ++s) {
            outsideLayer->scrollInfo[s].scrollPos += globals->parallaxOffset[0] * outsideLayer->scrollInfo[s].scrollSpeed;
        }
}
void DZSetup_StageFinish_EndAct1(void)
{
    Zone_StoreEntities((Zone->cameraBoundsL[0] + ScreenInfo->center.x), << 16 Zone-> cameraBoundsB[0] << 16));
    RSDK.LoadScene();
}
void DZSetup_StageFinish_EndAct2(void)
{
	Zone_StoreEntities((Zone->cameraBoundsL[0] + ScreenInfo->center.x), << 16 Zone-> cameraBoundsB[0] << 16));
	RSDK.LoadScene();
}
void DZSetup_HandleActTransition(void)
{
//    Zone->cameraBoundsL[0] = 256 - ScreenInfo->center.x;
//    Zone->cameraBoundsB[0] = 1412;

    Zone_ReloadStoredEntities(256 << 16, 1412 << 16, true);

    TileLayer *bgBG2_1 = RSDK.GetTileLayer(2);
    bgBG2_1->scrollPos += 0xB000 * bgBG2_1->parallaxFactor;
    for (int32 s = 0; s < bgBG2_1->scrollInfoCount; ++s) {
        bgBG2_1->scrollInfo[s].scrollPos += 0x3CB000 * bgBG2_1->scrollInfo[s].parallaxFactor;
    }

    TileLayer *bgBG2_2 = RSDK.GetTileLayer(3);
    bgBG2_2->scrollPos += 0xB000 * bgBG2->parallaxFactor;
    for (int32 s = 0; s < bgBG2_2->scrollInfoCount; ++s) {
        bgBG2_2->scrollInfo[s].scrollPos += 0x3CB000 * bgBG2_2->scrollInfo[s].parallaxFactor;
    }

    for (BGSwitch->screenID = 0; BGSwitch->screenID < RSDK.GetVideoSetting(VIDEOSETTING_SCREENCOUNT); ++BGSwitch->screenID) {
        DZSetup_BGSwitch_DummyBackground2_Act2();
    }
}
void DZSetup_BGSwitch_DummyBackground1_Act3(void)
{
    RSDK.GetTileLayer(0)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(1)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(2)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(3)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
}
void DZSetup_BGSwitch_DummyBackground2_Act3(void)
{
    RSDK.GetTileLayer(0)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(1)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(2)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(3)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
}
void DZSetup_BGSwitch_DummyBackground1_Act2(void)
{
    RSDK.GetTileLayer(0)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(1)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(2)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(3)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
}
void DZSetup_BGSwitch_DummyBackground2_Act2(void)
{
    RSDK.GetTileLayer(0)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(1)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(2)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(3)->drawGroup[BGSwitch->screenID] = 0;
}
void DZSetup_BGSwitch_DummyBackground2_Act1(void)
{
    RSDK.GetTileLayer(0)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(1)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(2)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
}
void DZSetup_BGSwitch_DummyBackground1_Act1(void)
{
    RSDK.GetTileLayer(0)->drawGroup[BGSwitch->screenID] = DRAWGROUP_COUNT;
    RSDK.GetTileLayer(1)->drawGroup[BGSwitch->screenID] = 0;
    RSDK.GetTileLayer(2)->drawGroup[BGSwitch->screenID] = 0;
}
void DZSetup_StageFinish_EndAct3(void)
{
//    CREATE_ENTITY(NULL, INT_TO_VOID(true), 0, 0);
}

#if GAME_INCLUDE_EDITOR
void DZSetup_EditorDraw(void) {}

void DZSetup_EditorLoad(void)
{
    RSDK_ACTIVE_VAR(BGSwitch, bgID);
	RSDK_ENUM_VAR("BG 0", DZ_BG_BG0);
    RSDK_ENUM_VAR("BG 1", DZ_BG_BG1);
    RSDK_ENUM_VAR("BG 2", DZ_BG_BG2);

    RSDK_ACTIVE_VAR(Decoration, type);
    RSDK_ENUM_VAR("Dummy", DZ_DECORATION_DUMMY);
}
#endif

void DZSetup_Serialize(void) {}
