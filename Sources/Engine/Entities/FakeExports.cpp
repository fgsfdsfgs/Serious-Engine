#include <Engine/Base/PSVita/FakeExports.h>
class CDLLEntityClass;

extern "C" CDLLEntityClass CEntity_DLLClass;
extern "C" CDLLEntityClass CLiveEntity_DLLClass;
extern "C" CDLLEntityClass CRationalEntity_DLLClass;
extern "C" CDLLEntityClass CMovableBrushEntity_DLLClass;
extern "C" CDLLEntityClass CMovableEntity_DLLClass;
extern "C" CDLLEntityClass CMovableModelEntity_DLLClass;
extern "C" CDLLEntityClass CPlayerEntity_DLLClass;

static CFakeLib exp_Internal("Internal", {
  { "CEntity_DLLClass", (void*)&CEntity_DLLClass },
  { "CLiveEntity_DLLClass", (void*)&CLiveEntity_DLLClass },
  { "CRationalEntity_DLLClass", (void*)&CRationalEntity_DLLClass },
  { "CMovableEntity_DLLClass", (void*)&CMovableEntity_DLLClass },
  { "CMovableBrushEntity_DLLClass", (void*)&CMovableBrushEntity_DLLClass },
  { "CMovableModelEntity_DLLClass", (void*)&CMovableModelEntity_DLLClass },
  { "CPlayerEntity_DLLClass", (void*)&CPlayerEntity_DLLClass },
});
