#ifndef OBJ_DZSETUP_H
#define OBJ_DZSETUP_H

#include "Game.h"

typedef enum {
    DZ_BG_BG0,
    DZ_BG_BG1,
    DZ_BG_BG2,
} BGSwitchIDsDZ;

typedef enum { DZ_DECORATION_DUMMY } DecorationTypesDZ;

// Object Class
struct ObjectDZSetup {
    RSDK_OBJECT
    int32 paletteTimer;
    STATIC(int32 DZaniTiles1Timer, 30);
    int32 DZaniTiles1Frame;
    TABLE(int32 DZaniTiles1DurationTable[8], { 30, 2, 2, 2, 30, 2, 2, 2 });
    STATIC(int32 DZaniTiles2Timer, 60);
    int32 DZaniTiles2Frame;
    TABLE(int32 DZaniTiles2DurationTable[16], { 120, 2, 2, 2, 8, 2, 2, 2, 120, 2, 2, 2, 8, 2, 2, 2 });
    uint16 aniTiles;
};

// Entity Class
struct EntityDZSetup {
    RSDK_ENTITY
};

// Object Struct
extern ObjectDZSetup *DZSetup;

// Standard Entity Events
void DZSetup_Update(void);
void DZSetup_LateUpdate(void);
void DZSetup_StaticUpdate(void);
void DZSetup_Draw(void);
void DZSetup_Create(void *data);
void DZSetup_StageLoad(void);
#if GAME_INCLUDE_EDITOR
void DZSetup_EditorDraw(void);
void DZSetup_EditorLoad(void);
#endif
void DZSetup_Serialize(void);

// Extra Entity Functions
void DZSetup_SetupActBG(void);
void DZSetup_StageFinish_EndAct1(void);
void DZSetup_StageFinish_EndAct2(void);
void DZSetup_HandleActTransition(void);
void DZSetup_BGSwitch_DummyBackground1_Act3(void);
void DZSetup_BGSwitch_DummyBackground2_Act3(void);
void DZSetup_BGSwitch_DummyBackground1_Act2(void);
void DZSetup_BGSwitch_DummyBackground2_Act2(void);
void DZSetup_BGSwitch_DummyBackground1_Act1(void);
void DZSetup_BGSwitch_DummyBackground2_Act1(void);
void DZSetup_StageFinish_EndAct3(void);

#endif //! OBJ_DZSETUP_H
