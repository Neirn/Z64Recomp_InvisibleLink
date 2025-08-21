#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "playermodelmanager_api.h"

static void registerFormModel(const char internalName[], PlayerModelManagerModelType type) {
    PlayerModelManagerHandle h = PLAYERMODELMANAGER_REGISTER_MODEL(internalName, type);

    for (int i = 0; i < PMM_DL_MAX; ++i) {
        PlayerModelManager_setDisplayList(h, i, gEmptyDL);
    }
}

PLAYERMODELMANAGER_CALLBACK_REGISTER_MODELS void registerModel() {
    registerFormModel("invisible_human", PMM_MODEL_TYPE_CHILD);
    registerFormModel("invisible_deku", PMM_MODEL_TYPE_DEKU);
    registerFormModel("invisible_goron", PMM_MODEL_TYPE_GORON);
    registerFormModel("invisible_zora", PMM_MODEL_TYPE_ZORA);
    registerFormModel("invisible_fierce_deity", PMM_MODEL_TYPE_FIERCE_DEITY);
}
