#include "SDL.h"

#include <Engine/Base/Timer.h>
#include <Engine/Base/Input.h>
#include <Engine/Base/Translation.h>
#include <Engine/Base/KeyNames.h>
#include <Engine/Math/Functions.h>
#include <Engine/Graphics/ViewPort.h>
#include <Engine/Base/Console.h>
#include <Engine/Base/Synchronization.h>
#include <Engine/Base/SDL/SDLEvents.h>
#include <Engine/Base/Shell.h>
#include <Engine/Base/ErrorReporting.h>

#include <vitasdk.h>
#include <vitaGL.h>

namespace OSK
{
  static SceWChar16 osk_wstrInitText[SCE_IME_DIALOG_MAX_TEXT_LENGTH + 1];
  static SceWChar16 osk_wstrInputText[SCE_IME_DIALOG_MAX_TEXT_LENGTH + 1];
  static SceImeDialogResult osk_Result;
  static BOOL osk_bOskActive;

  static inline void FromUTF16(CTString& strOut, const SceWChar16 *wstrSrc, const ULONG iOutMax)
  {
    char Tmp[SCE_IME_DIALOG_MAX_TEXT_LENGTH + 1];
    ULONG i;
    for (i = 0; i < iOutMax && i < SCE_IME_DIALOG_MAX_TEXT_LENGTH && wstrSrc[i]; ++i)
      Tmp[i] = wstrSrc[i] & 0xFF;
    Tmp[i] = 0;
    strOut = Tmp;
  }

  static inline void ToUTF16(SceWChar16 *wstrOut, const CTString& strSrc, const ULONG iOutMax)
  {
    ULONG i = 0;
    if (!strSrc.IsEmpty())
    {
      for (; i < iOutMax && i < SCE_IME_DIALOG_MAX_TEXT_LENGTH && strSrc.str_String[i]; ++i)
        wstrOut[i] = strSrc[i];
    }
    wstrOut[i] = 0;
  }
};

BOOL CInput::IsOnScreenKeyboardSupported(void) const
{
  return TRUE;
}

BOOL CInput::GetOnScreenKeyboardInput(const CTString& strInitText, CTString& strOutText, const ULONG iOutMax)
{
  SceImeDialogParam Param;

  OSK::ToUTF16(OSK::osk_wstrInitText, strInitText, SCE_IME_DIALOG_MAX_TEXT_LENGTH);

  sceImeDialogParamInit(&Param);
  Param.supportedLanguages = SCE_IME_LANGUAGE_ENGLISH;
  Param.languagesForced = SCE_TRUE;
  Param.type = SCE_IME_TYPE_BASIC_LATIN;
  Param.title = (const SceWChar16 *)u"Enter text";
  Param.maxTextLength = SCE_IME_MAX_TEXT_LENGTH;
  Param.initialText = OSK::osk_wstrInitText;
  Param.inputTextBuffer = OSK::osk_wstrInputText;

  sceImeDialogInit(&Param);

  BOOL bRet = FALSE;
  while (TRUE)
  {
    if (sceImeDialogGetStatus() == 2)
    {
      memset(&OSK::osk_Result, 0, sizeof(OSK::osk_Result));
      sceImeDialogGetResult(&OSK::osk_Result);
      sceImeDialogTerm();
      if (OSK::osk_Result.button == SCE_IME_DIALOG_BUTTON_ENTER)
      {
        OSK::FromUTF16(strOutText, OSK::osk_wstrInputText, iOutMax);
        bRet = TRUE;
      }
      break;
    }
    vglSwapBuffers(GL_TRUE);
  }

  return bRet;
}
